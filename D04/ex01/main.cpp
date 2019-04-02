/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:27:40 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:35:40 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "AWeapon.hpp"
 #include "PlasmaRifle.hpp"
 #include "PowerFist.hpp"
 #include "Character.hpp"
 #include "RadScorpion.hpp"
 #include "SuperMutant.hpp"

 int main()
{
    Character* zaz = new Character("zaz");
    std::cout << *zaz;
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);
    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    // Enemy is dead from here
    std::cout << b->getHP() << std::endl;
    zaz->attack(b);
    std::cout << *zaz;
    // No more damage on enemy but nothing say we can't shoot a dead enemy right ?
    std::cout << b->getHP() << std::endl;

    return 0;
}