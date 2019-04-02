/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:57:38 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 13:41:47 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
    Zombie      un;
    Zombie      deux;
    Zombie      *trois;
    ZombieEvent event;

    un.announce();
    deux.setName("Arnold");
    deux.setType("half-dolphin");
    deux.announce();
    event.randomChump();
    event.setZombieType("random");
    event.randomChump();
    trois = event.newZombie("Felix");
    trois->announce();
    delete trois;
    return (0);
}