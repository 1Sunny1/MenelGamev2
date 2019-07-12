#include "pch.h"
#include "Game.h"
#include "Interview.h"
#include <conio.h>
std::string Game::createDate() {
	unsigned int day = Game::random<unsigned>(1, 30);
	unsigned int month = Game::random<unsigned>(0, 11);
	unsigned int year = Game::random<unsigned>(1950, 2020);
	return std::to_string(day) + " " + getMonths()[month] + " " + std::to_string(year);
}

void Game::prologue() {
	using namespace PrintSleep;
	cls();
	std::cout << "Date: ";
	printSleep(createDate(), 2000);
	std::cout << "\nPlace: ";
	printSleep(getProvince() + " police department", 2000);
	cls();
	printSleep("<< Suddenly a policeman enters the cell >>\n", 2000);
	printSleep("\t [So, I am Christopher Rootkowsky, detective general for special affairs.]\n", 3000);
	cls();
	startCharacterCreator();
	cls();
	printSleep("\t[Fine, thats enough informations about You.]\n", 3000);
	printSleep("\t[Our meeting has already come to an end.]\n", 3000);
	cls();
	printSleep("\t[Behind the corner in the cupboard there are your confiscated items.]\n", 3000);
	printSleep("\t[Take it and leave immediately.]", 3000);
	cls();
	printSleep("<< You're leaving interrogation room and takes your backpack with few items. >>\n", 3000);
	printSleep("<< then You left police department. >>\n", 3000);
	cls();
	printSleep("<< a summary of Your hero's statistics: >>\n", 1000);
	mainHero.showHeroStatistics();
}

void Game::startCharacterCreator() {
	char userChoice;
	mainHero.setDefaults();
	for (const auto & it : Interview::dialogue) {
		PrintSleep::printSleep(it.first + '\n', 2000);
		std::cout << '\t' << it.second << '\n';
		do {
			userChoice = _getch();
		} while (userChoice != '1' && userChoice != '2' && userChoice != '3');
		mainHero.addRandomAttribute(mainHero);
		cls();
	}
	std::cout << "\t[Okay, so the last question is: what is your name?]\n";
	std::string tempName;
	std::cout << "[My name is...] << Enter the name of your hero!>> : ";
	getline(std::cin, tempName);
	mainHero.setName(tempName);
	
}

