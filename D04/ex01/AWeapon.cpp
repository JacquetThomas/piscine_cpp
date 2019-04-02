/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:40:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 15:20:01 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) {
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = damage;
}

AWeapon::AWeapon(AWeapon const & rhs) {
    *this = rhs;
}

AWeapon::~AWeapon(void) {
}

std::string const & AWeapon::getName(void) const{
    return (this->_name);
}

unsigned int AWeapon::getAPCost(void) const{
    return (this->_apcost);
}

unsigned int AWeapon::getDamage(void) const{
    return (this->_damage);
}

AWeapon & AWeapon::operator=(AWeapon const & rhs) {
    this->_name = rhs.getName();
    this->_apcost = rhs.getAPCost();
    this->_damage = rhs.getDamage();

    return (*this);
}
