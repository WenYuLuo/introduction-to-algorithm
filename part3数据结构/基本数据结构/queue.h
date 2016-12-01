#pragma once
#define sizearr 12
class queue
{
	int A[sizearr];
	int head;
	int tail;
	int length;

public:
	queue(int a, int b);
	virtual ~queue();

	void enqueue(int x);
	int dequeue();
	void show();

};

