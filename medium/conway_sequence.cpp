#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> next_line(vector<int> line) {
    vector<int> result;
    int current_num = line[0];
    int current_count = 1;
    for(int i = 1;i < line.size();++i) {
        if(line[i] == current_num)
            ++current_count;
        else {
            result.push_back(current_count);
            result.push_back(current_num);
            current_num = line[i];
            current_count = 1;
        }
    }
    result.push_back(current_count);
    result.push_back(current_num);
    
    return result;
}

int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    vector<int> line(1, R);
    
    for(int i = 1;i < L;++i) {
        line = next_line(line);
    }
    
    for(int i = 0;i < line.size();++i)
        cout << line[i] << (i < line.size()-1 ? " " : "");
    cout << endl;
}