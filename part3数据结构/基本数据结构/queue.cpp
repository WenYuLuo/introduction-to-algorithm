#include "stdafx.h"
#include "queue.h"
#include "iostream"
using namespace std;

queue::queue( int a, int b)
{
	head = a;
	tail = b;
	if (head > tail&&tail>=0)
	{
		for (int i = head;i < sizearr;i++)
			A[i] = rand()%20;
		length = sizearr - head;
		if (tail > 0)
		{
			for (int j = 0;j < tail;j++)
				A[j] = rand()%20;
			length = length + tail;
		}
	}

	else if (head<tail)
	{
		for(int i=head;i<tail;i++)
			A[i] = rand() % 20;
		length = tail - head + 1;
	}

	else
	{
		cout << "the queue is empty!" << endl;
	}
	
}



queue::~queue()
{
	head = 0;
	tail = head;
	for (int i = 0;i < sizearr;i++)
		A[i] = 0;
}

void queue::enqueue(int x)
{
	if (tail + 1 == head)
		cout << "the queue is full, can't enter any number" << endl;
	else
	{
		A[tail] = x;
		if (tail == sizearr - 1)
			tail = 0;
		else tail = tail + 1;
		length = length + 1;
	}

}

int queue::dequeue()
{
	if (tail == head)
		cout << "the queue is empty!" << endl;
	
	else 
	{
		int n;
		n = A[head];
		if (head == sizearr-1)
			head = 0;
		else head = head + 1;
		length = length - 1;
		return n;
	}

	return 0;
}

void queue::show()
{
	if (head > tail&&tail >= 0)
	{
		for (int i = head;i < sizearr;i++)
			cout << "  " << A[i];
		length = sizearr - head;
		if (tail > 0)
		{
			for (int j = 0;j < tail;j++)
				cout << "  " << A[j];
			length = length + tail;
		}
		cout << "   head= " << head << "  tail= " << tail << "  length= " << length << endl;
	}

	else if (head<tail)
	{
		for (int i = head;i<tail;i++)
			cout << "  " << A[i] ;
		length = tail - head + 1;
		cout << "   head= " << head << "  tail= " << tail << "  length= " << length << endl;
	}

	else
	{
		cout << "the queue is empty!" << endl;
	}

}
