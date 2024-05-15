// TESTEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    ll a[n], b[m];
    set<ll> st;
    rep(i, 0, n)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    rep(i, 0, m)
    {
        cin >> b[i];
        st.insert(b[i]);
    }

    for (auto x : st)
        cout << x << " ";

    return 0;
}
