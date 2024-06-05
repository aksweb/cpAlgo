#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long totalSubarrays = (long long)n * (n + 1) / 2;

    long long onsb = 0;
    long long csegLen = 0;
    long long msSeg = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
        {
            csegLen++;
        }
        else
        {
            onsb += (csegLen * (csegLen + 1)) / 2;
            if (csegLen > msSeg)
            {
                msSeg = csegLen;
            }
            csegLen = 0;
        }
    }

    if (csegLen > 0)
    {
        onsb += (csegLen * (csegLen + 1)) / 2;
        if (csegLen > msSeg)
        {
            msSeg = csegLen;
        }
    }

    if (msSeg > 0)
    {
        onsb -= (msSeg * (msSeg + 1)) / 2;
        msSeg--;
        onsb += (msSeg * (msSeg + 1)) / 2;
    }

    int oc = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            oc++;
    }
    if (oc == n)
    {
        if (n % 2 == 0)
        {
            cout << n + (n / 2) * ((n / 2) - 1);
        }
        else
        {
            cout << n + (n / 2) * (n / 2);
        }
    }
    else
    {
        // Subarrays containing at least one 0
        long long result = totalSubarrays - onsb;
        cout << result << endl;
    }
    // cout << zc(a) << endl;

    return 0;
}
