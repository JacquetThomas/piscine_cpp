/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:57:38 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 11:13:58 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void) {
    ZombieHorde Horde = ZombieHorde(10);
    ZombieHorde Horde2 = ZombieHorde(1);
    ZombieHorde Horde3 = ZombieHorde();

    Horde.announce();
    Horde2.announce();
    Horde3.announce();
    return (0);
}
