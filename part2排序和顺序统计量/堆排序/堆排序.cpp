// ������.cpp : ����ע�������C++��������λΪ0����Ӧ��Ҳ���Ժ�����һ�㣬�����ڷ����ڴ���ʱ�����һλ���������й�����û�ж���λ������
//Ϊ�˱��ڵ��ã������˶��ࣨheap��

#include "stdafx.h"
#include "heap.h"
#include "iostream"
using namespace std;

int main()
{
	int n;
	cout << "�������г��ȣ�";
	cin >> n;
	int *P = new int[n];
	for (int i = 0;i < n;i++)
	{
		P[i] = rand() % 50;  //����0��50��α�����
//		cout << "  " << P[i];
	}
//	cout << endl;
	heap heap1 = { P,n,n };
	cout << "�������У�";
	heap1.show();
	heap1.heapsort();
	cout << "��������";
	heap1.show();
	
	//���ȶ���
	heap1.build_max_heap();
	cout << "�����������ȶ���demo��\n" 
		    <<"�������ֵ��"<< heap1.heap_maximum() << endl;
	//ȥ�������ֵ�Ԫ��
	heap1.heap_extract_max();
	cout << "ȥ�������ֵ�Ԫ�غ�Ķ���: ";
	heap1.show();
	//
	int key,i;
	cout << "���еĵ�i��Ԫ�أ�i = ";
	cin >> i;
	if (i > n)
	{
		cout << "error: input should be smaller than heap_size = " << heap1.heapsize()
			<< "\nplease input again: i= ";
		cin >> i;
	}
		cout << "����ļ�ֵ����key = ";
		cin >> key;
		heap1.heap_increase_key(i, key);
		heap1.show();
	//��ĩβ����һ���µļ���
	int key1;
	cout << "�����µ�key = ";
	cin >> key1;
	heap1.max_heap_insert(key1);
	heap1.show();
	return 0;
}

