#include <iostream>
#include <vector>

using namespace std;
void VectorOut(const vector<vector<float>>& matrix);		//вывод матрицы
int main()
{
	system("chcp 1251");

	vector < vector < float>> matrix = {		//исходная матрица
	{34, 9, -5, 1, 9},
	{0, 24, 5, -6, 8},
	{9, 8, 28, 2, -1},
	{-8, -8, -2, 34, 9},
	{9, 6, -4, -4, 35}
	};
	
	cout << "\nИсходная матрица:\n";
	VectorOut(matrix);

	vector<float> c = { 48, 62, 138, 50, 42 };		//результирующий столбец

	double eps = 0.001;								//точность эпсила

	int row = matrix.size();

	vector<float> Old_x(row, 0);					//вектор старых значений

	vector<float> New_x(row, 0);					//вектор новых значений
	
	cout << "Точность eps: " << eps<< "\n";

	int k = 1;										//номер итерации

	while (1)
	{
		for (int i = 0; i < row; i++)
		{
			float sum = c[i];
			for (int j = 0; j < matrix[i].size(); j++)
				if (i != j)
					sum -= matrix[i][j] * Old_x[j];
			New_x[i] = (1 / matrix[i][i]) * sum;	//вычисляем вектор новых значений
		}

		int flag = 0;
		for (int i = 0; i < Old_x.size(); i++)
		{
			if (abs(New_x[i] - Old_x[i]) < eps)
				flag++;
		}

		Old_x = New_x;

		if (flag == Old_x.size())
			break;
	}
	
	cout << "\nРезультат:\n";
	for (int i = 0; i < New_x.size(); i++)
		cout << New_x[i] << "  ";
	cout << "\n";

}
void VectorOut(const vector<vector<float>>& matrix)		//вывод матрицы
{
	cout << "\n";
	for (int i = 0; i < matrix.size(); i++) 
	{
		for (int j = 0; j < matrix[i].size(); j++) 
			printf_s("%7.2f", matrix[i][j]);
					
		cout << "\n";
	}
	cout << "\n";
}
//fksf,fcdm,d,dcfr