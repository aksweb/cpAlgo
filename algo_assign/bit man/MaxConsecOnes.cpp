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

int longestConsecutiveOnes(int num)
{
    int max_ones = 0; //

    string binary = bitset<32>(num).to_string(); // Convert integer to binary string
    int count = 0;                               // Counter for consecutive 1s
    int max_count = 0;

    for (char digit : binary)
    {
        if (digit == '1')
        {
            count++;
            max_count = max(max_count, count);
        }
        else
        {
            count = 0; // Reset count if digit is not 1
        }
    }

    max_ones = max(max_ones, max_count);
    // cout << binary << "\n";

    return max_ones;
}

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        int ans = longestConsecutiveOnes(a[i]);
        cout << ans br;
    }

    return 0;
}
