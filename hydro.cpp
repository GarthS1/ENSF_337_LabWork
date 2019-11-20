//hydro.cpp

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
#include "list.h"
#include "hydro.h"

int main(void)
{
	FlowList x;
	int numRecords;
	displayHeader();
	numRecords = readData(x);
	cout << numRecords; 
	int quit =0;
	while(1)
	{
		switch(menu())
		{
			case 1:
				// call display function;
				pressEnter();
				break;
			case 2:
				// call addData function
				// call pressEnter;
				break;
			case 3:
				// call saveData function;
				// call pressEnter;
				break;
			case 4:
				// call removeData
				// call presenter;
				break;
			case 5:
				cout << "\nProgram terminated!\n\n";
				quit = 1;
				break;
			default:
				cout << "\nNot a valid input.\n";
				pressEnter();
		}
		if(quit == 1) break;
	}
	return 0;
}

void displayHeader()
{
	cout << "Program: Flow Studies – Fall 2019 \nVersion: 1.0 \nLab Section: B01 \nProduced by: Garth Slaney \n" ;
	pressEnter();
}

int readData(FlowList &x)
{
	ifstream inObj;
	inObj.open("C:\\Users\\Garth\\ENSF_337\\Lab 8\\Exercise E\\flow.txt");
	
	if( ! inObj)
	{
		cout << "Error: can not read file";
		exit(1);
	}
	
	int dataread;
	ListItem* temp = new ListItem; 
	while( !inObj.eof() );
	{
		inObj >> temp -> year >> temp -> flow;
		//x.insert(temp);
		cout << temp -> year << temp -> flow << "\n";
		dataread++;
	}
	
	return dataread;		
}

int menu()
{
	cout << "Please select on the following operations \n 1. Display flow list, average and median \n 2. Add data.\n 3. Save data into the file \n 4. Remove data \n 5. Quit \n Enter your choice (1, 2, 3, 4, or 5): "; 
	int a = 0;
	cin >> a;
	return a;
}

void display()
{
	
}

void addData()
{
	
}

void removeData(int year)
{
	
}

int average()
{
	
}

int median()
{
	
}

void saveData(char *)
{
	
}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue>>>>\n";
	cin.get();
	/*
	//calls the same loop twice because it reads an enter at the begining 
	//after trying to figure out the issue I came up with this work-around
	cin.clear();
	char a;
	do{
		cin.get(a);	
	}while(a != '\n'); 
	
	cin.clear();
	a ='a';
	do{
		cin.get(a);
	}while(a != '\n');
	*/
}
