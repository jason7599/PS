#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <array>

using namespace std;

#define P(x) cout << x << ' ';
#define PL(x) cout << x << endl;
#define NL cout << '\n';
#define FOR(i, n) for (int i = 0; i < n; i++)

void input_test();
void sort_string();
void bitset_test();
void cin_chars_test();
void string_char_append();
long long long_long_max_val();
void random_test();
void bool_arr_true();
void string_find_all(string, char);
void string_insert();
void queue_pop_foreach();
void string_append();
void string_erase();
void array_default();
void c_arr_foreach();
void std_array_args(array<int, 5>&);
void std_fill_n();
void std_fill();
vector<int> foreach_callee();
void foreach_call();

int main()
{
    cout << "hello world!\n" << endl;

    // int* a = (int*)malloc(sizeof(int) * 10);
    // delete a;
    // input_test();
    // sort_string();
    // bitset_test();
    // cin_chars_test();
    // string_char_append();
    // cout << (int)'0' << ' ' << (int)'A' << endl;
    // cout << long_long_max_val() << endl;
    // cout << (char)('a' + 16);
    // random_test();
    // cout << as[4].b << endl;
    // float a = 0;
    // cout << (bool)a << endl;
    // bool_arr_true();
    // string_find_all("niagara falls", 'a');
    // string_insert();
    // queue_pop_foreach();
    // string_append();
    // string_erase();
    // array_default();
    // c_arr_foreach();
    // std_fill_n();
    // std::string s;
    // s = 'c';
    // PL(s)
    // std_fill();
    // std::string a = "1222";
    // std::string b = "921";
    // PL((a < b))
    // foreach_call();
    // PL(-3 % 2)
    // if (!(-4%2))
        // P('a');
    // PL((1 << 10 - 1))
    // map<int, int> m;
    // m[1] = 5;
    // m[1] = 6;
    // PL(m[1])
    // P(4 % 3 + 1)
    // PL(-6%6)
    // string a = "zza";
    // std::cout << next_permutation(a.begin(), a.end()) << '\n';
    // std::cout << a;
    // string s = "bc";
    // PL('a' + s)
    // int a = 10;
    // int b = a += 10;
    // PL(a);
    // PL(b)
    // short s = 0;
    // while (s <= 0)
    //     s--;
    // // P(s)
    // unsigned char a = 0;
    // a--;
    // PL((int)a);
    // PL((int)++a)
    // char c = 'A';
    // PL(c)
    // unsigned char t = c;
    // PL(t)
    int a = 10, b = 20;
    a, b += 30;
    PL(a)
    PL(b)

    cout << "\nend\n";
    return 0;
}

vector<int> foreach_callee()
{
    PL("foreach_callee() called")
    NL
    
    vector<int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    return v;
}

void foreach_call()
{
    for (int i : foreach_callee())
        P(i);
    NL;
}

void std_fill()
{
    int arr[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            arr[i][j] = i * 5 + j;
    }

    // ***
    std::fill(&arr[0][0], &arr[5][0], 10);

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
            std::cout << arr[y][x] << ' ';
        std::cout << '\n';
    }
}

void std_fill_n()
{
    int dp[5][10];
    fill_n(dp[0], 30, 1);

    FOR(i, 5)
    {
        FOR(j, 10)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
}

void std_array_args(array<int, 5>& arr)
{
    arr[3] = 1;
}

void c_arr_foreach()
{
    int arr[] = {1, 2, 3};
    for (int a : arr)
        cout << a << ' ';
}

void array_default()
{
    array<int, 5> arr;
    for (int v : arr)
        cout << v << ' ';
}

void string_erase()
{
    string hello = "Hello World!";
    // hello.erase(hello.find(' '));
    // hello.replace()
    hello.erase(hello.find(' '), 1);
    cout << hello << endl;
}

void string_append()
{
    string a = "abcd";
    cout << a.append("efg") << endl;
}

void input_test()
{
    char input[3];
    scanf("%s", input);
    printf("%s", input);
}

void sort_string()
{
    string a = "hello";
    sort(a.begin(), a.end());
    cout << a << '\n';
}

void bitset_test()
{
    bitset<5> b("10110");

    // cout << b << endl;

    // uint val = b.to_ulong();

    // cout << val << endl;

    

    // cout << bb << endl;
    // cout << b << endl;

    // b - (b & (~b));
}

void cin_chars_test()
{
    char a, b;
    cin >> a >> b;
    cout << '\"' << a << b << "\"\n";
}

void string_char_append()
{
    string s;
    
    int t = 11;
    s += t - 10 + 'A';

    cout << s << endl;
}

long long long_long_max_val()
{
    long long a = -1 ^ (1ll << 63);
    return a;
}

void random_test()
{
    srand(time(nullptr));

    int iter = 1e2;

    const long long mv = long_long_max_val(); 

    while (iter--)
    {
        long long val = (long long)rand() * rand();
        // if (val < 0 )
    }
}

void bool_arr_true()
{
    bool arr[5] = {1, };
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] != 1)
            cout << "arr[" << i <<"] is not 1!" << endl;
    }
}

void string_find_all(string str, char c)
{
    size_t pos = 0;
    while ((pos = str.find(c, pos)) != string::npos)
    {
        cout << pos << ", ";
        pos++;
    }
    cout << endl;
}

void string_insert()
{
    string s = "abcd";
    // s.insert('k', 0);
    // cout << s << endl;
}

void queue_pop_foreach()
{
    vector<queue<int>> vq(1);
    vq[0].push(5);

    for (auto& q : vq)
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << vq[0].size() << endl;
}