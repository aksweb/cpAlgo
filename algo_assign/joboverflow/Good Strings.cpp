#include <bits/stdc++.h>
using namespace std;

int pred(int mid, string str, vector<int> &perm, vector<vector<int>> &queries)
{
    int size = str.length();

    vector<vector<int>> freq(26, vector<int>(size + 1, 0));

    for (int i = mid; i < perm.size(); i++)
    {
        int charIndex = int(str[perm[i] - 1] - 'a');

        freq[charIndex][perm[i]]++;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            freq[i][j] += freq[i][j - 1];
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];

        for (int j = 0; j < 26; j++)
        {
            if (freq[j][r] - freq[j][l - 1] > 1)
            {
                return 0;
            }
        }
    }

    return 1;
}

int BinarySearch(string str, vector<int> &perm, vector<vector<int>> &queries)
{
    int l = -1, r = perm.size();

    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;

        if (pred(mid, str, perm, queries) == 0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    return l + 1;
}

int main()
{

    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        cin >> perm[i];
    }

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    int ans = BinarySearch(str, perm, queries);

    cout << ans;

    return 0;
}