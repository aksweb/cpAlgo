// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define br << endl
int main()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> vec(n);
    for (int &x : vec)
        cin >> x;
    sort(vec.begin(), vec.end());
    int ans = 1e9;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            vector<int> tmp;
            for (int k = 0; k < n; ++k)
            {
                if (k != i and k != j)
                {
                    tmp.push_back(vec[k]);
                }
            }
            int tmp_ans = 0;
            for (int k = 1; k < tmp.size(); k += 2)
            {
                tmp_ans += tmp[k] - tmp[k - 1];
            }
            ans = min(ans, tmp_ans);
        }
    }
    cout << ans << endl;
    return 0;
}