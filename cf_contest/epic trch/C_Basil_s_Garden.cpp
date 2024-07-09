#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        // Find the maximum height in the array
        int max_height = *max_element(h.begin(), h.end());

        // The number of seconds needed for all flowers to reach height 0
        cout << max_height << endl;
    }
    return 0;
}
