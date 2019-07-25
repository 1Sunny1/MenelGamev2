#ifndef SKILL_H_
#define SKILL_H_
#include <string>
#include <vector>
class Skill {
public:
	Skill() = delete;
	explicit Skill(std::string skillname, size_t damage, size_t manacost) noexcept;
	std::string getSkillName() const;
	size_t getDamage() const;
	size_t getManaCost() const;
private:
	std::string skillName;
	size_t damage;
	size_t manaCost;
};

#endif
