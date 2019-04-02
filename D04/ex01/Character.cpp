/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:16:04 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:22:54 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) {
    this->_name = name;
    this->_actionPoints = 40;
    this->_weapon = NULL;
}

Character::Character(void) {
}

Character::Character(Character const & rhs) {
    *this = rhs;
}

Character::~Character(void) {
}

std::string const &  Character::getName(void) const{
    return (this->_name);
}

int     Character::getActionPoints(void) const{
    return (this->_actionPoints);
}

AWeapon *Character::getWeapon(void) const {
    return (this->_weapon); 
}

void    Character::equip(AWeapon *weapon) {
    this->_weapon = weapon;
}

void    Character::attack(Enemy *enemy) {
    if (this->_weapon && this->_actionPoints > (int)this->_weapon->getAPCost()) {
        std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->attack();
        this->_actionPoints -= this->_weapon->getAPCost();
        enemy->takeDamage(this->_weapon->getDamage());
    }

}

void    Character::recoverAP(void) {
    if (this->_actionPoints <= 30)
        this->_actionPoints += 10;
    else if (this->_actionPoints > 30)
        this->_actionPoints = 40;
}

Character & Character::operator=(Character const & rhs) {
    this->_name = rhs.getName();
    this->_actionPoints = rhs.getActionPoints();
    this->_weapon = rhs.getWeapon();
    return (*this);
}


std::ostream & operator<<(std::ostream & o, Character const & rhs) {
    if (rhs.getWeapon())
        o << rhs.getName() << " has " << rhs.getActionPoints() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        o << rhs.getName() << " has " << rhs.getActionPoints() << " AP and is unarmed" << std::endl;

    return (o);
}