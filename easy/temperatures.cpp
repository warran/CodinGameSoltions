#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n; cin >> n;
	cerr << n << endl;
	
	if(n == 0) {
	    cout << "0" << endl;
	    return 0;
	}
	
	int b; cin >> b;

	for (int i = 1; i < n; i++) {
		int t;
    		cin >> t;
		if(abs(t) < abs(b))
    			b = t;
    		else if ((abs(t) == abs(b)) && (t > b))
    	    		b = t;
    	}
	
	cout << b << endl;
	
	return 0;
}
