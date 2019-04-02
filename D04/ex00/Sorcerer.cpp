/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:40:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 13:48:21 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) {
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & rhs) {
    *this = rhs;
}

Sorcerer::~Sorcerer(void) {
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

void        Sorcerer::setName(std::string name) {
    this->_name = name;
}

void        Sorcerer::setTitle(std::string title) {
    this->_title = title;
}

std::string Sorcerer::getName(void) const{
    return (this->_name);
}

std::string Sorcerer::getTitle(void) const{
    return (this->_title);
}

void        Sorcerer::polymorph(Victim const &victim) const {
    victim.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs) {
    this->_name = rhs.getName();
    this->_title = rhs.getTitle();

    return (*this);
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs) {
    o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies!" << std::endl;
    return (o);
}