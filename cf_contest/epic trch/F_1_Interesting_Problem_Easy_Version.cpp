#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int count = 0;
        for (int i = 0; i < a.size() - 1;)
        {
            if (a[i] == i + 1)
            {
                count++;
                a.erase(a.begin() + i, a.begin() + i + 2);
                if (i > 0)
                {
                    i--; // Move back one position to check for new possible operation after removal
                }
            }
            else
            {
                i++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
