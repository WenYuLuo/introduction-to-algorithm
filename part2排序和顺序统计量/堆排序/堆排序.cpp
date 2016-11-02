// 堆排序.cpp : 必须注意的是在C++中数组首位为0，（应该也可以忽略这一点，等于在分配内存是时多分配一位，且在运行过程中没有对零位操作）
//为了便于调用，创建了堆类（heap）

#include "stdafx.h"
#include "heap.h"
#include "iostream"
using namespace std;

int main()
{
	int n;
	cout << "输入序列长度：";
	cin >> n;
	cout << endl;
	int *P = new int[n];
	for (int i = 0;i < n;i++)
	{
		P[i] = rand() % 50;  //生成0—50的伪随机数
//		cout << "  " << P[i];
	}
//	cout << endl;
	heap heap1 = { P,n,n };
	cout << "生成序列：";
	heap1.show();
	heap1.heapsort();
	cout << "排序结果：";
	heap1.show();
	return 0;
}

