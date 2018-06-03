#include <iostream>
#include <string>
#include "Heap.h"
using namespace std;


coorY Heap::getMax()
{
	return ycoorArray[1]; //implemented the get max function, but since we use a max heap, its not necessary, so its kind of useless in this program
}


void Heap::getSkyline()
{
	if (xcoorArray[1].xcoor != 0)//if smallest x doesnt start from 0, that means our skyline is starting from 0
	{
		cout << "0 " << myMax << endl;
	}

	for (int i = 1; i < xcoorArray.size(); i++)//creation of the skyline, for the xcoordinate heap
	{
		if (xcoorArray[i].position == "l")//we add height to our heap if x coordinate is left
		{
			insert(xcoorArray[i].buildingLabel, xcoorArray[i].height);

			for (; i < xcoorArray.size() - 1 && xcoorArray[i].xcoor == xcoorArray[i + 1].xcoor; i++)//for more than 1 building containing same xcoordinates
			{
				if (xcoorArray[i + 1].position == "r")//when x coordinate is right, we remove the current height
				{
					remove(xcoorArray[i + 1].buildingLabel);
				}
				if (xcoorArray[i + 1].position == "l")//we add height to our heap if x coordinate is left
				{
					insert(xcoorArray[i + 1].buildingLabel, xcoorArray[i + 1].height);
				}
			}
			
			if (ycoorArray[1].buildingHeight != myMax) //check for if our max is changed after the operations, if changed, set the new myMax 
			{
				myMax = ycoorArray[1].buildingHeight;
				cout << xcoorArray[i].xcoor << " " << myMax << endl;
			}
		}
		else if (xcoorArray[i].position == "r")//when x coordinate is right, we remove the current height
		{
			remove(xcoorArray[i].buildingLabel);

			for (; i < xcoorArray.size() - 1 && xcoorArray[i].xcoor == xcoorArray[i + 1].xcoor; i++)//for more than 1 building containing same xcoordinates
			{
				if (xcoorArray[i + 1].position == "r")//when x coordinate is right, we remove the current height
				{
					remove(xcoorArray[i + 1].buildingLabel);
				}
				if (xcoorArray[i + 1].position == "l")//we add height to our heap if x coordinate is left
				{
					insert(xcoorArray[i + 1].buildingLabel, xcoorArray[i + 1].height);
				}
			}
			
			if (ycoorArray[1].buildingHeight != myMax) //check for if our max is changed after the operations, if changed, set the new myMax 
			{
				myMax = ycoorArray[1].buildingHeight;
				cout << xcoorArray[i].xcoor << " " << myMax << endl;
			}
		}
	}
}

Heap::~Heap()
{
	//actually not necessary since this program does not use any dynamic data allocation
}


void Heap::heapSort(vector<coorX> &a)
{
	for (int i = a.size() / 2; i >= 0; i--)
	{
		XperDown(a, i, a.size()); //heapsort algorithm
	}

	for (int j = a.size() - 1; j > 0; j--)
	{
		swap(a[0], a[j]); 
		XperDown(a, 0, j); //end of the algorithm
	}
}


void Heap::insert(int label, int height) //adds an item to ycoordinate heap
{
	int hole = ++mySize;

	while (hole>1 && height > ycoorArray[hole/2].buildingHeight)
	{
		ycoorArray[hole] = move(ycoorArray[hole/2]);
		positionArray[ycoorArray[hole].bldngLabel] = hole;
		hole/=2;
	}
	ycoorArray[hole].buildingHeight = height;
	ycoorArray[hole].bldngLabel = label;
	positionArray[ycoorArray[hole].bldngLabel] = hole;
}


void Heap::insertxcoor(int label, string pos, int xcoordinate, int height) //adds an item to xcoordinate heap
{
	if (pos == "l") //if left
	{
		xcoorArray[label].buildingLabel = (label + 1) / 2;
	}

	if (pos == "r") //if right
	{
		xcoorArray[label].buildingLabel = label / 2;
	}
	xcoorArray[label].position = pos;
	xcoorArray[label].xcoor = xcoordinate;
	xcoorArray[label].height = height;
}


bool Heap::isEmpty()
{
	return (ycoorArray[1].bldngLabel == 0); //because heap starts from index 1, we check the element at index 1 
}


void Heap::remove(int label)
{
	if (!isEmpty()) //first check for if it is empty
	{
		ycoorArray[positionArray[label]] = ycoorArray[mySize];
		ycoorArray[mySize].bldngLabel = 0;
		ycoorArray[mySize--].buildingHeight = 0;
		YperDown(positionArray[label]);
	}
}


void Heap::sort()
{
	heapSort(xcoorArray); //basically calling the heapSort algorithm
}


void Heap::XperDown(vector<coorX> &a, int i, int n)
{
	int child;
	coorX temp;

	for (temp = a[i]; (2 * i) + 1 < n; i = child)
	{
		child = (2 * i) + 1;
		if (child != n - 1 && a[child].xcoor < a[child + 1].xcoor)
		{
			child++;
		}
		if (a[child].xcoor > temp.xcoor)
		{
			a[i] = a[child];
		}
		else
		{
			break;
		}
	}
	a[i] = temp;
}


void Heap::YperDown(int hole)
{
	int child;
	coorY temp = ycoorArray[hole];

	for (; hole * 2 <= mySize; hole = child)
	{
		child = hole * 2;
		if (child != mySize && ycoorArray[child + 1].buildingHeight > ycoorArray[child].buildingHeight)
		{
			child++;
		}

		if (ycoorArray[child].buildingHeight > temp.buildingHeight)
		{
			ycoorArray[hole] = ycoorArray[child];
		}
		else
		{
			break;
		}
	}

	ycoorArray[hole] = temp;
}