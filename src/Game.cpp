#include "pch.h"
#include "Game.h"
#include <fstream>
#include <conio.h>

Game::Game() noexcept {
	loadDataFromFile("logo.txt", logoArt);
	showLogo();
	loadDataFromFile("provinces.txt", provinces);
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

void Game::loadDataFromFile(const std::string & filename, std::vector<std::string> & collection) {
	std::fstream file(filename);
	if (!file) {
		std::cerr << "Error loading " << filename << ".\n";
		exit(0);
	}
	else {
		std::string lineToRead;
		while (getline(file, lineToRead))
			collection.push_back(lineToRead);
	}
}
void Game::startGame() {
	std::cout << "\n\nPress any button to begin\n\n";
	_getch();
	setMonths();
	setProvince();
}
void Game::setProvince() {
	chosenProvince = provinces[Game::random<size_t>(0, 15)];
}

void Game::setMonths() {
	months =
	{"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December" };
}

void Game::showLogo() const {
	for (auto &s : logoArt)
		std::cout <<"\t\t\t\t\t" << s << '\n';
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
