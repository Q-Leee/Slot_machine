#include "Game.h"

void Game::money()
{
	for (;;)
	{
		cout << "How much do you want to put? >> ";
		cin >> inicash;
;
		if (inicash < 1)
		{
			cout << "Invalid amount. Please try again.." << endl;
		}
		else
		{
			break;
		}
	}
}

int Game::bet()
{
	int amount = 0;
	cout << "How much do you want to bet? >> ";
	cin >> amount;

	return amount;
}

void Game::slotMachine()
{
	cout << "-----------------------------------" << endl;
	cout << "| @@@@@@@ | SLOT MACHINE | @@@@@@@|" << endl;
	cout << "-----------------------------------" << endl << endl;
}

void Game::credits()
{
}

void Game::wheels(int wheel1, int wheel2, int wheel3)
{
	Sleep(2000);
	cout << "\n\t| " << wheel1 << " | " << wheel2 << " | " << wheel3 << " | \n\n";
}

int Game::check(int wheel1, int wheel2, int wheel3, int winnings, int howMuch)
{
	if (wheel1 == wheel2 && wheel2 == wheel3)
	{
		if (wheel1 == 7 && wheel2 == 7 && wheel3 == 7)
		{
			cout << "@@ JACK POT @@\tYou got Triple 7" << endl;
			cout << "You can get x10" << "\t";
			Sleep(2000);
			cout << "You earn $" << howMuch * 10 << endl;
			winnings += howMuch*10;
		}
		cout << "You got Three of a kind ! Congrats !!" << endl;
		cout << "You can get x5" << "\t";
		Sleep(2000);
		cout << "You earn $" << howMuch * 5 << endl;
		winnings += howMuch*5;
	}
	else if ((wheel1 == wheel2 && wheel2 != wheel3) || (wheel1 != wheel2 && wheel2 == wheel3) || (wheel1 == wheel3 && wheel1 != wheel2))
	{
		cout << "You got Pair ! Congrats !!" << endl;
		cout << "You can get x2" << "\t";
		Sleep(2000);
		cout << "You earn $" << howMuch * 2 << endl;
		winnings += howMuch*2;
	}
	else
	{
		cout << "No Win.. Try Again" << endl;
	}
	
	return winnings;
}

void Game::displaySlotMachine()
{
	//int playercash = inicash;
	int winnings = 0;
	int wheel1 = 0;
	int wheel2 = 0;
	int wheel3 = 0;

	slotMachine();
	money();
	int howMuch = bet();
	Sleep(1000);
	system("cls");

	for (;;)
	{
		srand(time(NULL));
		wheel1 = rand() % 6 + 2;
		wheel2 = rand() % 6 + 2;
		wheel3 = rand() % 6 + 2;

		slotMachine();
		int playercash = inicash - howMuch + winnings;
		cout << "You bet $" << howMuch << "\t\t\t" << playercash << endl;
		inicash -= howMuch;

		cout << "***********************" << endl;		
		wheels(wheel1, wheel2, wheel3);
		winnings = check(wheel1, wheel2, wheel3, winnings, howMuch);
		
		playercash = inicash + winnings;
		cout << "\t\tNew Total $" << playercash << endl << endl;

		cout << "<ENTER> to continue or any other key to finish" << endl;
		if (_getch() == 13)
		{
			system("cls");
		}
		else
		{
			cout << "See you again.." << endl;
			Sleep(2000);
			break;
		}
	}
}

void Game::menu()
{
	string errorString = "InValid Number. Please choose 1,2 or 3..";
	int choice = 0;
	
	for (;;)
	{	
		cout << "1.Play, 2.Credits, 3.Exit >> ";		
		cin >> choice;
		system("cls");

		if (choice == 1)
		{	
			displaySlotMachine();
		}
		else if (choice == 2)
		{
			credits();
		}
		else if (choice == 3)
		{

		}
		else
		{
			cout << errorString << endl;
			Sleep(2000);
			system("cls");
		}
	}
}
