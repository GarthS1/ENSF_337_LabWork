//hydro.cpp

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include "list.h"
#include "hydro.h"

int main(void)
{
	FlowList x;
	int numRecords;
	int quit = 0;
	
	displayHeader();
	numRecords = readData(x);
	while(1)
	{
		switch(menu())
		{
			case 1:
				display(numRecords, x); 
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
				removeData(x, numRecords);
				pressEnter();
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

void displayHeader() //works 
{
	cout << "Program: Flow Studies – Fall 2019 \nVersion: 1.0 \nLab Section: B01 \nProduced by: Garth Slaney \n" ;
	pressEnter();
}

int readData(FlowList &x) //works 
{
	ifstream inObj;
	int dataread = 0;
	ListItem temp;
	
	inObj.open("C:\\Users\\Garth\\Documents\\GitHub\\ENSF_337_LabWork\\flow.txt");
	
	if( !inObj )
	{
		cout << "Error: can not read file";
		exit(1);
	}
	
	while( !inObj.eof() )
	{
		inObj >> temp.year;
		inObj >> temp.flow;
		x.insert(temp);
		dataread++;
	}
	
	inObj.close();
	return dataread;		
}

int menu() //works 
{
	cout << "Please select on the following operations \n 1. Display flow list, average and median \n 2. Add data.\n 3. Save data into the file \n 4. Remove data \n 5. Quit \n Enter your choice (1, 2, 3, 4, or 5): "; 
	int a = 0;
	cin >> a;
	return a;
}

void display(int num, FlowList &x) //works
{
	Node* tracker = x.headM;
	cout << "Year    Flow (in billions of cubic meters) \n" ;
	for(int i = 0; i < num; i++)
	{
		cout << tracker -> item.year <<"             " << tracker -> item.flow << endl;
		tracker = tracker ->next;
	}
	
	cout << "The annual average of the flow is: " << average(num, x) <<  " billions cubic meter \n" ; 
	cout << "The median flow is " << median(num, x) << " billions cubic meter \n";
}

void addData()
{
	
}

void removeData(FlowList &x, int & num) //works
{
	int year;
	cout << "Please enter the year that you want to remove: " ; 
	cin >> year;
	if(x.remove(year))
	{
		cout << "Record was successfully removed.";
		num --;
	}
	else
	{
		cout << "Error: No such a data.";
	}
}

double average(int num, FlowList &x) // works
{
	Node* tracker = x.headM;
	double sum = 0;
	for(int i = 0; i < num; i++)
	{
		sum += tracker -> item.flow;
		tracker = tracker ->next;
	}
	
	return sum / (double)num ;
}

double median(int num, FlowList &x) //works
{
	int before, after;
	Node* tracker = x.headM;
	if( num % 2 == 0)
	{
		num = num / 2;
		for(int i = 0; i < num; i++)
		{
		tracker = tracker ->next;
		}
		
		return tracker -> item.flow; 
	}
	else
	{
		before = floor( (double) num / 2);
		after = ceil( (double) num / 2);
		double sum = 0;
		for(int i = 1; i <= num ; i++)
		{
			if(i == before || i == after)
			{
				sum += tracker -> item.flow;
			}
			tracker = tracker ->next;
		}	
		return sum / 2;
	}
}

void saveData(char *)
{
	
}

void pressEnter() //need to try and fix a little or at least add comments 
{
	cout << "\n<<< Press Enter to Continue>>>>\n";
	//cin.clear();
	//cin.get();
	
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

}
