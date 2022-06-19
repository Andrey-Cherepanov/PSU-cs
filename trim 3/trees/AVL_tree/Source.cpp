#include <iostream>

using namespace std;

struct node{
	int field;
	unsigned char height;
	node* right;
	node* left;
};

node* add(node** tree, int val);
void fixeheight(node* p);
int bfactor(node* p);
node* rotateright(node** p);
node* rotateleft(node** tree);
node* balance(node** tree);
void print(node* tree);
void print(node* tree, int level);

int main() {
	setlocale(0, "");
	node* root = NULL;
	bool f = true;
	cout << "1 - Добавление вершины;\n" <<
		"2 - Вывод дерева;\n" <<
		"0 - Выход.\n";
	short op; int temp = 0;
	while (f) {
		cout << ">>";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Введите значение вершины: ";
			cin >> temp;
			root = add(&root, temp);
			break;
		case 2:
			print(root);
			break;
		case 0:
			f = false;
			break;
		default:
			cout << "1 - Добавление вершины;\n" <<
				"2 - Вывод дерева;\n" <<
				"0 - Выход.\n";
			break;
		}
	}
}

node* add(node** tree, int val)
{
	if (!(*tree)) {
		*tree = new node;
		(**tree).right = NULL; (**tree).left = NULL;
		(**tree).field = val;
		(**tree).height = 1;
		return *tree;
	}
	if ((**tree).field > val) (**tree).left = add(&(**tree).left, val);
	else if ((**tree).field < val) (**tree).right = add(&(**tree).right, val);
	else return *tree;
	return balance(tree);
}

void fixeheight(node* p)
{
	unsigned char hl, hr;
	if ((*p).right) hr = (*(*p).right).height;
	else hr = 0;

	if ((*p).left) hl = (*(*p).left).height;
	else hl = 0;

	(*p).height = (hl > hr ? hl : hr) + 1;
}

int bfactor(node* p)
{
	unsigned char hl, hr;
	if ((*p).right) hr = (*(*p).right).height;
	else hr = 0;

	if ((*p).left) hl = (*(*p).left).height;
	else hl = 0;

	return hr - hl;
}

node* rotateright(node** p)
{
	node* q = (**p).left;
	(**p).left = (*q).right;
	(*q).right = *p;
	fixeheight(*p);
	fixeheight(q);
	return q;
}

node* rotateleft(node** p)
{
	node* q = (**p).right;
	(**p).right = (*q).left;
	(*q).left = *p;
	fixeheight(*p);
	fixeheight(q);
	return q;
}

node* balance(node** tree)
{
	fixeheight(*tree);

	if (bfactor(*tree) == 2) {
		if (bfactor((**tree).right) < 0)
			(**tree).right = rotateright(&(**tree).right);
		return rotateleft(tree);
	}
	if (bfactor(*tree) == -2) {
		if (bfactor((**tree).left) > 0)
			(**tree).left = rotateleft(&(**tree).left);
		return rotateright(tree);
	}
	return *tree;
}

void print(node* tree)
{
	if (!tree) return;
	cout << (*tree).field << "\n";
	print((*tree).left, 1);
	print((*tree).right, 1);
}

void print(node* tree, int level)
{
	if (!tree) return;
	for (int i = 0; i < level; i++) cout << "_";
	cout << (*tree).field << "\n";
	print((*tree).left, level + 1);
	print((*tree).right, level + 1);
}
