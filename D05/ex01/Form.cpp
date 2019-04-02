/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:30:20 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 14:35:49 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form( std::string name, int signedGrade, int execGrade) : _name(name), _signedGrade(signedGrade), _execGrade(execGrade)
{
    _signed = false;
    return ;
}


Form::Form( const Form & inst ) : _name(inst.getName()), _signedGrade(inst.getSignedGrade()), _execGrade(inst.getExecGrade())
{
    *this = inst;
    return ;
}

Form::~Form( void )
{
    return ;
}

Form    &    Form::operator=( const Form & rhs )
{
    (void)rhs;
    return *this;
}

/* getters and setters */
std::string Form::getName( void ) const{
    return (this->_name);
}

bool        Form::getSigned( void ) const{
    return (this->_signed);
}

void        Form::setSigned(bool sign) {
    this->_signed = sign;
}

int         Form::getExecGrade( void ) const{
    return (this->_execGrade);
}

int         Form::getSignedGrade( void ) const{
    return (this->_signedGrade);
}

/* functions */
void        Form::beSigned(Bureaucrat &bureaucrate) {
    
    if (bureaucrate.getGrade() > this->_signedGrade) {
        throw Form::GradeTooLowException();
    }
    else if (this->_signed) {
        throw Form::AlreadySignedFormException();
    }
    else
    {
        this->_signed = true;
    }
    
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
    o 
    << rhs.getName() 
    << ", Form sign requiered grade : " 
    << rhs.getSignedGrade() 
    << " , exexcution required grade : "
    << rhs.getExecGrade()
    << std::endl
    << "Form "
    << rhs.getName()
    << " actual state, signed : "
    << rhs.getSigned()
    << std::endl;
    return (o);
}

/* Grade Exceptions */

Form::
GradeTooHighException::GradeTooHighException( void ){ return ;}

Form::
GradeTooHighException::GradeTooHighException ( const GradeTooHighException & inst) {
    *this = inst ;
    return ;
}

Form::
GradeTooHighException::~GradeTooHighException( void ) throw() { return ;}

Form::
GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException & inst) { 
    (void)inst;
    return *this;
}

const  char *Form::GradeTooHighException::what() const throw() {
    return ("Grade too high exception");
}

Form::
GradeTooLowException::GradeTooLowException( void ){ return ;}

Form::
GradeTooLowException::GradeTooLowException ( const GradeTooLowException & inst) {
    *this = inst ;
    return ;
}

Form::
GradeTooLowException::~GradeTooLowException( void ) throw() { return ;}

Form::
GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException & inst) {
    (void)inst;
    return *this;
}

const  char *Form::GradeTooLowException::what() const throw() {
    return ("Grade too Low exception");
}

Form::
AlreadySignedFormException::AlreadySignedFormException( void ){ return ;}

Form::
AlreadySignedFormException::AlreadySignedFormException ( const AlreadySignedFormException & inst) {
    *this = inst ;
    return ;
}

Form::
AlreadySignedFormException::~AlreadySignedFormException( void ) throw() { return ;}

Form::
AlreadySignedFormException &Form::AlreadySignedFormException::operator=(const AlreadySignedFormException & inst) {
    (void)inst;
    return *this;
}

const  char *Form::AlreadySignedFormException::what() const throw() {
    return ("Already signed form exception");
}