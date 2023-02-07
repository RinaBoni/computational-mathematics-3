#include <iostream>

using namespace std;

int main()
{
	const int m = 5, n = m + 1;
	double buf = 0;
	double ar[m][n] = {
	{-0.49, 0.12, -0.82, 0.53, 0.17, -0.42},
	{0.85, 0.23, 0.04,-0.39, 0.69, 0.29},
	{0.76, 0.67, 0.91, 0.16, 0, -0.66},
	{-0.67, -0.76, -0.6, 0.39, 0.22, -0.47},
	{-0.25, 0.62, 0.79, -0.13, -0.35, 0.95}
	};

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<< ar[i][j] << "\t";
		}
		cout << endl;
	}

	for (int k = 0; k < m; k++)
	{
		if (fabs(ar[k][k]) < 0.0000001)
		{
			int o = k++;
			while ((fabs(ar[o][k]) > 0.0000001) || (o > m))
			{
				for (int l = 0; l < n; l++)
				{
					buf = ar[k][l];
					ar[k][l] = ar[o][l];
					ar[o][l] = buf;
					buf = 0;
				};
				o++;
			}
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = k + 1; j < n; j++)
				{
					if ((i != k) && (j > k))
					{
						ar[i][j] = (ar[i][j] * ar[k][k] - ar[i][k] * ar[k][j]) / ar[k][k];
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i != k)
			{
				ar[i][k] = 0;
			}
		}
		for (int j = n - 1; j >= k; j--)
		{
			ar[k][j] = ar[k][j] / ar[k][k];
		}

	}

	/*for (int i = 0; i < m; i++)
	{
	for (int j = 0; j < n; j++)
	{
	cout << ar[i][j] <<
	}
	}*/
	cout << "\nresult" << endl;
	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ar[i][j] << "\t";
		}
		cout << endl;
	}

}