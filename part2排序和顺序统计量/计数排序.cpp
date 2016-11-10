// 计数排序.cpp : 
//A[]原始数组，B[]存放排序结果的输出，C[]存放位置（这里我称其为地址）
//稳定性：对两个相同的数来说，在输入数组中先出现的数，在输出数组中也位于前面

#include "stdafx.h"
#include "iostream"
using namespace std;
void couting_sort(int *A, int *B, int n, int k);

int main()
{
	cout << "计数排序demo：" << endl;
	int n,k;
	cout << "请输入数列长度:";
	cin >> n;
	cout << "请输入数值范围:";
	cin >> k;
	int *A = new int[n];
	int *B = new int[n];
	cout << "生成的随机数列:";
	for(int i=1;i<=n;i++)
	{
		A[i] = rand() % k;//初始化随机数组，范围[0,k）
		cout << "  " << A[i];
	}
	cout << endl;
	couting_sort(A, B, n, k);
	cout << "计数排序结果:";
	for (int i = 1;i <= n;i++)
	{
		cout << "  " << B[i];
	}
	cout << endl;
	return 0;
}

void couting_sort(int *A, int *B, int n,int k)
{
	int *C = new int[k+1];  //数列范围0~k，因此定义的数组长度为k+1（数组下标表示排序值，数组内容表示其存放的位置即地址）
	for (int i = 0;i <= k;i++)
		C[i] = 0;                   //初始化地址
	for (int j = 1;j <= n;j++)
		C[A[j]] = C[A[j]] + 1;//计数，即每个数出现的次数 如C[0]=1，说明0在数列中有1个；C[1]=2，说明1在数列中有两个；C[2]=3，说明2在数列中有三个
	for (int i = 1;i <= k;i++)
		C[i] = C[i] + C[i - 1];//计算地址，由小到大将各数出现的频次加起来得到该数的地址，接上面的例子：完成循环后C[0]=1，C[1]=3，C[2]=6，各自表面0,1,2在数列中的位置
	for (int j = n;j >= 1;j--)
	{
		B[C[A[j]]]=A[j];  //在B的相应位置存放排序值
		C[A[j]] = C[A[j]] - 1;//确保当下一个值等于A[j]时，该元素可以直接被放到输出数组中的A[j]的前一个位置，
		                              //如上例：若我们已完成一个数1的排序，即将其插入到B[3]，此时C[1]=3-1=2，于是遇到下一个数1时，我们将其插入到B[2]
		                             //这里j由n~1循环的，这就确保了计数排序是稳定的
	}

}

