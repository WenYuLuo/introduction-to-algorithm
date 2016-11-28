#include "stdafx.h"
#include "stack.h"
#include "iostream"
using namespace std;

stack::stack(int *P, int s)
{
	stop = s;
	int i;
	A[0] = 0;
	for (i = 1;i <= stop;i++)
	{
		A[i] = P[i];
		//cout << A[i];
     }
}

//stack::~stack()
//{
//	delete[] A;
//	A = NULL;
//}

int stack::isempty()
{
	if (stop == 0)
		return 1;
	return 0;
}

void stack::push(int x)
{
	stop = stop + 1;
	A[stop] = x;
}

int stack::pop()
{
	if (isempty())
		cout << "underflow" << endl;
	else stop = stop - 1;
	return A[stop + 1];
}

void stack::show()
{
	for (int i = 1;i <= stop;i++)
		cout << "  " << A[i];
	cout << endl;
}




