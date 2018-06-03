#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"

using namespace std;

int main()
{
	ifstream inputFile("recdb.txt"); //this is the file that we will find our rectangles inside

	int top, left, bot, right; //first rectangle is our extent of the root of our tree
	inputFile >> top >> left >> bot >> right;
	TwoDimensionalTree myTree(top, left, bot, right);

	while (right != -1) //until the last input is -1
	{
		inputFile >> top >> left >> bot >> right;
		if(right != -1)
			myTree.addRectangle(top, bot, left, right, myTree.root); //adding the rectangle into the tree
	}

	int x = 0, y; //these variables are for the coordinate we will search for

	while (x != -1)
	{
		cin >> x >> y;
		list temporary; //a list for storing which rectangles are inclosing our coordinate
		int count = 0; //count is set to 0 for every new coordinate
		cout << x << " " << y << endl;

		myTree.findCoordinate(x, y, myTree.root, temporary, count); //finding the rectangles
		cout << count << endl;
		temporary.displayList();

		temporary.~list(); //destruction of the list
	}


	inputFile.close();
	myTree.deleteTree(myTree.root); //destruction of the tree
	
}