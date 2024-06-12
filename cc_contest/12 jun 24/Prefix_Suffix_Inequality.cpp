#include <iostream>
#include <vector>
using namespace std;

// Function to generate the array as per the given logic
vector<int> generate_array(int N)
{
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i += 2)
    {
        arr[i] = 7;
        if (i + 1 < N)
        {
            arr[i + 1] = 5;
        }
    }
    return arr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        // Generate the array and print it
        vector<int> result = generate_array(N);
        for (int i = 0; i < N; ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
