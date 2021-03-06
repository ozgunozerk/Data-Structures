#include <iostream>
#include <vector>
#include "myStack.h"
using namespace std;

//coordinate system creation
void coorCreation(vector<vector<int>> & coor,int row, int col, int x, int y)
{
	int temp;	//for the coordinate system elements inputs

	coor.resize(row);
	//filling the array
	for (int i = 0; i < row; i++)
	{
		coor[i].resize(col);
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			coor[i][j] = temp;
		}
	}
}

//if a coordinate exists in a stack
bool isThere(int a, int b, myStack &stack)
{
	Node * temp = stack.top;	//starting point
	while (temp != NULL)	//until the end of the stack
	{
		if (a == temp->x && b == temp->y)
		{
			return true;	//means it exist
		}
		temp = temp->next;
	}
	return false;	//means it does not exist
}

//finding where to go for next step
void nextStep(int row, int col, vector<vector<int>> coor, int &a, int &b, myStack &memory, myStack &future, myStack &path)
{
	int found = 0;	//to store how many neighbours are "0 cells"
	int a1, b1;

	//search of all 4 neighbours, if the target location is zero and if we havent been there before, we increase found count
	if ((b-1) > 0 && coor[a][b - 1] == 0 && !isThere(a, b - 1, memory))
	{
		a1 = a;
		b1 = (b - 1);
		found++;
	}
	if ((b+1) < col && coor[a][b + 1] == 0 && !isThere(a, b + 1, memory))
	{
		a1 = a;
		b1 = (b + 1);
		found++;
	}
	if ((a-1) > 0 && coor[a - 1][b] == 0 && !isThere(a - 1, b, memory))
	{
		b1 = b;
		a1 = (a - 1);
		found++;
	}
	if ((a+1) < row && coor[a + 1][b] == 0 && !isThere(a + 1, b, memory))
	{
		b1 = b;
		a1 = (a + 1);
		found++;
	}

	//means if we are stuck and need to go back to previous checkpoint
	if (found == 0)
	{
		Node temp;
		temp = future.pop(); //we access our previous checkpoint here
		int m = temp.x, n = temp.y; //we access its coordinates

		//this is for deleting our steps to the checkpoint backwards, in order to print out the shortest way
		while (path.top->x != m || path.top->y != n)
		{
			path.pop();
		}
		path.pop();
		a1 = m;
		b1 = n;
	}

	//means we have more than 1 option, so we create a checkpoint
	if (found >= 2)
	{
		future.push(a, b);
	}
		a = a1;
		b = b1;

}

//checks for if we escaped from the maze or not
bool ifBorder(Node current, int a, int b)
{
	if (current.x == a-1 || current.y == b-1)
	{
		return true; //means yes
	}
	return false; //means no
}

int main()
{
	int row, col, a, b;

	cout << "Please enter the row and column number respectively: " << endl;
	cin >> row >> col;

	cout << "Please enter the starting coordinate (first row, then column): " << endl;
	cin >> a >> b;

	cout << "Please enter the coordinates in order: " << endl;

	myStack memory, future, path; //memory for the record of the cells we have traveled, future is for checkpoints, path is for the shortest way out

	vector<vector<int>> coor;

	coorCreation(coor, row, col, a, b);

	Node current; //creating the start point
	current.x = a;
	current.y = b;

	do //since we may begin from a border, our loop must run at least once, hence we require "do while"
	{
		memory.push(current.x, current.y); //recording our current cell to stack
		path.push(current.x, current.y); //also to the path, but we may delete it later
		nextStep(row, col, coor, current.x, current.y, memory, future, path); //making a step forward to next cell
	} while (!ifBorder(current, row, col)); //until we reach to a exit
	path.push(current.x, current.y); //we did not add the last cell because we already got out of the loop

	cout << "The solution to the puzzle is: " << endl;
	path.display();

	cin.ignore();
	cin.get();
	cin.ignore();
	cin.get();
}

