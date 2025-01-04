#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::getline(std::cin, text);

    int n_happy = 0;
    int n_sad = 0;

    for (size_t base = 0; base < text.length();)
    {
        size_t t = text.find(":-", base);
       
        if (t == std::string::npos
        || t + 2 >= text.length())
            break;
        
        if (text[t + 2] == ')')
        {
            n_happy++;
            base = t + 3;
        }
        else if (text[t + 2] == '(')
        {
            n_sad++;
            base = t + 3;
        }
        else
            base = t + 2;
    }

    if (!n_happy && !n_sad)
        std::cout << "none";
    else if (n_happy == n_sad)
        std::cout << "unsure";
    else if (n_happy > n_sad)
        std::cout << "happy";
    else
        std::cout << "sad";
}