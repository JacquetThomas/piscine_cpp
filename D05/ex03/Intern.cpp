/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:51:53 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 20:49:02 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
    return ;
}

Intern::Intern( const Intern & inst )
{
    *this = inst;
    return ;
}

Intern::~Intern( void )
{
    return ;
}

Intern    &    Intern::operator=( const Intern & lhs )
{
    (void)lhs;
    return *this;
}

Form            *Intern::makeForm(std::string form, std::string target) {
    Form    *new_form;

    if (form.compare("robotomy form") == 0) {
        new_form = new RobotomyRequestForm((std::string)target);
    } else if (form.compare("presidential form") == 0) {
        new_form = new PresidentialPardonForm((std::string)target);
    } else if (form.compare("shrubbery form") == 0) {
        new_form = new ShrubberyCreationForm((std::string)target);
    } else {
        std::cout << "Intern can't create " << form << std::endl;
        throw UnknownFormException();
        return (0);
    }
    std::cout << "Intern create " << new_form->getName() << std::endl;
    return (new_form);
}

Intern::
UnknownFormException::UnknownFormException( void ){ return ;}

Intern::
UnknownFormException::UnknownFormException ( const UnknownFormException & inst) {
    *this = inst ;
    return ;
}

Intern::
UnknownFormException::~UnknownFormException( void ) throw() { return ;}

Intern::
UnknownFormException &Intern::UnknownFormException::operator=(const UnknownFormException & inst) {
    (void)inst;
    return *this;
}

const  char *Intern::UnknownFormException::what() const throw() {
    return ("Unknown form exception");
}