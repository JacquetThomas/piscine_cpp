/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:23:04 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(ClapTrap const & ClapTrap) {
    std::cout << "ClapTrap Copy constructor called || " << ClapTrap.getName() << " is copied" << std::endl;
    *this = ClapTrap;
}

ClapTrap::ClapTrap(void) {
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->_name = "No name";
    this->initValues();
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap Constructor called for " << name << std::endl;
    this->_name = name;
    this->initValues();
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap Destructor called for " << this->_name << std::endl;
}

void        ClapTrap::initValues(void) {
    this->_level = 1;
    this->_type = "CL4P-TP ";
}

void        ClapTrap::rangedAttack(std::string const & target) {
    std::cout << this->_type << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " damages" << std::endl;
}

void        ClapTrap::meleeAttack(std::string const & target) {
    std::cout << this->_type << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " damages" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount) {
    unsigned int    damage;

    if (this->_hitPoints == 0) {
        std::cout << this->_type << this->_name << " Stop it! i'm already dead !" << std::endl;
        return ;
    }
    damage = amount - this->getArmorDamageReduction();
    std::cout << this->_type << this->_name << " takes " << damage << " damages" << std::endl;
    if (damage >= this->getHitPoints()) {
        this->setHitPoints(0);
        std::cout << this->_type << this->_name << " Aaaannnnnd I'm dead." << std::endl;
    } else {
        this->_hitPoints -= damage;
    }
}

void        ClapTrap::beRepaired(unsigned int amount) {
    if (amount > this->_energyPoints) {
        std::cout << this->_type << this->_name << " Not enough energy !" << std::endl;
    } else if (amount + this->_hitPoints > this->_maxHitPoints) {
        this->_hitPoints = this->_maxHitPoints;
        this->_energyPoints = ((int)this->_energyPoints - (int)amount < 0) ? 0 : this->_energyPoints - amount;
    } else {
        this->_hitPoints += amount;
        this->_energyPoints -= amount;
    }
}

void        ClapTrap::setName(std::string name) {
    this->_name = name;
}

void        ClapTrap::setType(std::string type) {
    this->_type = type;
}

void        ClapTrap::setHitPoints(unsigned int hitPoints) {
    this->_hitPoints = hitPoints;
}

void        ClapTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    this->_maxHitPoints = maxHitPoints;
}

void        ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    this->_energyPoints = energyPoints;
}

void        ClapTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    this->_maxEnergyPoints = maxEnergyPoints;
}

void        ClapTrap::setLevel(unsigned int level) {
    this->_level = level;
}

void        ClapTrap::setMeleeAttackDamage(unsigned int meleeAttackDamage) {
    this->_meleeAttackDamage = meleeAttackDamage;
}

void        ClapTrap::setRangedAttackDamage(unsigned int rangedAttackDamage) {
    this->_rangedAttackDamage = rangedAttackDamage;
}

void        ClapTrap::setArmorDamageReduction(unsigned int armorDamageRedcution) {
    this->_armorDamageReduction = armorDamageRedcution;
}

std::string ClapTrap::getName(void) const{
    return (this->_name);
}

std::string ClapTrap::getType(void) const{
    return (this->_type);
}

unsigned int         ClapTrap::getHitPoints(void) const{
    return (this->_hitPoints);
}

unsigned int         ClapTrap::getMaxHitPoints(void) const{
    return (this->_maxHitPoints);
}

unsigned int         ClapTrap::getEnergyPoints(void) const{
    return (this->_energyPoints);
}

unsigned int         ClapTrap::getMaxEnergyPoints(void) const{
    return (this->_maxEnergyPoints);
}

unsigned int         ClapTrap::getLevel(void) const{
    return (this->_level);
}

unsigned int         ClapTrap::getMeleeAttackDamage(void) const{
    return (this->_meleeAttackDamage);
}

unsigned int         ClapTrap::getRangedAttackDamage(void) const{
    return (this->_rangedAttackDamage);
}

unsigned int         ClapTrap::getArmorDamageReduction(void) const{
    return (this->_armorDamageReduction);
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs){
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->_rangedAttackDamage = rhs.getRangedAttackDamage();
    this->_armorDamageReduction = rhs.getArmorDamageReduction();
    this->_type = rhs.getType();
    return (*this);
}

void    ClapTrap::printInfo(void) { 
    std::cout << "--- INFORMATIONS FOR " << this->_name << " OF TYPE " << this->_type << "LEVEL " << this->_level << " ---" << std::endl;
    std::cout << "hit points : " << this->_hitPoints << " \tmax hit points : " << this->_maxHitPoints << std::endl;
    std::cout << "energy points : " << this->_energyPoints << " \tmax energy points : " << this->_maxEnergyPoints << std::endl;
    std::cout << "melee damage : " << this->_meleeAttackDamage << " \tranged damage : " << this->_rangedAttackDamage << std::endl;
    std::cout << "armor reduction : " << this->_armorDamageReduction << std::endl;

}