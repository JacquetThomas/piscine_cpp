/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:54:27 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 13:46:48 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "Constructed Zombie" << std::endl;
	this->_name = "Randone";
	this->_type = "Basic";
}

Zombie::Zombie(std::string name, std::string type) {
	std::cout << "Constructed with parameters " << name << std::endl;
	this->_name = name;
	this->_type = type;
}

Zombie::~Zombie(void) {
	std::cout << "Destructed " << this->_name << std::endl;
}

void		Zombie::announce(void) {
	std::cout << "< " << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void		Zombie::setName(std::string name) {
	this->_name = name;
}

std::string	Zombie::getName(void) {
	return (this->_name);
}

void		Zombie::setType(std::string type) {
	this->_type = type;
}

std::string	Zombie::getType(void) {
	return (this->_type);
}