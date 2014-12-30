#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    string vs;
    getline(cin, vs);
    
    int max_loss = 0, current_start = 0;
    stringstream vsstream(vs);
    for(int i = 0;i < n;++i) {
        int ccv; vsstream >> ccv;
        
        if(ccv > current_start)
            current_start = ccv;
        else if(current_start - ccv > max_loss)
            max_loss = current_start - ccv;
    }

    cout << -max_loss << endl;
}
