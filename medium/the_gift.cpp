#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    
    int BSum = 0;
    int BS[N];
    for (int i = 0; i < N; i++) {
        cin >> BS[i]; cin.ignore();
        BSum += BS[i];
    }
    
    if(BSum < C)
        cout << "IMPOSSIBLE" << endl;
    else {
        sort(BS, BS + N);
        int expected = C / N;
        
        for(int i = 0;i < N;++i) {
            int b = min(BS[i], expected);
            cout << b << endl;
            C -= b;
            if(i < N - 1)
                expected = C / (N - i - 1);
        }
    }
}
