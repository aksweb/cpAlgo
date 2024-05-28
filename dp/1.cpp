#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int N;
    string P, Q;

    // Input reading
    cin >> N;
    cin >> P;
    cin >> Q;

    // Frequency map for characters in P
    map<char, int> freqMap;
    for (char c : P)
    {
        freqMap[c]++;
    }

    string result(N, '');

    for (int i = 0; i < N; i++)
    {
        bool found = false;
        // Try to find the smallest lexicographical character from the frequency map
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            if (it->second > 0 && it->first != Q[i])
            {
                result[i] = it->first;
                it->second--;
                found = true;
                break;
            }
        }
        // If no valid character is found, we should handle this case
        // if (!found) {
        //     cout << "No valid string can be formed." << endl;
        //     return 0;
        // }
    }

    cout << result << endl;
    return 0;
}
