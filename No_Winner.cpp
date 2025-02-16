// TSETEN
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define INF 1000000000000000000

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        int no1, n2, n3, match;
        cin >> no1 >> n2 >> n3 >> match;
        if (no1 == n2 || n2 == n3 || n3 == no1)
        {
            cout << "YES\n";
        }
        else
        {
            if (abs(no1 - n2) <= match || abs(n2 - n3) <= match || abs(n3 - no1) <= match)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}