#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

#define ll long long int

// Function to find the minimum number of operations needed to go from A to B
ll minOperations(ll A, ll B, ll K)
{
    if (A >= B)
        return 0; // No operations needed if already at or beyond B

    queue<pair<ll, ll>> q;     // pair<current_value, current_operations_count>
    unordered_set<ll> visited; // To keep track of visited states to avoid cycles
    q.push(make_pair(A, 0));
    visited.insert(A);

    while (!q.empty())
    {
        ll current = q.front().first;
        ll operations = q.front().second;
        q.pop();

        if (current == B)
        {
            return operations;
        }

        // Option 1: Increment current by 1
        if (current + 1 == B)
        {
            return operations + 1;
        }
        if (current + 1 < B && visited.find(current + 1) == visited.end())
        {
            q.push(make_pair(current + 1, operations + 1));
            visited.insert(current + 1);
        }

        // Option 2: Multiply current by K
        if (current * K == B)
        {
            return operations + 1;
        }
        if (current * K < B && visited.find(current * K) == visited.end())
        {
            q.push(make_pair(current * K, operations + 1));
            visited.insert(current * K);
        }
    }

    // If we exit the loop, it means we could not find a path from A to B, which should not happen
    return -1;
}

int main()
{
    int T;
    cin >> T;
    vector<ll> results(T);

    for (int i = 0; i < T; ++i)
    {
        ll A, B, K;
        cin >> A >> B >> K;
        results[i] = minOperations(A, B, K);
    }

    for (const auto &result : results)
    {
        cout << result << endl;
    }

    return 0;
}
