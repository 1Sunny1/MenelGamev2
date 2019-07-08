#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <string>
#include <random>
#include "Hero.h"
static std::mt19937 gen{ std::random_device{}() };
class Game final {
public:
	explicit Game() noexcept;
	static void setConsoleTextGreen();
	static void setConsoleTextDefault();
	template<typename T>
	static inline T random(T min, T max) {
		return std::uniform_int_distribution<T>{min, max}(gen);
	}
	void prologue();
	static void cls();
	std::vector<std::string> getMonths() const;
	std::string getProvince() const;
	void loadProvincesFromFile();
	void startCharacterCreator();
	void setProvince();
	std::string createDate();
private:
	Hero mainHero("def",0,0,0,0);
	void showLogo() const;
	void startGame();
	std::vector<std::string> logoArt;
	void loadLogoFromFileToVector();
	std::vector<std::string> months;
	std::vector<std::string> provinces;
	void setMonths();
	std::string chosenProvince;
};

#endif
