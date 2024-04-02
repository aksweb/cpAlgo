#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int diff = B - A;
    bool possible = true;
    for (int i = 0; i < N; ++i)
    {
        int D;
        cin >> D;
        if (D <= A || D > B && D % diff == 0)
            possible = false;
    }
    cout << (possible ? "Yes" : "No") << endl;
    return 0;
}
