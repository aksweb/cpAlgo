#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Monster
{
    int position;
    int health;
};

bool canChefWin(int N, int K, vector<int> &positions, vector<int> &healths)
{
    vector<Monster> monsters(N);
    for (int i = 0; i < N; i++)
    {
        monsters[i] = {positions[i], healths[i]};
    }

    // Try placing the bomb at every possible position
    for (int x = positions[0] - K; x <= positions[N - 1] + K; x++)
    {
        vector<Monster> remainingMonsters;
        for (auto &monster : monsters)
        {
            if (monster.position < x - K || monster.position > x + K)
            {
                remainingMonsters.push_back(monster);
            }
        }

        // Sort the remaining monsters by position
        sort(remainingMonsters.begin(), remainingMonsters.end(), [](const Monster &a, const Monster &b)
             { return a.position < b.position; });

        // Use a priority queue to handle the monsters by their closest position to 0
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &monster : remainingMonsters)
        {
            pq.push({monster.position, monster.health});
        }

        int time = 0;
        bool chefWins = true;
        while (!pq.empty())
        {
            auto current = pq.top();
            pq.pop();
            int pos = current.first - time;
            int health = current.second;
            if (pos <= 0)
            {
                chefWins = false;
                break;
            }
            if (--health > 0)
            {
                pq.push({current.first, health});
            }
            time++;
        }

        if (chefWins)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> positions(N);
        vector<int> healths(N);
        for (int i = 0; i < N; i++)
        {
            cin >> positions[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> healths[i];
        }

        if (canChefWin(N, K, positions, healths))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}