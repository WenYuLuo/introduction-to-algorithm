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
	for(i=0;i<m;i++)                      //生成随机序列
	{
		A[i] = rand() % 1000;
		cout << "   " << A[i] ;
	}
	cout << endl;
	merge(A, 0, m-1);                 //调用归并排序
	cout << "归并排序结果\n";
	for(j=0;j<m;j++)
	{
		cout <<"   "<< A[j] ;
	}
	cout << endl;
	delete [] A;
    return 0;
}



void merge(int *A, int p, int r)   //归并排序算法
{
	if (p<r)                                      //判断序列长度是否为1，若为1则不再继续分治
	{
		int q;
		q = int((p + r) / 2);               //找到序列中点
		merge(A, p, q);                   //左序列递归分治
		merge(A, q + 1, r);             //右序列递归分治
		merge_sort(A, p, q, r);      //归并排序，由最小单位1开始回溯，即自底向上推进
	}
}


void merge_sort(int *A, int p, int q, int r)
{
	int n_1 = q - p + 1;                //左序列长度
	int n_2 = r - q;                       //右序列长度
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
	delete[] L;                 //删除预分配动态内存
	delete[] R;
}
