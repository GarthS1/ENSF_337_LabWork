/*
*
* lab2exe_F.c
* ENSF 337 - Lab 2 - Exercise F
*
* Write a program that asks a user for a distance in kilometres and vehicle’s average speed,
* and its output is the travel time in hours and minutes
*
*/


#include <stdio.h>
#include <stdlib.h>


void get_user_input(double* distance, double* speed);
/*
Run # Your inputs What is the value
of n
What is the value
of I
What is the value
of d
1 12 0.56 2 12 0.560000
2 5.12 9.56 2 5 0.120000
3 12 ab 1 12 1234.500000
4 ab 12 0 333 1234.500000
5 5ab 9.56 1 5 1234.500000
6 13 67 2 13 67.000000
* REQUIRES
* User has been prompted to type in reads the user input for distance in km, and vehicles speed in
km/hr.
* PROMISES
* Stores values in proper memory
*/

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
/*
* REQUIRES
* Receives the user inputs for distance and speed
* PROMISES
* Calculates travel time in hours and minutes and stores them properly
*
*/

void display_info( double distance, double speed, double hour, double minutes);
/*
* REQUIRES
* All values calculated and from user
* PROMISES
* Displays the distance, speed, hour and minutes
*
*/


int main(void)
{
	double distance, speed, hours, minutes;
	get_user_input(&distance, &speed);
	travel_time_hours_and_minutes(distance, speed, &hours, &minutes);
	display_info(distance, speed, hours, minutes);
	return 0;
}

void get_user_input(double* distance, double* speed)
{
	printf("Please enter the travel distance in km:");
	scanf("%lf", distance);
	printf("Now enter the vehicle's average speed (km/hr):");
	scanf("%lf", speed);
}
void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes)
{
	*hours = (int) (distance / speed);
	*minutes = (distance /speed - *hours) * 60;
}

void display_info( double distance, double speed, double hour, double minutes)
{
	printf("You have travel %.02lf (km) with a speed of %.02lf in %.02lf hour(s) and %.02lf minute(s)",
	distance, speed, hour, minutes);
}