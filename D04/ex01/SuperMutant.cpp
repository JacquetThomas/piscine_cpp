/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:37 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 19:50:59 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "SuperMutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & rhs) : Enemy(170, "SuperMutant") {
    *this = rhs;
}

SuperMutant::~SuperMutant(void) {
    std::cout << "Aaargh ..." << std::endl;
}

void    SuperMutant::takeDamage(int damage) {
    Enemy::takeDamage(damage - 3);
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs) {
    Enemy::operator=(rhs);
    return (*this);
}
