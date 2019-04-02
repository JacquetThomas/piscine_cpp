/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:31:07 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 17:27:23 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "Form.hpp"
# include <fstream>
# include <iostream>

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( const PresidentialPardonForm & inst );
        ~PresidentialPardonForm( void );

        PresidentialPardonForm    &operator=( const PresidentialPardonForm & inst );

        /* getters and setter */
        std::string     getTarget( void ) const;
        void    execute(Bureaucrat &executor) const;

    private:
        PresidentialPardonForm( void );
        
        std::string     _target;
};

#endif