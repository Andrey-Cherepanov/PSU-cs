#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int max_dist = INT_MAX;

vector<vector<int>> matrix;

vector<int> deykstra(int n, int v);

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
	cout << "¬ведите начальную вершину: ";
	int v; cin >> v;
	vector<int> res = deykstra(n, v-1);
	for (int i = 0; i < n; i++) {
		if (i+1 != v)
			cout << v << " -> " << i + 1 << " = " << res[i] << "\n";
	}
}

vector<int> deykstra(int n, int v)
{
	vector<int> distance(n, max_dist);
	vector<bool> visited(n, 0);
	distance[v] = 0; bool f = true;
	while (f) {
		for (int i = 0; i < n; i++) {
			if (matrix[v][i] && !visited[i]) {
				distance[i] = distance[i] < (distance[v] + matrix[v][i]) ?
					distance[i] : distance[v] + matrix[v][i];
			}
		}
		visited[v] = 1;
		int min = max_dist;
		for (int i = 0; i < n; i++) {
			if (distance[i] < min && !visited[i]) {
				min = distance[i];
				v = i;
			}
		}
		if (min == max_dist) f = 0;
	}
	return distance;
}
