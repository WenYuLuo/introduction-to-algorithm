#pragma once
class heap
{
	int heap_size;
	int length;
	int *A = new int[length];
	
public:
	heap(int *P, int i_length, int i_heap_size);//���캯��
	int parent(int i);//���ڵ�
	int left(int i);//����
	int right(int i);//�Һ���
	void max_heapity(int j);//ά������
	void build_max_heap();//���ѣ����ѣ�
	void heapsort();//������
	void show();
};

