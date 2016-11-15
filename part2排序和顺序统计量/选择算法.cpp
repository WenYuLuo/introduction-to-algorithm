// ѡ���㷨.cpp : ����������Ϊ����ʱ���ѡ���㷨��������λ���Ŀ������򻮷֡�
//��Ҫע�⼸�㣬��new���䶯̬�ڴ�ʱ����������Ϊ�˱�ʾ���㲻ʹ������a[0]������ڶ������Ӧ��Ϊ�ڴ���1.
//������Ϊ����A����nλ����ӦΪ int *A=new int[n+1];

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;
//int rand_partition(int *A, int p, int r);
int partition(int *A, int p, int r,int z);
int median(int *A,int p, int r);
int median_mid(int *A, int length,int p,int r);
int select(int *A, int p, int r, int s);
int medianmm(int *A, int *mid, int n);

int main()
{
	int s, length;
	cout << "������Ϊ����ʱ���ѡ���㷨demo��" << endl;
	cout << "���������г��ȣ�";
	cin >> length;
	int *A = new int[length+1];
	cout << "���ɵ��������Ϊ��";
	for(int i=1;i<=length;i++)
	{
		A[i] = rand() % 20;
		cout << "  " << A[i];
	}
	cout << endl;
	cout << "ѡ�������е�sС������s=";
	cin >> s;
	cout << "��õ���Ϊ��" << A[select(A, 1, length, s)] << endl;
	
	//����Ϊ�������򣬷�����֤ѡ���㷨����ȷ��
	int j, i, key, n;
	for (j = 2; j <= length; j++)
	{
		key = A[j];
		//��A[j]�����ź����A[1...j-1]
		i = j - 1;
		while (i > 0 && A[i] > key)   //�Ƚ�A[i + 1]��A[i]������Ϊ����
		{
			A[i + 1] = A[i];       //��˽���������A[i + 1]
			i = i - 1;             //Ŀ�Ļ��ݼ��
		}
		A[i + 1] = key;
	}

	cout << "������������";
	for (n = 1;n <=length ;n++)
	{
		cout << A[n] << "  ";
	}
	cout << endl;
	delete[] A;
	return 0;
}


int select(int *A, int p, int r,int s)
{
	int q, length,k;
	if (p == r)    //�ж����鳤�ȣ���ֻ��һ�����򷵻�r
		return r;
	else
	{
		length = r - p + 1; //�������鳤��
		q = partition(A, p, r, median_mid(A, length,p,r)); //������λ������λ����Ϊ��Ԫ��������
		//for (int j = 1;j <= 10;j++)
		//{
		//	cout << A[j] << " ";
		//}
		//cout << endl;
		k = q - p + 1;
		if (s == k)//�ж�ѡ������Ԫ�Ƿ���ϵ�sС
		{
			return q; //���Ϸ���ѡ������Ԫq
		}
		else if (s < k)
		{
			return select(A, p, q - 1, s);//��ѡ�������ȵ�sС��������ȡ�ϰ벿�ּ����ݹ黮��
		}
		else
		{
			return select(A, q + 1, r, s - k);//��ѡ�������ȵ�sС����С����ȡ�°벿�ּ����ݹ黮�֣�ע�������°벿�ֱȵ�kС�������ô������Ѱ�ҵ�s-kС������
		}
	}
}


int median_mid(int *A, int length,int p,int r)//����λ������λ��
{
	if(p==r)//�����鳤��Ϊһ���򷵻�Ψһֵ
	{
		return p; 
	}
	else
	{
		int n = floor(length / 5);   //ȷ��������ÿ��5��Ԫ��

		if (length % 5 == 0)      //���ܱ�5��������ǡ��n=floor��length/5����
		{
			int *mid = new int[n+1];   //mid���ڴ洢��λ��������A�е�λ��
			for (int i = 1;i <= n;i++)
			{
				mid[i] = median(A, p + (i - 1) * 5, p + i * 5 - 1); //��ʼλ��Ϊp��p+5��p+10.... �յ�λ��Ϊp+4��p+9��p+14......
				//for (int j = 1;j <= length;j++)
				//{
				//	cout << A[j] << " ";
				//}
				//cout << endl;
			}
			return medianmm(A, mid, n); //����λ������λ��
			delete[] mid;
		}
		else        //�����ܱ�5��������ֳ�n=floor��length/5��+1��
		{
			int *mid = new int[n + 1+1];  //mid���ڴ洢��λ��������A�е�λ��
			for (int i = 1;i <= n;i++)
			{
				mid[i] = median(A, p + (i - 1) * 5, p + i * 5 - 1);//������ʼλ��Ϊp��p+5��p+10.... �յ�λ��Ϊp+4��p+9��p+14......
			}
			mid[n + 1] = median(A, p + n * 5, r);//����n+1�飬Ϊp+n*5��r
			return medianmm(A, mid, n + 1); //����λ������λ��
			delete[] mid;
		}
	}
}

int median(int *A, int p, int r)
{
	if(p==r)//�ж����鳤�ȣ���Ϊһ����Ψһֵ
	{
		return p;
	}
	else
	{
		int n = r - p + 1;   //��������
		int key;
		int i;
		for (int j = p + 1; j <= r; j++)
		{
			key = A[j];
			//��A[j]�����ź����A[1...j-1]
			i = j - 1;
			while ((i > (p - 1)) && (A[i] > key))   //�Ƚ�A[i + 1]��A[i]������Ϊ����
			{
				A[i + 1] = A[i];       //��˽���������A[i + 1]
				i = i - 1;             //Ŀ�Ļ��ݼ��
			}
			A[i + 1] = key;
		}
		//t a = A[p + int(floor(n / 2))];
		//t b = p + int(floor(n / 2));
		return p + int(floor(n / 2)); //ͨ�������±귵����λ����λ��
	}
}

int medianmm(int *A, int *mid, int n) //������λ������λ��
{
	if(n==1)
	{
		return mid[n];
	}
	else
	{    //����������mid[]Ϊ����������λ������λ��
		int key;
		int i;
		for (int j = 2; j <= n; j++)
		{
			key = A[mid[j]];
			//��A[j]�����ź����A[1...j-1]
			i = j - 1;
			while ((i > 0) && (A[mid[i]] > key))   //�Ƚ�A[i + 1]��A[i]������Ϊ����
			{
				A[mid[i + 1]] = A[mid[i]];       //��˽���������A[i + 1]
				i = i - 1;             //Ŀ�Ļ��ݼ��
			}
			A[mid[i + 1]] = key;
		}
		//int a = mid[int(floor(n / 2))];
		return mid[int(floor(n / 2))];//������λ��mid����
	}
}

int partition(int *A, int p, int r, int z)
{
	int m = A[z]; //��ѡ������Ԫ��������ĩ��
	A[z] = A[r];
	A[r] = m;
	int x = A[r];    //ѡ����Ԫ
	int i = p - 1;    //��ʼ��i
	int mid;
	for (int j = p;j < r;j++)
	{
		if (A[j] <= x) //������̬���ڣ�ȷ����������
		{
			i = i + 1;
			mid = A[i];
			A[i] = A[j];
			A[j] = mid;
		}
	}
	mid = A[i + 1];
	A[i + 1] = A[r];
	A[r] = mid;      //����Ԫ������������ֵ��
	return i + 1;
}

