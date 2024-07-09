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
        vector<int> cakes(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> cakes[i];
        }

        // Sort the cakes in descending order
        sort(cakes.rbegin(), cakes.rend());

        int aliceCakes = 0;
        int aliceMaxTastiness = 0;

        for (int i = 0; i < n; ++i)
        {
            // Alice's turn: check if the cake can be eaten by Alice
            if (cakes[i] > aliceMaxTastiness)
            {
                aliceMaxTastiness = cakes[i];
                aliceCakes++;
            }
            // Bob's turn follows, simply continue to next cake
        }

        cout << aliceCakes << endl;
    }
    return 0;
}
