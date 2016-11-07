// 快速排序.cpp : 采用了随机版本，本次忽略了序列A【0】的值，也就是在运行过程中不考虑A[0]。定义序列A时直接定义了一个长度为n+1的动态数组
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;
void quicksort(int *A, int p, int r);
int rand_partition(int *A, int p, int r);
int partition(int *A, int p, int r);

int main()
{
	int n;
	cout << "快速排序demo：" << endl;
	cout << "请输入序列长度：";
	cin >> n;
	int *A = new int[n];
	cout << "生成的随机序列：";
	for(int i=1;i<=n;i++)
	{
		A[i] = rand() % 50;
		cout << " " << A[i];
	}
	cout << endl;
	quicksort(A, 1, n);
	cout << "快速排序结果：";
	for (int i = 1;i <= n;i++)
		cout << " " << A[i];
	cout << endl;
	return 0;
}

int partition(int *A, int p, int r)
{
	int x = A[r];    //选定主元
	int i = p - 1;    //初始化i
	int mid;
	for (int j = p;j < r;j++)
	{
		if (A[j] <= x) //滑动动态窗口，确定左右序列
		{
			i = i + 1;
			mid = A[i];
			A[i] = A[j];
			A[j] = mid;
		}
	}
	mid = A[i + 1];
	A[i + 1] = A[r];
	A[r] = mid;      //将主元交换至序列中值处
	return i + 1;
}

int rand_partition(int *A, int p, int r)
{
	int mid, i = p + (rand() % (r - p + 1)); //生成q-r的随机数，即随机选取主元
	mid = A[r];
	A[r] = A[i];
	A[i] = mid;
	return partition(A, p, r);
}

void quicksort(int *A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = rand_partition(A, p, r);   //利用随机选取的主元，划分序列
		quicksort(A, p, q - 1);   //迭代划分左序列至触底
		quicksort(A, q + 1, r);  //迭代划分右序列至触底
	}
}