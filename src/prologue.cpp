#include "pch.h"
#include "Game.h"
#include "Interview.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
std::string Game::createDate() {
	unsigned day = Game::random<unsigned>(1, 30);
	unsigned month = Game::random<unsigned>(0, 11);
	unsigned year = Game::random<unsigned>(1950, 2020);
	return std::to_string(day) + " " + getMonths()[month] + " " + std::to_string(year) + "r.";
}

void Game::prologue() {
	cls();
	std::cout << "Data: " << createDate() << '\n';
	Sleep(1000);
	std::cout << "Miejsce: " << getProvince() << " komisariat policji.\n";
	Sleep(2000);
	cls();
	std::cout << "<< Do celi wchodzi policjant >>\n";
	Sleep(2000);
	std::cout << "\t [A wiec menelu, nazywam sie Krzysztof Rootkowski, detektyw generalny ds. Menelni & Brudasow.]\n";
	Sleep(3000);
	cls();
	
	startCharacterCreator();
}

void Game::startCharacterCreator() {
	char userChoice;
	for (auto & it : Interview::dialogue) {
		std::cout << it.first << '\n';
		Sleep(2000);
		std::cout << '\t' << it.second << '\n';
		do {
			userChoice = _getch();
		} while (userChoice != '1' && userChoice != '2' && userChoice != '3');
		mainHero.addRandomAttribute(mainHero);
		Sleep(2000);
	}
}

