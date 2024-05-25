#include <iostream>
#include <vector>
#include <climits>
#define ll long long int

using namespace std;

bool is_beautiful(const vector<ll> &a)
{
    ll n = a.size();

    if (n < 2)
        return false; // This case is guaranteed by constraints but kept for logical completeness

    // Find the two smallest distinct elements
    ll min1 = INT_MAX, min2 = INT_MAX;

    for (ll num : a)
    {
        if (num < min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if (num != min1 && num < min2)
        {
            min2 = num;
        }
    }

    // If there's only one unique element in the array, it's beautiful
    if (min2 == INT_MAX)
    {
        return true;
    }

    // Check if all elements are divisible by either min1 or min2
    for (ll num : a)
    {
        if (num % min1 != 0 && num % min2 != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        if (is_beautiful(a))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
