#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class HashedObj>//template class
class HashTable
{
private:

	struct HashEntry
	{
		HashedObj element; //we will create struct with template value HashedObj
		int key;		   //and a key value for assigning it into our dictionary which is a hash table
	};

	vector<HashEntry> my_array; //our hash table

	int currentSize; //to control how many inputs we have currentyl
	const HashedObj ITEM_NOT_FOUND; //default value of the empty objects in the hash table


	int findPos(const HashedObj & x) const
	{
		unsigned int currentPos = hash<HashedObj>{}(x); //hash function, hashing the template object
		currentPos = currentPos % my_array.size(); //applying modulo to it, if the hash value is greater than the vector size

		while (my_array[currentPos].element != ITEM_NOT_FOUND && my_array[currentPos].element != x) //if collision occurs
		{//below operations are for linear probing
			currentPos++;  // add the difference
			if (currentPos >= my_array.size()) //apply mod if necessary
			{
				currentPos -= my_array.size();
			}
		}
		return currentPos;
	}

public:

	HashTable<HashedObj>(const HashedObj & notFound, int size = 4096) //constructor
		: ITEM_NOT_FOUND(notFound), my_array(size), currentSize(0)
	{
		for (unsigned int i = 0; i < my_array.size(); i++)
		{
			my_array[i].element = ITEM_NOT_FOUND;//assigning default value to our vector
		}
	}

	int find(const HashedObj & x)
	{
		int currentPos = findPos(x);
		if (my_array[currentPos].element != x)
		{
			//cout << "This item is Not in the Table" << endl;
			return 0;
		}
		return my_array[currentPos].key;//if we found our object in the table, we return the integer its corresponding
	}

	void insert(const HashedObj & x, int &y) 
	{
		int currentPos = findPos(x);
		if (my_array[currentPos].element == x)
		{
			//cout << "Already in the list" << endl;
			return;
		}
		my_array[currentPos].element = x;
		my_array[currentPos].key = y;
		currentSize++;//if not in the list, we insert it using our struct variables
	}
	bool isTableAvailable()//to check if table is full
	{
		if (currentSize + 1 < my_array.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};