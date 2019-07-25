#include "pch.h"
#include "Skill.h"

Skill::Skill(std::string skillname, size_t damage, size_t manacost) noexcept 
	: skillName(skillname), damage(damage), manaCost(manacost) {}

std::string Skill::getSkillName() const {
	return this->skillName;
}

size_t Skill::getDamage() const {
	return this->damage;
}

size_t Skill::getManaCost() const {
	return this->manaCost;
}
