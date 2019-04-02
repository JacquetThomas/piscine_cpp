/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:54:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 14:37:25 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
    Bureaucrat  bob("Bob", 2);
    Bureaucrat  jim("Jim");
    Form        lowForm("little one", 149, 1);

    std::cout << bob << jim << std::endl;
    std::cout << "--- Upgrading bob" << std::endl;
    try
    {
        bob.upGrade();
    }
    catch (std::exception & e)
    {
        std::cout << bob << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- Trying to upgrade bob AND downgrade Jim" << std::endl;
    try
    {
        bob.upGrade();
        jim.downGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- Form trying to be signed a too low bureaucrat" << std::endl;
    try
    {
        lowForm.beSigned(jim);
    }
    catch (std::exception & e)
    {
        std::cout << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- Jim trying to sign a too high level form" << std::endl;
    try
    {
        jim.signForm(lowForm);
    }
    catch (std::exception & e)
    {
        std::cout << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- Upgrading Jim" << std::endl;
    try
    {
        jim.upGrade();
    }
    catch (std::exception & e)
    {
        std::cout << jim << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- Jim trying to sign form after upgrade" << std::endl;
     try
    {
        jim.signForm(lowForm);
    }
    catch (std::exception & e)
    {
        std::cout << jim << "exception == " << e.what() << std::endl;
    }

     std::cout << "--- Jim trying to sign an already signed form" << std::endl;
     try
    {
        jim.signForm(lowForm);
    }
    catch (std::exception & e)
    {
        std::cout << jim << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- printing final state of all" << std::endl;
    std::cout << bob << jim << lowForm;
    return (0);
}