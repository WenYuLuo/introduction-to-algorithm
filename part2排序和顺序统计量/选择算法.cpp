// 选择算法.cpp : 采用了最坏情况为线性时间的选择算法，基于中位数的快速排序划分。
//需要注意几点，在new分配动态内存时，由于我们为了表示方便不使用数组a[0]，因此在定义语句应该为内存多加1.
//如我们为数组A分配n位，则应为 int *A=new int[n+1];

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;
//int rand_partition(int *A, int p, int r);
int partition(int *A, int p, int r,int z);
int median(int *A,int p, int r);
int median_mid(int *A, int length,int p,int r);
int select(int *A, int p, int r, int s);
int medianmm(int *A, int *mid, int n);

int main()
{
	int s, length;
	cout << "最好情况为线性时间的选择算法demo：" << endl;
	cout << "请输入序列长度：";
	cin >> length;
	int *A = new int[length+1];
	cout << "生成的随机序列为：";
	for(int i=1;i<=length;i++)
	{
		A[i] = rand() % 20;
		cout << "  " << A[i];
	}
	cout << endl;
	cout << "选择序列中第s小的数：s=";
	cin >> s;
	cout << "获得的数为：" << A[select(A, 1, length, s)] << endl;
	
	//以下为插入排序，方便验证选择算法的正确性
	int j, i, key, n;
	for (j = 2; j <= length; j++)
	{
		key = A[j];
		//将A[j]插入排好序的A[1...j-1]
		i = j - 1;
		while (i > 0 && A[i] > key)   //比较A[i + 1]与A[i]，这里为升序。
		{
			A[i + 1] = A[i];       //因此将大数置于A[i + 1]
			i = i - 1;             //目的回溯检测
		}
		A[i + 1] = key;
	}

	cout << "数组排序结果：";
	for (n = 1;n <=length ;n++)
	{
		cout << A[n] << "  ";
	}
	cout << endl;
	delete[] A;
	return 0;
}


int select(int *A, int p, int r,int s)
{
	int q, length,k;
	if (p == r)    //判断数组长度，若只有一个数则返回r
		return r;
	else
	{
		length = r - p + 1; //计算数组长度
		q = partition(A, p, r, median_mid(A, length,p,r)); //利用中位数的中位数作为主元划分数组
		//for (int j = 1;j <= 10;j++)
		//{
		//	cout << A[j] << " ";
		//}
		//cout << endl;
		k = q - p + 1;
		if (s == k)//判断选定的主元是否符合第s小
		{
			return q; //符合返回选定的主元q
		}
		else if (s < k)
		{
			return select(A, p, q - 1, s);//若选定的数比第s小的数大，则取上半部分继续递归划分
		}
		else
		{
			return select(A, q + 1, r, s - k);//若选定的数比第s小的数小，则取下半部分继续递归划分，注意由于下半部分比第k小的数来得大，因此需寻找第s-k小的数。
		}
	}
}


int median_mid(int *A, int length,int p,int r)//求中位数的中位数
{
	if(p==r)//若数组长度为一，则返回唯一值
	{
		return p; 
	}
	else
	{
		int n = floor(length / 5);   //确定组数，每组5个元素

		if (length % 5 == 0)      //若能被5整除，则恰好n=floor（length/5）组
		{
			int *mid = new int[n+1];   //mid用于存储中位数在数组A中的位置
			for (int i = 1;i <= n;i++)
			{
				mid[i] = median(A, p + (i - 1) * 5, p + i * 5 - 1); //起始位置为p，p+5，p+10.... 终点位置为p+4，p+9，p+14......
				//for (int j = 1;j <= length;j++)
				//{
				//	cout << A[j] << " ";
				//}
				//cout << endl;
			}
			return medianmm(A, mid, n); //求中位数的中位数
			delete[] mid;
		}
		else        //若不能被5整除，则分成n=floor（length/5）+1组
		{
			int *mid = new int[n + 1+1];  //mid用于存储中位数在数组A中的位置
			for (int i = 1;i <= n;i++)
			{
				mid[i] = median(A, p + (i - 1) * 5, p + i * 5 - 1);//类似起始位置为p，p+5，p+10.... 终点位置为p+4，p+9，p+14......
			}
			mid[n + 1] = median(A, p + n * 5, r);//但第n+1组，为p+n*5至r
			return medianmm(A, mid, n + 1); //求中位数的中位数
			delete[] mid;
		}
	}
}

int median(int *A, int p, int r)
{
	if(p==r)//判断数组长度，若为一返回唯一值
	{
		return p;
	}
	else
	{
		int n = r - p + 1;   //插入排序
		int key;
		int i;
		for (int j = p + 1; j <= r; j++)
		{
			key = A[j];
			//将A[j]插入排好序的A[1...j-1]
			i = j - 1;
			while ((i > (p - 1)) && (A[i] > key))   //比较A[i + 1]与A[i]，这里为升序。
			{
				A[i + 1] = A[i];       //因此将大数置于A[i + 1]
				i = i - 1;             //目的回溯检测
			}
			A[i + 1] = key;
		}
		//t a = A[p + int(floor(n / 2))];
		//t b = p + int(floor(n / 2));
		return p + int(floor(n / 2)); //通过数组下标返回中位数的位置
	}
}

int medianmm(int *A, int *mid, int n) //计算中位数的中位数
{
	if(n==1)
	{
		return mid[n];
	}
	else
	{    //插入排序，以mid[]为索引排序中位数的中位数
		int key;
		int i;
		for (int j = 2; j <= n; j++)
		{
			key = A[mid[j]];
			//将A[j]插入排好序的A[1...j-1]
			i = j - 1;
			while ((i > 0) && (A[mid[i]] > key))   //比较A[i + 1]与A[i]，这里为升序。
			{
				A[mid[i + 1]] = A[mid[i]];       //因此将大数置于A[i + 1]
				i = i - 1;             //目的回溯检测
			}
			A[mid[i + 1]] = key;
		}
		//int a = mid[int(floor(n / 2))];
		return mid[int(floor(n / 2))];//返回中位数mid索引
	}
}

int partition(int *A, int p, int r, int z)
{
	int m = A[z]; //将选定的主元放置数组末端
	A[z] = A[r];
	A[r] = m;
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

