// ��С������.cpp : ���β������
//��ΪC++����һ�������޷����ض��ֵ����������ȫ�ֱ���������ÿ�������ķ���ֵ
//���˶�C++���Ե�ʹ���д��ڳ����׶Σ���������˽�Ϊ�ͼ��ķ���.

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
int low1, high1, sum1;          //����ȫ�ֱ���,���ڴ溯���ķ���ֵ��
                                               //ÿ�εݹ����ǰ�ֵ�͸��βν��в��������ÿ�εݹ����ȫ�ֱ����ĸ��²�Ӱ�����н����

int main()
{
	int  m, n;
	cout << "�������������" << endl;
	cin >> m;
	int *A = new int[m];
	cout << "�������������" << endl;
	for (n = 0;n <= m - 1;n++)
	{
		A[n] = -floor((100*rand())/RAND_MAX)+50;  //���ɵ�α�������Χ��[-50,50]
		cout << A[n] << " ";
	}
	cout << endl;
	//int low, high, sum;
	find_maximum_subarray(A, 0, m - 1);
	cout << "������������꣺\n���:  " << low1+1                            //������
		     << "   �յ�:  " << high1+1 << "   ���������֮�ͣ�  "<<sum1<<endl;
	delete[] A;
    return 0;                             
}

void find_max_crossing_subarray(int *A, int low, int mid, int high)
{
	int left_sum = -10000, right_sum = -10000, sum = 0;   //��ʼ�㹻С��left_sum��right_sum
	int i, j;
	//int max_left, max_right;
	for(i=mid;i>=low;i--)                                                          //�����е��������е����������
	{
		sum = sum + A[i];
		if(sum>left_sum)                                                        
		{
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for(j=mid+1;j<=high;j++)                                              //�����е��������е����������
	{
		sum = sum + A[j];
		if(sum>right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	max_sum = left_sum + right_sum;                             //�����Խ�е������������
}


void find_maximum_subarray(int *A, int low, int high)  //���εݹ����������
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
		find_maximum_subarray(A, low, mid);       //Ѱ�������������飨�ݹ������ף�
		left_low = low1, left_high = high1, left_sum = sum1;
        find_maximum_subarray(A, mid+1, high);  //Ѱ���Ҳ���������飨�ݹ������ף�
		right_low = low1, right_high = high1, right_sum = sum1;
        find_max_crossing_subarray(A, low, mid,high); //Ѱ�ҿ�Խ�е���������飨��С��λhigh-low=1��
		cross_low = max_left, cross_high = max_right, cross_sum = max_sum;
		if ((left_sum >= right_sum) && (left_sum >= cross_sum))  //���أ����£���С�����顣
			low1 = left_low, high1 = left_high, sum1 = left_sum;
		else if ((right_sum >= left_sum) && (right_sum >= cross_sum))
			low1 = right_low, high1 = right_high, sum1 = right_sum;
		else
			low1 = cross_low, high1 = cross_high, sum1 = cross_sum;
	}
}