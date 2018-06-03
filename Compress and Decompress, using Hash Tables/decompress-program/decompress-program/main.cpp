#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

	ifstream ifile("compout");//compressed file
	ofstream ofile("decompout");//decompressed file
	string empty = "not_found!";
	string P = "", C = "", PC = "", toBeAdded = "", temp = "";
	string my_array[4096];//create a vector with the same size as the hash table
	int code, receivedCode, CW, PW;
	for (code = 1; code < 256; code++)//filling out vector with ascii table
	{
		temp = char(code);
		my_array[code] = temp;
	}
	//lzw algorithm starts
	ifile >> CW;
	ofile << my_array[CW];

	while (!ifile.eof())
	{
		PW = CW;
		ifile >> CW;
		if (my_array[CW].empty())//if entry not in the list
		{
			P = my_array[PW];
			C = my_array[PW].substr(0, 1);
			PC = P + C;
			ofile << PC;
			my_array[code] = PC;
			code++;
		}
		else//if we have this entry
		{
			ofile << my_array[CW];
			P = my_array[PW];
			C = my_array[CW].substr(0, 1);
			PC = P + C;
			my_array[code] = PC;
			code++;
		}
	}
	//lzw algorithm ends
	cin.ignore();
	cin.get();
	//REKT
	return 0;
}