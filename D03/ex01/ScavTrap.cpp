/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/28 15:48:15 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(ScavTrap const & ScavTrap) {
    std::cout << "ScavTrap Copy constructor called || " << ScavTrap.getName() << " is copied" << std::endl;
    *this = ScavTrap;
}

ScavTrap::ScavTrap(void) {
    std::cout << "Default ScavTrap constructor called" << std::endl;
    this->_name = "No name";
    this->initValues();
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap Constructor called for " << name << std::endl;
    this->_name = name;
    this->initValues();
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap Destructor called for " << this->_name << std::endl;
}

void        ScavTrap::initValues(void) {
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeAttackDamage = 20;
    this->_rangedAttackDamage = 15;
    this->_armorDamageReduction = 5;
}

void        ScavTrap::rangedAttack(std::string const & target) {
    std::cout << "SC4V-TP your servitor " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " damages, sorry ;)" << std::endl;
}

void        ScavTrap::meleeAttack(std::string const & target) {
    std::cout << "SC4V-TP your servitor " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " damages, sorry ;)" << std::endl;
}

void        ScavTrap::takeDamage(unsigned int amount) {
    unsigned int    damage;

    if (this->_hitPoints == 0) {
        std::cout << "SC4V-TP " << this->_name << " Stop it! i'm already dead !" << std::endl;
        return ;
    }
    damage = amount - this->getArmorDamageReduction();
    std::cout << "SC4V-TP " << this->_name << " takes " << damage << " damages" << std::endl;
    if (damage >= this->getHitPoints()) {
        this->setHitPoints(0);
        std::cout << "SC4V-TP " << this->_name << " Aaaannnnnd I'm dead." << std::endl;
    } else {
        this->_hitPoints -= damage;
    }
}

void        ScavTrap::beRepaired(unsigned int amount) {
    if (amount > this->_energyPoints) {
        std::cout << "SC4V-TP " << this->_name << " Not enough energy !" << std::endl;
    } else if (amount + this->_hitPoints > this->_maxHitPoints) {
        this->_hitPoints = this->_maxHitPoints;
        this->_energyPoints = ((int)this->_energyPoints - (int)amount < 0) ? 0 : this->_energyPoints - amount;
    } else {
        this->_hitPoints += amount;
        this->_energyPoints -= amount;
    }
}

void        ScavTrap::challengeNewcomer(void) {
    int         randn = rand() % 5;
    std::string challenges[] = {"Listen nyan cat for no reason for 5 hours.",
                                "Act like a cat.",
                                "Jumps every two step.",
                                "Read the entire dictionary.",
                                "Draw cats all over the floor."};
        std::cout << "SC4V-TP " << this->_name << " you have to " << challenges[randn] << " Good Luck !" << std::endl;
}

void        ScavTrap::setName(std::string name) {
    this->_name = name;
}

void        ScavTrap::setHitPoints(unsigned int hitPoints) {
    this->_hitPoints = hitPoints;
}

void        ScavTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    this->_maxHitPoints = maxHitPoints;
}

void        ScavTrap::setEnergyPoints(unsigned int energyPoints) {
    this->_energyPoints = energyPoints;
}

void        ScavTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    this->_maxEnergyPoints = maxEnergyPoints;
}

void        ScavTrap::setLevel(unsigned int level) {
    this->_level = level;
}

void        ScavTrap::setMeleeAttackDamage(unsigned int meleeAttackDamage) {
    this->_meleeAttackDamage = meleeAttackDamage;
}

void        ScavTrap::setRangedAttackDamage(unsigned int rangedAttackDamage) {
    this->_rangedAttackDamage = rangedAttackDamage;
}

void        ScavTrap::setArmorDamageReduction(unsigned int armorDamageRedcution) {
    this->_armorDamageReduction = armorDamageRedcution;
}

std::string ScavTrap::getName(void) const{
    return (this->_name);
}

unsigned int         ScavTrap::getHitPoints(void) const{
    return (this->_hitPoints);
}

unsigned int         ScavTrap::getMaxHitPoints(void) const{
    return (this->_maxHitPoints);
}

unsigned int         ScavTrap::getEnergyPoints(void) const{
    return (this->_energyPoints);
}

unsigned int         ScavTrap::getMaxEnergyPoints(void) const{
    return (this->_maxEnergyPoints);
}

unsigned int         ScavTrap::getLevel(void) const{
    return (this->_level);
}

unsigned int         ScavTrap::getMeleeAttackDamage(void) const{
    return (this->_meleeAttackDamage);
}

unsigned int         ScavTrap::getRangedAttackDamage(void) const{
    return (this->_rangedAttackDamage);
}

unsigned int         ScavTrap::getArmorDamageReduction(void) const{
    return (this->_armorDamageReduction);
}


ScavTrap & ScavTrap::operator=(ScavTrap const & rhs){
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->_rangedAttackDamage = rhs.getRangedAttackDamage();
    this->_armorDamageReduction = rhs.getArmorDamageReduction();

    return (*this);
}