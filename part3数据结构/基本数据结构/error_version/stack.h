#pragma once
class stack
{
	int stop;
	int *A = new int[stop + 1];

	
public:
	stack(int *P, int s);
	~stack();
	int isempty();
	void push(int x);
	int pop();
	void show();
	void free();
};

