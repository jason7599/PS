#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {

    while(true) {
        string input;
        cin >> input;
        if(input == "end")
            break;
        
        bool check = false;
        int vowelStreak = 0;
        int consonantStreak = 0;
        char prev = 'Z';

        for(char c : input) {
            if(isVowel(c)) {
                check = true;
                if(++vowelStreak==3) {
                    check = false;
                    break;
                }
                consonantStreak = 0;
            }
            else {
                if(++consonantStreak==3) {
                    check = false;
                    break;
                }
                vowelStreak = 0;
            }
            if(c == prev && c != 'e' && c != 'o') {
                check = false;
                break;
            }
            prev = c;
        }


        cout<<'<'<<input<<"> is ";
        if(!check) 
            cout<<"not ";
        cout<<"acceptable.\n";
    }

}