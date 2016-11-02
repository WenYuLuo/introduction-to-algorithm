#include "stdafx.h"
#include "heap.h"
#include "math.h"
#include "iostream"
using namespace std;


heap::heap(int * P, int i_length, int i_heap_size)
{
//	for (int i = 0;i < i_length;i++)
//	{
//		A[i] = P[i];
//	}
	A = P;
	length = i_length;
	heap_size = i_heap_size;
}



int heap::parent(int i)//��Ҫע�����A[0]Ϊ���ڵ�
{	
	return floor((i+1)/2)-1;
}

int heap::left(int i)
{
	return 2*(i+1)-1;
}

int heap::right(int i)
{
	return 2*(i+1);
}

void heap::max_heapity(int j)//ά������
{
	int l, r,largest;
	l = left(j);
	r = right(j);
	if ((l< heap_size) &&(A[l]>A[j]))//�����ӱȽ�
		largest = l;
	else
		largest = j;
	if ((r < heap_size)&&(A[r] > A[largest]))//�����Һ��ӱȽ�
		largest = r;
	if (largest != j)//�����Һ��ӱȸõ���򽻻��������ֵ�������ڵ�
	{
		int mid;
		mid = A[j];
		A[j] = A[largest];
		A[largest] = mid;
		max_heapity(largest); //�ݹ���ã�ֱ���õ��������������
		                                        //������ֻ�иõ㲻��������ʱ�������ã�Ҳ���������Һ����������㣬�����޷������õģ������Ǿֲ�ά����
	}

}

void heap::build_max_heap()
{
	heap_size = length;
	int i;
	for(i=(floor(length/2)-1);i>=0;i--)//�Ե����ϵݹ����ά���Ѻ�����ʹ���������������ѣ�A[floor(length/2)+1....n]��������Ҷ�ڵ㣬����ݹ��Ǵ����Ҳ����С���ڵ㿪ʼ�ģ�
	{
		max_heapity(i);
	}
}

void heap::heapsort()
{
	build_max_heap();
//	int *B = new int[heap_size];
	for(int i=length-1;i>=1;i--)  //
	{
		int mid;
		mid = A[0];
//		B[heap_size - 1] = A[0];
		A[0] = A[i];
		A[i] = mid;                        //�����ڵ��ֵ��������ĩλ
		heap_size=heap_size-1;  //ʹ�öѶ����������Χ��һ�������ٶ��ѱ��û������λ�����ֵ���κδ���
		max_heapity(0);
	}
}

void heap::show()
{
	for (int i = 0;i < length;i++)
	{
		cout << "  " << A[i];
	}
	cout << endl;
}
