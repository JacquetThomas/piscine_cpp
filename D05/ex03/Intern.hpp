/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:50:05 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 20:26:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern( void );
        Intern( const Intern & inst );
        ~Intern( void );

        Form    *makeForm(std::string form, std::string target);

        class UnknownFormException : public std::exception
        {
            public:
                UnknownFormException( void );
                UnknownFormException( const UnknownFormException & inst );
                ~UnknownFormException( void ) throw();

                virtual const char* what() const throw();
            
            private:
                UnknownFormException    &operator=( const UnknownFormException & inst );
        };

    private:
        Intern    &operator=( const Intern & inst );
};

#endif