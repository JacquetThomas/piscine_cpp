/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:55:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 19:11:46 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	std::cout << "Constructed " << type << std::endl;
	this->_type = type;
}

Weapon::Weapon(void) {
	std::cout << "Constructed Weapon" << std::endl;
}


Weapon::~Weapon(void) {
	std::cout << "Destructed " << this->_type << std::endl;
}

void			Weapon::setType(std::string type) {
	this->_type = type;
}

std::string&	Weapon::getType() {
	return (this->_type);
}