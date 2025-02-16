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
#define rloop(i, a, b) for (ll i = a; i > b; i--)
#define trav(a, b) for (auto a : b)
#define MOD2 629421302
#define INF 1000000000000000000

// Ye kab tk likhoge
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// jo cheating kiya, uski ma r****

void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> coord(n);
        ll lmp = 1e9, rmp = 0, tmp = 1e9, bmp = 0;
        rep(i, n)
        {
            cin >> coord[i].first >> coord[i].second;
            lmp = min(lmp, coord[i].first);
            tmp = min(tmp, coord[i].second);
            rmp = max(rmp, coord[i].first);
            bmp = max(bmp, coord[i].second);
        }

        if (n == 1)
        {
            cout << 0 << endl; // Only one well, no time needed
            continue;
        }

        ll rows = bmp - tmp + 1; // Number of rows
        ll cols = rmp - lmp + 1; // Number of columns

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<ll, ll>> q;

        for (auto &it : coord)
        {
            ll adjustedX = it.first - lmp;
            ll adjustedY = it.second - tmp;
            visited[adjustedY][adjustedX] = true;
            q.push({adjustedY, adjustedX});
        }

        vector<pair<ll, ll>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        ll time = 0;

        while (!q.empty())
        {
            ll sz = q.size();
            bool anyAdded = false;

            rep(i, sz)
            {
                auto curr = q.front();
                ll currY = curr.first;
                ll currX = curr.second;
                q.pop();

                for (const auto &dir : directions)
                {
                    ll newY = currY + dir.first;
                    ll newX = currX + dir.second;

                    if (newY >= 0 && newY < rows && newX >= 0 && newX < cols && !visited[newY][newX])
                    {
                        visited[newY][newX] = true;
                        q.push({newY, newX});
                        anyAdded = true;
                    }
                }
            }

            if (anyAdded)
                time++; // Increment only if new nodes are added
        }

        cout << time << endl; // Output the minimum time
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
