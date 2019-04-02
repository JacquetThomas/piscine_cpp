/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 12:19:59 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer {

    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const & Sorcerer);
        ~Sorcerer(void);
        Sorcerer & operator=(Sorcerer const & rhs);

        void        setName(std::string name);
        void        setTitle(std::string title);
        std::string getName(void) const;
        std::string getTitle(void) const;

        void        polymorph(Victim const &) const;
        
    private:
        Sorcerer(void);
        std::string     _name;
        std::string     _title;

};

std::ostream &  operator<<(std::ostream & o, Sorcerer const & rhs);

#endif