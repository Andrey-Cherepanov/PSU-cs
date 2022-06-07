#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

void create_list(node** head);
void print_list(node* head);
void add_first(node** head);
void add_last(node** head);
void del_node_by_value(node** head, int val);
void del_node(node** prev, node** curr);
void del_list(node** head);

int main() {
	setlocale(0, "");
	node* head = new node;
	(*head).next = NULL;
	bool f = true;
	cout << "1 - ������� ������;\n" <<
		"2 - ������� ������;\n" <<
		"3 - �������� ���� � ������ ������;\n" <<
		"4 - �������� ���� � ����� ������;\n" <<
		"5 - ������� ��� ���� � �������� ���������;\n" <<
		"6 - ������� ������;\n" <<
		"0 - ���������.\n";
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
			cout << "������� ��������: "; cin >> val;
			del_node_by_value(&head, val);
			break;
		case 6:
			del_list(&head);
			break;
		case 0:
			f = false;
			break;
		default:
			cout << "����� ������� ���";
		}
	}
	
}

void create_list(node** head)
{
	if ((**head).next != NULL) del_list(head);
	node* curr = *head;
	node* new_n = NULL;
	int n, data;
	cout << "������� ���������� ��������� � ������: "; cin >> n;
	for (int i = 0; i < n; i++) {
		new_n = new node;
		(*new_n).next = NULL;
		(*curr).next = new_n;
		cout << "������� �������� ����: "; cin >> (*new_n).data;
		curr = new_n;
	}
	(**head).data = n;
}

void print_list(node* head)
{
	node* curr = (*head).next;
	while (curr != NULL) {
		cout << (*curr).data << " ";
		curr = (*curr).next;
	}
	cout << "\n";
}

void add_first(node** head)
{
	cout << "������� �������� ����: ";
	node* new_n = new node;
	(*new_n).next = (**head).next;
	cin >> (*new_n).data;
	(**head).next = new_n;
	(**head).data += 1;
}

void add_last(node** head)
{
	node* curr = (**head).next;
	node* temp = NULL;
	while (curr != NULL) {
		temp = curr;
		curr = (*curr).next;
	}
	curr = new node; (*curr).next = NULL;
	cout << "������� �������� ����: "; cin >> (*curr).data;
	(*temp).next = curr;
	(**head).data += 1;
}

void del_node(node** prev, node** curr) {
	(**prev).next = (**curr).next;
	delete *curr;
	*curr = (**prev).next;
}

void del_node_by_value(node** head, int val){
	node* curr = (**head).next;
	node* temp = *head;
	while (curr != NULL) {

		if ((*curr).data == val) {
			del_node(&temp, &curr);
			(**head).data -= 1;
		}
		temp = curr;
		curr = (*curr).next;
	}
}

void del_list(node** head){
	if ((**head).next == NULL) return;
	node* curr =  (**head).next;
	while (curr != NULL) {
		del_node(head, &curr);
		curr = (**head).next;
	}
	(**head).data = 0;
}