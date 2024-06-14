// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define br << endl

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int P, X, R1;
        int N, Y, R2;

        cin >> P >> X >> R1;
        cin >> N >> Y >> R2;

        double timePaul = static_cast<double>(P) / X + R1;
        double timeNina = static_cast<double>(N) / Y + R2;

        if (timePaul < timeNina)
        {
            cout << "PAUL" br;
            cout << static_cast<int>(timePaul) br;
        }
        else if (timeNina < timePaul)
        {
            cout << "NINA" br;
            cout << static_cast<int>(timeNina) br;
        }
        else
        {
            cout << "BOTH" br;
            cout << static_cast<int>(timePaul) br; 
        }
    }

    return 0;
}
