/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:37:08 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap(NinjaTrap const & NinjaTrap) {
    std::cout << "NinjaTrap Copy constructor called || " << NinjaTrap.getName() << " is copied" << std::endl;
    *this = NinjaTrap;
}

NinjaTrap::NinjaTrap(void) {
    std::cout << "NinjaTrap Default constructor called" << std::endl;
    this->_name = "No name";
    this->initValues();
}

NinjaTrap::NinjaTrap(std::string name) {
    std::cout << "NinjaTrap Constructor called for " << name << std::endl;
    this->_name = name;
    this->initValues();
}

NinjaTrap::~NinjaTrap(void) {
    std::cout << "NinjaTrap Destructor called for " << this->_name << std::endl;
}

void        NinjaTrap::initValues(void) {
    ClapTrap::initValues();
    this->_hitPoints = 60;
    this->_maxHitPoints = 60;
    this->_energyPoints = 120;
    this->_maxEnergyPoints = 120;
    this->_meleeAttackDamage = 60;
    this->_rangedAttackDamage = 5;
    this->_armorDamageReduction = 0;
    this->_scavTrapAttackDamage = 42;
    this->_fragTrapAttackDamage = 43;
    this->_clapTrapAttackDamage = 44;
    this->_type = "NINJ4-TP ";
}

void        NinjaTrap::ninjaShoebox(FragTrap & frag) {
    std::cout << "NINJ4-TP " << this->_name << " attacks " << frag.getName() << " with saber, causing " << this->_fragTrapAttackDamage << " damages" << std::endl;
}

void        NinjaTrap::ninjaShoebox(ScavTrap & scav) {
    std::cout << "NINJ4-TP " << this->_name << " attacks " << scav.getName() << " with shuriken, causing " << this->_scavTrapAttackDamage << " damages" << std::endl;
}

void        NinjaTrap::ninjaShoebox(ClapTrap & clap) {
    std::cout << "NINJ4-TP " << this->_name << " attacks " << clap.getName() << " with sai, causing " << this->_clapTrapAttackDamage << " damages" << std::endl;
}

void        NinjaTrap::ninjaShoebox(NinjaTrap & ninja) {
    std::cout << "NINJ4-TP " << this->_name << " can't attacks " << ninja.getName() << " because it's a ninja too" << std::endl;
}

void        NinjaTrap::setFragTrapAttackDamage(unsigned int damage) {
    this->_fragTrapAttackDamage = damage;
}

void        NinjaTrap::setScavTrapAttackDamage(unsigned int damage) {
    this->_scavTrapAttackDamage = damage;
}

void        NinjaTrap::setClapTrapAttackDamage(unsigned int damage) {
    this->_clapTrapAttackDamage = damage;
}

unsigned int        NinjaTrap::getFragTrapAttackDamage(void) const{
    return (this->_fragTrapAttackDamage);
}

unsigned int        NinjaTrap::getScavTrapAttackDamage(void) const{
    return (this->_scavTrapAttackDamage);
}

unsigned int        NinjaTrap::getClapTrapAttackDamage(void) const{
    return (this->_clapTrapAttackDamage);
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs){
    ClapTrap::operator=(rhs);
    this->_fragTrapAttackDamage = rhs.getFragTrapAttackDamage();
    this->_scavTrapAttackDamage = rhs.getScavTrapAttackDamage();
    this->_clapTrapAttackDamage = rhs.getClapTrapAttackDamage();
    return (*this);
}