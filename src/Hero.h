#ifndef HERO_H_
#define HERO_H_
#include <string>
class Hero {
public:
	Hero() = default;
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
	void showHeroStatistics() const;
	void setDefaults();
private:
	std::string name;
	int health;
	int mana;
	size_t strength;
	size_t dexterity;
};
#endif