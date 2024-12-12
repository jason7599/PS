#include <iostream>
#include <string>
#include <map>

struct Node
{
    std::map<char, Node*> children;
    bool end = 0;
    bool do_rm = 0;
    bool safe_to_rm = 1; // true if this node has no "dont-rm" subnodes
};

void add_file_name(Node* root, const std::string& file_name, bool do_rm)
{
    Node* node = root;

    for (char c : file_name)
    {
        if (!do_rm)
            node->safe_to_rm = 0;

        if (!node->children.count(c))
            node->children[c] = new Node(); // fuck

        node = node->children[c];
    }

    node->end = 1;
    node->safe_to_rm = do_rm;
    node->do_rm = do_rm;
}

int get_min_rms(Node* node)
{
    if (node->safe_to_rm)
        return 1;

    int min_rms = 0;
    if (node->do_rm && node->end) // without wildcard
        min_rms++;

    for (auto& [c, child] : node->children)
        min_rms += get_min_rms(child);
    
    return min_rms;
}

void cleanup(Node* node)
{
    for (auto& [c, child] : node->children)
    {
        cleanup(child);
        delete child;
    }
    node->children.clear();
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        Node root;

        for (int do_rm = 1; do_rm >= 0; do_rm--)
        {
            int n_files;
            std::cin >> n_files;
            while (n_files--)
            {
                std::string file_name;
                std::cin >> file_name;
                add_file_name(&root, file_name, do_rm);
            }
        }

        std::cout << get_min_rms(&root) << '\n';

        cleanup(&root);
    }
}