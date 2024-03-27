#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int pred(ll m, const vector<pair<ll, ll>> &islands, ll n)
{
    ll nop = 0;
    ll prev = -1e18;
    for (auto it : islands)
    {
        ll st = max(it.first, prev + m);
        while (st <= it.second)
        {
            nop++;
            prev = st;
            st += m;
            if (nop >= n)
                return 1;
        }
    }
    return 0;
}

ll findMaxMinDistance(const vector<pair<ll, ll>> &islands, ll N)
{
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> islands(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> islands[i].first >> islands[i].second;
    }

    ll l = -1, r = 1e18;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (pred(m, islands, N))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l;

    return 0;
}
