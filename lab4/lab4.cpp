#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

void FillVector(vector<float>& vec);
void VectorOut(vector<float>& vec);

int main()
{
	system("chcp1251");

	int n;
	cout << "Количество строк";
	cin >> n;

	vector<float> a(n);
	vector<float> b(n);
	vector<float> c(n);
	vector<float> f(n);

	//заполнение векторов
	FillVector(a);
	FillVector(b);
	FillVector(c);
	FillVector(f);

	//вывод векторов
	cout << "a:" << endl;
	VectorOut(a);
	cout << "b:" << endl;
	VectorOut(b);
	cout << "c:" << endl;
	VectorOut(c);
	cout << "f:" << endl;
	VectorOut(f);

	vector<float> A(n);		//вектор альфа
	vector<float> B(n);		//вектор бета 
	vector<float> z(n);		//вектор, который будет в знаменателе

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			z[0] = c[0];
			A[0] = (-1) * b[0] / z[0];
			B[0] = f[0] / z[0];
			continue;
		}
		
		A[i] = 6;
	}
}

void FillVector(vector<float>& vec)
{
	srand(time(nullptr));
	for (int i = 0; i < vec.size(); i++)
		vec[i] = rand() % 100;
}

void VectorOut(vector<float>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		printf_s("%7.2f", vec[i]);
}