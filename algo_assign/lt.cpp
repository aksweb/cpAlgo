class Solution
{
public:
    double solve(string ic, vector<vector<string>> &p1, vector<double> &r1, vector<vector<string>> &p2, vector<double> &r2, vector<double> &dp, int idx)
    {
        if (idx == dp.size())
            return 1.0;
        double take = 0.0, not_take = 0.0;
        if (dp[idx] != -1.0)
            return dp[idx];

        if (idx < p1.size() && p1[idx][0] == ic)
        {
            take = r1[idx] * solve(p1[idx][1], p1, r1, p2, r2, dp, idx + 1);
            not_take = solve(p1[idx][1], p1, r1, p2, r2, dp, idx + 1);
        }
        else if (idx > p2.size() && idx < p2.size() && p2[idx][0] == ic)
        {
            int prev = p1.size();
            take = r2[idx - prev] * solve(p2[idx][1], p1, r1 p2, r2, dp, idx + 1);
            not_take = solve(p2[idx][1], p1, r1, p2, r2, dp, idx + 1)
        }
        return dp[idx] = max(dp[idx - 1], take, not_take);
    }

    double maxAmount(string ic,
                     vector<vector<string>> &p1,
                     vector<double> &r1,
                     vector<vector<string>> &p2,
                     vector<double> &r2)
    {
        int n = p1.size() + p2.size();
        vector<double> pairs;
        for (int i = 0; i < r1.size(); i++)
        {
            pairs.push_back(r1[i]);
        }
        for (int i = 0; i < r2.size(); i++)
        {
            pairs.push_back(r2[i]);
        }
        vector<double> dp(n + 1, -1.0);
        return (int)solve(ic, p1, r1, p2, r2, dp, 1);
    }
};