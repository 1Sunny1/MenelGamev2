#include "pch.h"
#include "Game.h"
#include "Interview.h"
#include "Gameplay.h"
#include <conio.h>

std::string Game::createDate() {
	unsigned int day = Game::random<unsigned>(1, 30);
	unsigned int month = Game::random<unsigned>(0, 11);
	unsigned int year = Game::random<unsigned>(1950, 2020);
	return std::to_string(day) + " " + getMonths()[month] + " " + std::to_string(year);
}
void Game::askIfStatisticsGood() {
	Game::setConsoleTextColoured(Game::Color::blue);
	std::cout << "<< Do you accept these stats? >>\n";
	Game::setConsoleTextDefault();
	std::cout << "[1]Continue\t[2]Randomize\n";
	do {
		char userChoice;
		do
			userChoice = _getch();
		while (userChoice != '1' && userChoice != '2');
		if (userChoice == '2') {
			mainHero.setDefaults();
			for (auto i = 0; i < 5; ++i)
				mainHero.addRandomAttribute(mainHero);
			mainHero.showHeroStatistics();
			std::cout << "\n[1]Continue\t[2]Randomize\n";
		}
		else
			break;
	} while (true);
}

void Game::prologue() {
	using namespace PrintSleep;
	cls();
	setConsoleTextColoured(Game::Color::blue);
	std::cout << "Date: ";
	printSleep(createDate(), 2000);
	std::cout << "\nPlace: ";
	printSleep(getProvince() + " police department", 2000);
	cls();
	printSleep("<< Suddenly a policeman enters the cell >>\n", 2000);
	setConsoleTextColoured(Game::Color::yellow);
	printSleep("\t [So, I am Christopher Rootkowsky, detective general for special affairs.]\n", 3000);
	setConsoleTextDefault();
	cls();
	startCharacterCreator();
	cls();
	setConsoleTextColoured(Game::Color::yellow);
	printSleep("\t[Fine, thats enough informations about You.]\n", 3000);
	printSleep("\t[Our meeting has already come to an end.]\n", 3000);
	cls();
	printSleep("\t[Behind the corner in the cupboard there are your confiscated items.]\n", 3000);
	printSleep("\t[Take it and leave immediately.]", 3000);
	cls();
	setConsoleTextColoured(Game::Color::blue);
	printSleep("<< You're leaving interrogation room and takes your backpack with few items. >>\n", 3000);
	printSleep("<< then You left police department. >>\n", 3000);
	cls();
	printSleep("<< a summary of Your hero's statistics: >>\n", 1000);
	setConsoleTextDefault();
	mainHero.showHeroStatistics();
	askIfStatisticsGood();
	cls();
	Sleep(2000);
	endPrologue();
}

void Game::startCharacterCreator() {
	char userChoice;
	mainHero.setDefaults();
	for (const auto & it : Interview::dialogue) {
		setConsoleTextColoured(Game::Color::yellow);
		PrintSleep::printSleep(it.first + '\n', 2000);
		setConsoleTextDefault();
		std::cout << '\t' << it.second << '\n';
		do {
			userChoice = _getch();
		} while (userChoice != '1' && userChoice != '2' && userChoice != '3');
		mainHero.addRandomAttribute(mainHero);
		cls();
	}
	setConsoleTextColoured(Game::Color::yellow);
	std::cout << "\t[Okay, so the last question is: what is your name?]\n";
	std::string tempName;
	setConsoleTextColoured(Game::Color::green);
	std::cout << "[My name is...]";
	setConsoleTextColoured(Game::Color::blue);
	std::cout << " << Enter the name of your hero!>> : ";
	getline(std::cin, tempName);
	mainHero.setName(tempName);
	setConsoleTextDefault();
}

void Game::endPrologue() {
	using PrintSleep::printSleep;
	setConsoleTextColoured(Game::Color::blue);
	printSleep(" << Behind the police station door there are two alleys >>\n", 2000);
	printSleep(" << Wchich one you go? >>\n", 1000);
	setConsoleTextDefault();
	std::cout << "[1]Left\t[2]Right\n";
	char userChoice;
	do
		userChoice = _getch();
	while (userChoice != '1' && userChoice != '2');
	if (userChoice == '1') {
		Gameplay x;
		x.playerWentLeft();
	}
	else {
		Gameplay y;
		y.playerWentRight();
	}
}
