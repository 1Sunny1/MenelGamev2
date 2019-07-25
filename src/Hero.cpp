#include "pch.h"
#include "Hero.h"
#include "Game.h"
Hero::Hero(std::string name, int health, int mana, int strength, int dexterity) noexcept
	: name(name), health(health), mana(mana), strength(strength), dexterity(dexterity) {}

std::string Hero::getName() const {
	return this->name;
}
size_t Hero::getDexterity() const {
	return this->dexterity;
}

size_t Hero::getStrength() const {
	return this->strength;
}

int Hero::getHealth() const {
	return this->health;
}

int Hero::getMana() const {
	return this->mana;
}

void Hero::addStrength(size_t amount) {
	this->strength += amount;
}

void Hero::addDexterity(size_t amount) {
	this->dexterity += amount;
}

void Hero::addHealth(int amount) {
	this->health += amount;
}

void Hero::addMana(int amount) {
	this->mana += amount;
}

void Hero::setName(const std::string & name) {
	this->name = name;
}

int Hero::punchDamage() {
	return punchDmg = Game::random<int>(this->strength - 10, this->strength + 15);
}

void Hero::addRandomAttribute(Hero & hero) {
	switch (int randNumber = Game::random<int>(0, 3)) {
	case 0: hero.addDexterity(Game::random<size_t>(5, 10)); break;
	case 1: hero.addStrength(Game::random<size_t>(5, 10)); break;
	case 2: hero.addHealth(Game::random<int>(10, 30)); break;
	case 3: hero.addMana(Game::random<int>(10, 30)); break;
	}
}

void Hero::showHeroStatistics() const {
	std::cout << "|Name: \t\t" << this->name << '\n';
	std::cout << "|Strength: \t" << this->strength << '\n';
	std::cout << "|Dexterity: \t" << this->dexterity << '\n';
	std::cout << "|Health: \t" << this->health << '\n';
	std::cout << "|Mana: \t\t" << this->mana << '\n';
}

void Hero::setDefaults() {
	this->strength = 10;
	this->dexterity = 10;
	this->health = 40;
	this->mana = 40;
}

int percent(int percent, int value) {
	return (percent * value) / 100;
}

int Hero::fireball_damage() {
	return Game::random<int>(percent(20, this->mana), percent(40, this->mana));
}
int Hero::lightning_damage() {
	return Game::random<int>(0, this->mana);
}
int Hero::heal() {
	return 30 + percent(30, this->mana);
}
int Hero::meditation() {
	return percent(30, this->maxMana);
}

void Hero::showSkills() {
	for (const auto &skill : skillCollection)
		skill.getSkillName();
}

void Hero::fillSkillCollection() {
	Skill fireball("Fireball", fireball_damage(), 30);
	Skill lightning("Lightning bolt", lightning_damage(), 50);
	Skill heal("Heal", heal(), 40);
	Skill meditation("Meditation", meditation(), 0);
	skillCollection.push_back(fireball);
	skillCollection.push_back(lightning);
	skillCollection.push_back(heal);
	skillCollection.push_back(meditation);
	
}