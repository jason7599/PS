#include <iostream>
#include <string>

using namespace std;

const string alphabets[] = 
{
    "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};

int main()
{
    string input; cin >> input;

    int index = 0;
    int num_alphabets = 0;

    while (index < input.length())
    {
        bool match_found = false;
        for (string alphabet : alphabets)
        {
            if (input.length() - index < alphabet.length())
                continue;
            
            int match;
            for (match = 0; match < alphabet.length(); match++)
            {
                if (input[index + match] != alphabet[match])
                    break;
            }

            if (match == alphabet.length())
            {
                index += alphabet.length();
                match_found = true;
                break;
            }
        }
        num_alphabets++;
        if (!match_found)
            index++;
    }

    cout << num_alphabets;
}