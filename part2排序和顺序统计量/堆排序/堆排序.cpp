// ������.cpp : ����ע�������C++��������λΪ0����Ӧ��Ҳ���Ժ�����һ�㣬�����ڷ����ڴ���ʱ�����һλ���������й�����û�ж���λ������
//Ϊ�˱��ڵ��ã������˶��ࣨheap��

#include "stdafx.h"
#include "heap.h"
#include "iostream"
using namespace std;

int main()
{
	int n;
	cout << "�������г��ȣ�";
	cin >> n;
	cout << endl;
	int *P = new int[n];
	for (int i = 0;i < n;i++)
	{
		P[i] = rand() % 50;  //����0��50��α�����
//		cout << "  " << P[i];
	}
//	cout << endl;
	heap heap1 = { P,n,n };
	cout << "�������У�";
	heap1.show();
	heap1.heapsort();
	cout << "��������";
	heap1.show();
	return 0;
}

