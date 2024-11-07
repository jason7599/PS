#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string one_to_nineteen[] =
{
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

const string twenty_to_ninety[] =
{
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

string num_to_string(int num)
{
    string str;

    int hundreds = num / 100;
    if (hundreds)
        str = one_to_nineteen[hundreds - 1] + "hundred";
    
    int tens_and_ones = num % 100;
    if (tens_and_ones < 20)
        str += one_to_nineteen[tens_and_ones - 1];
    else
    {
        int tens = tens_and_ones / 10;
        int ones = tens_and_ones % 10;
        str += twenty_to_ninety[tens - 2];
        if (ones)
            str += one_to_nineteen[ones - 1];
    }
    
    return str;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_words;
    cin >> num_words;

    vector<string> words(num_words);
    int num_str_idx;
    int fixed_len = 0;

    for (int i = 0; i < num_words; i++)
    {
        string word;
        cin >> word;
        
        if (word == "$")
            num_str_idx = i;
        else
        {
            fixed_len += word.length();
            words[i] = word;
        }
    }

    for (int total_len = fixed_len + 3;; total_len++)
    {
        string num_str = num_to_string(total_len);
        if (fixed_len + num_str.length() == total_len)
        {
            words[num_str_idx] = num_str;
            break;
        }
    }

    for (string word : words)
        cout << word << ' ';

    return 0;
}