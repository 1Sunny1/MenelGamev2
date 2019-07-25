#ifndef HERO_H_
#define HERO_H_
#include <string>
#include <vector>
#include "Skill.h"
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
	int punchDamage();
	void showSkills();
private:
	void fillSkillCollection();
	std::vector<Skill> skillCollection;
	std::string name;
	int health;
	int mana;
	size_t strength;
	size_t dexterity;
private:
	int maxHealth{ health };
	int maxMana{ mana };
	size_t maxStrength{ strength };
	size_t maxDexterity{ dexterity };
private:
	int punchDmg;
	int fireball_damage();
	int lightning_damage();
	int heal();
	int meditation();
};
#endif