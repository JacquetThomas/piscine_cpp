/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 14:53:24 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {

    public:
        Peon(std::string name);
        Peon(Peon const & Peon);
        ~Peon(void);
        
		Peon & operator=(Peon const & rhs);

        virtual void        getPolymorphed(void) const;

    private:
        Peon(void);

};

#endif
