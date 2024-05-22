#include <bits/stdc++.h>
using namespace std;

int main()
{

    unsigned int n;
    cin >> n;
    int firstSetBitLeft = 31 - __builtin_clz(n);
    int mask = (1 << (firstSetBitLeft + 1)) - 1;
    cout << (n ^ mask);

    return 0;
}