#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool helper(ll n, ll mid)
{
    ll sum = (n * (n + 1)) / 2;
    if (sum % mid != 0)
    {
        return false;
    }

    ll targetSum = sum / mid;
    ll currentSum = 0;
    ll count = 0;

    for (ll i = 1; i <= n; ++i)
    {
        currentSum += i;
        if (currentSum == targetSum)
        {
            currentSum = 0;
            count++;
        }
        else if (currentSum > targetSum)
        {
            return false;
        }
    }

    return count == mid;
}

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        ll n;
        cin >> n;
        ll l = 1, h = (n * (n + 1)) / 2;
        while (l <= h)
        {
            ll mid = l + (h - l) / 2;
            if (helper(n, mid))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        cout << h << endl;
    }

    return 0;
}
