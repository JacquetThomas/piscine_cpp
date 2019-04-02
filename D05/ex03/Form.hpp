/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:30:17 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 19:12:22 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"


class Form
{
    public:
        Form( std::string name, int signedGrade, int execGrade);
        Form( const Form & inst );
        virtual ~Form( void );

       

        /* Grade Exceptions */
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException( void );
                GradeTooHighException( const GradeTooHighException & inst );
                ~GradeTooHighException( void ) throw();

                virtual const char* what() const throw();

            private:
                GradeTooHighException    &operator=( const GradeTooHighException & inst );
        };

        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException( void );
                GradeTooLowException( const GradeTooLowException & inst );
                ~GradeTooLowException( void ) throw();

                virtual const char* what() const throw();
            
            private:
                GradeTooLowException    &operator=( const GradeTooLowException & inst );
        };

        class AlreadySignedFormException : public std::exception
        {
            public:
                AlreadySignedFormException( void );
                AlreadySignedFormException( const AlreadySignedFormException & inst );
                ~AlreadySignedFormException( void ) throw();

                virtual const char* what() const throw();
            
            private:
                AlreadySignedFormException    &operator=( const AlreadySignedFormException & inst );
        };

        class NotSignedFormException : public std::exception
        {
            public:
                NotSignedFormException( void );
                NotSignedFormException( const NotSignedFormException & inst );
                ~NotSignedFormException( void ) throw();

                virtual const char* what() const throw();
            
            private:
                NotSignedFormException    &operator=( const NotSignedFormException & inst );
        };

        /* getters and setters*/
        std::string getName( void ) const;
        bool        getSigned( void ) const;
        int         getSignedGrade( void ) const;
        int         getExecGrade( void ) const;
        void        setSigned(bool sign);

        /* functions */
        void                beSigned(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat &executor) const = 0;


    private:
     Form    &operator=( const Form & inst );
        Form( void );
        std::string const   _name;
        bool                _signed;
        int const           _signedGrade;
        int const           _execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif