// 归并排序.cpp : 分治策略
//需要注意的是，这里没有采用到书中所引入的哨兵牌作为“子牌堆”抽完的标记，而是每次“抽牌”
//都作了判决（这里主要是不知道如何实现，所以希望有朋友能够帮助改进）。另外由于C++数组
//A[0]表示第一个元素，因此基于书中伪代码需要做出一些更改。

#include "stdafx.h"
#include "iostream" 
#include "stdlib.h"
using namespace std;
void merge_sort(int *A, int p, int q, int r);
void merge(int *A, int p, int r);


int main()
{
	int i,j,m;
	cout << "输入随机数个数:  " ;
	cin >> m;
	int *A = new int[m];
	cout << "生成的随机序列\n";
	for(i=0;i<m;i++)
	{
		A[i] = rand() % 1000;
		cout << "   " << A[i] ;
	}
	cout << endl;
	merge(A, 0, m-1);
	cout << "归并排序结果\n";
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
	int *L = new int[n_1], *R = new int[n_2];//分配子数组长度
	for (i = 0;i < n_1;i++)
	{
		L[i] = A[p + i ];
	}
	for (j = 0;j < n_2;j++)
	{
		R[j] = A[q + j+1];
	}
	i = 0, j = 0;
	for (int k = p;k <= r;k++) //开始归并抽牌
	{
		if (i >= n_1)            //判断L数组是否全部复制回A
		{
			A[k] = R[j];
			j = j + 1;
			continue;
		}
		else if (j >= n_2)    //判断R数组是否全部复制回A
		{
			A[k] = L[i];
			i = i + 1;
			continue;
		}
		else if (L[i] >= R[j])  //若均未抽完，比较子数组顶端数字大小，取小数复制回A数组
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
