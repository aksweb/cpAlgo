// Modified RGIPT Code
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Utility function to calculate GCD
ll calculateGCD(ll a, ll b)
{
    return (b == 0) ? a : calculateGCD(b, a % b);
}

// Utility function to calculate LCM
ll calculateLCM(ll a, ll b)
{
    return a * (b / calculateGCD(a, b));
}

// given n;
// construct an array such that : Place odd numbers in ascending order at the start of the permutation.Place even numbers in descending order next.This arrangement ensures that the subarray sums are distributed in such a way that they avoid divisibility by N + 1.

void processTestCases()
{
    ll testCases;
    cin >> testCases;

    while (testCases--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        ll a[n];
        rep(i, n) cin >> a[i];
        ll t_xor = a[0];
        for (ll i = 1; i < n; i++)
            t_xor ^= a[i];
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll temp = t_xor ^ a[i];
            ans ^= (ll)pow(temp, n - 1);
        }
        if (ans >= l && ans <= r)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    processTestCases();

    return 0;
}
