#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to validate if a given mid-point satisfies the condition
bool isValid(vector<ll> &penalties, ll mid)
{
    ll n = penalties.size();
    set<vector<ll>> uniqueConfigs;

    for (ll i = 0; i < n; ++i)
    {
        ll current = penalties[i];
        vector<ll> adjusted;

        for (ll j = 0; j < n; ++j)
        {
            if (penalties[j] != current)
            {
                adjusted.push_back((penalties[j] > current) ? penalties[j] - 1 : penalties[j]);
            }
        }
        uniqueConfigs.insert(adjusted);
    }

    return uniqueConfigs.size() >= mid;
}

void calculatePenalties()
{
    ll testCases;
    cin >> testCases;

    while (testCases--)
    {
        ll numBooks;
        cin >> numBooks;

        vector<ll> returnDays(numBooks);
        for (ll i = 0; i < numBooks; ++i)
        {
            cin >> returnDays[i];
        }

        vector<ll> sortedDays(returnDays.begin(), returnDays.end());
        sort(sortedDays.begin(), sortedDays.end());

        unordered_map<ll, ll> dayRanking;
        ll rank = numBooks;

        for (ll i = 0; i < numBooks; ++i)
        {
            dayRanking[sortedDays[i]] = rank--;
        }

        for (ll i = 0; i < numBooks; ++i)
        {
            returnDays[i] = dayRanking[returnDays[i]];
        }

        ll low = 1, high = numBooks, maxPenalty = 1;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (isValid(returnDays, mid))
            {
                maxPenalty = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << maxPenalty << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    calculatePenalties();

    return 0;
}
