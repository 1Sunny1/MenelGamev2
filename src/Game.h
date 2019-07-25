#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <Windows.h>
#include "Hero.h"
#include "Skill.h"

static std::mt19937 gen{ std::random_device{}() };

class Game {
public:
	explicit Game() noexcept;
	enum class Color { red, blue, green, yellow };
	static void setConsoleTextColoured(const Color&);
	static void setConsoleTextDefault();
	template<typename T>
	static inline T random(T min, T max) {
		return std::uniform_int_distribution<T>{min, max}(gen);
	}
	static char safeGetCharThreeArgs();
	static char safeGetCharTwoArgs();
	void prologue();
	static void cls();
	std::vector<std::string> getMonths() const;
	std::string getProvince() const;
	void loadDataFromFile(const std::string &, std::vector<std::string>&);
	void startCharacterCreator();
	void setProvince();
	std::string createDate();
	void askIfStatisticsGood();
	void endPrologue();
	Hero getMainHeroObj();
private:
	Hero mainHero;
	void showLogo() const;
	void startGame();
	std::vector<std::string> logoArt;
	std::vector<std::string> months;
	std::vector<std::string> provinces;
	void setMonths();
	std::string chosenProvince;	
};

namespace PrintSleep {
	static void printSleep(std::string str, size_t duration) {
		std::cout << str;
		Sleep(duration);
	}
}

#endif
