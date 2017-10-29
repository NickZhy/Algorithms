#include <iostream>
#include <vector>
#include <limits>
#define INF numeric_limits<int>::max()

using namespace std;

vector<int> dfs(int start, int end, vector<vector<int> > graph) {
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
		if(!sign)
			path.pop_back();
	}
	return path;
}

vector<vector<int> > maxFlow(int start, int end, vector<vector<int> >& graph) {
	int num = graph.size();
	vector<vector<int> > residual = graph;
	vector<vector<int> > flow(num, vector<int>(num, 0));

	while(1) {
		vector<int> path = dfs(start, end, residual);
		if(!path.size())
			break;

		int newFlow = INF;
		for(int i = 0; i + 1 < path.size(); ++i) {
			int a = path[i];
			int b = path[i + 1];
			newFlow = min(newFlow, residual[a][b]);
		}
		cout << endl;
		for(int i = 0; i + 1 < path.size(); ++i) {
			int a = path[i];
			int b = path[i + 1];
			residual[a][b] -= newFlow;
			residual[b][a] += newFlow;
			flow[a][b] += newFlow;
		}
	}
	return flow;
}

void printMatrix(vector<vector<int> > matrix) {
	for(int i = 0; i < matrix.size(); ++i) {
		for(int j = 0; j < matrix[i].size(); ++j) {
			cout << matrix[i][j] << ",";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int> > graph = {	{0, 2, 0, 4, 0, 0},
									{0, 0, 2, 0, 0, 0},
									{0, 0, 0, 0, 0, 1},
									{0, 0, 3, 0, 1, 0},
									{0, 0, 0, 0, 0, 1},
									{0, 0, 0, 0, 0, 0}};
	vector<vector<int> > flow = maxFlow(0, 5, graph);
	printMatrix(flow);
	return 0;
}
