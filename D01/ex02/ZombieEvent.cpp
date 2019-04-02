/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:54:18 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 13:45:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
	std::cout << "Constructed ZombieEvent" << std::endl;
	this->_zombieType = "default";
}

ZombieEvent::~ZombieEvent(void) {
	std::cout << "Destructed ZombieEvent" << std::endl;
}

void	ZombieEvent::setZombieType(std::string zombieType) {
	this->_zombieType = zombieType;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	Zombie*	newZombie = new Zombie(name, _zombieType);
	return (newZombie);
}

void	ZombieEvent::randomChump() {
	std::string	names[10] = {"Timothe", "Charles", "Eugene", "Hector", "William", "Fabrice", "Valentin", "Serge", "Armand", "Thibault"};
	int			randn;
	Zombie		chump;

	randn = rand() % 9;
	chump.setName(names[randn]);
	chump.setType(this->_zombieType);
	chump.announce();
}