#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, i, min = 10000000;
	cin >> n;
	vector<int> v(n, 0);
    
	for(i=0; i<n; i++)
		cin >> v[i];
	
	sort(v.begin(),v.end());
	for(i=0; i<n-1; i++)
		if(v[i+1] - v[i] < min)
			min = v[i+1] - v[i];
	
	printf("%d\n",min);
	return 0;
}
