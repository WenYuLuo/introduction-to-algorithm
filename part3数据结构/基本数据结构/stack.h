#pragma once
class stack
{
	int stop;
	int A[30];

public:
	stack(int *P, int s);
	//~stack();
	int isempty();
	void push(int x);
	int pop();
	void show();
};

