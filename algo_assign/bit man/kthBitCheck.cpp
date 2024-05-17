// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll MOD = 1e9 + 7;

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    int k;
    cin >> n >> k;
    cout << ((n & (1LL << k)) ? 1 : 0);
    return 0;
}