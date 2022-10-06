#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void sort_odd_even(T arr[], const int length);
void my_pow(int*num,int pow);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//������ 1
	//	�������� ������ �� 10 ���������.�������� ���������, ������� �������� ������� �� ������ �
	//	�������� �������� �������.�������, ������� �� ������� 0 �������� ���������� � ��������� ������� 1.
	//	������� �� ������� 2 �������� � ��������� ������� 3 � �.�.��������� � ��������� ������� ���������� �
	//	������� ���������� - ��������� �� ������� ������� �������.
	
	std::cout << "������ 1.\n";
	const int size = 10;
	int arr[size];
	fill_arr(arr, size, 0, 10);
	std::cout << "��������� ������:\n";
	show_arr(arr, size);
	sort_odd_even(arr, size);
	std::cout << "�������� ������:\n";
	show_arr(arr, size);
	
	//������ 2
	//	�������� ������� ���� void, ������� ��������� ����� ���������� � ����� - ������ �����.����������,
	//	����� ������� ��� �������, ���������� � �������, ������ ����������� �����.������ ����������������,
	//  �� �������� � ������������� �������, ���������� � ���� ���������������� �++.
	std::cout << "������2\n������� �����:\n";
	std::cin >> n;
	std::cout << "������� � ����� ������� �������� �����:\n";
	std::cin >> m;
	my_pow(&n, m);
	std::cout<<"����������� ���������: "<<n << "\n";
	return 0;
}
//���������� �������
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % end;
}
//����� �������
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//������ ������� ������ � �������� �������� �������
template <typename T>
void sort_odd_even(T arr[], const int length) {
	for (int i = 0; i < length; i+=2)
		std::swap(*(arr+i),*(arr+1+i));
}
//���������� � �������
void my_pow( int*num,int pow) {
	int n = *num;
	if (pow <= 0)
		*num = 1;
	else
		while (pow > 1) {
			*num *= n;
			pow -= 1;
		}
}