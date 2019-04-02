/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/27 18:48:10 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
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

Fixed::Fixed(int const number) {
    std::cout << "Int constructor called" << std::endl;
    this->_number = number << this->frac;
}

Fixed::Fixed(float const number) {
    std::cout << "Float constructor called" << std::endl;
    this->_number = (int)roundf(number * (1 << this->frac));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    std::cout << "Assignation operator called" << std::endl;
    this->_number = rhs.getRawBits();

    return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return (o);
}

float   Fixed::toFloat(void) const {
    return ((float)this->_number / (1 << this->frac));
}

int     Fixed::toInt(void) const {
    return (this->_number >> this->frac);
}

int     Fixed::getRawBits() const {
    return (this->_number);
}

void    Fixed::setRawBits(int const raw) {
    this->_number = raw;
}