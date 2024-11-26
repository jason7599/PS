#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct File
{
    string name; // debug
    bool is_dir;
    vector<string> dir;
};

map<string, File> all_files;

void print(const string& file_name, int depth = 0)
{
    for (int i = 0; i < depth; i++) cout << '\t';
    cout << file_name << '\n';

    File file = all_files[file_name];
    if (file.is_dir)
    {
        for (const string& sub_files : file.dir)
        {
            print(sub_files, depth + 1);
        }
    }
}

void print_info(string path)
{
    int t;
    while ((t = path.find('/')) != -1)
    {
        string dir = path.substr(0, t);
        path = path.substr()
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    all_files["main"] = File{"main", true};

    int num_dirs, num_files;
    cin >> num_dirs >> num_files;

    for (int i = 0; i < num_dirs + num_files; i++)
    {
        string dir_name, file_name;
        bool is_dir;

        cin >> dir_name >> file_name >> is_dir;

        all_files[file_name] = {file_name, is_dir};
        all_files[dir_name].dir.push_back(file_name);
    }

    int num_queries;
    cin >> num_queries;

    while (num_queries--)
    {
        string path;
        cin >> path;
    }

    return 0;
}