#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <utility>

using namespace std;

pair<int, int> get_move(int room_type, string from_pos)
{
    switch(room_type) {
        case 1:  return make_pair(0, 1);
        case 2:  return (from_pos == "LEFT" ? make_pair(1, 0) : make_pair(-1, 0));
        case 3:  return make_pair(0, 1);
        case 4:  return (from_pos == "TOP" ? make_pair(-1, 0) : make_pair(0, 1));
        case 5:  return (from_pos == "TOP" ? make_pair(1, 0) : make_pair(0, 1));
        case 6:  return (from_pos == "LEFT" ? make_pair(1, 0) : make_pair(-1, 0));
        case 7:  return make_pair(0, 1);
        case 8:  return make_pair(0, 1);
        case 9:  return make_pair(0, 1);
        case 10: return make_pair(-1, 0);
        case 11: return make_pair(1, 0);
        case 12: return make_pair(0, 1);
        case 13: return make_pair(0, 1);
    }
}
 
int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    
    int rooms[W][H];
    for (int i = 0; i < H; i++)
        for(int j = 0;j < W;++j)
            cin >> rooms[j][i];

    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        
        pair<int, int> move = get_move(rooms[XI][YI], POS);

        
        cout << XI + move.first << " " << YI + move.second << endl; // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
    }
}
