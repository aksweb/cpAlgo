#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDepart(int maxWait, int M, int C, vector<int> &arrivalTimes)
{
    int buses = 0;
    
    int lastDeparture = 0;
    for (int i = 0; i < arrivalTimes.size(); ++i)
    {
        if (i - lastDeparture >= C || arrivalTimes[i] - arrivalTimes[lastDeparture] > maxWait)
        {
            lastDeparture = i;
            buses++;
        }
    }
    return buses <= M;
}

int minMaxWait(int N, int M, int C, vector<int> &arrivalTimes)
{
    sort(arrivalTimes.begin(), arrivalTimes.end());
    int low = 0, high = arrivalTimes[N - 1] - arrivalTimes[0], result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canDepart(mid, M, C, arrivalTimes))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> arrivalTimes(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arrivalTimes[i];
    }
    cout << minMaxWait(N, M, C, arrivalTimes) << endl;
    return 0;
}
