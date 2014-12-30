#include <iostream>
#include <string>

using namespace std;

int main()
{
    int lx,ly,tx,ty;
    cin >> lx >> ly >> tx >> ty;

    while (1) {
        int n;
        cin >> n;
        if(tx < lx) {
            if(ty < ly)
		cout<<"SE\n"; ty++;
            else if(ty>ly) 
		cout<<"NE\n"; ty--;
            else cout<<"E\n";
	            tx++;
        }
        else if(tx > lx) {
            if(ty < ly)
		cout<<"SW\n"; ty++;
            else if(ty > ly)
		cout<<"NW\n"; ty--;
            else 
		cout<<"W\n";
            tx--;
        }
        else {
            if(ty < ly)
		cout<<"S\n"; ty++;
            else
		cout<<"N\n"; ty--;
        }
    }

    return 0;
}
