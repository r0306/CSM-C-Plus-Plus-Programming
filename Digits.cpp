/**
* @Author: Robert Lu
* @Email: robertlu99@yahoo.com
* @Course: CIS 278
* @G-Number: G00926921
* @Project Number: 1
* @Project Name: Digits
* @Purpose: This program allows the user to enter any number and computes the square and cubes of the specified amount of digits from left to right.
* @Date: 6/21/2013
*/

#include <iostream>
using namespace std;

int number;                           //This variable stores the number entered by the user.
int amount;                           //This variable stores the amount of digits to compute.
int digits;                           //This variable stores the total number of digits the number has.

int getDigits();                      //Function identifier.

int main()
{
	
	cout << "The following program allows the user to enter any number." << "\n" << "It then prints out three columns of numbers." 
		 << "\n" << "The first column displays each digit of the number from left to right." << "\n" << "The second column displays the square of each digit in the first column."
		 << "\n" << "The third column displays the cube of each digit in the first column." << "\n\n";

	while (true)                       //This loop repeats until the user enters a valid number.
	{
	
		cout << "Enter a number: ";
		cin >> number;

		if (number < 0)                //Converts negative numbers into positive numbers for later calculation.
		{

			number *= -1;		

		}

		if (std::cin)                  //Checks to see if input is a valid number and not a string.
		{
			
		    digits = getDigits();      //Calls the function to get the total number of digits in the number and store it in the digits variable.

			break;                     //Once the input is valid, the code breaks from the current loop.

		}

		cin.clear();										   //Resets the inputstream to prevent invalid values.
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');    //This helps prevent infinite loops when a characcter is input instead of an integer.

		cout << "The number you entered is invalid. Please try again." << "\n\n";

	}

	while (true)											   //This loop continues until a valid digit count is entered.
	{

		cout << "\n" << "Enter the maximum number of digits to be processed: ";
		cin >> amount;

		cin.clear();										  
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');    

		if (!std::cin)             
		{

			cout << "The number you have entered is invalid. Please try again." << "\n";

		}

		else if (amount <= 0)       
		{

			cout << "You must enter an amount greater than 0!" << "\n";

		}

		else if (amount > digits)
		{

			cout << "The amount you entered exceeds the actual digit size. Please try again." << "\n";

		}

		else
		{

			break;                                                //If conditions are met, it breaks free of the loop and continues on.

		}

	}

	for (int temp; amount > 0; amount--)                          //The for loop iterates through the amount of digits specified and uses basic math to compute the digits.
	{

		temp = number / pow(10, digits - 1);                      //This line gets the foremost digit of the number.
		number -= (temp * pow(10, digits - 1));                   //This line subtracts the foremost digit from the number and sets it as the new number after the program is done with that digit.
		cout << "\n" << temp << "   " << pow(temp, 2) << "   " << pow(temp, 3);

		digits --;                                                //This line subtracts one digit to match the foremost digit that was subtracted from the original number.

	}                                                             //The loop continues until the amount specified is reached.

	cout << "\n\n" << "The digits are shown above, followed by their squares and cubes." << "\n";

	return 0;

}

int getDigits()                                                   //This function returns the amount of digits in the number entered.
{

	int count = 1;                                                //The variable count keeps track of the number of iterations that represent the amount of digits.

	for (int temp = number; temp > 10; temp /= 10)                //Each iteration divides the current number by 10 until the result is smaller than 10.
	{

		count ++;                                                 //We increment the value of count by one to keep track of the number of digits.

	}

	return count;                                                 //When the loop ends, the total number of digits recorded is returned.

}