#include <iostream>

int main() {
    int before=0,after;
    int mushroom[10];
    int input,result;

    for(int i=0; i<10; i++)
        std::cin>>mushroom[i];

    for(int i=0; i<10; i++) {
        input=mushroom[i];
        after=before+input;
        if(after>=100) {
            result = (after-100)>(100-before) 
                        ? before : after;
            break;
        }
        before=after;
        result=after;
    }

    std::cout<<result;
}