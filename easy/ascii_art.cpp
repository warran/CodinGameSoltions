#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cctype>

using namespace std;

string to_upper(string s)
{
    for(int i = 0;i < s.size();++i)
        s[i] = toupper(s[i]);
    return s;
}

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    T = to_upper(T);
    
    vector<string> alphabet[27];
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        
        for(int j = 0;j < 27;++j) {
            string line = ROW.substr(j * L, L);
            alphabet[j].push_back(line);
        }
    }
    
    for(int i = 0; i < H;++i) {
        for(int j = 0;j < T.length();++j)
        {
            int index = int(T[j]) - int('A');
            if(index < 0 || index > 25)
                index = 26;
            cout << alphabet[index][i];
        }
        cout << endl;
    }
}
