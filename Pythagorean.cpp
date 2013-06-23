/**
* @Author: Robert Lu
* @Email: robertlu99@yahoo.com
* @Course: CIS 278
* @G-Number: G00926921
* @Project Number: 1
* @Project Name: Pythagorean
* @Purpose: This program prompts the user for three numbers and informs them if they constitute to a right triangle.
* @Date: 6/21/2013
*/

#include <iostream>
using namespace std;

int numberOne, numberTwo, numberThree = -1;                        //These integers store the three numbers to be entered.
char prompt;                                                       //This character stores the response of the user when asked whether to run the code again.

bool isARightTriangle();                                           //Function identifiers.
int square(int num);

int main()
{

	cout << "The following program prompts the user for three different positive integers." 
		 << "\n" << "It then determines if numbers form the sides of a right triangle." << "\n";

	while (true)												   //Keeps repeating the code until the user decides not to run again.
	{
	
		while (true)                                               //Nested while loop repeats to prompt user for integers until a valid response is given.
		{
		
			cout << "\n" << "Please enter three positive integers (separated by spaces): ";
			cin >> numberOne >> numberTwo >> numberThree;

			cin.clear();										   //Resets the inputstream to prevent invalid values.
		    cin.ignore(numeric_limits<streamsize>::max(),'\n');    //This helps prevent infinite loops when a characcter is entered instead of an integer.


			if (numberOne > 0 && numberTwo > 0 && numberThree > 0)
			{

				break;											   //Breaks free of the while loop if input is valid.

			}
		
			else
			{

				cout << "One or more of the numbers is not positive. Please try again." << "\n";

			}
	
		}

		cout << "\nThe numbers you entered were: " << numberOne << ", " << numberTwo << ", and " << numberThree << ".\n";
		
		isARightTriangle() ? cout << "The values DO constitute to a right triangle." : cout << "The values DO NOT constitute to a right triangle."; //I use the ternary operator in place of an if-else statement. The boolean function is called that determines if the three values make a right triangle and the correct message is printed based on the value of the boolean.

		while (true)                                               //Yet another nested loop to prevent invalid inputs other than Y or N. 
		{
			
			cout << "\n\n" << "Do you want to run this program again? (Y/N): ";

			cin >> prompt;

			if (char(tolower(prompt)) == 'y')                      //I convert the characters to lower case to make the computer recognize register both upper and lower case inputs.
			{

				break;                                             //Breaks free of this nested while loop if user types 'y' to run the main code again.

			}

			else if (char(tolower(prompt)) == 'n')
			{

				exit(0);                                           //If user types 'n', it ends the program and all the loops.

			}

			else
			{

				cout << "\n" << "Please enter Y for yes and N for no.";

			}

		}

	}

	return 0;

}

bool isARightTriangle()                                            //This function finds the largest number and uses it as the hypotenuse, returning true if the values make a right triangle.
{

	if (numberOne >= numberTwo && numberOne >= numberThree)
	{

		return (square(numberOne)) == (square(numberTwo) +  square(numberThree));

	}
	
	else if (numberTwo >= numberThree && numberTwo >= numberOne)
	{

		return (square(numberTwo)) == (square(numberThree) + square(numberOne));

	}

	return (square(numberThree)) == (square(numberTwo) + square(numberOne));

}

int square(int num)                                                //I find that the use of this function helps makes the code a bit easier to read.
{

	return num * num;

}
