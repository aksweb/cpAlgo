#include <iostream>
#include <limits>  // Include <limits> to use std::numeric_limits

int main() {
    // Using numeric_limits with int
    std::cout << "Properties of int:" << std::endl;
    std::cout << "Minimum value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum value: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Is signed: " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "Is integer: " << std::numeric_limits<int>::is_integer << std::endl;
    std::cout << "Digits: " << std::numeric_limits<int>::digits << std::endl;

    std::cout << std::endl;

    // Using numeric_limits with float
    std::cout << "Properties of float:" << std::endl;
    std::cout << "Minimum value: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Maximum value: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Is signed: " << std::numeric_limits<float>::is_signed << std::endl;
    std::cout << "Is integer: " << std::numeric_limits<float>::is_integer << std::endl;
    std::cout << "Digits: " << std::numeric_limits<float>::digits << std::endl;
    std::cout << "Digits10: " << std::numeric_limits<float>::digits10 << std::endl;

    std::cout << std::endl;

    // Using numeric_limits with double
    std::cout << "Properties of double:" << std::endl;
    std::cout << "Minimum value: " << std::numeric_limits<long long>::min() << std::endl;
    std::cout << "Maximum value: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Is signed: " << std::numeric_limits<double>::is_signed << std::endl;
    std::cout << "Is integer: " << std::numeric_limits<double>::is_integer << std::endl;
    std::cout << "Digits: " << std::numeric_limits<double>::digits << std::endl;
    std::cout << "Digits10: " << std::numeric_limits<double>::digits10 << std::endl;

    return 0;
}
