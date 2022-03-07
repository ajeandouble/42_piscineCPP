#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type)
{
	this->_hp = hp;
	this->_type = type;
}

Enemy::~Enemy()
{
}

Enemy &Enemy::operator=(const Enemy &e)
{
	this->_hp = e.getHP();
	this->_type = e.getType();
	return (*this);
}

std::string Enemy::getType() const
{
	return (this->_type);
}

int Enemy::getHP() const
{
	int hp = this->_hp;
	return (hp);
}

void Enemy::takeDamage(int damage)
{
	this->_hp -= damage;
	if (this->_hp <= 0)
		this->_hp = 0;
}
