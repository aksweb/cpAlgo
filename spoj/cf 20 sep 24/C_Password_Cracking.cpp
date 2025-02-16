#include <iostream>
#include <string>
using namespace std;

// Function to query Mansur's system
int query(const string &t)
{
    cout << "? " << t << endl; // Make the query
    cout.flush();              // Flush the output buffer
    int response;
    cin >> response; // Read Mansur's response (1 or 0)
    return response;
}

void solve()
{
    int n;
    cin >> n; // Read the length of the password

    string password = ""; // Initialize the password as an empty string

    // For each bit position, query both '0' and '1' and decide the correct bit
    for (int i = 0; i < n; i++)
    {
        string query_with_0 = password + '0';
        string query_with_1 = password + '1';

        // First query with '0' appended
        int response_with_0 = query(query_with_0);

        // Then query with '1' appended
        int response_with_1 = query(query_with_1);

        // Based on the response, append the correct bit to the password
        if (response_with_1 == 1)
        {
            password += '1'; // If '1' is a valid substring, append '1'
        }
        else
        {
            password += '0'; // Otherwise, '0' is valid, so append '0'
        }
    }

    // Output the final password once we have guessed all bits
    cout << "! " << password << endl;
    cout.flush(); // Make sure to flush the output buffer after the final answer
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        solve(); // Solve each test case
    }
    return 0;
}
