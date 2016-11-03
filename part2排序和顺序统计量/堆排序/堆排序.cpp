// 堆排序.cpp : 必须注意的是在C++中数组首位为0，（应该也可以忽略这一点，等于在分配内存是时多分配一位，且在运行过程中没有对零位操作）
//为了便于调用，创建了堆类（heap）

#include "stdafx.h"
#include "heap.h"
#include "iostream"
using namespace std;

int main()
{
	int n;
	cout << "输入序列长度：";
	cin >> n;
	int *P = new int[n];
	for (int i = 0;i < n;i++)
	{
		P[i] = rand() % 50;  //生成0—50的伪随机数
//		cout << "  " << P[i];
	}
//	cout << endl;
	heap heap1 = { P,n,n };
	cout << "生成序列：";
	heap1.show();
	heap1.heapsort();
	cout << "排序结果：";
	heap1.show();
	
	//优先队列
	heap1.build_max_heap();
	cout << "基于最大堆优先队列demo：\n" 
		    <<"队列最大值："<< heap1.heap_maximum() << endl;
	//去掉最大键字的元素
	heap1.heap_extract_max();
	cout << "去掉最大键字的元素后的队列: ";
	heap1.show();
	//
	int key,i;
	cout << "队列的第i个元素：i = ";
	cin >> i;
	if (i > n)
	{
		cout << "error: input should be smaller than heap_size = " << heap1.heapsize()
			<< "\nplease input again: i= ";
		cin >> i;
	}
		cout << "将其的键值加至key = ";
		cin >> key;
		heap1.heap_increase_key(i, key);
		heap1.show();
	//在末尾并入一个新的键字
	int key1;
	cout << "增加新的key = ";
	cin >> key1;
	heap1.max_heap_insert(key1);
	heap1.show();
	return 0;
}

