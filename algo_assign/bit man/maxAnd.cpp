// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// isse achha approach nhi melega.
// question r k l
// cnts
// tcs

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    vector<ll> temp;
    for (ll i = 31; i >= 0; i--)
    {
        if (temp.size() < 2)
        {
            temp.clear();
            for (auto x : a)
            {
                if (x & (1LL << i))
                {
                    temp.pb(x);
                }
            }
        }
        else
        {
            ans = (1LL << i + 1);
            // cout << "ans: " << ans br;
            for (ll j = i; j >= 0; j--)
            {
                vector<ll> t2;

                for (auto x : temp)
                {
                    if (x & (1LL << j))
                    {
                        t2.pb(x);
                    }
                    // else
                    // {
                    //     temp.erase(remove(temp.begin(), temp.end(), x), temp.end());
                    // }
                }

                if (t2.size() >= 2)
                {
                    temp.clear();
                    for(auto x: t2)temp.pb(x);
                    // cout << "modifi";
                    ans = ans | (1LL << j);
                }
            }

            break;
        }
    }
    cout << ans br;

    return 0;
}