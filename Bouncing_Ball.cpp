// TSETEN
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> forward(n, 0);
        vector<int> backward(n, 0);
        forward[0] = arr[0];
        backward[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            forward[i] = forward[i - 1] + arr[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            backward[i] = backward[i + 1] + arr[i];
        }
        ll res = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {

                if (abs(forward[i] - backward[i]) == 1)
                    res++;
                if (abs(forward[i] - backward[i]) == 0)
                    res += 2;
            }
        }
        cout << res << "\n";
    }

    return 0;
}