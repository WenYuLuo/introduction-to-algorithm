// 基本数据结构.cpp : this running well.
//定义数组，未使用new。

#include "stdafx.h"
#include "iostream"
#include "stack.h"

using namespace std;

int main()
{
	cout << "栈："<<endl;
	int size;
	cout << "      输入初始化栈长度：";
	cin >> size;
	int P[30];
	P[0] = 0;
	cout << "        初始化栈：";
	for(int i=1;i<=size;i++)
	{
		P[i] = rand() % 10;
	}
	//for (int i = 1;i <= size;i++)
	//	cout << "  " << P[i];
	//cout << endl;
	stack sta(P, size);
	sta.show();
	cout << "       栈空否？：" << sta.isempty() << endl;
	cout << "       出栈："<<sta.pop()<<endl;
	cout << "       堆栈：";
	int x;
	cin >> x;
	sta.push(x);
	cout << "      堆栈结果：";
	sta.show();

    //delete[] P;
	//P = NULL;
	//sta.~stack();
	//sta.free();
	return 0;
}

