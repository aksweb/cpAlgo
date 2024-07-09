
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define ll long long int
#define br << endl
// #define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (x < 0 && y > 0)
        {
            if (y >= abs(x))
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else if(x<0 && y<0){
            if (abs(x)>abs(y) || (x==-1 && y==-1))
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else if (x > 0 && y < 0){
            
        }
        else if (y >= x || y == 0 || (x == 1 && y == -1) || (x == -1 && y == 1))
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
