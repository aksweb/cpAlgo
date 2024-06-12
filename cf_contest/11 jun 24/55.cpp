#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        long long k;
        cin >> x >> y >> z >> k;

        long long max_positions = 0;

        for (int a = 1; a <= x && (long long)a * a * a <= k; ++a)
        {
            if (k % a != 0)
                continue;
            for (int b = 1; b <= y && (long long)a * b * b <= k; ++b)
            {
                if ((k / a) % b != 0)
                    continue;
                int c = k / (a * b);
                if (c > z)
                    continue;
                if ((long long)a * b * c == k)
                {
                    vector<int> dims = {a, b, c};
                    sort(dims.begin(), dims.end());

                    do
                    {
                        if (dims[0] <= x && dims[1] <= y && dims[2] <= z)
                        {
                            long long positions = (x - dims[0] + 1) * (y - dims[1] + 1) * (z - dims[2] + 1);
                            max_positions = max(max_positions, positions);
                        }
                    } while (next_permutation(dims.begin(), dims.end()));
                }
            }
        }

        cout << max_positions << '\n';
    }

    return 0;
}
