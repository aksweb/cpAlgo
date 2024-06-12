#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Weapon
{
    int damage;
    int max_uses;
    int displeasure;
};

bool compare(const Weapon &a, const Weapon &b)
{
    return a.displeasure < b.displeasure;
}

void sind(int j=)
int main()
{
    int N, D;
    cin >> N >> D;

    vector<Weapon> weapons(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> weapons[i].damage >> weapons[i].max_uses >> weapons[i].displeasure;
    }

    sort(weapons.begin(), weapons.end(), compare);

    int total_displeasure = 0;
    int damage_done = 0;

    for (int i = 0; i < N && damage_done < D; ++i)
    {
        int uses_needed = (D - damage_done + weapons[i].damage - 1) / weapons[i].damage; // ceiling division
        if (uses_needed <= weapons[i].max_uses)
        {
            damage_done += uses_needed * weapons[i].damage;
        }
        else
        {
            damage_done += weapons[i].max_uses * weapons[i].damage;
            total_displeasure += (uses_needed - weapons[i].max_uses) * weapons[i].displeasure;
        }
    }

    cout << total_displeasure << endl;

    return 0;
}
