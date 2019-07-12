#ifndef SKILL_H_
#define SKILL_H_
#include <string>
class Skill {
public:
	explicit Skill() noexcept;
	std::string getSkillName() const;
	size_t getDamage() const;
	size_t getManaCost() const;
private:
	std::string skillName;
	size_t damage;
	size_t manaCost;
};

#endif
