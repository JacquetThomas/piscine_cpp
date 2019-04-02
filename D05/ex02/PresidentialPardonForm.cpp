/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:32:25 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 17:27:07 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("PresidentialPardonForm", 25, 5)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )  : Form("PresidentialPardonForm", 145, 137)
{
    this->_target = target;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & inst )  : Form(inst.getTarget(), 145, 137)
{
    *this = inst;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    return ;
}

PresidentialPardonForm    &    PresidentialPardonForm::operator=( const PresidentialPardonForm & lhs )
{
    this->_target = lhs.getTarget();
    return *this;
}

std::string         PresidentialPardonForm::getTarget( void ) const{
    return (this->_target);
}

void                PresidentialPardonForm::execute(Bureaucrat &executor) const {
    this->Form::execute(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}