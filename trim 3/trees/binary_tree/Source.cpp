#include <iostream>

using namespace std;

struct tnode {
	int field;
	struct tnode* left;
	struct tnode* right;
};

void add_node(tnode** tree, int val);
void create_tree(tnode** tree);
void print_tree(tnode* tree);
void print_tree(tnode* tree, int level);
void del_node(tnode** tree, int val);
void del_tree(tnode** tree);
tnode* search(tnode** tree, int val);

int main() {
	setlocale(0, "");
	tnode* root = NULL;
	bool f = true;
	cout << "1 - �������� ������;\n" <<
		"2 - ����� ������;\n" <<
		"3 - ���������� �������;\n" <<
		"4 - �������� �������;\n" <<
		"5 - �������� ������;\n" <<
		"0 - �����.\n";
	short op; int temp = 0;
	while (f) {
		cout << ">>";
		cin >> op;
		switch (op)
		{
		case 1:
			create_tree(&root);
			break;
		case 2:
			print_tree(root);
			break;
		case 3:
			cout << "������� �������� �������: ";
			cin >> temp;
			add_node(&root, temp);
			break;
		case 4:
			cout << "������� �������� �������: ";
			cin >> temp;
			del_node(&root, temp);
			break;
		case 5:
			del_tree(&root);
			break;
		case 0:
			f = false;
			break;
		default:
			cout << "1 - �������� ������;\n" <<
				"2 - ����� ������;\n" <<
				"3 - ���������� �������;\n" <<
				"4 - �������� �������;\n" <<
				"5 - �������� ������;\n" <<
				"0 - �����.\n";
			break;
		}
	}
}

void add_node(tnode** tree, int val)
{
	if (!(*tree)) {
		*tree = new tnode;
		(**tree).right = NULL; (**tree).left = NULL;
		(**tree).field = val;
	}
	else {
		if (val < (**tree).field) add_node(&(**tree).left, val);
		else if (val > (**tree).field)  add_node(&(**tree).right, val);
		else return;
	}
}

void create_tree(tnode** tree)
{
	int n;
	cout << "������� ���������� ������: ";
	cin >> n;
	int val;
	cout << "������� �������� �����: ";
	cin >> val;
	add_node(tree, val);
	for (int i = 1; i < n; i++) {
		cout << "������� �������� �������: ";
		cin >> val;
		add_node(tree, val);
	}
}

void print_tree(tnode* tree)
{
	if (!tree) return;
	cout << (*tree).field << "\n";
	print_tree((*tree).left, 1);
	print_tree((*tree).right, 1);
}

void print_tree(tnode* tree, int level)
{
	if (!tree) return;
	for (int i = 0; i < level; i++) cout << "_";
	cout << (*tree).field << "\n";
	print_tree((*tree).left, level+1);
	print_tree((*tree).right, level+1);
}

void del_node(tnode** tree, int val)
{
	if (!(*tree)) return;
	tnode* curr = *tree;
	tnode* parent = *tree;
	while ((*curr).field != val) {
		parent = curr;
		if ((*curr).field > val) {
			if ((*curr).left) curr = (*curr).left;
			else return;
		}
		else {
			if ((*curr).right) curr = (*curr).right;
			else return;
		}
	}
	if ((*curr).right && (*curr).left) {
		//���� ��� �������� ��������
		tnode* min = (*curr).right;
		while ((*min).left) min = (*min).left;
		int temp_min = (*min).field;
		del_node(tree, temp_min);
		(*curr).field = temp_min;
	}
	else if ((*curr).right || (*curr).left) {
		//���� ���� �������� �������
		if (curr == *tree) {
			if ((*curr).left) *tree = (*curr).left;
			else *tree = (*curr).right;
			return;
		}
		tnode* temp;
		if ((*curr).left) temp = (*curr).left;
		else temp = (*curr).right;
		if ((*parent).field > val) (*parent).left = temp;
		else (*parent).right = temp;
		delete curr;
	}
	else {
		//���� ����
		if (curr == *tree) {
			del_tree(tree);
			return;
		}
		delete curr;
		if ((*parent).field > val) (*parent).left = NULL;
		else (*parent).right = NULL;
	}
}

void del_tree(tnode** tree)
{
	if (!(*tree)) return;
	del_tree(&(**tree).right);
	del_tree(&(**tree).left);
	delete *tree;
	*tree = NULL;
}

tnode* search(tnode** tree, int val)
{
	if (!tree) return NULL;
	if (val > (**tree).field) return search(&(**tree).right, val);
	else  if (val < (**tree).field) return search(&(**tree).left, val);
	return *tree;
}