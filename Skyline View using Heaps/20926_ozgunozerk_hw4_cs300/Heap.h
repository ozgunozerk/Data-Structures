#pragma once
#include <iostream>
#include <vector>

using namespace std;


struct coorX //we need a struct for every buildings x coordinate
{
	int xcoor;
	int height;
	int buildingLabel;
	string position;

	coorX() : buildingLabel(0), xcoor(-1), position(""), height(0) {} //initialization
};

struct coorY //we need a struct for every buildings y coordinate
{
	int bldngLabel;
	int buildingHeight;

	coorY() : bldngLabel(0), buildingHeight(0) {} //initialization
};


class Heap
{
private:

	int myMax; //for storing the maximum
	int mySize; //for storing the size

	vector<int> positionArray; //array for locations
	vector<coorY>  ycoorArray; //array for y coordinates
	vector<coorX>  xcoorArray; //array for x coordinates


	//functions


	coorY getMax(); //not necessary, but still implemented it
	void heapSort(vector<coorX> &a); //applies heapsort algorithm to our xcoordinate array
	void insert(int label, int height); //inserts new building to our y coordinate array
	bool isEmpty(); //checks for the heap (ycoordinate) if its empty
	void XperDown(vector<coorX>& a, int i, int n); //applies percolate down operation to xcoordinate heap, heapSort will use this one
	void YperDown(int pos); //this is the percolate down for the y coordinate heap
	void remove(int label); //removes an element from the y heap and returns it, although returned object is not necessary for this implementation

public:
	Heap(int size)
		: myMax(0), mySize(0), ycoorArray(size + 1), xcoorArray(2 * size + 1), positionArray(size + 1) {}

	~Heap(); //actually not necessary

	void getSkyline(); //draws the skyline
	void insertxcoor(int label, string pos, int x, int h); //inserts a building with beginning or ending coordinate only
	void sort(); //necessary for calling the heapSort from outside of the class
};