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
    vector<int> w(n);
    rep(i, 0, n)
    {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 1; i < n; i += 2)
    {
        pq.push({abs(w[i] - w[i - 1]), {i - 1, i}});
    }
    while (!pq.empty())
    {
        auto x = pq.top();
        cout << x.first << " " << x.second.first << " " << x.second.second << " ";
        pq.pop();
    }

    // auto topp = pq.top();
    // int ind1 = topp.second.second;
    // pq.pop();
    // topp = pq.top();
    // int ind2 = topp.second.first;

    // w.erase(w.begin() + ind1);
    // w.erase(w.begin() + ind2);
    // ll ans = 0;

    // for(auto x: w)cout<<x<<" ";
    // for (int i = 1; i < n; i += 2)
    // {
    //     ans += (w[i] - w[i - 1]);
    // }

    // cout << ans br;
    return 0;
}
