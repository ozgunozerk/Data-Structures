#include "Tree.h"


TwoDimensionalTree::TwoDimensionalTree(int top, int left, int bottom, int right) //constructor
{
	root = new TreeNode;
	root->Extent.Top = top;
	root->Extent.Bottom = bottom;
	root->Extent.Left = left;
	root->Extent.Right = right;

	//setting pointers of this pointer to NULL
	root->Extent.next = NULL;
	root->botLeft = NULL;
	root->botRight = NULL;
	root->topLeft = NULL;
	root->topRight = NULL;

	//lines of the root
	root->horizontalLine = (root->Extent.Bottom + root->Extent.Top) / 2;
	root->verticalLine = (root->Extent.Right + root->Extent.Left) / 2;
}

void TwoDimensionalTree::deleteTree(TreeNode * node)
{
	if (node != NULL)
	{
		//first delete the lists
		node->vertical.~list();
		node->horizontal.~list();

		//then do the same for all the subtrees recursively
		deleteTree(node->botLeft);
		deleteTree(node->botRight);
		deleteTree(node->topLeft);
		deleteTree(node->topRight);
	}
}


void TwoDimensionalTree::addRectangle(int top, int bot, int left, int right, TreeNode * node)
{
	if ((top <= node->horizontalLine) && (bot > node->horizontalLine)) //if the rectangle to add is on the horizontalLine
		node->horizontal.add_node(top, bot, right, left);


	else if ((left <= node->verticalLine) && (right > node->verticalLine)) //if the rectangle to add is on the verticalLine
		node->vertical.add_node(top, bot, right, left);

	else if ((top < node->horizontalLine) && (left < node->verticalLine)) //if the rectangle to add going to the topLeft subtree
	{
		if (node->topLeft == NULL) //if the subtree is empty, then create it
		{
			node->topLeft = new TreeNode;
			node->topLeft->Extent.Top = node->Extent.Top;
			node->topLeft->Extent.Bottom = (node->Extent.Bottom + node->Extent.Top) / 2;
			node->topLeft->Extent.Left = node->Extent.Left;
			node->topLeft->Extent.Right = (node->Extent.Right + node->Extent.Left) / 2;
			node->topLeft->horizontalLine = (node->topLeft->Extent.Bottom + node->topLeft->Extent.Top) / 2;
			node->topLeft->verticalLine = (node->topLeft->Extent.Right + node->topLeft->Extent.Left) / 2;

			//setting new pointers of this subtree to NULL
			node->topLeft->Extent.next = NULL;
			node->topLeft->topLeft = NULL;
			node->topLeft->botLeft = NULL;
			node->topLeft->topRight = NULL;
			node->topLeft->botRight = NULL;

			addRectangle(top, bot, left, right, node->topLeft); //now we have to check again with our recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->topLeft); //now we have to check again with our recursive function
		}
	}
	else if ((top > node->horizontalLine) && (left < node->verticalLine)) //if the rectangle to add going to the botLeft subtree
	{
		if (node->botLeft == NULL) //if the subtree is empty, then create it
		{
			node->botLeft = new TreeNode;
			node->botLeft->Extent.Top = node->Extent.Bottom - (node->Extent.Bottom - node->Extent.Top) / 2;
			node->botLeft->Extent.Bottom = node->Extent.Bottom;
			node->botLeft->Extent.Left = node->Extent.Left;
			node->botLeft->Extent.Right = (node->Extent.Right + node->Extent.Left) / 2;
			node->botLeft->horizontalLine = (node->botLeft->Extent.Bottom + node->botLeft->Extent.Top) / 2;
			node->botLeft->verticalLine = (node->botLeft->Extent.Right + node->botLeft->Extent.Left) / 2;

			//setting new pointers of this subtree to NULL
			node->botLeft->Extent.next = NULL;
			node->botLeft->topLeft = NULL;
			node->botLeft->botLeft = NULL;
			node->botLeft->topRight = NULL;
			node->botLeft->botRight = NULL;

			addRectangle(top, bot, left, right, node->botLeft); //now we have to check again with our recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->botLeft); //now we have to check again with our recursive function
		}
	}

	else if ((top < node->horizontalLine) && (left > node->verticalLine)) //if the rectangle to add going to the topRight subtree
	{
		if (node->topRight == NULL) //if the subtree is empty, then create it
		{
			node->topRight = new TreeNode;
			node->topRight->Extent.Top = (node->Extent.Top);
			node->topRight->Extent.Bottom = (node->Extent.Bottom + node->Extent.Top) / 2;
			node->topRight->Extent.Left = node->Extent.Right - (node->Extent.Right - node->Extent.Left) / 2;
			node->topRight->Extent.Right = node->Extent.Right;
			node->topRight->horizontalLine = (node->topRight->Extent.Bottom + node->topRight->Extent.Top) / 2;
			node->topRight->verticalLine = (node->topRight->Extent.Right + node->topRight->Extent.Left) / 2;

			//setting new pointers of this subtree to NULL
			node->topRight->Extent.next = NULL;
			node->topRight->topLeft = NULL;
			node->topRight->botLeft = NULL;
			node->topRight->topRight = NULL;
			node->topRight->botRight = NULL;

			addRectangle(top, bot, left, right, node->topRight); //now we have to check again with our recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->topRight); //now we have to check again with our recursive function
		}
	}
	else if ((top > node->horizontalLine) && (left > node->verticalLine)) //if the rectangle to add going to the botRight subtree
	{
		if (node->botRight == NULL) //if the subtree is empty, then create it
		{
			node->botRight = new TreeNode;
			node->botRight->Extent.Top = node->Extent.Bottom - (node->Extent.Bottom - node->Extent.Top) / 2;
			node->botRight->Extent.Bottom = node->Extent.Bottom;
			node->botRight->Extent.Left = node->Extent.Right - (node->Extent.Right - node->Extent.Left) / 2;
			node->botRight->Extent.Right = node->Extent.Right;
			node->botRight->horizontalLine = (node->botRight->Extent.Bottom + node->botRight->Extent.Top) / 2;
			node->botRight->verticalLine = (node->botRight->Extent.Right + node->botRight->Extent.Left) / 2;

			//setting new pointers of this subtree to NULL
			node->botRight->Extent.next = NULL;
			node->botRight->topLeft = NULL;
			node->botRight->botLeft = NULL;
			node->botRight->topRight = NULL;
			node->botRight->botRight = NULL;

			addRectangle(top, bot, left, right, node->botRight); //now we have to check again with our recursive function
		}
		else
		{
			addRectangle(top, bot, left, right, node->botRight); //now we have to check again with our recursive function
		}

		//eger 2ye bolununce 1den kucukse iptal
	}
}

void TwoDimensionalTree::findCoordinate(int x, int y, TreeNode * node, list &memory, int &count)
{
	//first check the lines
	node->vertical.findRectangles(x, y, memory, count);
	node->horizontal.findRectangles(x, y, memory, count);


	//now check the relative subtrees
	if (x < node->verticalLine && y < node->horizontalLine && node->topLeft != NULL)
		findCoordinate(x, y, node->topLeft, memory, count);
	else if (x < node->verticalLine && y > node->horizontalLine && node->botLeft != NULL)
		findCoordinate(x, y, node->botLeft, memory, count);
	else if (x > node->verticalLine && y < node->horizontalLine && node->topRight != NULL)
		findCoordinate(x, y, node->topRight, memory, count);
	else if (x > node->verticalLine && y > node->horizontalLine && node->botRight != NULL)
		findCoordinate(x, y, node->botRight, memory, count);
}




