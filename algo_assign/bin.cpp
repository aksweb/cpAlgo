#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        unordered_map<ll, ll> maxPenalty;

        for (ll i = 0; i < n; i++)
        {
            ll day;
            cin >> day;

            maxPenalty[day] = max(maxPenalty[day], i + 1);
        }

        ll totalPenalty = 0;
        for (auto &entry : maxPenalty)
        {
            totalPenalty += entry.second;
        }

        cout << totalPenalty << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
