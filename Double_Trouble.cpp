#include <iostream>
#include <vector>
using namespace std;

bool canActivateAllBalls(int N, vector<int> &X, vector<int> &P)
{
    if (N == 2)
    {
        return true;
    }

    // Check if activating from the leftmost ball covers all balls
    int pos = X[0];
    int power = P[0];
    for (int i = 1; i < N; ++i)
    {
        if (pos + power >= X[i])
        {
            pos = X[i];
            power = max(power, P[i] - (X[i] - pos));
        }
        else
        {
            break;
        }
        if (i == N - 1)
        {
            return true;
        }
    }

    // Check if activating from the rightmost ball covers all balls
    pos = X[N - 1];
    power = P[N - 1];
    for (int i = N - 2; i >= 0; --i)
    {
        if (pos - power <= X[i])
        {
            pos = X[i];
            power = max(power, P[i] - (pos - X[i]));
        }
        else
        {
            break;
        }
        if (i == 0)
        {
            return true;
        }
    }

    // Check if two moves can cover all balls
    // Activate leftmost ball
    pos = X[0];
    power = P[0];
    int firstUncovered = -1;
    for (int i = 1; i < N; ++i)
    {
        if (pos + power >= X[i])
        {
            pos = X[i];
            power = max(power, P[i] - (X[i] - pos));
        }
        else
        {
            firstUncovered = i;
            break;
        }
    }

    // Activate rightmost ball
    pos = X[N - 1];
    power = P[N - 1];
    int lastUncovered = -1;
    for (int i = N - 2; i >= 0; --i)
    {
        if (pos - power <= X[i])
        {
            pos = X[i];
            power = max(power, P[i] - (pos - X[i]));
        }
        else
        {
            lastUncovered = i;
            break;
        }
    }

    if (firstUncovered != -1 && lastUncovered != -1 && firstUncovered <= lastUncovered)
    {
        return true;
    }

    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> X(N), P(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> X[i];
        }
        for (int i = 0; i < N; ++i)
        {
            cin >> P[i];
        }
        if (canActivateAllBalls(N, X, P))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
