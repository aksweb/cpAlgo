#include <bits/stdc++.h>
using namespace std;

// dp Defeination: Maximum sum till index i.
vector<int> dp;
int kadane(vector<int> &a){
    
    for(int i=0; i<a.size(); i++){
        dp[i]= max(dp[i-1]+a[i], a[i])
    }
}

int main()
{

    int n;
    cin >> n;
    dp.resize(n, 0);

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    
    cout<< kadane(a);

    return 0;
}