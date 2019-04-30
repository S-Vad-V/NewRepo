#include <iostream>
#include <string>
#define null NULL
/*
	6-� �����, 
	����� ���-�� ��������� ������ ������ ��. ���������������
	7-� 
	����� ����� ��������� ������ ������� max-min
	8-� �����
	����� ���-�� ������ ��������� ������ [a,b]

*/

using namespace std;

struct tree {
	int info;
	tree *R, *L;
};

#pragma region �� ������ ����
void ADDDDP(tree *p, int x) { // � - ������ �� ������ ������
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

int Max(tree *p) {
	while (p != null)
		p = p->R;
	return p->info;
}
int Min(tree *p) {
	while (p != null)
		p = p->L;
	return p->info;
}

int sum_of_tree(tree *p) {
	if (p != null) {
			return p->info + sum_of_tree(p->L) + sum_of_tree(p->R);
	}
	else return 0;
}
int count_of_tree(tree *p) {
	if (p != null) {
		if (p->info > 0)
			return 1 + Count(p->R) + Count(p->L);
		else
			return Count(p->R) + Count(p->L);
	}
	else return 0;
}



double Average(tree *p) {
	return sum_of_tree(p) / count_of_tree(p);
}

#pragma endregion

#pragma region 6-� �����

int Count_min_averege(tree *p, double ave) {
	if (p != null) {
		if (p->info < ave) {
			return 1 + Count_min_averege(p->L, ave) + Count_min_averege(p->R, ave);
		}
		else
			return Count_min_averege(p->L, ave) + Count_min_averege(p->R, ave);
	}
	else
		return 0;
}

void Six(tree *p) {
	cout << endl << Count_min_averege(p, Average(p));
}
#pragma endregion

#pragma region 7-� �����
void Seven(tree *p) {
	int min = Min(p), max = Max(p);
	cout << endl << Sum_Seven(p, max - min);
}

int Sum_Seven(tree *p, int a) {
	if (p != null) {
		if (p->info > a)
			return p->info + Sum_Seven(p, a) + Sum_Seven(p, a);
		else
			return Sum_Seven(p, a) + Sum_Seven(p, a);

	}
	else
		return 0;
}

#pragma endregion

#pragma region 8-� �����


#pragma endregion

#pragma region ������ ����
/*
	���� � ������ ������������ ���� �� 2 ������� 3 �������, �� ��������� ������ ��������� ������ � 2 ����
	����� �������� ��� ������� ��� �������� �� �������� ����� �
*/
void Second_Lesson_1(tree *p) {
	if (Count_of_three(p) > 2)
		Increase(p, 2);
	else {
		int x;
		cin >> x;
		Replecement(p, x);
	}
}

void Replecement(tree *p, int x) {
	// ������ ������
	if (p != null) {
		if (p->info % 3 == 0)
			p->info = x;
		Replecement(p->R, x);
		Replecement(p->L, x);
	}
}

void Increase(tree *p, int a) {
	if (p != null) {
		if (p->info % 2 == 0) 
			p->info *= a;
		Increase(p->R, a);
		Increase(p->L, a);
		
	}
}


int Count_of_three(tree *p) {
	if (p != null) {
		if (p->info % 3 == 0)
			return 1 + Count_of_three(p->R) + Count_of_three(p->L);
		else
			return Count_of_three(p->R) + Count_of_three(p->L);
	}
	else
		return 0;
}
/*
	���� ��� �������� ������ �� ������ 4-�
	�� ��������� ������������� �������� �� ������� �������� ��������� ������
 */

void Second_Lesson_2(tree *p) {
	if (Multiplisity(p, 3) == 0)
		Decrees(p, Average(p));
	print_sort(p);
}

void Decrees(tree *p, int a, bool is_positive) {
	// ��������� ��� �������� �� �������� �������� "�"
	// ���� ������������� is_positive = true
	// ���� ���, �� �������� ��� is_positive
	if (p != null) {
		if ((p->info > 0)^is_positive) {
			p->info -= a;
			Decrees(p->L, a, is_positive);
			Decrees(p->R, a, is_positive);
		}
	}
}void Decrees(tree *p, int a) {
	// ��������� ��� �������� �� �������� �������� "�"
	if (p != null) {		
			p->info -= a;
			Decrees(p->L, a);
			Decrees(p->R, a);		
	}
}

int Multiplisity(tree *p, int del) {
	// ���������� ���-�� ��������� ������� del
	if (p != null) {
		if (p->info % del == 0)
			return 1 + Multiplisity(p->R, del) + Multiplisity(p->L,del);
		else
			return Multiplisity(p->R,del) + Multiplisity(p->L,del);
	}
	else
		return 0;

}

/*
	���� ��� �������� ������ ������ 7, �� �������� ������������� �������� �� ��������, �����
	��������� ��� �������� �� �������� ������������.

*/
void Second_Lesson_3(tree *p) {
	if (Multipasity_bool(p, 7))
		Replecement_abs(p);
	else
		Decrees(p, Min(p));

}

void Replecement_abs(tree *p) {
	// ������ ������
	if (p != null) {
		if (p->info < 0)
			p->info = abs(p->info);
		Replecement(p->R, abs(p->info));
		Replecement(p->L, abs(p->info));
	}
}

bool Multipasity_bool(tree *p, int del) {
	// ���� ��� �������� ������ del ������� true, false ����� 
	if (p != null) {
		if (p->info % del == 0)
			return (true && Multipasity_bool(p->R, del) && Multipasity_bool(p->L, del));
		else
			return false;
	}
	return true;
}
#pragma endregion


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
	Six(t);
	Seven(t);
	system("pause");
	return 0;
}

