/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:31:07 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 16:55:42 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "Form.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( const ShrubberyCreationForm & inst );
        ~ShrubberyCreationForm( void );

        ShrubberyCreationForm    &operator=( const ShrubberyCreationForm & inst );

        /* getters and setter */
        std::string     getTarget( void ) const;
        void    execute(Bureaucrat &executor) const;

    private:
        ShrubberyCreationForm( void );
        
        std::string     _target;
};

#endif