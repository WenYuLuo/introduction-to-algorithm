// ��������.cpp : ע��C++��������0��ʼ��
//new �� delete ������ʹ�ã���ֹ�ڴ�й©��

#include "stdafx.h"
#include "iostream" 
#include "stdlib.h" 
using namespace std;
int main()
{
	int j, i, key, m, n;
	cout << "�������������" << endl;
	cin >> m;
	int *A = new int[m];
	cout << "�������������" << endl;
	for (n = 0;n <= m-1;n++)
	{
		A[n] = rand() % 1000;
		cout << A[n] << " ";
	}
	cout << endl;
	for (j = 1; j <= m-1; j++)
	{
		key = A[j];
		//��A[j]�����ź����A[1...j-1]
		i = j - 1;
		while (i >= 0 && A[i] > key)   //�Ƚ�A[i + 1]��A[i]������Ϊ����
		{
			A[i + 1] = A[i];       //��˽���������A[i + 1]
			i = i - 1;             //Ŀ�Ļ��ݼ��
		}
		A[i + 1] = key;
	}

	cout << "����������" << endl;

	for (n = 0;n <= m-1;n++)
	{
		cout << A[n] << " ";
	}
	cout << endl;
	delete[] A;
	return 0;
}
