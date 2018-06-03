#include "LinkedList.h"

list::list() //constructor
{
	head = NULL;
	tail = NULL;
}

void list::add_node(int top, int bot, int right, int left)
{
	Rectangle *tmp = new Rectangle; //creating a new rectangle
	tmp->Top = top;
	tmp->Bottom = bot;
	tmp->Right = right;
	tmp->Left = left;
	tmp->next = NULL;

	if (head == NULL) //if list is empty
	{
		head = tmp;
		tail = tmp;
	}
	else //if list is not empty
	{
		tail->next = tmp;
		tail = tail->next;
	}
}
void list::findRectangles(int x, int y, list &memory, int &count)
{
	if (head != NULL) // if list is not empty
	{
		Rectangle * tmp = head;
		while (tmp != NULL)
		{
			if (x >= tmp->Top && x < tmp->Bottom && y <= tmp->Right && y > tmp->Left) //this is for checking if the coordinate is not outside of the rectangle
				count++; //increase count for each rectangle we found
				memory.add_node(tmp->Top, tmp->Bottom, tmp->Right, tmp->Left); //adding the relevant rectangle to our memory list
			tmp = tmp->next; //iteration
		}
	}
}

void list::displayList()
{
	Rectangle * tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->Top << " " << tmp->Left << " " << tmp->Bottom << " " << tmp->Right << endl; //displaying the rectangle
		tmp = tmp->next; //iteration
	}
}

list::~list()
{
	Rectangle * tmp = head; //new temporary pointer to delete the list
	while (tmp != NULL)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}