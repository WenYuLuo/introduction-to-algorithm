#pragma once
#include "iostream"
class Matrix
{
	int row;
	int colum;
	

public:
	int **P;
	void init(int i, int j); //初始化矩阵 
	void show(); //打印矩阵
	void delet();//删除给矩阵分配的动态空间
	void build(int i, int j); //矩阵赋值
	void creat(int i, int j); //随机生成矩阵
	//Matrix strassen_multiply(Matrix &rc);

};

