#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <map>

using namespace std;

bool clone_going_in_good_dir(int clonePos, int destPos, string direction)
{
    if(clonePos <= destPos && direction == "RIGHT")
        return true;
    if(clonePos >= destPos && direction == "LEFT")
        return true;
    return false;
}

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    
    map<int, int> elevators_pos;
    
    cin >> nbFloors >> width >> nbRounds
        >> exitFloor >> exitPos >> nbTotalClones
        >> nbAdditionalElevators >> nbElevators;
    cin.ignore();
    
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        elevators_pos[elevatorFloor] = elevatorPos;
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();

        if(cloneFloor == -1 && clonePos == -1) {
            cout << "WAIT" << endl; 
            continue;
        }
        
        int destination = 0;
        if(cloneFloor == exitFloor)
            destination = exitPos;
        else
            destination = elevators_pos[cloneFloor];
        
        if(clone_going_in_good_dir(clonePos, destination, direction))
            cout << "WAIT" << endl;
        else
            cout << "BLOCK" << endl;
    }
}
