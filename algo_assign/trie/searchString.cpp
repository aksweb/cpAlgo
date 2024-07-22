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
    while (n--)
    {
        int q;
        string s;
        cin >> q >> s;
        if (q == 1)
        {
            insert(t, s);
        }
        else if (q == 2)
        {
            int result = check(t, s);
            cout << (result > 0 ? 1 : 0) br;
        }
        else if (q == 3)
        {
            bool foundPrefix = true;
            int curr = 0;
            for (char c : s)
            {
                int idx = c - 'a';
                if (t.v[curr][idx] == -1)
                {
                    foundPrefix = false;
                    break;
                }
                curr = t.v[curr][idx];
            }
            cout << (foundPrefix ? 1 : 0)br;
        }
    }
    return 0;
}
