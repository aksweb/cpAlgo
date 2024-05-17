#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    if (k >= n)
    {
        unordered_set<int> unique_elements(a.begin(), a.end());
        cout << unique_elements.size() << endl;
        return 0;
    }
    unordered_map<int, int> temp;
    rep(i, 0, k)
    {
        temp[a[i]]++;
    }
    int ind = 0;
    cout << temp.size() << " ";
    rep(i, k, n)
    {
        temp[a[ind]]--;
        if (temp[a[ind]] == 0)
            temp.erase(a[ind]);
        temp[a[i]]++;
        cout << temp.size() << " ";
        ind++;
    }

    return 0;
}
