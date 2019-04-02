/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:30:17 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 17:07:10 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Form;

# include <iostream>
# include <stdexcept>


# include "Form.hpp"

class Bureaucrat
{
    public:
        Bureaucrat( std::string name, int grade );
        Bureaucrat( std::string name);
        Bureaucrat( const Bureaucrat & inst );
        ~Bureaucrat( void );

        Bureaucrat    &operator=( const Bureaucrat & inst );

        /* getters and setters*/
        std::string getName( void ) const;
        int         getGrade( void ) const;

        /* grade's functions */
        void        upGrade( void );
        void        downGrade( void );

        /* functions*/
        void        signForm(Form &form);
        void        executForm(Form &form);

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

    private:
        Bureaucrat( void );
        std::string const   _name;
        int                 _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif