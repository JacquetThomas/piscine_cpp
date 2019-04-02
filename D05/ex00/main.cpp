/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:54:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 12:15:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void ) {
    Bureaucrat bob("Bob", 2);
    Bureaucrat jim("Jim");

    std::cout << bob << jim << std::endl;
    try
    {
        bob.upGrade();
    }
    catch (std::exception & e)
    {
        std::cout << bob << "exception == " << e.what() << std::endl;
    }

    std::cout << "Trying to upgrade bob AND downgrade Jim" << std::endl;
    try
    {
        bob.upGrade();
        jim.downGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "exception == " << e.what() << std::endl;
    }

    std::cout << bob << jim << std::endl;

    std::cout << "Upgrading Jim" << std::endl;
    try
    {
        jim.upGrade();
    }
    catch (std::exception & e)
    {
        std::cout << jim << "exception == " << e.what() << std::endl;
    }
    std::cout << bob << jim;
    return (0);
}