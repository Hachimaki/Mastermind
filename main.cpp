/*
 *	Tic-tac-toe challenge
 *	Main game class
 */

#include <iostream>
#include <string>

#include "GameManager.h"

//============================================================
// Global variables

GameManager gameManager;

//============================================================
// Function prototypes

//============================================================
// Class definitions

//============================================================
// main
int main()
{
	gameManager.initGame();

	system("PAUSE");
	return 0;
}

//============================================================
// End main.cpp