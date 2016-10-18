// 插入排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <stdlib.h> 
using namespace std;
int main()
{
	int j, i, key, m, n;
	cout << "输入随机数个数" << endl;
	cin >> m;
	int *A = new int[m];
	cout << "生成随机数序列" << endl;
	for (n = 1;n <= m;n++)
	{
		A[n] = rand() % 1000;
		cout << A[n] << " ";
	}
	cout << endl;
	for (j = 2; j <= m; j++)
	{
		key = A[j];
		//将A[j]插入排好序的A[1...j-1]
		i = j - 1;
		while (i > 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}

	cout << "返回排序结果" << endl;

	for (n = 1;n <= m;n++)
	{
		cout << A[n] << " ";
	}
	cout << endl;
	return 0;
}