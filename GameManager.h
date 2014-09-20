#pragma once

#include <iostream>
#include <string>

#include "Board.h"
#include "Player.h"

//============================================================

class GameManager
{

//============================================================

	public:
		GameManager();

		void gameOver();
		void initGame();
		bool isGameWon();
		void runGame();
		void setUpPlayer();

		bool getGameWon();
		void setGameWon(bool gameWon);

//============================================================

	private:
		Board _board;
		bool _gameWon;
		Player _player;

//============================================================

	protected:
};

//============================================================