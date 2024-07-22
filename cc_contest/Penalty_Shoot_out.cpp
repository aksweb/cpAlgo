#include <iostream>
using namespace std;
#define ll long long int

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int x, y;
        cin >> x >> y;

         if ((x <= y + 1) && (y <= x + 2))
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
