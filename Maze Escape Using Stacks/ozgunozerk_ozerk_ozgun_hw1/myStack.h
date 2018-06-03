#pragma once

#ifndef myStack_h
#define myStack_h

#include <iostream>

struct Node
{
	Node * next;
	int x;
	int y;
};

class myStack
{
public:
	Node * top;
	myStack()
	{
		top = NULL;
	}

	~myStack()
	{
		Node * old;
		while (top != NULL)
		{
			old = top;
			top = top->next;
			delete(old);
		}
	}
	void push(int a, int b);
	Node pop();
	void display();
};

#endif /* myStack_h */

