/*
 *	Main game class.  Controls game loop and execution.
 */

#include "GameManager.h"

//============================================================

GameManager::GameManager()
{
	// Default constructor
}

//============================================================


void GameManager::initGame()
{
	// Start main game process.
	std::cout << "*** Welcome to MASTERMIND ***" << std::endl;
	std::cout << "This is a game for one player." << std::endl;
	std::cout << "Try to beat the Mastermind by guessing the secret code!" << std::endl;
	std::cout << "Insert red, blue, green, yellow, white, and black pegs to guess." << std::endl;
	std::cout << "In response, a black peg indicates a correct color in the correct position" << std::endl;
	std::cout << "while a white peg indicates a correct color in the wrong position." << std::endl;
	std::cout << "You have twelve guesses to break the code.  Good luck!" << std::endl;

	// Set up the player's information.
	setUpPlayer();

	// Set up the board for play.
	_board.setUpBoard();

	// Run game process.
	runGame();
}

//============================================================

void GameManager::gameOver()
{
	// Runs scripts for end of game.  Asks the player if they want to play again and either quits or resets the board for another game.

	char newGame = ' ';


	// Print results
	// Ask about another game
	std::cout << "Would you like to play again? (y/n) ";
	std::cin >> newGame;
	while (std::cin.fail() || (newGame != 'y' && newGame != 'Y' && newGame != 'n' && newGame != 'N'))
	{
		std::cout << "Invalid entry." << std::endl << "Would you like to play again? (y/n) ";
		std::cin >> newGame;
	}
	
	if (newGame == 'y' || newGame == 'Y')
	{
		_board.resetBoard();
		runGame();
	}
	else if (newGame == 'n' || newGame == 'N')
	{
		std::cout << "Thanks for playing!" << std::endl;
	}
	else
	{
	}
}

//============================================================

bool GameManager::isGameWon()
{
	// Checks to see if the player has guessed the correct code, outputs the hint pegs, and sets the gameWon variable.

	return getGameWon();
}

//============================================================

void GameManager::runGame()
{
	// Runs the main game thread.

	// Sets the initial value for gameWon so we don't prematurely end the game.
	setGameWon(false);

	// Game loop.
	do
	{
		// Output the board to the player.
		_board.printBoard();

		// Get the player's move.
		_board.move();

		// Check for win condition.
	}
	while (!isGameWon());

	// End game state; inquire about playing again.
	gameOver();
}

//============================================================

void GameManager::setUpPlayer()
{
	// Sets up the player's information.

	std::string playerName;
	Player player;

	// Set up player's name and welcome them to the game.
	std::cout << "What is your name? ";
	std::cin >> playerName;
	_player.setName(playerName);
	std::cout << "Welcome to MASTERMIND " << _player.getName() << "!\n" <<  std::endl;
}

//============================================================

bool GameManager::getGameWon()
{
	return _gameWon;
}

//============================================================

void GameManager::setGameWon(bool gameWon)
{
	_gameWon = gameWon;
}

//============================================================