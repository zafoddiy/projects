#include <iostream>
#include <fstream>
#include <string>
#include "hw1.h"

int main(void)
{
	data people[MAX_DATA];
	int dataSize = Read_Data(MAX_DATA, people);
	std::ofstream fo("F2.txt"); // write into output file
	Output_Data(dataSize, people, fo);
	std::string hobbyQuery = Read_Hobby(fo);
	Find_People(dataSize, people, hobbyQuery, fo);
	fo.close();
	return 0;
}

int Read_Data(int size, data *array)
{
	std::ifstream fi("F1.txt");
	if (!fi)			// check if the input file exists
	{
		std::cout << "ERROR: Input file doesn't exist, exiting." << std::endl;
		exit(-1);		// if it doesnt, exit with error code '-1'
	}
	int i = 0;
	int j;
	// loop while the 1st 2 elements of a line
	// are a string and integer, in that order
	while (fi >> array[i].name >> array[i].hobbiesNum)
	{
		// read the next number of strings,
		// number is the 2nd element that was read
		for (j = 0; j < array[i].hobbiesNum; ++j)
		{
			fi >> array[i].hobbies[j];
		}
		// scan the last 3 elements into nested structure
		fi >> array[i].place.street >> array[i].place.city >> 
			array[i].place.index;
		++i;
	}
	fi.close();	// close file (important when dealing with file pointers)
	return i;
}

std::string Read_Hobby(std::ofstream& fo)
{
	std::string string;
	std::cout << "Enter a hobby to search for!" << std::endl;
	fo << "Enter a hobby to search for!" << std::endl;
	std::cin >> string;
	fo << string << std::endl;
	return string;
}

void Output_Data(int size, data *people, std::ofstream& fo)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		std::cout << "Name: " << people[i].name << std::endl;
		std::cout << "Hobbies:" << std::endl;
		fo << "Name: " << people[i].name << std::endl;
		fo << "Hobbies:" << std::endl;
		for (j = 0; j < people[i].hobbiesNum; ++j)
		{
			std::cout << j + 1 << ')' << people[i].hobbies[j] << std::endl;
			fo << j + 1 << ')' << people[i].hobbies[j] << std::endl;
		}
		std::cout << "Address:" << std::endl;
		std::cout << people[i].place.street << ", " << people[i].place.city << 
			std::endl << people[i].place.index << std::endl << std::endl;
		fo << "Address:" << std::endl;
		fo << people[i].place.street << ", " << people[i].place.city << 
			std::endl << people[i].place.index << std::endl << std::endl;
	}
}

void Find_People(int dataSize, data *people, std::string hobbyQuery, 
std::ofstream& fo)
{
	int i, j;
	bool check;
	int check2 = 0;
	std::cout << "People with hobby '" << hobbyQuery << "':" << std::endl;
	// same as cout, but prints into output file
	fo << "People with hobby '" << hobbyQuery << "':" << std::endl;
	for (i = 0; i < dataSize; ++i)
	{
		for (j = 0; j < people[i].hobbiesNum; ++j)
		{
			check = iequals(people[i].hobbies[j], hobbyQuery);
			if (check)	// breaks loop if matching string is found
			{
				check2 = 1;
				break;
			}
		}
		if (check)	// if strings matched, prints the data associated
		{
			std::cout << people[i].name << " - " << people[i].place.street << 
				", " << people[i].place.city << ", " << 
				"index: " << people[i].place.index << std::endl;
			fo << people[i].name << " - " << people[i].place.street << ", " << 
				people[i].place.city << ", " << "index: " << 
				people[i].place.index << std::endl;
		}
	}
	if (check2 == 0)	// if string didnt match with anyone, print following
	{
		std::cout << "No one has such hobby!" << std::endl;
		fo << "No one has such hobby!" << std::endl;
	}
}

bool iequals(const std::string& a, const std::string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}
