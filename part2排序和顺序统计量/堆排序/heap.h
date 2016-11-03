#pragma once
class heap
{
	int heap_size;
	int length;
	int *A = new int[length];
	
public:
	heap(int *P, int i_length, int i_heap_size);//构造函数
	int heapsize();//取数组有效长度
	int parent(int i);//父节点
	int left(int i);//左孩子
	int right(int i);//右孩子
	void max_heapity(int j);//维护最大堆
	void build_max_heap();//建堆（最大堆）
	void heapsort();//堆排序
	void show();

	//优先队列(基于最大堆，因此调用一下函数前，必须先调用建堆函数)
	int heap_maximum();//返回队列最大值
	int heap_extract_max();//提取并返回队列最大值
	void heap_increase_key(int i, int key); //队列的第i个元素的键值加至key 
	void max_heap_insert(int key);//在队列末尾并入一个新的键字
};

