/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 13:48:19 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim {

    public:
        Victim(std::string name);
        Victim(Victim const & Victim);
        ~Victim(void);
        Victim & operator=(Victim const & rhs);

        void        setName(std::string name);
        std::string getName(void) const;

        virtual void        getPolymorphed(void) const;

    protected:
        std::string     _name;

    private:
        Victim(void);

};

std::ostream &  operator<<(std::ostream & o, Victim const & rhs);

#endif