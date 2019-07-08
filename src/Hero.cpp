#include "pch.h"
#include "Hero.h"
#include "Game.h"
Hero::Hero(std::string name, int health, int mana, int strength, int dexterity) noexcept
	: name(name), health(health), mana(mana), strength(strength), dexterity(dexterity) {


}

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

void Hero::addRandomAttribute(Hero & hero) {
	switch (int randNumber = Game::random<int>(0, 4)) {
	case 0: hero.addDexterity(Game::random<size_t>(5, 10)); break;
	case 1: hero.addStrength(Game::random<size_t>(5, 10)); break;
	case 2: hero.addHealth(Game::random<int>(20, 50)); break;
	case 3: hero.addMana(Game::random<int>(20, 50)); break;
	}
}