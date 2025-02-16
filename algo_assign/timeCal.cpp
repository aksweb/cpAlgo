#include <iostream>
#include <chrono>

int main()
{
    long long n = 1e9;
    auto start = std::chrono::high_resolution_clock::now();
    n *= 3;
    long long sum = 1;
    for (long long i = 1; i <= n; i++)
    {
        sum += i; // Simple computation
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    return 0;
}
