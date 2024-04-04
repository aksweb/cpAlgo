
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int _;
    cin >> _;
    while (_--)
    {

        ll n, k, x;
        cin >> n >> k >> x;

        if(k>1)
        if (x >= (ll)pow(2, k - 1))
        {
            // cout << a[k - 1] br;
            cout << "Yes" br;
        }
        else
            cout << "No" br;
    }
    return 0;
}