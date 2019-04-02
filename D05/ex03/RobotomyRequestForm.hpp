/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:31:07 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/01 17:51:04 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFOM_H
# define ROBOTOMYREQUESTFOM_H

# include "Form.hpp"
# include <fstream>
# include <iostream>

class RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( const RobotomyRequestForm & inst );
        ~RobotomyRequestForm( void );

        RobotomyRequestForm    &operator=( const RobotomyRequestForm & inst );

        /* getters and setter */
        std::string     getTarget( void ) const;
        void    execute(Bureaucrat &executor) const;

    private:
        RobotomyRequestForm( void );
        
        std::string     _target;
};

#endif