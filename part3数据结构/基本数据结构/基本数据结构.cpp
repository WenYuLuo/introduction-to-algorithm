// �������ݽṹ.cpp : this running well.
//�������飬δʹ��new��
//�����˶���ʵ�֡�

#include "stdafx.h"
#include "iostream"
#include "stack.h"
#include "queue.h"
#define sizearr 12
using namespace std;

int main()
{
	cout << "ջ��"<<endl;
	cout << "���������ó���Ϊ30������ʵ�ֶ��С�" << endl;
	int size;
	cout << "      �����ʼ��ջ���ȣ�";
	cin >> size;
    /////����һЩ�߽��ж�
	while (size>30)
	{
		cout << "input error,please input again:";
		cin >> size;
	}
	int P[30];
	P[0] = 0;
	cout << "��ʼ��ջ��";
	for(int i=1;i<=size;i++)
	{
		P[i] = rand() % 10;
	}
	//for (int i = 1;i <= size;i++)
	//	cout << "  " << P[i];
	//cout << endl;
	stack sta(P, size);
	sta.show();
	cout << " ջ�շ񣿣�" << sta.isempty() << endl;
	cout << " ��ջ��"<<sta.pop()<<endl;
	cout << " ��ջ��";
	int x;
	cin >> x;
	sta.push(x);
	cout << "��ջ�����";
	sta.show();

    //delete[] P;
	//P = NULL;
	//sta.~stack();
	//sta.free();
	cout << "���У�" << endl;
	cout << "���������ó���Ϊ12������ʵ�ֶ��С�" << endl;
	//int P[sizearr];
	int head;
	int tail;
	cout << "��ʼ�����У�" << endl;
	cout << "�������ͷ��<11��:";
	cin >> head;
	while(head>11)
	{
		cout << "input error,please input again:";
		cin >> head;
	}
	cout << "�������β��<11��:";
	cin >> tail;
	while (tail>11)
	{
		cout << "input error,please input again:";
		cin >> tail;
	}
	queue que(head, tail);
	cout << "��ʼ�����У�";
	que.show();
	cout << "��ӣ�";
	int M;
	cin >> M;
	que.enqueue(M);
	cout << "��ǰ���У� ";
	que.show();
	cout << "���ӣ� " << que.dequeue()<<endl;
	cout << "��ǰ���У� ";
	que.show();



	return 0;
}

