/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:12:41 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 09:40:25 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void) {
	Phonebook::Phonebook    phonebook;
    std::string command;

    std::cout << "Welcome in your phonebook !" << std::endl;
    std::cout << "Available commands are : ADD | SEARCH | EXIT" << std::endl;

    std::cout << "command : ";
    std::cin >> command;
    while (command.compare("EXIT") != 0) {
        if (command.compare("ADD") == 0) {
            phonebook.addContact();
        } else if (command.compare("SEARCH") == 0) {
            phonebook.search();
        } else {
            std::cout << "I can't answer that" << std::endl;
        }
        std::cout << "command : ";
        std::cin >> command;
    }
    return (0);
}
