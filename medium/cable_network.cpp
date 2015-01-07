#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>
#include <cstdlib>
#include <utility>

using namespace std;

typedef pair<long int, long int> position;

long long int cable_needed(long int cable_y, vector<position>& houses, long int minX, long int maxX)
{
    long long int result = 0;
    for(int i = 0;i < houses.size();++i)
        result += abs(cable_y - houses[i].first);
    return result + (maxX - minX);
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<position> houses;
    long int minX = LONG_MAX, maxX = LONG_MIN;
    for (int i = 0; i < N; i++) {
        int X; int Y;
        cin >> X >> Y; cin.ignore();
        cerr << X << " " << Y << endl;
        
        if(X < minX)
            minX = X;
        if(X > maxX)
            maxX = X;
            
        houses.push_back(make_pair(Y, X));
    }

    sort(houses.begin(), houses.end());
    int median = N/2;
    
    long long int answer = 0;
    if(N % 2 == 0) {
        long long int answer1 = cable_needed(houses[median].first, houses, minX, maxX);
        long long int answer2 = cable_needed(houses[median+1].first, houses, minX, maxX);
        answer = min(answer1, answer2);
    } else
        answer = cable_needed(houses[median].first, houses, minX, maxX);

    cout << answer << endl;
}
