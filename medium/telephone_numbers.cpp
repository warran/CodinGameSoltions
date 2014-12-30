#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    int n = min(a.size(), b.size());
    for(int i = 0;i < n;++i) {
        if(a[i] < b[i]) 
            return true;
        else if(a[i] > b[i])
            return false;
    }
    return (a.size() < b.size());
}

int main()
{
	int N;
	cin >> N;
	
	string numbers[N];
	for (int i = 0; i < N; i++) {	
		cin >> numbers[i];
	}
	
	sort(numbers, numbers + N, comp);
	
	int result = numbers[0].size();
	for(int i = 1; i < N; ++i) {
	    int comm = 0;
	    int m = min(numbers[i].size(), numbers[i-1].size());
	    for(int j = 0;j < m;++j) {
	        if(numbers[i][j] == numbers[i-1][j])
	            ++comm;
	        else
	            break;
	    }
	    result += numbers[i].size() - comm;
	}
	
	cout << result << endl;
	
	return 0;
}
