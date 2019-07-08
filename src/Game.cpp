#include "pch.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

Game::Game() noexcept {
	loadLogoFromFileToVector();
	showLogo();
	loadProvincesFromFile();
	startGame();
}

namespace consoleColorHandle {
	HANDLE hOut;
}

void Game::setConsoleTextGreen() {
	consoleColorHandle::hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleColorHandle::hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void Game::setConsoleTextDefault() {
	consoleColorHandle::hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleColorHandle::hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

void Game::loadProvincesFromFile() {
	std::fstream file("provinces.txt");
	if (!file) {
		std::cerr << "Cos poszlo nie tak z wczytywaniem provinces.txt.\n";
		exit(0);
	}
	else {
		std::string lineToRead;
		while (getline(file, lineToRead))
			provinces.push_back(lineToRead);
	}
}
void Game::startGame() {
	std::cout << "\n\nWcisnij dowolny przycisk, a by rozpoczac swoja rozgrywke!\n\n";
	_getch();
	setMonths();
	setProvince();
}
void Game::setProvince() {
	chosenProvince = provinces[Game::random<size_t>(0, 15)];
}

void Game::setMonths() {
	months =
	{ "Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec",
	"Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien" };
}

void Game::showLogo() const {
	for (auto &s : logoArt)
		std::cout <<"\t\t\t\t\t" << s << '\n';
}

void Game::loadLogoFromFileToVector() {
	std::fstream file("logo.txt");
	if (!file) {
		std::cerr << "Cos poszlo nie tak z ladowaniem logo..\n";
		exit(0);
	}
	else {
		std::string lineToRead;
		while (getline(file, lineToRead))
			logoArt.push_back(lineToRead);
	}
}

void Game::cls() {			
	system("cls"); 
}

std::vector<std::string> Game::getMonths() const {
	return months;
}

std::string Game::getProvince() const {
	return chosenProvince;
}
