// ��������.cpp : ����������汾�����κ���������A��0����ֵ��Ҳ���������й����в�����A[0]����������Aʱֱ�Ӷ�����һ������Ϊn+1�Ķ�̬����
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;
void quicksort(int *A, int p, int r);
int rand_partition(int *A, int p, int r);
int partition(int *A, int p, int r);

int main()
{
	int n;
	cout << "��������demo��" << endl;
	cout << "���������г��ȣ�";
	cin >> n;
	int *A = new int[n];
	cout << "���ɵ�������У�";
	for(int i=1;i<=n;i++)
	{
		A[i] = rand() % 50;
		cout << " " << A[i];
	}
	cout << endl;
	quicksort(A, 1, n);
	cout << "������������";
	for (int i = 1;i <= n;i++)
		cout << " " << A[i];
	cout << endl;
	return 0;
}

int partition(int *A, int p, int r)
{
	int x = A[r];    //ѡ����Ԫ
	int i = p - 1;    //��ʼ��i
	int mid;
	for (int j = p;j < r;j++)
	{
		if (A[j] <= x) //������̬���ڣ�ȷ����������
		{
			i = i + 1;
			mid = A[i];
			A[i] = A[j];
			A[j] = mid;
		}
	}
	mid = A[i + 1];
	A[i + 1] = A[r];
	A[r] = mid;      //����Ԫ������������ֵ��
	return i + 1;
}

int rand_partition(int *A, int p, int r)
{
	int mid, i = p + (rand() % (r - p + 1)); //����q-r��������������ѡȡ��Ԫ
	mid = A[r];
	A[r] = A[i];
	A[i] = mid;
	return partition(A, p, r);
}

void quicksort(int *A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = rand_partition(A, p, r);   //�������ѡȡ����Ԫ����������
		quicksort(A, p, q - 1);   //��������������������
		quicksort(A, q + 1, r);  //��������������������
	}
}