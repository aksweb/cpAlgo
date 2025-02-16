#include <iostream>
#include <vector>
using namespace std;

int computeBeauty(const string &s)
{
    int n = s.size();
    int score = 0;
    int prefixSum = 0;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] != s[i - 1])
        {
            prefixSum++; // Increase the count of distinct adjacent pairs
        }
        score += prefixSum; // Accumulate the total score
    }

    return score;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << computeBeauty(s) << endl;
    }
    return 0;
}
