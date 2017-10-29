#include <iostream>
#include <vector>

using namespace std;

// In this version, the stack is exactly the current path from the start.
vector<int> dfsFindPath(int start, int end, vector<vector<int> > graph) {
	int num = graph.size();
	vector<bool> visit(num, false);
	vector<int> path;
	path.push_back(start);
	visit[start] = true;

	while(path.size()) {
		int curr = path.back();
		if(curr == end)
			break;

		bool sign = false;
		for(int i = 0; !sign && i < num; ++i) {
			if(!visit[i] && graph[curr][i]) {
				visit[i] = true;
				sign = true;
				path.push_back(i);
			}
		}
		if(!sign) path.pop_back();
	}
	return path;
}

// Another simple and concise solution, it's more suitable for label problems.
void dfsLabel(int start, vector<vector<int> > graph) {
	int num = graph.size();
	vector<bool> visit(num, false);
	vector<int> stack;
	stack.push_back(start);
	visit[start] = true;

	while(stack.size()) {
		int curr = stack.back();
		stack.pop_back();
		cout << curr << " ";
		for(int i = 0; i < num; ++i) {
			if(!visit[i] && graph[curr][i]) {
				visit[i] = true;
				stack.push_back(i);
			}
		}
	}
	cout << endl;
}

int main() {
	vector<vector<int> > graph = {	{0, 1, 1, 1, 0, 0},
									{0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 1, 1},
									{0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0}};
	vector<int> path = dfsFindPath(0, 5, graph);
	for(int i = 0; i < path.size(); ++i) 
		cout << path[i] << " ";
	cout << endl;
	dfsLabel(0, graph);
	return 0;
}
