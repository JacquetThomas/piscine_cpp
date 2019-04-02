/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:40:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 12:58:59 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name) {
    this->_name = name;
    std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & rhs) {
    *this = rhs;
}

Victim::Victim(void) {
}

Victim::~Victim(void) {
    std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

void        Victim::setName(std::string name) {
    this->_name = name;
}

std::string Victim::getName(void) const{
    return (this->_name);
}

void        Victim::getPolymorphed(void) const {
    std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

Victim & Victim::operator=(Victim const & rhs) {
    this->_name = rhs.getName();

    return (*this);
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs) {
    o << "I am " << rhs.getName() << " and I like otters!" << std::endl;
    return (o);
}