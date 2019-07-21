#include "pch.h"
#include "Game.h"
#include <fstream>
#include <conio.h>

namespace {
	constexpr auto red = Game::Color::red;
	constexpr auto blue = Game::Color::blue;
	constexpr auto green = Game::Color::green;
	constexpr auto yellow = Game::Color::yellow;
}

Game::Game() noexcept {
	loadDataFromFile("logo.txt", logoArt);
	showLogo();
	loadDataFromFile("provinces.txt", provinces);
	startGame();
}

namespace consoleColorHandle {
	HANDLE hOut;
}

void Game::setConsoleTextColoured(const Color& color) {
	consoleColorHandle::hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color) {
		case Game::Color::red: SetConsoleTextAttribute(consoleColorHandle::hOut, 12); break;
		case Game::Color::green: SetConsoleTextAttribute(consoleColorHandle::hOut, 10); break;
		case Game::Color::blue: SetConsoleTextAttribute(consoleColorHandle::hOut, 11); break; //more like cyan, but for visibility purposes i chosen this one.
		case Game::Color::yellow: SetConsoleTextAttribute(consoleColorHandle::hOut, 14); break;
	}
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

char Game::safeGetChar() {
	char c;
	do
		c = _getch();
	while (std::strchr("123", c) == nullptr);
	return c;
}