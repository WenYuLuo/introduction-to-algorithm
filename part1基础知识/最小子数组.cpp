// 最小子数组.cpp : 分治策略求解
//因为C++语言一个函数无法返回多个值，所以我用全局变量来定义每个函数的返回值
//本人对C++语言的使用尚处在初级阶段，这里采用了较为低级的方法.

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
#include "math.h"
using namespace std;
void find_max_crossing_subarray(int *A, int low, int mid, int high);
void find_maximum_subarray(int *A, int low, int high);
int max_left, max_right, max_sum;
//int left_low, left_high, left_sum;
//int right_low, right_high, right_sum;
int low1, high1, sum1;          //定义全局变量,用于存函数的返回值。
                                               //每次递归我们把值送给形参进行操作，因此每次递归迭代全局变量的更新不影响运行结果。

int main()
{
	int  m, n;
	cout << "输入随机数个数" << endl;
	cin >> m;
	int *A = new int[m];
	cout << "生成随机数序列" << endl;
	for (n = 0;n <= m - 1;n++)
	{
		A[n] = -floor((100*rand())/RAND_MAX)+50;  //生成的伪随机数范围在[-50,50]
		cout << A[n] << " ";
	}
	cout << endl;
	//int low, high, sum;
	find_maximum_subarray(A, 0, m - 1);
	cout << "最大子数组坐标：\n起点:  " << low1+1                            //输出结果
		     << "   终点:  " << high1+1 << "   最大子数组之和：  "<<sum1<<endl;
	delete[] A;
    return 0;                             
}

void find_max_crossing_subarray(int *A, int low, int mid, int high)
{
	int left_sum = -10000, right_sum = -10000, sum = 0;   //初始足够小的left_sum和right_sum
	int i, j;
	//int max_left, max_right;
	for(i=mid;i>=low;i--)                                                          //计算中点以左序列的最大子数组
	{
		sum = sum + A[i];
		if(sum>left_sum)                                                        
		{
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for(j=mid+1;j<=high;j++)                                              //计算中点以右序列的最大子数组
	{
		sum = sum + A[j];
		if(sum>right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	max_sum = left_sum + right_sum;                             //计算跨越中点的子数组最大和
}


void find_maximum_subarray(int *A, int low, int high)  //分治递归最大子数组
{
	int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;
	int mid;
	if (high == low)
	{
		low1 = low, high1 = high, sum1 = A[low];
	//	return(low, high, A[low]);
	}
	else
	{
		mid = floor((low + high) / 2);
		find_maximum_subarray(A, low, mid);       //寻找左侧最大子数组（递归至触底）
		left_low = low1, left_high = high1, left_sum = sum1;
        find_maximum_subarray(A, mid+1, high);  //寻找右侧最大子数组（递归至触底）
		right_low = low1, right_high = high1, right_sum = sum1;
        find_max_crossing_subarray(A, low, mid,high); //寻找跨越中点最大子数组（最小单位high-low=1）
		cross_low = max_left, cross_high = max_right, cross_sum = max_sum;
		if ((left_sum >= right_sum) && (left_sum >= cross_sum))  //返回（更新）最小子数组。
			low1 = left_low, high1 = left_high, sum1 = left_sum;
		else if ((right_sum >= left_sum) && (right_sum >= cross_sum))
			low1 = right_low, high1 = right_high, sum1 = right_sum;
		else
			low1 = cross_low, high1 = cross_high, sum1 = cross_sum;
	}
}