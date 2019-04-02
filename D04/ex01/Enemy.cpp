/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:00:33 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:27:17 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) {
    this->_hitPoints = hp;
    this->_type = type;
}

Enemy::Enemy(void) {
}

Enemy::Enemy(Enemy const & rhs) {
    *this = rhs;
}

Enemy::~Enemy(void) {
}

std::string const & Enemy::getType(void) const {
    return (this->_type);
}

int     Enemy::getHP(void) const{
    return (this->_hitPoints);
}

void    Enemy::takeDamage(int damage) {
    if (this->_hitPoints > 0) {
        this->_hitPoints -= damage;
        if (this->_hitPoints <= 0)
            this->~Enemy();
    }
}

Enemy & Enemy::operator=(Enemy const & rhs) {
    this->_hitPoints = rhs.getHP();
    return (*this);
}
