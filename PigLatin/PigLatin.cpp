// PigLatin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

const int stringLength = 50;

int countLetters(char ph[stringLength]);
void moveLetter(char ph[stringLength]);
bool notConjunction(char ph[stringLength]);
void translateToPigLatin(char ph[stringLength]);



int main()
{
	char word[stringLength];
	char answer;

	do //Loop to repeat program 
	{
		do //Loop if they entered nothing or a number so that it can restart
		{
			cout << "Please enter a word so that it can be translated into Pig Latin: ";
			cin >> word;

			if (isalpha(word[0]) && word != " ")//condition to make sure user entered a valid word
			{
				translateToPigLatin(word);
				break;
			}
			else
				cout << "Either you entered nothing or " << "your word starts with a number. " << endl;
			cout << " Try again? enter y for yes: ";
			cin >> answer;

		} while (answer == 'Y' || answer == 'y');


		cout << endl;
		cout << "Would you like to do another word? Use 'Y' for yes. ";
		cin >> answer;

	} while (answer == 'Y' || answer == 'y');


    return 0;
}


int countLetters(char ph[stringLength]) //counts number of letters in word 
{
	int i;
	int count = 0;

	// counting just the characters in a phrase not including spaces
	for (i = 0; ph[i] != '\0'; i++)
	{
		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z'))
			count++;
	}
	return count;
}


void moveLetter(char ph[stringLength])
{
	char temp = ph[0];//stores the first letter in another string
	int i;

	for (i = 0; i < stringLength - 1 && ph[i + 1] != 0; i++)
	{
		ph[i] = ph[i + 1];//shifts letters to the left of its original position in the string 
	}
	ph[i] = temp;//adds the original 
}


bool notConjunction(char ph[stringLength])//Takes care of the conjunction condition
{
	if (!strcmp(ph, "and"))
	{
		return true;
	}
	if (!strcmp(ph, "but"))
	{
		return true;
	}
	if (!strcmp(ph, "for"))
	{
		return true;
	}
	if (!strcmp(ph, "nor"))
	{
		return true;
	}
	if (!strcmp(ph, "yet"))
	{
		return true;
	}
	else
		return false;
}

void translateToPigLatin(char ph[stringLength])//Pig latin translator
{
	char pigAddOn[] = "ay";//array to add-on the end of words that fit the conditions 

	if (notConjunction(ph) == false)//calls the conjunction function 
	{
		if (countLetters(ph) > 2 && strcmp(ph, "the")) /* takes care of article parameters and
													   any words */
		{
			if ((ph[0] != 'a' && ph[0] != 'A') && (ph[0] != 'e' && ph[0] != 'E')
				&& (ph[0] != 'i' && ph[0] != 'I') && (ph[0] != 'o' && ph[0] != 'O')
				&& (ph[0] != 'u' && ph[0] != 'U'))/* Tests whether first character is a vowel or not. 
												  I'm sure there's a more efficient and effective way
												  of doing this, but I didn't want to mess with it. */
			{
				moveLetter(ph);
				strcat(ph, pigAddOn);
				cout << "Your word in Pig Latin: " << ph << endl;
			}
			else
			{
				strcat(ph, pigAddOn);
				cout << "Your word in Pig Latin: " << ph << endl;
			}
		}
		else
			cout << "Your word in Pig Latin: " << ph << endl;
	}
	else
		cout << "Your word in Pig Latin: " << ph << endl;
}

