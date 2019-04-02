/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:15:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 17:10:27 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {
	std::cout << "Constructed Human" << std::endl;
}



Human::~Human(void) {
	std::cout << "Destructed Human " << std::endl;
}

std::string	Human::identify(void) {
	return (this->_brain.identify());
}

Brain	Human::getBrain(void) {
	return (this->_brain);
}