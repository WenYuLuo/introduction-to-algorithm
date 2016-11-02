#pragma once
class heap
{
	int heap_size;
	int length;
	int *A = new int[length];
	
public:
	heap(int *P, int i_length, int i_heap_size);//构造函数
	int parent(int i);//父节点
	int left(int i);//左孩子
	int right(int i);//右孩子
	void max_heapity(int j);//维护最大堆
	void build_max_heap();//建堆（最大堆）
	void heapsort();//堆排序
	void show();
};

