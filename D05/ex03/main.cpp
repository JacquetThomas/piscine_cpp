/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:54:43 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 20:46:47 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) {
    Bureaucrat  bob("Bob", 2);
    Bureaucrat  jim("Jim");
    Intern      nobody;
    Form        *tree;// = nobody.makeForm("shrubbery form", "YOU");
    Form        *robot; //= nobody.makeForm("robotomy form", "ME");
    Form        *president;// = nobody.makeForm("presidential form", "PRESIDENT");

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

    std::cout << "--- Creation of Form's by intern" << std::endl;
    try {
        tree = nobody.makeForm("shrubbery form", "YOU");
        robot = nobody.makeForm("robotomy form", "ME");
        president = nobody.makeForm("presidential form", "PRESIDENT");; 
    } catch (std::exception &e ) {
        std::cout << "exception == " << e.what() << std::endl;
    }

    std::cout << "--- Form trying to be signed a too low bureaucrat" << std::endl;
    try {
        tree->beSigned(jim);
    } catch (std::exception &e) {
        std::cout << "exception == " << e.what() << std::endl;
    }
    std::cout << std::endl << "--- Jim trying to sign a too high level form" << std::endl;
    jim.signForm(*tree);


    std::cout << std::endl << "--- Upgrading Jim" << std::endl;
    try
    {
        jim.upGrade();
    }
    catch (std::exception & e)
    {
        std::cout << jim << "exception == " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Jim trying to sign form after upgrade" << std::endl;
    jim.signForm(*tree);

    std::cout << std::endl << "--- bob trying to sign a good grade form" << std::endl;
    bob.signForm(*tree);

    std::cout << std::endl << "--- executing shrubbery by bob" << std::endl;
    bob.executForm(*tree);

    std::cout << std::endl << "--- ROBOTOMYFORM make jim signed then bob execute then bob sign the jim execute then bob execute" << std::endl;
    jim.signForm(*robot);
    bob.executForm(*robot);
    bob.signForm(*robot);
    jim.executForm(*robot);
    bob.executForm(*robot);

    std::cout << std::endl << "--- PRESIDENTIAL make jim signed then bob execute then bob sign the jim execute then bob execute" << std::endl;
    jim.signForm(*president);
    bob.executForm(*president);
    bob.signForm(*president);
    jim.executForm(*president);
    bob.executForm(*president);
    
    std::cout << std::endl << "--- Finally intern try to create Unknown form" << std::endl;
    try {
        Form    *what = nobody.makeForm("specimen", "Intern");
        delete   what;
    } catch (std::exception &e) {
        std::cout << "exception == " << e.what() << std::endl;
    }
    delete tree;
    delete president;
    delete robot;
    return (0);
}