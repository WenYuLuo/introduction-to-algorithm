// 插入排序.cpp : 注意C++中数组由0开始。
//new 与 delete 需配套使用，防止内存泄漏。

#include "stdafx.h"
#include "iostream" 
#include "stdlib.h" 
using namespace std;
int main()
{
	int j, i, key, m, n;
	cout << "输入随机数个数" << endl;
	cin >> m;
	int *A = new int[m];
	cout << "生成随机数序列" << endl;
	for (n = 0;n <= m-1;n++)
	{
		A[n] = rand() % 1000;
		cout << A[n] << " ";
	}
	cout << endl;
	for (j = 1; j <= m-1; j++)
	{
		key = A[j];
		//将A[j]插入排好序的A[1...j-1]
		i = j - 1;
		while (i >= 0 && A[i] > key)   //比较A[i + 1]与A[i]，这里为升序。
		{
			A[i + 1] = A[i];       //因此将大数置于A[i + 1]
			i = i - 1;             //目的回溯检测
		}
		A[i + 1] = key;
	}

	cout << "返回排序结果" << endl;

	for (n = 0;n <= m-1;n++)
	{
		cout << A[n] << " ";
	}
	cout << endl;
	delete[] A;
	return 0;
}
