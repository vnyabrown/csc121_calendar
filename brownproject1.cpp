/*****************************************************************************************
** File name : cs121_project1_30920.cpp
** This program computes and displays a monthly calender of the users choice!
** The user will enter the year and month, and then the program will display the month!
** Programmer : Naya Brown
** Date created : 3/9/20
*****************************************************************************************/



#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{

	int getmonth, spacefirstday, getyear;
	string month;
	int january = 31, february = 28, march = 31, april = 30, may = 31, june = 30, july = 31, august = 31, september = 30, october = 31, november = 30, december = 31;
	int daysofmonth;
	int sumofdays = 0;
	string dayofweekname;
	string sun = "Sun", mon = "Mon", tue = "Tue", wed = "Wed", thurs = "Thurs", fri = "Fri", sat = "Sat";
	char choice;



	do //do-While loop to run program for as long as user wants to. 
	{
		// 1. Introduce the program! Ask user for their desired month and year.
		cout << "Hello! Welcome to your calender! What month would you like to see? ( Month 1 (January) - 12 (December) )" << endl; //Ask user for desired month
		cin >> getmonth;
		while (getmonth <= 0 || getmonth > 12) // Error check!
		{
			cout << "invalid! Please enter again to find your desired month." << endl;
			cin >> getmonth;
			cout << endl;
		} // end of while loop

		cout << endl;
		cout << "From within what year would you like to find this month?" << endl; // Ask user for desired year
		cin >> getyear;
		while (getyear <= 1800 || getyear >= 3000)
		{
			cout << "Invalid! Please enter again to find your desired year." << endl; // Error check!
			cin >> getyear;
			cout << endl;
		} // end of while loop

		int year = getyear; //Store year value into a different variable to make calculations easier

		// 2. Calculations to find correct values for the calender
		switch (getmonth) // Find how many days are in each month
		{
		case 1:
			month = "January";
			daysofmonth = january;
			sumofdays = 0;
			break;
		case 2:
			month = "February";
			if ((!(year % 4) && (year % 100)) || !(year % 400)) // Find leap year
			{
				february = 29;
				daysofmonth = february;
			}

			else daysofmonth = february;
			sumofdays = january;

			break;
		case 3:
			month = "March";
			daysofmonth = march;
			sumofdays = january + february;
			break;
		case 4:
			month = "April";
			daysofmonth = april;
			sumofdays = january + february + march;
			break;
		case 5:
			month = "May";
			daysofmonth = may;
			sumofdays = january + february + march + april;
			break;
		case 6:
			month = "June";
			daysofmonth = june;
			sumofdays = january + february + march + april + may;
			break;
		case 7:
			month = "July";
			daysofmonth = july;
			sumofdays = january + february + march + april + may + june;
			break;
		case 8:
			month = "August";
			daysofmonth = august;
			sumofdays = january + february + march + april + may + june + july;
			break;
		case 9:
			month = "September";
			daysofmonth = september;
			sumofdays = january + february + march + april + may + june + july + august;
			break;
		case 10:
			month = "October";
			daysofmonth = october;
			sumofdays = january + february + march + april + may + june + july + august + september;
			break;
		case 11:
			month = "November";
			daysofmonth = november;
			sumofdays = january + february + march + april + may + june + july + august + september + october;
			break;
		case 12:
			month = "December";
			daysofmonth = december;
			sumofdays = january + february + march + april + may + june + july + august + september + october + november;
			break;
		default:
			cout << "Something very terrible has happened!" << endl;
		} // end of switch

		//Formula for calculating first day of year
		int yearformula = ((((year - 1) * 365) + floor((year - 1) / 4) - floor((year - 1) / 100) + floor((year - 1) / 400)) + 1);
		int dayofweek = yearformula % 7;

		if (dayofweek % 7 == 0)
		{
			dayofweekname = "Sunday";
		}

		else if (dayofweek % 6 == 0)
		{
			dayofweekname = "Saturday";
		}

		else if (dayofweek % 5 == 0)
		{
			dayofweekname = "Friday";
		}

		else if (dayofweek % 4 == 0)
		{
			dayofweekname = "Thursday";
		}

		else if (dayofweek % 3 == 0)
		{
			dayofweekname = "Wednesday";
		}

		else if (dayofweek % 2 == 0)
		{
			dayofweekname = "Tuesday";
		}

		else if (dayofweek % 1 == 0)
		{
			dayofweekname = "Monday";
		}

		else if (dayofweek == 0)
		{
			dayofweekname = "Sunday";
		}

		else
			cout << "Something terrible has happened!" << endl;


		int dayofmonthweek;

		//Calculating first day of given month
		if (getmonth == 1)
		{
			dayofmonthweek = dayofweek;
		}

		else 
		{
			dayofmonthweek = (dayofweek + sumofdays) % 7;
		}

		// 3. Display your calender!
		cout << endl << endl;
		cout << setw(12) << month << setw(42) << year << endl; // Display year
		cout << setw(8) << sun << setw(8) << mon << setw(8) << tue << setw(8) << wed << setw(8) << thurs << setw(8) << fri << setw(8) << sat << endl; // Display labels of days of week

		for (spacefirstday = 0; spacefirstday < dayofmonthweek; spacefirstday++)
		{
			cout << "        ";
		}
		for (int daycounter = 1; daycounter <= daysofmonth; daycounter++)
		{
			cout << setw(8) << daycounter;
			if (++spacefirstday > 6)
			{
				spacefirstday = 0;
				cout << endl << endl;
			}
		}
		if (spacefirstday)
			cout << "\n\n";
		dayofmonthweek = spacefirstday;

				// 4. Get another calender, or exit the program!
		cout << "Would you like to see another calender?" << endl;
		cout << "Enter Y or N for Yes or No." << endl;
		cin >> choice;

		while (!((choice == 'Y') || (choice == 'y') || (choice == 'N') || (choice == 'n')))
		{
			cout << "Invalid! Enter again." << endl;
			cin >> choice;
		}

	}

	while (choice == 'Y' || choice == 'y');

	return 0;
}