#ifndef HERO_H_
#define HERO_H_
#include <string>
#include <memory>
class Hero {
public:
	Hero() = delete;
	Hero(std::string name, int health, int mana, int strength, int dexterity) noexcept;
	std::string getName() const;
	int getHealth() const;
	int getMana() const;
	size_t getStrength() const;
	size_t getDexterity() const;
	void addStrength(size_t);
	void addDexterity(size_t);
	void addHealth(int);
	void addMana(int);
	void setName(const std::string &);
	void addRandomAttribute(Hero&);
private:
	std::string name;
	int health;
	int mana;
	size_t strength;
	size_t dexterity;
};

class Skills {
public:
	Skills();
private:
	std::string skillName;
	size_t damage;
	size_t manaCost;
};
#endif