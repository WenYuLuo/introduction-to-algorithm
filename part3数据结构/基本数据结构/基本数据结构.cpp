// �������ݽṹ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "stack.h"

using namespace std;

int main()
{
	cout << "ջ��"<<endl;
	int size;
	cout << "      �����ʼ��ջ���ȣ�";
	cin >> size;
	int *P = new int[size+1];
	cout << "                  ��ʼ��ջ��";
	for(int i=1;i<=size;i++)
	{
		P[i] = rand() % 10;
	}
	//for (int i = 1;i <= size;i++)
	//	cout << "  " << P[i];
	//cout << endl;
	stack sta(P, size);
	sta.show();
	cout << "                  ջ�շ񣿣�" << sta.isempty() << endl;
	cout << "                        ��ջ��"<<sta.pop()<<endl;
	cout << "                        ��ջ��";
	int x;
	cin >> x;
	sta.push(x);
	cout << "                  ��ջ�����";
	sta.show();

	delete[] P;
	//sta.free();
	return 0;
}

