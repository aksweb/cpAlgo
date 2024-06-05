#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Monster
{
    int position;
    int health;
};

// Function to check if Chef can win given a specific bomb position
bool canChefWin(int K, vector<Monster> &monsters)
{
    sort(monsters.begin(), monsters.end(), [](const Monster &a, const Monster &b)
         { return a.position < b.position; });

    int time = 0;
    for (auto &monster : monsters)
    {
        int distance = monster.position - time;
        if (distance <= 0)
        {
            return false; // Monster reaches Chef
        }
        time += monster.health; // Spend health seconds to kill the monster
    }
    return true; // All monsters are killed before reaching Chef
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
        vector<Monster> monsters(N);
        for (int i = 0; i < N; i++)
        {
            cin >> positions[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> healths[i];
        }

        for (int i = 0; i < N; i++)
        {
            monsters[i] = {positions[i], healths[i]};
        }

        bool result = false;
        // Try placing the bomb at each monster's position
        for (int i = 0; i < N; i++)
        {
            int bombPosition = positions[i];
            vector<Monster> remainingMonsters;
            for (auto &monster : monsters)
            {
                if (monster.position < bombPosition - K || monster.position > bombPosition + K)
                {
                    remainingMonsters.push_back(monster);
                }
            }
            if (canChefWin(K, remainingMonsters))
            {
                result = true;
                break;
            }
        }

        if (result)
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
