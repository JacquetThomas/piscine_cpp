/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:32:25 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 17:13:09 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", 145, 137)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )  : Form("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & inst )  : Form(inst.getTarget(), 145, 137)
{
    *this = inst;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    return ;
}

ShrubberyCreationForm    &    ShrubberyCreationForm::operator=( const ShrubberyCreationForm & lhs )
{
    this->_target = lhs.getTarget();
    return *this;
}

std::string         ShrubberyCreationForm::getTarget( void ) const{
    return (this->_target);
}

void                ShrubberyCreationForm::execute(Bureaucrat &executor) const {
    this->Form::execute(executor);
    std::ofstream file;
    file.open(this->_target + "_shrubbery");
    file << "               ,@@@@@@@," << std::endl
        << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
        << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
        << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'" << std::endl
        << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'" << std::endl
        << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
        << "   `&%\\ ` /%&\'    |.|        \\ \'|8'" << std::endl
        << "       |o|        | |         | |" << std::endl
        << "       |.|        | |         | |" << std::endl
        << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
    file.close();
}