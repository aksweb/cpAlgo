#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        int flip_count = 0;
        bool has_zero = false;

        // Check if the string contains '0'
        for (int i = 0; i < N; ++i)
        {
            if (S[i] == '0')
            {
                has_zero = true;
                break;
            }
        }

        // Count transitions from '01'
        for (int i = 0; i < N - 1; ++i)
        {
            if (S[i] == '0' && S[i + 1] == '1')
            {
                ++flip_count;
            }
        }

        // If the string starts with a '0' and has '1' afterward, increase the flip count
        if (has_zero)
        {
            ++flip_count;
        }

        cout << flip_count << endl;
    }

    return 0;
}
