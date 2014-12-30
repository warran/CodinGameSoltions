#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    while (1) {
        int count; // The number of current enemy ships within range
        cin >> count; cin.ignore();
        int best_dist;
        string best_enemy;
        cin >> best_enemy >> best_dist; cin.ignore();
        for (int i = 1; i < count; i++) {
            string enemy; // The name of this enemy
            int dist; // The distance to your cannon of this enemy
            cin >> enemy >> dist; cin.ignore();
            
            if(best_dist > dist) {
                best_enemy = enemy;
                best_dist = dist;
            }
        }

        cout << best_enemy << endl; 
    }
}
