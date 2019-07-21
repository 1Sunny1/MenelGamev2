#include "pch.h"
#include "Gameplay.h"
#include "Game.h"
#include <conio.h>
void dialogueChoiceL (char choice) {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::green);
	switch (choice) {
	case '1': printSleep("\tHere you are. Now let me go.\n", 2000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\tThat's not enough! I am taking your head haha!\n", 2500); break;
	case '2': 
		Game::setConsoleTextColoured(Game::Color::blue);
		printSleep(" << You're trying to run, but stranger is way faster than You: >>\n", 2500);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("You tried to get away from me? Ahaha! Nonsense!\n", 2500); break;
	case '3': 
		Game::setConsoleTextColoured(Game::Color::green);
		printSleep("\tOnly in your dreams. I can kick your arse off\n", 2500);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\tYou will regret that. Come here you fool!\n", 2500); break;
	}
}

void dialogueChoiceR(char choice) {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::blue);
	switch (choice) {
	case '1': 
		printSleep("\t I don't know where i am, let me go.\n", 2000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\tNo man, you violated my territory, You need some penalty for that!\n", 2500); break;
	case '2':
		Game::setConsoleTextColoured(Game::Color::blue);
		printSleep(" << You're trying to run, but stranger is way faster than You: >>\n", 3000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("You tried to get away from me? Ahaha! Nonsense!\n", 2500); break;
	case '3':
		Game::setConsoleTextColoured(Game::Color::green);
		printSleep("\tDo You have some problem, you fatso?\n", 2000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\tI'll crush you small boy!\n", 2000); break;
	}
}

void Gameplay::playerWentLeft() {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::blue);
	printSleep(" << You went left, towards the street. >>\n", 2500);
	printSleep(" << Nearly on the street, stranger hooked to you: >>\n", 2500);
	Game::cls();
	Game::setConsoleTextColoured(Game::Color::yellow);
	printSleep("\tSup stranger, listen to me.\n", 2000);
	printSleep("\tGive me all your money, or i'll take ya head!\n", 2000);
	Game::setConsoleTextDefault();
	std::cout << "[1]Give him your savings\t[2]Run\t[3]Refuse\n";
	char userChoice = Game::safeGetChar();
	dialogueChoiceL(userChoice);
}

void Gameplay::playerWentRight() {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::blue);
	printSleep(" << You went right, towards parking. >> ", 2500);
	printSleep(" << Then you hear someone yelling at you: >> ", 2500);
	Game::cls();
	Game::setConsoleTextColoured(Game::Color::yellow);
	printSleep("\tHey, you! Come here now!\n", 2000);
	printSleep("\tThis is my place, you better have a good reason to be here.\n", 2500);
	Game::setConsoleTextDefault();
	std::cout << "[1]I am lost\t[2]Try to run away\t[3]Do you have a problem with that?\n";
	char userChoice = Game::safeGetChar();
	dialogueChoiceR(userChoice);
}