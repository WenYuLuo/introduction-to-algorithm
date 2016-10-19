// �鲢����.cpp : ���β���
//��Ҫע����ǣ�����û�в��õ�������������ڱ�����Ϊ�����ƶѡ�����ı�ǣ�����ÿ�Ρ����ơ�
//�������о���������Ҫ�ǲ�֪�����ʵ�֣�����ϣ���������ܹ������Ľ�������������C++����
//A[0]��ʾ��һ��Ԫ�أ���˻�������α������Ҫ����һЩ���ġ�

#include "stdafx.h"
#include "iostream" 
#include "stdlib.h"
using namespace std;
void merge_sort(int *A, int p, int q, int r);
void merge(int *A, int p, int r);


int main()
{
	int i,j,m;
	cout << "�������������:  " ;
	cin >> m;
	int *A = new int[m];
	cout << "���ɵ��������\n";
	for(i=0;i<m;i++)
	{
		A[i] = rand() % 1000;
		cout << "   " << A[i] ;
	}
	cout << endl;
	merge(A, 0, m-1);
	cout << "�鲢������\n";
	for(j=0;j<m;j++)
	{
		cout <<"   "<< A[j] ;
	}
	cout << endl;
	delete [] A;
    return 0;
}



void merge(int *A, int p, int r)
{
	if (p<r)
	{
		int q;
		q = int((p + r) / 2);
		merge(A, p, q);
		merge(A, q + 1, r);
		merge_sort(A, p, q, r);
	}
}


void merge_sort(int *A, int p, int q, int r)
{
	int n_1 = q - p + 1;
	int n_2 = r - q;
	int i, j;
	int *L = new int[n_1], *R = new int[n_2];//���������鳤��
	for (i = 0;i < n_1;i++)
	{
		L[i] = A[p + i ];
	}
	for (j = 0;j < n_2;j++)
	{
		R[j] = A[q + j+1];
	}
	i = 0, j = 0;
	for (int k = p;k <= r;k++) //��ʼ�鲢����
	{
		if (i >= n_1)            //�ж�L�����Ƿ�ȫ�����ƻ�A
		{
			A[k] = R[j];
			j = j + 1;
			continue;
		}
		else if (j >= n_2)    //�ж�R�����Ƿ�ȫ�����ƻ�A
		{
			A[k] = L[i];
			i = i + 1;
			continue;
		}
		else if (L[i] >= R[j])  //����δ���꣬�Ƚ������鶥�����ִ�С��ȡС�����ƻ�A����
		{
			A[k] = R[j];
			j = j + 1;
		}
		//if j>n_1
		else
		{
			A[k] = L[i];
			i = i + 1;
		}
	}
	delete[] L;
	delete[] R;
}
