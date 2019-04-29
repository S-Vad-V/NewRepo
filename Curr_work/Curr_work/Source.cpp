#include <iostream>
#include <string>

using namespace std;

struct list {
	int info;
	list *next;
	list *pred;
};

void Add(list *head) {
	list *r = head;
	while (r->next != NULL)
		r = r->next;
	list *cur = new list;
	cin >> cur->info;
	r->next = cur;
	cur->pred = r;
	cur->next = NULL;
}

bool Is_True(list *head, int count) {
	list *left = head;
	list *right = head;
	//while (right->next != NULL) {
	//	right = right->next;

	//}
	//right = head;
	for (int i = 0; i < count / 2; i++)
		right = right->next;
	for (int i = 0; i < count / 2; i++) {
		if (right->info != left->info)
			return false;
		right = right->next;
		left = left->next;
	}
	return true;
}

int main() {
	list *head = new list;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		if (i == 0) {
			head->next = NULL;
			head->pred = NULL;
			cin >> head->info;
		}else
		Add(head);
	}
	cout << Is_True(head,size);
	system("pause");
	return 0;
}

