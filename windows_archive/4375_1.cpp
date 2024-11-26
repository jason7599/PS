#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int input;    
    while(true) {
        std::cin>>input;
        for(int i=3; ; i++) {
            bool youGotIt = true;
            std::string temp= std::to_string(input*i);
            for(char c : temp) {
                if(c!='1') {
                    youGotIt=false;
                    break;
                }
            }
            if(youGotIt) {
                std::cout<<temp<<std::endl;
                break;
            }
        }
    }
}