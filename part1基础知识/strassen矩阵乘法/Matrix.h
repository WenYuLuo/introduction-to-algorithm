#pragma once
#include "iostream"
class Matrix
{
	int row;
	int colum;
	

public:
	int **P;
	void init(int i, int j); //��ʼ������ 
	void show(); //��ӡ����
	void delet();//ɾ�����������Ķ�̬�ռ�
	void build(int i, int j); //����ֵ
	void creat(int i, int j); //������ɾ���
	//Matrix strassen_multiply(Matrix &rc);

};

