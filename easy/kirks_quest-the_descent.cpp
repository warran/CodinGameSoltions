#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    while (1) {
        int sx, sy;
        cin >> sx >> sy;
        cerr << sx << " " << sy << endl;
        int maxi = -1;
        int maxi_imax = -1000;
        int maxi_imin = 1000;
        vector<pair<int,int> > montagnes(8);
        for(int c=0; c<montagnes.size(); c++)
        {
            cin >> montagnes[c].first;
            montagnes[c].second = c;
        }
        sort(montagnes.rbegin(), montagnes.rend());
        int i = 0;
        while((montagnes[i].second>sx && sy%2) || (montagnes[i].second<sx && sy%2==0))
        {
            cerr << montagnes[i].first << " " << montagnes[i].second << endl;
            i++;
        }
        if(montagnes[i].second == sx)
		cout << "FIRE" << endl;
        else 
		cout << "HOLD" << endl;
    }
    return 0;
}
