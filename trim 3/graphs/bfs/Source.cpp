#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct q_node {
	int val;
	q_node* next;
};

vector<bool> visited;
q_node* head;
q_node* tail;
vector<vector<int>> matrix;

void bfs(int n, int v, vector<int>* res);
void push(int val);
int pop();
bool empty();


int main() {
	setlocale(0, "");
	ifstream fin("graph.txt");
	int n;
	fin >> n;
	matrix = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) fin >> matrix[i][j];
	}
	fin.close();
	visited = vector<bool>(n, false);
	vector<int> res;
	int v;
	cout << "¬ведите начальную вершину: ";
	cin >> v;
	bfs(n, v-1, &res);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i]+1 << " ";
	}

}

void bfs(int n, int v, vector<int>* res)
{
	push(v);
	visited[v] = 1;
	while(!empty()){
		
		for (int i = 0; i < n; i++) {
			if (matrix[v][i] && !visited[i]) {
				push(i);
				visited[i] = true;
			}
		}
		(*res).push_back(pop());
	}
}

void push(int val) {
	if (empty()) {
		q_node* new_node = new q_node;
		(*new_node).val = val;
		(*new_node).next = NULL;
		head = new_node; tail = new_node;
		return;
	}
	q_node* new_node = new q_node;
	(*new_node).next = NULL;
	(*tail).next = new_node;
	(*new_node).val = val;
	tail = new_node;
}

int pop() {
	if (empty()) {
		cout << "error\n";
		return -1;
	}
	int val = (*head).val;
	q_node* del_node = head;
	head = (*head).next;
	delete del_node;
	return val;
}

bool empty()
{
	if (!head) return true;
	return false;
}
