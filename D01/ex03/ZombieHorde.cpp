/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:54:18 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 11:15:57 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
	std::cout << "Constructed ZombieHorde" << std::endl;
	this->_zombieType = "horde";
	this->_horde = new Zombie[n];
	this->_nb = n;
	for (int i = 0; i < n; i++) {
		this->_horde[i].setType(this->_zombieType);
		this->_horde[i].setName(this->randomChump());
	}
}

ZombieHorde::ZombieHorde(void) {
	std::cout << "Constructed empty ZombieHorde" << std::endl;
	this->_zombieType = "horde";
	this->_nb = 0;
}

ZombieHorde::~ZombieHorde(void) {
	for (int i = 0; i < this->_nb; i++) {
		this->_horde[i].~Zombie();
	}
	std::cout << "Destructed ZombieHorde" << std::endl;
}

void	ZombieHorde::setZombieType(std::string zombieType) {
	this->_zombieType = zombieType;
}

std::string	ZombieHorde::randomChump() {
	std::string	names[10] = {"Timothe", "Charles", "Eugene", "Hector", "William", "Fabrice", "Valentin", "Serge", "Armand", "Thibault"};
	int			randn;

	randn = rand() % 9;
	return (names[randn]);
}

void		ZombieHorde::announce(void) {
	for (int i = 0; i < this->_nb; i++) {
		this->_horde[i].announce();
	}
}
