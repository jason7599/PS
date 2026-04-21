#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<string, int> sales;
    int max_sales = 0;
    string max_sale_book;

    int n_sales;
    cin >> n_sales;
    while (n_sales--) {
        string book;
        cin >> book;
        int& sale = ++sales[book];
        if (sale > max_sales || (sale == max_sales && book < max_sale_book)) {
            max_sales = sale;
            max_sale_book = book;
        }
    }
    
    cout << max_sale_book << '\n';
}