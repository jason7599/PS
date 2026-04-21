#include <iostream>
#include <string>

int main()
{
    int n_cols;
    std::cin >> n_cols;

    std::string pw;
    std::cin >> pw;
    
    int n_rows = pw.length() / n_cols;

    for (int i = 0; i < n_cols; i++)
    {
        for (int j = 0; j < n_rows; j++)
            std::cout << pw[j * n_cols + (j % 2 ? n_cols - 1 - i : i)];
    }
}