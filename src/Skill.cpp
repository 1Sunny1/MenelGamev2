#include "pch.h"
#include "Skill.h"

Skill::Skill() noexcept {

}

std::string Skill::getSkillName() const {
	return this->skillName;
}

size_t Skill::getDamage() const {
	return this->damage;
}

size_t Skill::getManaCost() const {
	return this->manaCost;
}