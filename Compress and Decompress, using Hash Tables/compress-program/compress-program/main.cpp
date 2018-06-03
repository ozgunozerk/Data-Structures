#include <iostream>
#include <string>
#include "HashTable.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream ifile("compin");//file to be compressed
	ofstream ofile("compout");//compressed output file
	string empty = "not_found!";
	string P = "", C = "", PC = "", toBeAdded = "", temp = "";
	HashTable<string> myTable(empty, 4096); //creating the has table
	char charString;
	int code, receivedCode;
	bool overdose = false; //control value for the scenario if table is full and we need to continue on operations

	for (code = 1; code < 256; code++)//filling the table with ascii codes
	{
		temp = char(code);
		myTable.insert(temp, code);
	}
	while (ifile.get(charString)) //lwz algorithm
	{
		C = charString;
		PC = P + C;
		receivedCode = myTable.find(PC);
		if (receivedCode != 0)
		{
			P = PC;
		}
		else
		{
			if (myTable.isTableAvailable()) //only this part is different than original algorithm
			{//if our table is full and we still have an unassigned object, we dont add it, we only add when there is space
				myTable.insert(PC, code);
				code++;
			}
			else
			{//changing control value for the condition that table is full
				overdose = true;
			}
			ofile << myTable.find(P) << " ";
			P = C;
		}
	}
	ofile << myTable.find(P); //end of the algorithm


	ifile.close();
	ofile.close();
	//REKT
	return 0;
}