#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

ll sumOfMaxMinDifferences(vector<int> &arr)
{
    int n = arr.size();
    vector<int> leftMax(n), rightMax(n), leftMin(n), rightMin(n);
    stack<int> s;

    // Calculate leftMax and rightMax
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
            s.pop();
        leftMax[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        rightMax[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Calculate leftMin and rightMin
    while (!s.empty())
        s.pop();
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
            s.pop();
        leftMin[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        rightMin[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ll maxContribution = (ll)(i - leftMax[i]) * (rightMax[i] - i);
        ll minContribution = (ll)(i - leftMin[i]) * (rightMin[i] - i);
        sum += arr[i] * (maxContribution - minContribution);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    cout << sumOfMaxMinDifferences(arr) br;

    return 0;
}
