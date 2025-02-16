#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n); 
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll ans = 0;

        // Iterate through the array to find subarrays
        for (int i = 0; i < n;)
        {
            // If the current element is already equal to k, skip it
            if (a[i] == k)
            {
                i++;
                continue;
            }

            // Try to apply GCD operation if GCD(A[i], K) == K
            if (__gcd(a[i], k) == k)
            {
                // cout << "id: " << i << " ";
                i++;
                // Process the subarray where the GCD operation applies
                while (i < n && __gcd(a[i], k) == k)
                {
                    i++;
                }
                // cout << "end: " << i << " ";

                ans++; // One GCD operation for this subarray
            }
            else
            {
                // Try to apply XOR operation if XOR(A[i], K) == K
                // cout << "id2: " << i << " ";
                ll val = a[i];
                i++;
                while (i < n && ((a[i] == val)))
                {
                    i++;
                }

                ans++; 
            }
        }

        cout << ans << endl;
    }

    return 0;
}
