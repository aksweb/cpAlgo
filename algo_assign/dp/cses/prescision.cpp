#include <bits/stdc++.h>
using namespace std;
int main()
{
    // float n = 5.0, m = 2.0;
    // // cout << n / m;
    // float num = 2.71828;
    // // setprecision(3);
    // cout << setprecision(3) << num;

    // using getline
    int n;
    cin >> n;
    cin.ignore();
    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        strs.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        stringstream ss(strs[i]);
        string str;
        while (ss >> str)
        {
            cout << str << " : ";
        }
        cout << endl;
    }
    return 0;
}