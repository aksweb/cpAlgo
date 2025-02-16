#include <bits/stdc++.h>
using namespace std;

// Function to check if two 3x3 matrices are equal
bool areEqual(vector<vector<int>> &a, vector<vector<int>> &b)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

// Function to check if two 3x3 matrices differ by at most one bit
bool isOneBitToggle(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int diffCount = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != b[i][j])
                diffCount++;
        }
    }
    return diffCount <= 1;
}

// Function to find the digit corresponding to a 3x3 matrix
int findDigit(vector<vector<int>> &digitMatrix, vector<vector<vector<int>>> &repr)
{
    for (int d = 0; d < 10; d++)
    {
        if (areEqual(digitMatrix, repr[d]) || isOneBitToggle(digitMatrix, repr[d]))
        {
            return d;
        }
    }
    return -1; // Invalid
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input the representation of digits 0-9
    vector<vector<vector<int>>> repr(10, vector<vector<int>>(3, vector<int>(3)));
    for (int i = 0; i < 3; i++)
    {
        string line;
        getline(cin, line);
        for (int d = 0; d < 10; d++)
        {
            for (int j = 0; j < 3; j++)
            {
                repr[d][i][j] = line[d * 3 + j] - '0';
            }
        }
    }

    // Input the faulty number representation
    vector<string> numInput(3);
    for (int i = 0; i < 3; i++)
    {
        getline(cin, numInput[i]);
    }

    int numDigits = numInput[0].size() / 3;
    vector<vector<vector<int>>> num(numDigits, vector<vector<int>>(3, vector<int>(3)));
    for (int digit = 0; digit < numDigits; digit++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                num[digit][i][j] = numInput[i][digit * 3 + j] - '0';
            }
        }
    }

    // Process each digit and calculate the sum of valid numbers
    long long ans = 0;
    bool invalid = false;
    vector<int> currentNumber;

    function<void(int)> backtrack = [&](int idx)
    {
        if (idx == numDigits)
        {
            long long number = 0;
            for (int d : currentNumber)
            {
                number = number * 10 + d;
            }
            ans += number;
            return;
        }

        int originalDigit = findDigit(num[idx], repr);
        if (originalDigit != -1)
        {
            currentNumber.push_back(originalDigit);
            backtrack(idx + 1);
            currentNumber.pop_back();
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                num[idx][i][j] ^= 1; // Toggle a bit
                int toggledDigit = findDigit(num[idx], repr);
                if (toggledDigit != -1)
                {
                    currentNumber.push_back(toggledDigit);
                    backtrack(idx + 1);
                    currentNumber.pop_back();
                }
                num[idx][i][j] ^= 1; // Revert the toggle
            }
        }
    };

    backtrack(0);

    // Check if there was any invalid digit
    for (int i = 0; i < numDigits; i++)
    {
        if (findDigit(num[i], repr) == -1)
        {
            invalid = true;
            break;
        }
    }

    if (invalid)
    {
        cout << "Invalid\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}

// // Output the sizes and contents of repr
// for (int i = 0; i < 3; i++)
// {
//     cout << "Size of repr[" << i << "]: " << repr[i].size() << "\nContents: ";
//     for (int v : repr[i])
//     {
//         cout << v;
//     }
//     cout << "\n";
// }

// // Output the sizes and contents of num
// for (int i = 0; i < 3; i++)
// {
//     cout << "Size of num[" << i << "]: " << num[i].size() << "\nContents: ";
//     for (int v : num[i])
//     {
//         cout << v;
//     }
//     cout << "\n";
// }