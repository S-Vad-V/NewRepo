#include <iostream>
#include <string>
#include <fstream>
#define null NULL
#define BUF_SIZE 10
/*
	„исло компонент файла целых чисел кратно 10, нудно переписать компоненты файла в новый файл,
	измен€€ пор€док чисел в каждой дес€тке, так чтоб сначала шли все отрицательные числа,
	а потом все неотрицательные

	ѕереписать из одного файла в другой все числа без повторений
*/

using namespace std;

#pragma region First
void Fake_Sort(int *a) {
	int count = 0;
	for (int i = 0; i < BUF_SIZE; i++)
	{
		if (a[i] < 0) {
			swap(a[i], a[count]);
			count++;
		}
	}
}

void First() {
	const string path_for_read1 = "input1.txt";
	const string path_for_read2 = "input1.txt";
	const string path_for_write = "out.txt";

	ifstream file1(path_for_read1);
	ifstream file2(path_for_read2);

	ofstream out(path_for_write);

	int buf[BUF_SIZE];
	int a;
	while (!file1.eof()) {
		for (int i = 0; i < BUF_SIZE; ++i)
			file1 >> buf[i];
		Fake_Sort(buf);
		for (int i = 0; i < BUF_SIZE; ++i)
			out << buf[i] << " ";
	}
	file1.close();
	out.close();
}
#pragma endregion

#pragma region Second

void Second() {
	const string path_for_read1 = "input1.txt";
	const string path_for_read2 = "input1.txt";
	const string path_for_write = "out.txt";

	ifstream file1(path_for_read1);
	ifstream file2(path_for_read2);

	ofstream out(path_for_write);

	int size = sizeof(file1) - 1;
	int *buf = new int[size];
	int a;
	for (int i = 0; !file1.eof(); ++i)
		file1 >> buf[i];
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j)
			if (buf[i] > buf[j])
				swap(buf[i], buf[j]);
	for (int i = 1; i < size; i++)
		if (buf[i] != buf[i - 1])
			out << buf[i] << " ";
	file1.close();
	out.close();
}
#pragma endregion


int main() {
	Second();
	//system("pause");
	return 0;
}

