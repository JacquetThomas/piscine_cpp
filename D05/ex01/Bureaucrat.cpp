/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:30:20 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 14:29:55 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
    this->_grade = grade;
    return ;
}

Bureaucrat::Bureaucrat( std::string name) : _name(name)
{
    this->_grade = 150;
    return ;
}


Bureaucrat::Bureaucrat( const Bureaucrat & inst )
{
    *this = inst;
    return ;
}

Bureaucrat::~Bureaucrat( void )
{
    return ;
}

Bureaucrat    &    Bureaucrat::operator=( const Bureaucrat & rhs )
{
    this->_grade = rhs._grade;
    return *this;
}

/* getters and setters */
std::string Bureaucrat::getName( void ) const{
    return (this->_name);
}

int         Bureaucrat::getGrade( void ) const{
    return (this->_grade);
}

/* grade's functions */
void        Bureaucrat::upGrade( void ) {
    if (this->_grade <= 1)
	    throw Bureaucrat::GradeTooHighException();
    else
        this->_grade -= 1;
}

void        Bureaucrat::downGrade( void ) {
        if (this->_grade >= 150)
	    throw Bureaucrat::GradeTooLowException();
    else
        this->_grade += 1;
}

/* functions */

void        Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " sign " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
    /*
    if (form.getSigned())
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because it's already signed" << std::endl;
    } 
    else if (this->_grade > form.getSignedGrade())
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << GradeTooLowException().what() << std::endl;
    }
    else
    {
        form.setSigned(true);
        std::cout << this->_name << " sign " << form.getName() << std::endl;
    }*/
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (o);
}

/* Grade Exceptions */

Bureaucrat::
GradeTooHighException::GradeTooHighException( void ){ return ;}

Bureaucrat::
GradeTooHighException::GradeTooHighException ( const GradeTooHighException & inst) {
    *this = inst ;
    return ;
}

Bureaucrat::
GradeTooHighException::~GradeTooHighException( void ) throw() { return ;}

Bureaucrat::
GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException & inst) { 
    (void)inst;
    return *this;
}

const  char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high exception");
}

Bureaucrat::
GradeTooLowException::GradeTooLowException( void ){ return ;}

Bureaucrat::
GradeTooLowException::GradeTooLowException ( const GradeTooLowException & inst) {
    *this = inst ;
    return ;
}

Bureaucrat::
GradeTooLowException::~GradeTooLowException( void ) throw() { return ;}

Bureaucrat::
GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException & inst) {
    (void)inst;
    return *this;
}

const  char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too Low exception");
}