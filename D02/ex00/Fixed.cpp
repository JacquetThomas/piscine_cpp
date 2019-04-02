/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/27 15:56:16 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
    std::cout << "Default constructor called" << std::endl;

    return ;
}

Fixed::Fixed(Fixed const & fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;

    return ;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    std::cout << "Assignation operator called" << std::endl;
    this->_number = rhs.getRawBits();

    return (*this);
}

int     Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_number);
}

void    Fixed::setRawBits(int const raw) {
    this->_number = raw;
}