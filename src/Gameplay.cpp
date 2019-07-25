#include "pch.h"
#include "Gameplay.h"
#include "Game.h"
#include "Skill.h"
#include <conio.h>
void dialogueChoiceL (char choice) {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::green);
	switch (choice) {
	case '1': printSleep("[Here you are. Now let me go.]\n", 2000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\t[That's not enough! I am taking your head haha!]\n", 2500); break;
	case '2': 
		Game::setConsoleTextColoured(Game::Color::blue);
		printSleep(" << You're trying to run, but stranger is way faster than You: >>\n", 2500);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\t[You tried to get away from me? Ahaha! Nonsense!]\n", 2500); break;
	case '3': 
		Game::setConsoleTextColoured(Game::Color::green);
		printSleep("[Only in your dreams. I can kick your arse off]\n", 2500);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\t[You will regret that. Come here you fool!]\n", 2500); break;
	}
}

void dialogueChoiceR(char choice) {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::blue);
	switch (choice) {
	case '1': 
		printSleep("[I don't know where i am, let me go.]\n", 2000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\t[No man, you violated my territory, You need some penalty for that!]\n", 2500); break;
	case '2':
		Game::setConsoleTextColoured(Game::Color::blue);
		printSleep(" << You're trying to run, but stranger is way faster than You: >>\n", 3000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\t[You tried to get away from me? Ahaha! Nonsense!]\n", 2500); break;
	case '3':
		Game::setConsoleTextColoured(Game::Color::green);
		printSleep("[Do You have some problem, you fatso?]\n", 2000);
		Game::setConsoleTextColoured(Game::Color::yellow);
		printSleep("\t[I'll crush you small boy!]\n", 2000); break;
	}
}

void Gameplay::playerWentLeft() {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::blue);
	printSleep(" << You went left, towards the street. >>\n", 2500);
	printSleep(" << Nearly on the street, stranger hooked to you: >>\n", 2500);
	Game::cls();
	Game::setConsoleTextColoured(Game::Color::yellow);
	printSleep("\t[Sup stranger, listen to me.]\n", 2000);
	printSleep("\t[Give me all your money, or i'll take ya head!]\n", 2000);
	Game::setConsoleTextDefault();
	std::cout << "[1]Give him your savings\t[2]Run\t[3]Refuse\n";
	char userChoice = Game::safeGetCharThreeArgs();
	dialogueChoiceL(userChoice);
	Hero suspicious_g("Suspicious greybeard", 50, 100, 20, 10);
	fight(suspicious_g);
}

void Gameplay::playerWentRight() {
	using PrintSleep::printSleep;
	Game::setConsoleTextColoured(Game::Color::blue);
	printSleep(" << You went right, towards parking. >> ", 2500);
	printSleep(" << Then you hear someone yelling at you: >> ", 2500);
	Game::cls();
	Game::setConsoleTextColoured(Game::Color::yellow);
	printSleep("\t[Hey, you! Come here now!]\n", 2000);
	printSleep("\t[This is my place, you better have a good reason to be here.]\n", 2500);
	Game::setConsoleTextDefault();
	std::cout << "[1]I am lost\t[2]Try to run away\t[3]Do you have a problem with that?\n";
	char userChoice = Game::safeGetCharThreeArgs();
	dialogueChoiceR(userChoice);
	Hero bulky_b("Bulky Brandon", 150, 10, 30, 10);
	fight(bulky_b);
}

void Gameplay::fight(Hero& enemy) {
	Hero mHero = getMainHeroObj();
	Game::setConsoleTextColoured(Game::Color::blue);
	std::cout << "\t<< Fight between " << enemy.getName() << " and " << mHero.getName() << " has started! >> ";
	Game::setConsoleTextDefault();
	char userChoice;
	do {
		std::cout << "Your health: " << mHero.getHealth() << "\tEnemy's health: " << enemy.getHealth() << '\n';
		std::cout << "Your mana: " << mHero.getMana() << "\tEnemy's mana: " << enemy.getMana() << '\n';
		std::cout << "[1]Punch" << "\t[2]Use skill" << '\n';
		userChoice = Game::safeGetCharTwoArgs();
		if (userChoice == '1') {
			std::cout << " << " << mHero.getName() << " uderzyl przeciwnika za " << mHero.punchDamage() << " obrazen! >> \n";
			enemy.addHealth(-(mHero.punchDamage()));
		}
		if (userChoice == '2') {
			mHero.showSkills();
			Sleep(10000);
			exit(0);
		}
	} while (true);
}