// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int pred(ll m, ll h)
{

    if (m > h)
        return 0;
    else
        return 1;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        vector<int> candidates;

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < N; i++)
        {
            if ((arr[i] & K) == K)
            {
                candidates.push_back(i + 1);
            }
        }

        int subset_and = -1;
        for (int idx : candidates)
        {
            if (subset_and == -1)
            {
                subset_and = arr[idx - 1];
            }
            else
            {
                subset_and &= arr[idx - 1];
            }
        }

        if (subset_and == K && !candidates.empty())
        {
            cout << "YES\n";
            cout << candidates.size() << "\n";
            for (int idx : candidates)
            {
                cout << idx << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
