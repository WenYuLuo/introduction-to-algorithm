// Strassen矩阵乘法.cpp : 这里没有使用书中采用的下标数组，而是复制矩阵进行运算，需要消耗较大的内存空间
//同时在不满足次幂的情况下,仅允许规模为16以下的矩阵运算。（bug：高于16的2次幂也不予计算）

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
#include "Matrix.h"
#include "math.h"
void strassen_multiply(int **A, int **B, int **C, int n);
void sepA(int **A, int **A11, int **A12, int **A21, int **A22, int n);
void sepB(int **A, int **A11, int **A12, int **A21, int **A22, int n);
void add(int **A, int **B, int **P, int n);
void sub(int **A, int **B, int **P, int n);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int size;                            //初始化参数
	cout << "输入参与乘法矩阵的规模:\n" ;
	cin >> size;
	cout << "创建矩阵A:" << endl;
	Matrix A;
	A.creat(size, size);
	A.show();
	cout << "创建矩阵B:" << endl;
	Matrix B;
	B.creat(size, size);
	B.show();
	Matrix C;
	C.init(size, size);
	//C.show();
	int size_zero;
	if(size<2)   //判断方阵规模是否为2的次幂，若不是补上全为零的行和列，使其满足2的次幂.
	{
		size_zero = 2;
	}
	else if(size>2&&size<4)
	{
		size_zero = 4;
	}
	else if(size>4 && size<8)
	{
		size_zero = 8;
	}
	else if(size>8 && size<16)
	{
		size_zero = 16;
	}
	else if(size>16)
	{
		size_zero = 0;
	}
	else
	{
		size_zero = size;
	}


	if (size_zero != 0)
	{
		int i, j;
		Matrix F;
		Matrix D;
		Matrix E;
		F.init(size_zero, size_zero);
		D.init(size_zero, size_zero);
		E.init(size_zero, size_zero);
		for (i = 0;i < size;i++)
		{
			for (j = 0;j < size;j++)
			{
				F.P[i][j] = A.P[i][j];
				D.P[i][j] = B.P[i][j];
			}
		}
		strassen_multiply(F.P, D.P, E.P, size_zero);   //调用strassen
		cout << "矩阵乘积A*B" << endl;
		for (i = 0;i < size;i++)
		{
			for (j = 0;j < size;j++)
			{
				cout << "  " << E.P[i][j];
			}
			cout << endl;
		}
		F.delet();
		D.delet();
		E.delet();
		A.delet();
		B.delet();
		C.delet();
	}
	else
	{
		cout << "输入矩阵超出预设范围" << endl;
	}
	return 0;
}

void strassen_multiply(int **A, int **B, int **C, int n)  //strassen乘法
{
	if (n == 1)   //触底乘法，矩阵只有一个元素时的计算
	{
		C[n-1][n-1] = A[n-1][n-1] * B[n-1][n-1];
	}
	else
	{
		int t;
		t = int(n / 2);  //取n/2
		Matrix S1, S2, S3, S4, S5, S6, S7, S8, S9, S10; // 定义中间步矩阵
		S1.init(t, t);
		S2.init(t, t);
		S3.init(t, t);
		S4.init(t, t);
		S5.init(t, t);
		S6.init(t, t);
		S7.init(t, t);
		S8.init(t, t);
		S9.init(t, t);
		S10.init(t, t);

		Matrix A11;    //分配分块矩阵内存
		Matrix A12;
		Matrix A21;
		Matrix A22;
		Matrix B11;
		Matrix B12;
		Matrix B21;
		Matrix B22;
		A11.init(t, t);  //分块矩阵初始化
		A12.init(t, t);
		A21.init(t, t);
		A22.init(t, t);
		B11.init(t, t);
		B12.init(t, t);
		B21.init(t, t);
		B22.init(t, t);
                                 //对矩阵B分块
		sepB(B, B11.P, B12.P, B21.P, B22.P, n);
		//S1 = B12 - B22
		sub(B12.P, B22.P, S1.P, t);
		//S4 = B21 - B11;
		sub(B21.P, B11.P, S4.P, t);
		//S6 = B11 + B22;
		add(B11.P, B22.P, S6.P, t);
		//S8 = B21 + B22;
		add(B21.P, B22.P, S8.P, t);
		//S10 = B11 + B12;
		add(B11.P, B12.P, S10.P, t);

		                          //对矩阵A分块
		sepA(A, A11.P, A12.P, A21.P, A22.P, n);
		//S2 = A11 + A12;
		add(A11.P, A12.P, S2.P, t);
		//S3 = A21 + A22;
		add(A21.P, A22.P, S3.P, t);
		//S5 = A11 + A22;
		add(A11.P, A22.P, S5.P, t);
		//S7 = A12 - A22;
		sub(A12.P, A22.P, S7.P, t);
		//S9 = A11 - A21;
		sub(A11.P, A21.P, S9.P, t);

		Matrix P1, P2, P3, P4, P5, P6, P7;   // 定义中间步矩阵
		P1.init(t, t);
		P2.init(t, t);
		P3.init(t, t);
		P4.init(t, t);
		P5.init(t, t);
		P6.init(t, t);
		P7.init(t, t);

		//P1 = A11*S1;
		strassen_multiply(A11.P, S1.P, P1.P, t);
		//P2 = S2*B22;
		strassen_multiply(S2.P, B22.P, P2.P, t);
		//P3 = S3*B11;
		strassen_multiply(S3.P, B11.P, P3.P, t);
		//P4 = A22*S4;
		strassen_multiply(A22.P, S4.P, P4.P, t);
		//P5 = S5*S6;
		strassen_multiply(S5.P, S6.P, P5.P, t);
		//P6 = S7*S8;
		strassen_multiply(S7.P, S8.P, P6.P, t);
		//P7 = S9*S10;
		strassen_multiply(S9.P, S10.P, P7.P, t);

		for (int i = 0;i < t;i++)
			for (int j = 0;j < t;j++)
			{
				//C11 = P5 + P4 - P2 + P6;
				C[i][j] = P5.P[i][j] + P4.P[i][j] - P2.P[i][j] + P6.P[i][j];
				//C12 = P1 + P2;
				C[i][j + t] = P1.P[i][j] + P2.P[i][j];
				//C21 = P3 + P4;
				C[i + t][j] = P3.P[i][j] + P4.P[i][j];
				//C22 = P5 + P1 - P3 - P7;
				C[i + t][j + t] = P5.P[i][j] + P1.P[i][j] - P3.P[i][j] - P7.P[i][j];
			}
		//删除预分配内存
		A11.delet();
		A12.delet();
		A21.delet();
		A22.delet();
		B11.delet();
		B12.delet();
		B21.delet();
		B22.delet();
		S1.delet();
		S2.delet();
		S3.delet();
		S4.delet();
		S5.delet();
		S6.delet();
		S7.delet();
		S8.delet();
		S9.delet();
		S10.delet();
		P1.delet();
		P2.delet();
		P3.delet();
		P4.delet();
		P5.delet();
		P6.delet();
		P7.delet();
	}
}

void sepA(int **A, int **A11, int **A12, int **A21, int **A22, int n)
{

		int t = n / 2;
		int i, j;
		for (i = 0;i < t;i++)
			for (j = 0;j < t;j++)
			{
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + t];
				A21[i][j] = A[i + t][j];
				A22[i][j] = A[i + t][j + t];
			};
	
}

void sepB(int **A, int **B11, int **B12, int **B21, int **B22, int n)
{
		int t = n / 2;
		int i, j;
		for (i = 0;i < t;i++)
		{
			for (j = 0;j < t;j++)
			{
				B11[i][j] = A[i][j];
				B12[i][j] = A[i][j + t];
				B21[i][j] = A[i + t][j];
				B22[i][j] = A[i + t][j + t];
			};
		}
}

void add(int **A, int **B, int **P,int n) //矩阵加法
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			P[i][j] = A[i][j] + B[i][j];
}

void sub(int **A, int **B, int **P, int n)//矩阵减法
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			P[i][j] = A[i][j] - B[i][j];
}