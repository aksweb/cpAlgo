#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);

    rep(i, 0, n) cin >> arr[i];

    k = k % n; // cases where k >= n
    rep(i, 0, n)
    {
        cout << arr[(i + k) % n] << " ";
    }
    cout br;

    return 0;
}
