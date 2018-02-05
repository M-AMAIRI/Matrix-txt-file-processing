/* 
M-AMAIRI 
project_1.cpp : 
.Data txt file manipulation .
The objects defined below may be used to read and write matrix to txt file 
*/

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class DataFile
{
public	: void CreateVector(vector<vector<double> > &res, string InTxtFile)
	{
		//ifstream infile("Vector_file.txt");
		const char * c = InTxtFile.c_str();
		ifstream infile(c);
		string line;
		while (getline(infile, line)) // Read a line
		{
			res.push_back(vector<double>()); // Add a new row to the matrix
			vector<double>& row = res.back();
			istringstream iss(line);
			double value;
			while (iss >> value) // Read columns
				row.push_back(value); // Add a column to the current row
		}
		infile.close();
	}

// This function is just for printing the result
public : void PrintVector(const vector<vector<double> > &res) {
		for (auto row : res) {
			for (auto value : row)
				cout << value << "\t";
			cout << endl;
		}
	}

public : void VectorToTxt(vector<vector<double>> res, string OuTxtFile)
	{
		const char * c = OuTxtFile.c_str();
		//std::ofstream outFile("saved_Vector.txt");
		std::ofstream outFile(c);
		for (int row = 0; row < res.size(); row++)
		{
			string line = std::to_string(res[row][0]);
			for (int Collumns = 1; Collumns < res[0].size(); Collumns++)
			{
				string str = " " + std::to_string(res[row][Collumns]);
				//cout<<"L-" + std::to_string(row)+"C-"+ std::to_string(Collumns)+":"+ std::to_string(res[row][Collumns])+" ";
				line = line + str;
			}
			outFile << line << endl;
			//cout << line;
		}
		outFile.close();
	}

};





int main()
{
	DataFile *Manipulation=new DataFile ;

	vector<vector<double> > mat ;
	Manipulation->CreateVector(mat,"saved_Vector.txt");
	Manipulation->PrintVector(mat);
	Manipulation->VectorToTxt(mat,"saved_Vector.txt");
	char c;
	cin >> c;
	return 0;
}



/*

// you can also create your own dynamic link library (DLL) written in C++
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif
extern "C" MATHLIBRARY_API DataFile * CreateInstance()
{
DataFile *Manipulation=new DataFile ;
return Manipulation ;
}
extern "C" MATHLIBRARY_API void PrintVector(vector<vector<double>> res)
{
Manipulation->PrintVector(res);
}
extern "C" MATHLIBRARY_API void CreateVector(vector<vector<double>> res, string OuTxtFile)
{
Manipulation->CreateVector(res,OuTxtFile)
}
extern "C" MATHLIBRARY_API void VectorToTxt(vector<vector<double>> res, string OuTxtFile)
{
Manipulation->VectorToTxt(res,OuTxtFile)
}
*/
