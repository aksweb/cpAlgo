#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
const ll MOD = 1e9 + 7;

struct Trie
{
    vector<vector<int>> v;
    vector<int> hotnode;
    int curr;

    Trie() : v(1000000, vector<int>(26, -1)), hotnode(1000000, 0), curr(0) {}
};

void insert(Trie &t, const string &s)
{
    int len = s.size();
    int curr = 0;
    for (int i = 0; i < len; i++)
    {
        int idx = s[i] - 'a';
        if (t.v[curr][idx] == -1)
        {
            t.v[curr][idx] = ++t.curr;
        }
        curr = t.v[curr][idx];
    }
    t.hotnode[curr]++;
}

int check(Trie &t, const string &s)
{
    int len = s.size();
    int curr = 0;
    for (int i = 0; i < len; i++)
    {
        int idx = s[i] - 'a';
        if (t.v[curr][idx] == -1)
            return -1;
        curr = t.v[curr][idx];
    }
    return t.hotnode[curr];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Trie t;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        insert(t, s[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str = s[i];
        reverse(str.begin(), str.end());
        int val = check(t, str);
        if (val != -1)
            ans += val;
    }
    cout << ans br;
    return 0;
}
