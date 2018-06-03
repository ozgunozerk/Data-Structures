#include <iostream>
#include "LinkedList.h"


struct TreeNode
{
	Rectangle Extent; //borders of our rectangle
	TreeNode * topLeft;
	TreeNode * botLeft;
	TreeNode * topRight;
	TreeNode * botRight;
	list vertical, horizontal; //two lists for two lines
	int verticalLine, horizontalLine; //two lines
};

class TwoDimensionalTree
{
	
public:
	TreeNode * root; //we want to access our root from everywhere easily
	TwoDimensionalTree(int top, int left, int bottom, int right);
	void deleteTree(TreeNode * node); //deallocation of the whole tree
	void addRectangle(int top, int bot, int left, int right, TreeNode * node); //adding a new rectangle to our tree
	void findCoordinate(int x, int y, TreeNode * node, list &memory, int &count); //finding all the rectangles which incloses the specified coordiante
};


