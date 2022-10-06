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
	//Задача 1
	//	Создайте массив из 10 элементов.Напишите программу, которая поменяет местами всё чётные и
	//	нечётные элементы массива.Элемент, стоящий на позиции 0 меняется значениями с элементом позиции 1.
	//	Элемент на позиции 2 меняется с элементом позиции 3 и т.д.Обращение к элементам массива реализуйте с
	//	помощью переменной - указателя на нулевой элемент массива.
	
	std::cout << "Задача 1.\n";
	const int size = 10;
	int arr[size];
	fill_arr(arr, size, 0, 10);
	std::cout << "Начальный массив:\n";
	show_arr(arr, size);
	sort_odd_even(arr, size);
	std::cout << "Итоговый массив:\n";
	show_arr(arr, size);
	
	//Задача 2
	//	Создайте функцию типа void, которая принимает адрес переменной и какое - нибудь число.Переменная,
	//	адрес которой был передан, возводится в степень, равную переданному числу.Задачу необходиморешить,
	//  не прибегая к использованию функций, встроенных в язык программирования С++.
	std::cout << "Задача2\nВведите число:\n";
	std::cin >> n;
	std::cout << "Введите в какую степень возвести число:\n";
	std::cin >> m;
	my_pow(&n, m);
	std::cout<<"Поллученный результат: "<<n << "\n";
	return 0;
}
//заполнение массива
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % end;
}
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//меняет местами четные и нечетные элементы массива
template <typename T>
void sort_odd_even(T arr[], const int length) {
	for (int i = 0; i < length; i+=2)
		std::swap(*(arr+i),*(arr+1+i));
}
//возведение в степень
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