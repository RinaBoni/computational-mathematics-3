#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;

template <typename T>
void Show_Vector(vector<T> arr); //Вывод на экран

template <typename T>
void Fill_Rand_Vector(vector < vector < T>>& Mtr); //Заполнение рандомом

template <typename T>
void Change_Rows(vector < vector < T>>& Mtr, int row); //Смена строк


template <typename T>
void Fill_Vector(vector<T>& arr);					//Заполнение вектора случайными числами

int main()
{
	system("chcp 1251");

	int n;
	cout << "Кол-во строк:";
	cin >> n;

	vector<float> a(n);

	vector<float> b(n);

	vector<float> c(n);

	vector<float> f(n);
	//Заполнение векторов
	srand(time(nullptr));
	for (int i = 0; i < a.size(); i++)
	{
		//arr[i].push_back(rand() % 100);
		a[i] = rand() % 100;
	}
	for (int i = 0; i < b.size(); i++)
	{
		//arr[i].push_back(rand() % 100);
		b[i] = rand() % 100;
	}
	for (int i = 0; i < c.size(); i++)
	{
		//arr[i].push_back(rand() % 100);
		c[i] = rand() % 100;
	}
	for (int i = 0; i < f.size(); i++)
	{
		//arr[i].push_back(rand() % 100);
		f[i] = rand() % 100;
	}
	cout << "a:\n";
	Show_Vector(a);
	cout << "b:\n";
	Show_Vector(b);
	cout << "c:\n";
	Show_Vector(c);
	cout << "f:\n";
	Show_Vector(f);

	vector<float> y(n);
	vector<float> A(n);
	vector<float> B(n);
	vector<float> result(n);



	//Вычисления
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			//y1
			y[0] = b[0];
			//A1
			A[0] = (-1) * c[0] / y[0];
			//B1
			B[i] = f[0] / y[0];
			continue;
		}

		y[i] = b[i] + a[i] * A[i - 1];
		A[i] = (-1) * c[i] / y[i];
		B[i] = (f[i] - a[i] * B[i - 1]) / y[i];
	}

	//Результирующий вектор
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			result[i] = B[i];
			continue;
		}
		result[i] = A[i] * result[i + 1] + B[i];

	}
	cout << "\nРезультирующий:\n";
	Show_Vector(result);


	//srand(time(NULL));
	/*Fill_Vector(a);

	Fill_Vector(b);
	Fill_Vector(c);
	Fill_Vector(f);*/



	/*vector < vector < double>> A;
	int row, col;
	do {
		cout << "Кол-во строк:";
		cin >> row;
	} while (row <= 0);

	do {
		cout << "Кол-во столбцов:";
		cin >> col;
	} while (col <= 0);

	A.resize(row);
	for (int i = 0; i < row; i++) //Выделение памяти под матрицу
	{
		A[i].resize(col);
	}

	Fill_Rand_Vector(A);
	Show_Vector(A);*/
}

template <typename T>
void Fill_Vector(vector<T>& arr) {					//Заполнение вектора случайными числами
	srand(time(nullptr));
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].push_back(rand() % 100);
		//arr[i] = rand() % 100;
	}
}

template <typename T>
void Change_Rows(vector < vector < T>>& Mtr, int row) { //Смена строк

	for (int i = row; i < Mtr.size(); i++) {

		if (Mtr[i][row] != 0) { //если нашли не нулевой элемент
			swap(Mtr[row], Mtr[i]);

			break; //и выходим из функции
		}
	}
}

template <typename T>
void Fill_Rand_Vector(vector < vector < T>>& Mtr) {
	srand(time(nullptr));
	for (int i = 0; i < Mtr.size(); i++)
	{
		for (int j = 0; j < Mtr[i].size(); j++)
		{
			if (fabs(j - i) <= 1 || j == Mtr[i].size() - 1) {
				Mtr[i][j] = rand() % 10;
			}
			else {
				Mtr[i][j] = 0;
			}
		}
	}
}

template <typename T>
void Show_Vector(vector <T> arr) {

	for (int i = 0; i < arr.size(); i++)
	{
		printf_s("%7.2f", arr[i]);
	}
	cout << "\n";
}
