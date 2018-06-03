#include <iostream>
using namespace std;

class TwoDimensionalTree;

struct Rectangle {
	int Top; // y coordinate of the upper edge 
	int Left; // x coordinate of the left edge 
	int Bottom; // y coordinate of the bottom edge 
	int Right; // x coordinate of the right edge ....
	Rectangle * next;
};

class list {

private:
	Rectangle *head, *tail;

public:

	friend class TwoDimensionalTree; //we want our tree class to reach list class' functions

	list(); //constructor
	~list(); //deallocation of the whole list
	void add_node(int top, int bot, int right, int left); //adding node
	void findRectangles(int x, int y, list &memory, int &count); //finding the rectangles
	void displayList(); //displaying the whole list

};
