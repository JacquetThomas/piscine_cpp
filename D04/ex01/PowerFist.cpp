/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:37 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:25:14 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("PowerFist", 8, 50) {
}

PowerFist::PowerFist(PowerFist const & rhs) : AWeapon("PowerFist", 8, 50) {
    *this = rhs;
}

PowerFist::~PowerFist(void) {
}

void    PowerFist::attack(void) const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs) {
    AWeapon::operator=(rhs);
    return (*this);
}
