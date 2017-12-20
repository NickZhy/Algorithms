#include <iostream>
#include <vector>

using namespace std;

//be aware of overflow!
vector<vector<int> > floyd(vector<vector<int> >& adjMat) {
	vector<vector<int> > dist = adjMat;	
	int n = adjMat.size();
	if(!n) return dist;
	if(adjMat[0].size() != n) return dist;

	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(dist[i][k] >= 0 && dist[k][j] >= 0) {
					int tmp = dist[i][k] + dist[k][j];
					if(dist[i][j] < 0 || dist[i][j] > tmp)
						dist[i][j] = tmp;
				}
	return dist;
}

void show(vector<vector<int> >& mat) {
	for(vector<int> row: mat) {
		for(int ele: row)
			printf("%3d ", ele);
		cout << endl;
	}
}

int main() {
	int num = 5;
	vector<vector<int> > adjMat(num, vector<int>(num, -1));
	adjMat[0][0] = 0;	adjMat[0][1] = 2;	adjMat[0][2] = 3;
	adjMat[1][0] = 2;	adjMat[1][1] = 0;	adjMat[1][2] = 15;	adjMat[1][3] = 2;
	adjMat[2][0] = 3;	adjMat[2][1] = 15;	adjMat[2][2] = 0;	adjMat[2][4] = 13;
	adjMat[3][1] = 2;	adjMat[3][3] = 0;	adjMat[3][4] = 9;
	adjMat[4][2] = 13;	adjMat[4][3] = 9;	adjMat[4][4] = 0;
	cout << "Input:" << endl;
	show(adjMat);
	vector<vector<int> > dist = floyd(adjMat);
	cout << "Output:" << endl;
	show(dist);
	return 0;
}

