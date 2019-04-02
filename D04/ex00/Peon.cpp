/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:40:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 14:54:52 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name) {
    this->_name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & rhs) : Victim(rhs.getName()) {
    *this = rhs;
}

Peon::~Peon(void) {
    std::cout << "Bleuark..." << std::endl;
}

void        Peon::getPolymorphed(void) const {
    std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}

Peon & Peon::operator=(Peon const & rhs) {
	Victim::operator=(rhs);

	return (*this);
}
