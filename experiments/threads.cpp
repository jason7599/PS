#include <iostream>
#include <thread>

int main()
{
    int a = 4;

    std::thread t([&a] 
    {
        a = 10;
        for (int i = 0; i < 5; i++)
            std::cout << "Lambda thread :)" << std::endl;
    });

    t.join();

    std::cout << a << '\n'; int 🤝 = 10;
    std::cout << 🤝 << '\n';
    std::cout << "🤝" << '\n';

    for (int i = 0; i < 5; i++)
    {
        [&i] {
            std::cout << ++i;
        } ();
    }
}