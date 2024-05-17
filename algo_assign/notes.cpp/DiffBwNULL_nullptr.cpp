
#include <iostream>

void foo(int)
{
    std::cout << "Called foo(int)\n";
}

void foo(void *)
{
    std::cout << "Called foo(void*)\n";
}

int main()
{
    foo(0);       // Ambiguous with NULL
    foo(NULL);    // Typically resolves to foo(int) due to NULL being 0
    foo(nullptr); // Resolves to foo(void*) due to type safety of nullptr
    return 0;
}
