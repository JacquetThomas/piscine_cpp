/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/28 15:05:02 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"


FragTrap::FragTrap(FragTrap const & FragTrap) {
    std::cout << "Copy constructor called || " << FragTrap.getName() << " is copied" << std::endl;
    *this = FragTrap;
}

FragTrap::FragTrap(void) {
    std::cout << "Default constructor called" << std::endl;
    this->_name = "No name";
    this->initValues();
}

FragTrap::FragTrap(std::string name) {
    std::cout << "Constructor called for " << name << std::endl;
    this->_name = name;
    this->initValues();
}

FragTrap::~FragTrap(void) {
    std::cout << "Destructor called for " << this->_name << std::endl;
}

void        FragTrap::initValues(void) {
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeAttackDamage = 30;
    this->_rangedAttackDamage = 20;
    this->_armorDamageReduction = 5;
    this->_nononoCatAttackDamage = 0;
    this->_kitlerCatAttackDamage = 666;
    this->_nyanCatAttackDamage = 42;
    this->_keyboardCatAttackDamage = 10;
    this->_ceillingCatAttackDamage = 32;
}

void        FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " damages" << std::endl;
}

void        FragTrap::meleeAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " damages" << std::endl;
}

void        FragTrap::nononoCatAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with nonono cat, causing " << this->_nononoCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::kitlerCatAttack(std::string const & target) {
        std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with kitler cat, causing " << this->_kitlerCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::nyanCatAttack(std::string const & target) {
            std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with nyan cat, causing " << this->_nyanCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::keyboardCatAttack(std::string const & target) {
        std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with keyboard cat, causing " << this->_keyboardCatAttackDamage << " damages" << std::endl;
}
void        FragTrap::ceillingCatAttack(std::string const & target) {
            std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with ceilling cat, causing " << this->_ceillingCatAttackDamage << " damages" << std::endl;
}

void        FragTrap::takeDamage(unsigned int amount) {
    unsigned int    damage;

    if (this->_hitPoints == 0) {
        std::cout << "FR4G-TP " << this->_name << " Stop it! i'm already dead !" << std::endl;
        return ;
    }
    damage = amount - this->getArmorDamageReduction();
    std::cout << "FR4G-TP " << this->_name << " takes " << damage << " damages" << std::endl;
    if (damage >= this->getHitPoints()) {
        this->setHitPoints(0);
        std::cout << "FR4G-TP " << this->_name << " Aaaannnnnd I'm dead." << std::endl;
    } else {
        this->_hitPoints -= damage;
    }
}

void        FragTrap::beRepaired(unsigned int amount) {
    if (amount > this->_energyPoints) {
        std::cout << "FR4G-TP " << this->_name << " Not enough energy !" << std::endl;
    } else if (amount + this->_hitPoints > this->_maxHitPoints) {
        this->_hitPoints = this->_maxHitPoints;
        this->_energyPoints = ((int)this->_energyPoints - (int)amount < 0) ? 0 : this->_energyPoints - amount;
    } else {
        this->_hitPoints += amount;
        this->_energyPoints -= amount;
    }
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
        std::cout << "FR4G-TP " << this->_name << " Not enough energy !" << std::endl;
}

void        FragTrap::setName(std::string name) {
    this->_name = name;
}

void        FragTrap::setHitPoints(unsigned int hitPoints) {
    this->_hitPoints = hitPoints;
}

void        FragTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    this->_maxHitPoints = maxHitPoints;
}

void        FragTrap::setEnergyPoints(unsigned int energyPoints) {
    this->_energyPoints = energyPoints;
}

void        FragTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    this->_maxEnergyPoints = maxEnergyPoints;
}

void        FragTrap::setLevel(unsigned int level) {
    this->_level = level;
}

void        FragTrap::setMeleeAttackDamage(unsigned int meleeAttackDamage) {
    this->_meleeAttackDamage = meleeAttackDamage;
}

void        FragTrap::setRangedAttackDamage(unsigned int rangedAttackDamage) {
    this->_rangedAttackDamage = rangedAttackDamage;
}

void        FragTrap::setArmorDamageReduction(unsigned int armorDamageRedcution) {
    this->_armorDamageReduction = armorDamageRedcution;
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

std::string FragTrap::getName(void) const{
    return (this->_name);
}

unsigned int         FragTrap::getHitPoints(void) const{
    return (this->_hitPoints);
}

unsigned int         FragTrap::getMaxHitPoints(void) const{
    return (this->_maxHitPoints);
}

unsigned int         FragTrap::getEnergyPoints(void) const{
    return (this->_energyPoints);
}

unsigned int         FragTrap::getMaxEnergyPoints(void) const{
    return (this->_maxEnergyPoints);
}

unsigned int         FragTrap::getLevel(void) const{
    return (this->_level);
}

unsigned int         FragTrap::getMeleeAttackDamage(void) const{
    return (this->_meleeAttackDamage);
}

unsigned int         FragTrap::getRangedAttackDamage(void) const{
    return (this->_rangedAttackDamage);
}

unsigned int         FragTrap::getArmorDamageReduction(void) const{
    return (this->_armorDamageReduction);
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
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->_rangedAttackDamage = rhs.getRangedAttackDamage();
    this->_armorDamageReduction = rhs.getArmorDamageReduction();
    this->_nononoCatAttackDamage = rhs.getNononoCatAttackDamage();
    this->_kitlerCatAttackDamage = rhs.getKitlerCatAttackDamage();
    this->_nyanCatAttackDamage = rhs.getNyanCatAttackDamage();
    this->_keyboardCatAttackDamage = rhs.getKeyboardCatAttackDamage();
    this->_ceillingCatAttackDamage = rhs.getCeillingCatAttackDamage();
    return (*this);
}