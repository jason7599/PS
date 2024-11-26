#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Dir
{
    string name;
    map<string, Dir> subdirs;
};

void list_dir(const Dir& dir, bool root_dir = false)
{
    static int indent;

    if (!root_dir)
    {
        for (int i = 0; i < indent; i++)
            cout << ' ';
        cout << dir.name << '\n';
        indent++;
    }
    for (auto i : dir.subdirs)
        list_dir(i.second);
    if (!root_dir)
        indent--;
}

Dir* get_or_make_subdir(Dir& parent, const string& subdir_name)
{
    if (parent.subdirs.find(subdir_name) == parent.subdirs.end())
        parent.subdirs[subdir_name] = Dir{subdir_name};
    return &parent.subdirs[subdir_name];
}

vector<string> parse_path(string path)
{
    vector<string> parsed;
    size_t t;
    while ((t = path.find('\\')) != -1)
    {
        parsed.push_back(path.substr(0, t));
        path = path.substr(t + 1);
    }
    parsed.push_back(path);
    return parsed;
}

void make_path(Dir& root, const string& path)
{
    vector<string> dir_names = parse_path(path);
    Dir* dir = &root;
    for (const string& dir_name : dir_names)
        dir = get_or_make_subdir(*dir, dir_name);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Dir root_dir{"ROOT"};

    int num_paths; 
    cin >> num_paths;
    while (num_paths--)
    {
        string path;
        cin >> path;
        make_path(root_dir, path);
    }
    
    list_dir(root_dir, true);
}