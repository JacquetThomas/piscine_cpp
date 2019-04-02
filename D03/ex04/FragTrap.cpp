/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:28:59 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"


FragTrap::FragTrap(FragTrap const & FragTrap) {
    std::cout << "FragTrap Copy constructor called || " << FragTrap.getName() << " is copied" << std::endl;
    *this = FragTrap;
}

FragTrap::FragTrap(void) {
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->_name = "No name";
    this->initValues();
}

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap Constructor called for " << name << std::endl;
    this->_name = name;
    this->initValues();
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap Destructor called for " << this->_name << std::endl;
}

void        FragTrap::initValues(void) {
    ClapTrap::initValues();
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_meleeAttackDamage = 30;
    this->_rangedAttackDamage = 20;
    this->_armorDamageReduction = 5;
    this->_nononoCatAttackDamage = 0;
    this->_kitlerCatAttackDamage = 666;
    this->_nyanCatAttackDamage = 42;
    this->_keyboardCatAttackDamage = 10;
    this->_ceillingCatAttackDamage = 32;
    this->_type = "FR4G-TP ";
}

void        FragTrap::nononoCatAttack(std::string const & target) {
    std::cout << this->_type << this->_name << " attacks " << target << " with nonono cat, causing " << this->_nononoCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::kitlerCatAttack(std::string const & target) {
        std::cout << this->_type<< this->_name << " attacks " << target << " with kitler cat, causing " << this->_kitlerCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::nyanCatAttack(std::string const & target) {
            std::cout << this->_type << this->_name << " attacks " << target << " with nyan cat, causing " << this->_nyanCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::keyboardCatAttack(std::string const & target) {
        std::cout << this->_type<< this->_name << " attacks " << target << " with keyboard cat, causing " << this->_keyboardCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::ceillingCatAttack(std::string const & target) {
            std::cout << this->_type << this->_name << " attacks " << target << " with ceilling cat, causing " << this->_ceillingCatAttackDamage << " damages" << std::endl;
}

void        FragTrap::vaulthunter_dot_exe(std::string const & target) {
    int     randn = rand() % 5;

    if (this->_energyPoints >= 25) {
        if (randn == 0) 
            nononoCatAttack(target);
        else if (randn == 1)
            kitlerCatAttack(target);
        else if (randn == 2)
            nyanCatAttack(target);
        else if (randn == 3)
            keyboardCatAttack(target);
        else
            ceillingCatAttack(target);
    this->_energyPoints -= 25;
    } else 
        std::cout << this->_type << this->_name << " Not enough energy !" << std::endl;
}

void        FragTrap::setNononoCatAttackDamage(unsigned int nononoCatAttackDamage) {
    this->_nononoCatAttackDamage = nononoCatAttackDamage;
}

void        FragTrap::setKitlerCatAttackDamage(unsigned int kitlerCatAttackDamage) {
    this->_kitlerCatAttackDamage = kitlerCatAttackDamage;
}

void        FragTrap::setNyanCatAttackDamage(unsigned int nyanCatAttackDamage) {
    this->_nyanCatAttackDamage = nyanCatAttackDamage;
}

void        FragTrap::setKeyboardCatAttackDamage(unsigned int keyboardCatAttackDamage) {
    this->_keyboardCatAttackDamage = keyboardCatAttackDamage;
}

void        FragTrap::setCeillingCatAttackDamage(unsigned int ceillingCatAttackDamage) {
    this->_ceillingCatAttackDamage = ceillingCatAttackDamage;
}

unsigned int        FragTrap::getNononoCatAttackDamage(void) const{
    return (this->_nononoCatAttackDamage);
}

unsigned int        FragTrap::getKitlerCatAttackDamage(void) const{
    return (this->_kitlerCatAttackDamage);
}

unsigned int        FragTrap::getNyanCatAttackDamage(void) const{
    return (this->_nyanCatAttackDamage);
}

unsigned int        FragTrap::getKeyboardCatAttackDamage(void) const{
    return (this->_keyboardCatAttackDamage);
}

unsigned int        FragTrap::getCeillingCatAttackDamage(void) const{
    return (this->_ceillingCatAttackDamage);
}

FragTrap & FragTrap::operator=(FragTrap const & rhs){
   ClapTrap::operator=(rhs);
    this->_nononoCatAttackDamage = rhs.getNononoCatAttackDamage();
    this->_kitlerCatAttackDamage = rhs.getKitlerCatAttackDamage();
    this->_nyanCatAttackDamage = rhs.getNyanCatAttackDamage();
    this->_keyboardCatAttackDamage = rhs.getKeyboardCatAttackDamage();
    this->_ceillingCatAttackDamage = rhs.getCeillingCatAttackDamage();
    return (*this);
}