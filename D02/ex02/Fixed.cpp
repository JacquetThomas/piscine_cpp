/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 18:08:22 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {

    return ;
}

Fixed::Fixed(Fixed const & fixed) {
    *this = fixed;

    return ;
}

Fixed::Fixed(int const number) {
    this->_number = number << this->frac;
}

Fixed::Fixed(float const number) {
    this->_number = (int)roundf(number * (1 << this->frac));
}

Fixed::~Fixed(void) {
}

Fixed & Fixed::operator=(Fixed const & rhs){
    this->_number = rhs.getRawBits();

    return (*this);
}

Fixed  Fixed::operator+(Fixed const & rhs){
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed  Fixed::operator-(Fixed const & rhs){
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed &Fixed::operator--(void){
    this->_number = this->_number - 1;
    return (*this);
}

Fixed &Fixed::operator--(int){
    Fixed   *n = new Fixed(*this);

    operator--();
    return (*n);
}

Fixed &Fixed::operator++(void){
    this->_number = this->_number + 1;
    return (*this);
}

Fixed &Fixed::operator++(int){
    Fixed   *n = new Fixed(*this);

    operator++();
    return (*n);
}

Fixed  Fixed::operator*(Fixed const & rhs){
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed  Fixed::operator/(Fixed const & rhs){
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool  Fixed::operator>(Fixed const & rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool  Fixed::operator<(Fixed const & rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool  Fixed::operator>=(Fixed const & rhs) const {
    return (this->getRawBits() >= rhs.getRawBits());
}

bool  Fixed::operator<=(Fixed const & rhs)const {
    return (this->getRawBits() <= rhs.getRawBits());
}

bool  Fixed::operator==(Fixed const & rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

bool  Fixed::operator!=(Fixed const & rhs) const {
    return (this->getRawBits() != rhs.getRawBits());
}

float   Fixed::toFloat(void) const {
    return ((float)this->_number / (1 << this->frac));
}

int     Fixed::toInt(void) const {
    return (this->_number );
}

int     Fixed::getRawBits() const {
    return (this->_number);
}

void    Fixed::setRawBits(int const raw) {
    this->_number = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return (o);
}

Fixed &         Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

Fixed const &         Fixed::min(Fixed const &a, Fixed const &b) {
    return (a < b ? a : b);
}

Fixed &         Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

Fixed  const &         Fixed::max(Fixed const &a, Fixed const &b) {
    return (a > b ? a : b);
}
