#include <iostream>
#include "myStack.h"
using namespace std;

void myStack::push(int a, int b)
{
	Node *newNode = new Node;
	newNode->x = a;
	newNode->y = b;

	if (top == NULL)
	{
		newNode->next = NULL;
		top = newNode;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

Node myStack::pop()
{
	Node temp;
	
	if (top == NULL)
		cout << "nothing to pop";
	else
	{
		temp.x = top->x;
		temp.y = top->y;
		Node * old = top;
		top = top->next;
		delete(old);
	}
	return temp;
}

void myStack::display()
{
	myStack temporary;
	Node temp;
	int a, b;
	while (top != NULL)
	{
		temp = pop();
		a = temp.x;
		b = temp.y;
		temporary.push(a, b);
	}
	while (temporary.top != NULL)
	{
		cout << temporary.top->x << " " << temporary.top->y << endl;
		temporary.top = temporary.top->next;
	}
}
