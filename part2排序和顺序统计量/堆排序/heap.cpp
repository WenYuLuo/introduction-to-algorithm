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

int heap::heapsize()
{
	return heap_size;
}



int heap::parent(int i)//需要注意的是A[0]为根节点
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

void heap::max_heapity(int j)//维护最大堆
{
	int l, r,largest;
	l = left(j);
	r = right(j);
	if ((l< heap_size) &&(A[l]>A[j]))//与左孩子比较
		largest = l;
	else
		largest = j;
	if ((r < heap_size)&&(A[r] > A[largest]))//再与右孩子比较
		largest = r;
	if (largest != j)//若左右孩子比该点大，则交换，即大的值换至父节点
	{
		int mid;
		mid = A[j];
		A[j] = A[largest];
		A[largest] = mid;
		max_heapity(largest); //递归调用，直至该点的子树满足最大堆
		                                        //（这里只有该点不满足最大堆时会起作用，也就是他左右孩子若不满足，这里无法起作用的，即它是局部维护）
	}

}

void heap::build_max_heap()
{
	heap_size = length;
	int i;
	for(i=(floor(length/2)-1);i>=0;i--)//自底向上递归调用维护堆函数，使得整个堆满足最大堆（A[floor(length/2)+1....n]都是树的叶节点，这里递归是从最右侧的最小树节点开始的）
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
		A[i] = mid;                        //将根节点的值交换至最末位
		heap_size=heap_size-1;  //使得堆对数组操作范围减一，即不再对已被置换于最后位的最大值做任何处理
		max_heapity(0);
	}
}

void heap::show()
{
	for (int i = 0;i < heap_size;i++)
	{
		cout << "  " << A[i];
	}
	cout << endl;
}

int heap::heap_maximum() //返回队列最大值
{
	return A[0];
}

int heap::heap_extract_max()//提取并返回队列最大值
{
	if (heap_size < 0)
		cout << "error: heap underflow." << endl;
	int max;
	max = A[0];
	A[0] = A[heap_size - 1];
	heap_size = heap_size - 1; //将最大值交换至队列尾，令heap_size减一，使得队列不在包含该最大值
	max_heapity(0);              //置换后维护最大堆，保证提取出最大值得堆仍为最大堆
	return max;
}

void heap::heap_increase_key(int i, int key)  //队列的第i个元素的键值加至key 
{
	i = i - 1; //我们考虑数组从零开始，因此第i个元素在数组中的位置为A[i-1]
	if (key < A[i])
		cout << "error: new key is smaller than current key." << endl;
	A[i] = key;
	int mid;
	while(i>0&&A[parent(i)]<A[i])
	{
		mid = A[i];
		A[i] = A[parent(i)];
		A[parent(i)] = mid;
		i = parent(i);     //自下向上循环检查最大堆的条件，并更正。
	}
}

void heap::max_heap_insert(int key)  //在队列末尾并入一个新的键字
{
	heap_size = heap_size + 1;
	A[heap_size - 1] = -INT16_MAX;
	heap_increase_key(heap_size, key);
}
