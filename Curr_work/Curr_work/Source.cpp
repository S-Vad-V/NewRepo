#include <iostream>
#include <string>
#define null NULL

using namespace std;

struct tree {
	int info;
	tree *R, *L;
};

void ADDDDP(tree *p, int x) { // р - ссылка на корень дерева
	tree *q;
	if (x < p->info)
		if (p->L == NULL) {
			q = new tree;
			q->info = x;
			q->L = NULL;
			q->R = NULL;
			p->L = q;
		}
		else ADDDDP(p->L, x);
	else if (p->R == NULL) {
		q = new tree;
		q->info = x;
		q->L = NULL;
		q->R = NULL;
		p->R = q;
	}
	else ADDDDP(p->R, x);
}

void print_sort(tree *p) {
	if (p != null) {
		print_sort(p->L);
		cout << p->info << " ";
		print_sort(p->R);
	}
}

void zam(tree *p) {
	if (p != null) {
		if (p->info % 3 == 0) {
			p->info *= p->info;
		}
		zam(p->L);
		zam(p->R);
	}
}

int sum(tree *p) {
	if (p != null) {
		if (p->info % 2 == 0) {
			return p->info + sum(p->L) + sum(p->R);
		}
		else return sum(p->L) + sum(p->R);
	}
	else return 0;
}

int Count(tree *p) {
	if (p != null) {
		if (p->L != null || p->R != null)
			return 1 + Count(p->R) + Count(p->L);
		else
			return Count(p->R) + Count(p->L);
	}
	else return 0;
}

int max(tree *p) {
	while (p != null)
		p = p->R;
	return p->info;
}

int sum_of_positive(tree *p) {
	if (p != null) {
		if (p->info > 0) {
			return p->info + sum_of_positive(p->L) + sum_of_positive(p->R);
		}
		else return sum_of_positive(p->L) + sum_of_positive(p->R);
	}
	else return 0;
}
int count_of_positive(tree *p) {
	if (p != null) {
		if (p->info > 0)
			return 1 + Count(p->R) + Count(p->L);
		else
			return Count(p->R) + Count(p->L);
	}
	else return 0;
}



double Average(tree *p) {
	return sum_of_positive(p) / count_of_positive(p);
}

int main() {
	tree *t;
	int x;
	cin >> x;
	t = new tree;
	t->info = x;
	t->L = NULL;
	t->R = NULL;
	while (x != 0) {
		cin >> x;
		if (x != 0)
			ADDDDP(t, x);
	}
	print_sort(t);
	cout << Average(t);
	system("pause");
	return 0;
}

