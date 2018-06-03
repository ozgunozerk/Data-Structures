#include <sstream>
#include <fstream>
#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	ifstream iFile;
	string line, height, xRight, xLeft;
	iFile.open("input.txt");
	(getline(iFile, line));
	istringstream ss1(line);

	Heap myHeap(stoi(line));

	for (int i = 1; getline(iFile, line); i++) //Constructs the cordinate array
	{
		istringstream ss2(line); //reading from the file operations
		ss2 >> xLeft;
		ss2 >> height;
		ss2 >> xRight;

		myHeap.insertxcoor(2 * i - 1, "l", stoi(xLeft), stoi(height));
		myHeap.insertxcoor(2 * i, "r", stoi(xRight), stoi(height));
	}

	myHeap.sort(); //sorts the heap with respect to the x coordinates of the buildings in the ascending order.
	myHeap.getSkyline(); //our main function to draw the skyline

	cin.ignore(); //for debugging
	cin.get(); //for debugging
	return 0;
}