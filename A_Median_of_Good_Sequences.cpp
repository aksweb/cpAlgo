#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binomialCoeff(int n, int r)
{
    if (r > n)
        return 0;
    ll res = 1;
    for (int i = 1; i <= r; ++i)
    {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<int> cnt(n + 1, k);
    vector<int> result;

    ll m = (binomialCoeff(n * k, k) + 1) / 2;

    for (int i = 0; i < n * k; i++)
    {
        for (int j = n; j >= 1; j--)
        { // Reverse the loop to prioritize larger numbers first
            if (cnt[j] > 0)
            {
                cnt[j]--;
                ll count = 1;

                int remaining = n * k - (i + 1);
                for (int l = 1; l <= n; l++)
                {
                    count *= binomialCoeff(remaining, cnt[l]);
                    remaining -= cnt[l];
                }

                if (m <= count)
                {
                    result.push_back(j);
                    break;
                }
                else
                {
                    m -= count;
                    cnt[j]++;
                }
            }
        }
    }

    for (ll x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
