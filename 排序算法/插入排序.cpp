// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> 
#include <stdlib.h> 
using namespace std;
int main()
{
	int j, i, key, m, n;
	cout << "�������������" << endl;
	cin >> m;
	int *A = new int[m];
	cout << "�������������" << endl;
	for (n = 1;n <= m;n++)
	{
		A[n] = rand() % 1000;
		cout << A[n] << " ";
	}
	cout << endl;
	for (j = 2; j <= m; j++)
	{
		key = A[j];
		//��A[j]�����ź����A[1...j-1]
		i = j - 1;
		while (i > 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}

	cout << "����������" << endl;

	for (n = 1;n <= m;n++)
	{
		cout << A[n] << " ";
	}
	cout << endl;
	return 0;
}