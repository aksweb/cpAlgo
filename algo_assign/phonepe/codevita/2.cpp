#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool areSidesMatching(vector<ll> &a, vector<ll> &b)
{
    if (a.size() != b.size())
        return false;
    ll k = a.size();
    for (ll offset = 0; offset < k; offset++)
    {
        bool matched = true;
        for (ll i = 0; i < k; i++)
        {
            if (a[i] != b[(i + offset) % k])
            {
                matched = false;
                break;
            }
        }
        if (matched)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<vector<ll>> sides(n);

    for (ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        vector<pair<ll, ll>> vertices(k);

        for (ll j = 0; j < k; j++)
        {
            ll a, b;
            cin >> a >> b;
            vertices[j] = {a, b};
        }

        for (ll j = 0; j < k; j++)
        {
            ll next = (j + 1) % k;
            ll dx = vertices[next].first - vertices[j].first;
            ll dy = vertices[next].second - vertices[j].second;
            sides[i].push_back(sqrt(dx * dx + dy * dy));
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            if (areSidesMatching(sides[i], sides[j]))
            {
                cout << i + 1 << " " << j + 1 << endl;
                return 0; 
            }
        }
    }
    
    return 0;
}
