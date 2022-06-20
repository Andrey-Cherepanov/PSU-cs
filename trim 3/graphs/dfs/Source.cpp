#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
vector<bool> visited;

void dfs(int n, int v, vector<int>* res);

int main() {
	setlocale(0, "");
	ifstream fin("graph.txt");
	int n;
	fin >> n;
	matrix = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> matrix[i][j];
	fin.close();
	visited = vector<bool>(n, 0);
	vector<int> res;
	cout << "¬ведите начальную вершину: ";
	int v;  cin >> v;
	dfs(n, v-1, &res);
	for (int i = 0; i < res.size(); i++) cout << res[i]+1 << " ";
}

void dfs(int n, int v, vector<int>* res)
{
	(*res).push_back(v);
	visited[v] = 1;
	for (int i = 0; i < n; i++) {
		if (matrix[v][i] && !visited[i]) dfs(n, i, res);
	}
}
