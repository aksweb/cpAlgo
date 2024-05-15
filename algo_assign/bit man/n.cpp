#include <iostream>
#include <string>

#define ll long long int

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if (n <= 1)
        {
            cout << n << endl;
            continue;
        }

        int count = 0;
        char prevChar = '\0';
        int consecutiveCount = 0;

        for (char c : s)
        {
            if (c == prevChar)
            {
                consecutiveCount++;
                if (consecutiveCount % 2 == 0)
                {
                    count++;
                }
            }
            else
            {
                consecutiveCount = 1;
            }
            prevChar = c;
        }

        cout << n - count << endl;
    }

    return 0;
}
