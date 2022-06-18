#include <iostream>

#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

void create_list(node** head);
void print_list(node* head);
void add_first(node** head);
void add_last(node** head);
void del_node_by_value(node** head, int val);
void del_node(node** curr);
void del_list(node** head);

int main() {
	setlocale(0, "");
	node* head = new node;
	(*head).next = NULL;
	(*head).prev = NULL;
	bool f = true;
	cout << "1 - создать список;\n" <<
		"2 - вывести список;\n" <<
		"3 - добавить узел в начало списка;\n" <<
		"4 - добавить узел в конец списка;\n" <<
		"5 - удалить все узлы с заданным значением;\n" <<
		"6 - удалить список;\n" <<
		"0 - закончить.\n";
	int op; int val;
	while (f) {
		cout << ">>";
		cin >> op;

		switch (op)
		{
		case 1:
			create_list(&head);
			break;
		case 2:
			print_list(head);
			break;
		case 3:
			add_first(&head);
			break;
		case 4:
			add_last(&head);
			break;
		case 5:
			cout << "¬ведите значение: "; cin >> val;
			del_node_by_value(&head, val);
			break;
		case 6:
			del_list(&head);
			break;
		case 0:
			f = false;
			break;
		default:
			cout << "такой команды нет";
		}
	}

}

void create_list(node** head)
{
	if ((**head).next != NULL) del_list(head);
	node* curr = *head;
	node* new_n = NULL;
	int n, data;
	cout << "¬ведите количество элементов в списке: "; cin >> n;
	for (int i = 0; i < n; i++) {
		new_n = new node;
		(*new_n).next = NULL;
		(*new_n).prev = curr;
		(*curr).next = new_n;
		cout << "¬ведите значение узла: "; cin >> (*new_n).data;
		curr = new_n;
	}
	(**head).data = n;
}

void print_list(node* head)
{
	if ((*head).next) {
		node* curr = (*head).next;
		while ((*curr).next) {
			cout << (*curr).data << " ";
			curr = (*curr).next;
		}
		cout << (*curr).data << "\n";
		while ((*curr).prev != head) {
			cout << (*curr).data << " ";
			curr = (*curr).prev;
		}
		cout << (*curr).data << "\n";
	}
}

void add_first(node** head)
{
	cout << "¬ведите значение узла: ";
	node* new_n = new node;
	(*new_n).next = (**head).next;
	(*new_n).prev = *head;
	cin >> (*new_n).data;
	(**head).next = new_n;
	if ((*new_n).next) (*((*new_n).next)).prev = new_n;
	(**head).data += 1;
}

void add_last(node** head)
{
	if ((**head).next) {
		node* curr = (**head).next;
		while ((*curr).next) curr = (*curr).next;
		node* new_n = new node;
		(*new_n).next = NULL;
		(*new_n).prev = curr;
		(*curr).next = new_n;
		cout << "¬ведите значение узла: ";
		cin >> (*new_n).data;
		(**head).data += 1;
	}
	else {
		add_first(head);
	}
}

void del_node(node** curr) {
	if ((**curr).next) {
		(*((**curr).prev)).next = (**curr).next;
		(*((**curr).next)).prev = (**curr).prev;
		delete *curr;
	}
	else {
		(*((**curr).prev)).next = NULL;
		delete* curr;
	}
}

void del_node_by_value(node** head, int val) {
	node* curr = (**head).next;
	node* temp = NULL;
	while (curr) {
		if ((*curr).data == val) {
			temp = (*curr).next;
			del_node(&curr);
			curr = temp;
			(**head).data -= 1;
		}
		else curr = (*curr).next;
	}
}

void del_list(node** head) {
	if ((**head).next == NULL) return;
	node* curr = (**head).next;
	while (curr != NULL) {
		del_node(&curr);
		curr = (**head).next;
	}
	(**head).data = 0;
}
