/*
	author: ferivonus
	last correction: 07.03.2021
	Version: Final
	I wrote this code to astrology interesters. By that, everyone can use my deck. 
 */

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
#include "Cards.h"
bool Controller(int[], int, int);
bool Controller_for_İmput_on_Black_Screen();



int main()
{   
	int length, Controller_for_İmput;
	int random_Number[150] = { 0 }, counter=0;
	string question_text;
	cout << "what is the question of the desk before drawing: ";
	getline(cin, question_text);
	cout << "How numbers cards do we need?"<< endl <<"You Can choose between 0 to 78: ";
	cin >> length;
	srand((unsigned)time(0));
	for (int turn = 0; turn < length; turn++)
	{
		do
		{
			random_Number[turn] = (rand() % 78);
			counter++;
		} while (Controller(random_Number, length, turn));
		random_Number[turn] += (1000 * (rand() % 2));
	}
	if (Controller_for_İmput_on_Black_Screen())
	for (int x = 0;	x < length; x++)
	{
		if (random_Number[x] >= 1000) 
		{
			x++; 
			cout << x << ". card is reverse ";
			x--;
			cout << random_Number[x] - 1000 << endl;
		}
			else 
		{
			x++;
			cout << x << ". card is         ";
			x--;
			cout << random_Number[x] << endl;
		}
	}

	//for txt

	string name, surname, full_Name, Full_Name_for_txt, turner, Reverser;
	cout << "For writing txt with cards names by your name "<< endl <<"Enter your name and surname ";
	cin >> name >> surname;
	full_Name = name + " " + surname;
	Full_Name_for_txt = "The Cards Drawn By " + full_Name + ".txt";
	ofstream File_of_Tarot ( Full_Name_for_txt );
	File_of_Tarot << full_Name << "'s take " << length << " cards \n \nThe question is that, " << question_text << endl << "\nDrawn cards are:\n";
	for (int writing_turn = 0; writing_turn < length; writing_turn++)
	{
		Reverser = "        ";
		if (random_Number[writing_turn] >= 1000)
		{
			Reverser = "Reverse ";
			random_Number[writing_turn] = random_Number[writing_turn] - 1000;
		}
		turner = Writing_to_Txt(random_Number, length, writing_turn);
		writing_turn++;
		File_of_Tarot << writing_turn << ". card is "<< Reverser << turner <<endl << endl ;
		writing_turn--;
	}

	File_of_Tarot.close();
	cout <<"The program draws " <<counter << " cards. ";
	return 0;
}

bool Controller(int random_Number[], int length, int turn)
{
	for (int controller = 0; controller < length; controller++)
	{
		if (turn != controller)
		{
			if (random_Number[turn] == random_Number[controller])
			{
				return true;
			}
		}

	}
	return false;
}

bool Controller_for_İmput_on_Black_Screen()
{
	int Controller_for_İmput, counter = 0;
	do
	{
		if (counter > 0)
			cout << "You made a mistake. You have to write 1 or 0 " << endl;
		cout << "would you want to see card numbers?" << endl << "If you want       write 1" << endl << "If you don't want write 0 " << endl;
		cin >> Controller_for_İmput;
		counter++;
	} while (Controller_for_İmput != 1 && Controller_for_İmput != 0);
	if (Controller_for_İmput == 1)
		return true;
	else if (Controller_for_İmput == 0)
		return false;
}
