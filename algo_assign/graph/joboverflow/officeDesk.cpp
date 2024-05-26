#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for (int i = m; i < n; i++)

// Function to calculate the maximum distance from any cell to the nearest office
int maxDistWithOffices(vector<pair<int, int>> &offices, int w, int h)
{
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;

    for (auto &office : offices)
    {
        q.push(office);
        dist[office.second][office.first] = 0;
    }

    vector<pair<int, int>> drxn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty())
    {
        auto data = q.front();
        q.pop();
        int i = data.first;
        int j = data.second;
        for (auto &d : drxn)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (ni >= 0 && ni < w && nj >= 0 && nj < h && dist[nj][ni] == -1)
            {
                dist[nj][ni] = dist[j][i] + 1;
                q.push({ni, nj});
            }
        }
    }

    int max_dist = 0;
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            max_dist = max(max_dist, dist[i][j]);
        }
    }
    return max_dist;
}

int main()
{
    int w, h, n;
    cin >> w >> h >> n;

    vector<pair<int, int>> cells;
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            cells.push_back({j, i});
        }
    }

    int min_max_dist = INT_MAX;

    // Generate all combinations of n cells out of the grid cells
    vector<int> combination(w * h, 0);
    fill(combination.begin(), combination.begin() + n, 1); // Fill first n elements with 1

    // Use prev_permutation to generate all combinations of placing n offices
    do
    {
        vector<pair<int, int>> offices;
        for (int i = 0; i < w * h; ++i)
        {
            if (combination[i] == 1)
            {
                offices.push_back(cells[i]);
            }
        }
        int max_dist = maxDistWithOffices(offices, w, h);
        min_max_dist = min(min_max_dist, max_dist);
    } while (prev_permutation(combination.begin(), combination.end()));

    cout << min_max_dist << endl;

    return 0;
}
