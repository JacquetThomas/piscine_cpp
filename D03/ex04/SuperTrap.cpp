/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:26:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperTrap.hpp"


SuperTrap::SuperTrap(SuperTrap const & SuperTrap) {
    std::cout << "SuperTrap Copy constructor called || " << SuperTrap.getName() << " is copied" << std::endl;
    *this = SuperTrap;
}

SuperTrap::SuperTrap(void) {
    std::cout << "SuperTrap Default constructor called" << std::endl;
    this->_name = "No name";
    this->initValues();
}

SuperTrap::SuperTrap(std::string name) {
    std::cout << "SuperTrap Constructor called for " << name << std::endl;
    this->_name = name;
    this->initValues();
}

SuperTrap::~SuperTrap(void) {
    std::cout << "SuperTrap Destructor called for " << this->_name << std::endl;
}

void        SuperTrap::initValues(void) {
    this->_hitPoints = FragTrap::getHitPoints();
    this->_maxHitPoints = FragTrap::getMaxHitPoints();
    this->_energyPoints = NinjaTrap::getEnergyPoints();
    this->_maxEnergyPoints = NinjaTrap::getMaxEnergyPoints();
    this->_meleeAttackDamage = NinjaTrap::getMeleeAttackDamage();
    this->_rangedAttackDamage = FragTrap::getRangedAttackDamage();
    this->_armorDamageReduction = FragTrap::getArmorDamageReduction();
    this->_type = "SUPER-TP ";
}

void        SuperTrap::rangedAttack(std::string const & target) {
    FragTrap::rangedAttack(target);
}

void        SuperTrap::meleeAttack(std::string const & target) {
    NinjaTrap::meleeAttack(target);
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs){
    FragTrap::operator=(rhs);
    NinjaTrap::operator=(rhs);
    return (*this);
}