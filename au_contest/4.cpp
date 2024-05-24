#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vector<int> ht(m, -1);
    rep(i, 0, n)
    {
        int ind = a[i] % m;
        int temp = ind;
        while (ht[ind] != -1 && ht[ind] != a[i])
        {
            ind = (ind + 1) % m;
            if (ind == temp)
                break;
        }
        if (ht[ind] == -1)
            ht[ind] = a[i];
    }

    rep(i, 0, m)
    {
        if (ht[i] != -1)
            cout << ht[i] << " ";
        else
            cout << "-1 ";
    }
    cout br;

    return 0;
}
