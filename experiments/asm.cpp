#include <iostream>

int main() 
{
    int a = 10, b = 20, result;
    asm 
    (
        "movl %1, %%eax;"  // Load `a` into EAX
        "addl %2, %%eax;"  // Add `b` to EAX
        "movl %%eax, %0;"  // Store the result in `result`
        : "=r"(result)     // Output operand
        : "r"(a), "r"(b)   // Input operands
        : "%eax"           // Clobbered registers
    );
    std::cout << "Result: " << result << std::endl;
    return 0;
}
