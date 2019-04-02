/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:37 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:24:39 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("PlasmaRifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & rhs) : AWeapon("PlasmaRifle", 5, 21) {
    *this = rhs;
}

PlasmaRifle::~PlasmaRifle(void) {
}

void    PlasmaRifle::attack(void) const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs) {
    AWeapon::operator=(rhs);
    return (*this);
}
