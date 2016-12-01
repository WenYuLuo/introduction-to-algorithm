// 基本数据结构.cpp : this running well.
//定义数组，未使用new。
//更新了队列实现。

#include "stdafx.h"
#include "iostream"
#include "stack.h"
#include "queue.h"
#define sizearr 12
using namespace std;

int main()
{
	cout << "栈："<<endl;
	cout << "本程序利用长度为30的数组实现队列。" << endl;
	int size;
	cout << "      输入初始化栈长度：";
	cin >> size;
    /////加入一些边界判断
	while (size>30)
	{
		cout << "input error,please input again:";
		cin >> size;
	}
	int P[30];
	P[0] = 0;
	cout << "初始化栈：";
	for(int i=1;i<=size;i++)
	{
		P[i] = rand() % 10;
	}
	//for (int i = 1;i <= size;i++)
	//	cout << "  " << P[i];
	//cout << endl;
	stack sta(P, size);
	sta.show();
	cout << " 栈空否？：" << sta.isempty() << endl;
	cout << " 出栈："<<sta.pop()<<endl;
	cout << " 堆栈：";
	int x;
	cin >> x;
	sta.push(x);
	cout << "堆栈结果：";
	sta.show();

    //delete[] P;
	//P = NULL;
	//sta.~stack();
	//sta.free();
	cout << "队列：" << endl;
	cout << "本程序利用长度为12的数组实现队列。" << endl;
	//int P[sizearr];
	int head;
	int tail;
	cout << "初始化队列：" << endl;
	cout << "请输入队头（<11）:";
	cin >> head;
	while(head>11)
	{
		cout << "input error,please input again:";
		cin >> head;
	}
	cout << "请输入队尾（<11）:";
	cin >> tail;
	while (tail>11)
	{
		cout << "input error,please input again:";
		cin >> tail;
	}
	queue que(head, tail);
	cout << "初始化队列：";
	que.show();
	cout << "入队：";
	int M;
	cin >> M;
	que.enqueue(M);
	cout << "当前队列： ";
	que.show();
	cout << "出队： " << que.dequeue()<<endl;
	cout << "当前队列： ";
	que.show();



	return 0;
}

