#pragma once
class heap
{
	int heap_size;
	int length;
	int *A = new int[length];
	
public:
	heap(int *P, int i_length, int i_heap_size);//���캯��
	int heapsize();//ȡ������Ч����
	int parent(int i);//���ڵ�
	int left(int i);//����
	int right(int i);//�Һ���
	void max_heapity(int j);//ά������
	void build_max_heap();//���ѣ����ѣ�
	void heapsort();//������
	void show();

	//���ȶ���(�������ѣ���˵���һ�º���ǰ�������ȵ��ý��Ѻ���)
	int heap_maximum();//���ض������ֵ
	int heap_extract_max();//��ȡ�����ض������ֵ
	void heap_increase_key(int i, int key); //���еĵ�i��Ԫ�صļ�ֵ����key 
	void max_heap_insert(int key);//�ڶ���ĩβ����һ���µļ���
};

