/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:15:16 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 17:14:01 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Constructed Brain" << std::endl;
	void *address = this;
	std::stringstream straddr;
	straddr << address;
	this->_address = straddr.str();
}

Brain::~Brain(void) {
	std::cout << "Destructed Brain" << std::endl;
}

std::string	Brain::identify(void) const {
	return (this->_address);
}