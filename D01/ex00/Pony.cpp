/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:01:39 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 10:39:43 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

Pony::Pony() {
	std::cout << "Constructed" << std::endl;
}

Pony::Pony(std::string name) {
	std::cout << "Constructed with name" << std::endl;
	this->_name = name;
}

Pony::~Pony(void) {
	std::cout << "Destructed " << this->_name << std::endl;
}

void		Pony::printInfo(void) {
	std::cout << "My name is " << this->getName() << " and I'm " << this->getColor() << std::endl;
}

void		Pony::setName(std::string name) {
	this->_name = name;
}

std::string	Pony::getName(void) {
	return (this->_name);
}

void		Pony::setColor(std::string color) {
	this->_color = color;
}

std::string	Pony::getColor(void) {
	return (this->_color);
}