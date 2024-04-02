
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _;
    cin >> _;
    while (_--)
    {
        ll a, b;
        cin >> a >> b;
        ll sc = a - b;
        if (sc >= 10)
        {
            cout << 0 br;
        }
        else
        {
            long double rq = 10 - sc;
            cout << ceil(rq / 3) br;
            // cout << ceil((10 - sc) / 3) br;
        }
    }
}