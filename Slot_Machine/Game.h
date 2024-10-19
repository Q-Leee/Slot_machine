#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Game
{
	int inicash;
public:
	Game() : inicash(0) {}
	void money();
	int bet();
	void slotMachine();
	void credits();
	void wheels(int wheel1, int wheel2, int wheel3);
	int check(int wheel1, int wheel2, int wheel3, int winnings, int howMuch);
	void displaySlotMachine();
	void menu();
};

