#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
    Node() : affected_by(0), longest_chain(1)
    {}

    int affected_by;
    int longest_chain;
    vector<int> affects;
};

int main()
{
	int n;
	cin >> n;
	
	map<int, Node> graph;
	
	for (int i = 0; i < n; i++) {	
		int a, b;
		cin >> a >> b;
		
		graph[a].affects.push_back(b);
		++graph[b].affected_by;
	}
	
	queue<int> to_lookup;
	for(map<int, Node>::iterator iter = graph.begin();iter != graph.end();++iter) {
	    if((*iter).second.affected_by == 0)
	        to_lookup.push((*iter).first);
	}
	
	int max_chain = 0;
	while(!to_lookup.empty()) {
	    int next_lookup_index = to_lookup.front();
	    to_lookup.pop();
	    Node next_lookup = graph[next_lookup_index];
	    
	    for(int i = 0;i < next_lookup.affects.size();++i) {
	        int aff_index = next_lookup.affects[i];
	        graph[aff_index].longest_chain = next_lookup.longest_chain + 1;
	        if(graph[aff_index].longest_chain > max_chain)
	            max_chain = graph[aff_index].longest_chain;

	        --graph[aff_index].affected_by;
	        if(graph[aff_index].affected_by == 0)
	            to_lookup.push(aff_index);
	    }
	}
	
	cout << max_chain << endl;
	
	return 0;
}
