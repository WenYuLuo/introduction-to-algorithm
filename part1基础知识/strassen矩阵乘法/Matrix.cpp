#include "stdafx.h"
#include "Matrix.h"
#include "iostream"
    using std::cout;
	using std::cin;
	using std::endl;


void Matrix::init(int m,int n)     //初始化矩阵 
{
	
	row = m;
	colum = n;
	P = new int*[row];
	for (int l = 0;l < row;l++)
	{
		P[l] = new int[colum];
	}
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < colum;j++)
		{
			P[i][j] = 0;
		}
	}
}


void Matrix::build(int m, int n)  //矩阵赋值
{
	//cout << "请输入矩阵元素个数[";
	//cin >> row;
	//cout << "][";
	//cin >> colum;
	//cout << "]"<<endl ;
	row = m;
	colum = n;
	P = new int*[row];
	for (int l = 0;l < row;l++)
	{
		P[l] = new int[colum];
	}
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < colum;j++)
		{
			cout << "请输入矩阵元素[" << i << "][" << j << "]:";
			cin >> P[i][j];
		}
	}
}

void Matrix::creat(int m, int n)
{
	row = m;
	colum = n;
	P = new int*[row];
	for (int l = 0;l < row;l++)
	{
		P[l] = new int[colum];
	}
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < colum;j++)
		{
			P[i][j]=rand()%100;
		}
	}
}




void Matrix::show()  //打印矩阵
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < colum;j++)
		{
			cout <<"  "<<P[i][j];
		}
		cout << endl;
	}
}


void Matrix::delet() //删除给矩阵分配的动态空间
{
	for (int i = 0;i < row;i++)
	{
		delete P[i];
		P[i] = NULL;
	}
	delete[row]P;
	P = NULL;
}



	
