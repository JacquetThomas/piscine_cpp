/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:32:25 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 18:17:29 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequestForm", 72, 45)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )  : Form("RobotomyRequestForm", 145, 137)
{
    this->_target = target;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & inst )  : Form(inst.getTarget(), 145, 137)
{
    *this = inst;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    return ;
}

RobotomyRequestForm    &    RobotomyRequestForm::operator=( const RobotomyRequestForm & lhs )
{
    this->_target = lhs.getTarget();
    return *this;
}

std::string         RobotomyRequestForm::getTarget( void ) const{
    return (this->_target);
}

void                RobotomyRequestForm::execute(Bureaucrat &executor) const {
    this->Form::execute(executor);
    std::cout << "BRBRBRRBRBRBRBRBRBRBRBRRBRRRRBRBRBR" << std::endl;
    srand (time(NULL));
    if ((rand() % 100) % 2)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " hasn't been robotomized.." << std::endl;       
    
}