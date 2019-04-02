/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:33:00 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

    public:
        NinjaTrap(void);
        NinjaTrap(std::string name);
        NinjaTrap(NinjaTrap const & NinjaTrap);
        ~NinjaTrap(void);
        NinjaTrap & operator=(NinjaTrap const & rhs);

        void        ninjaShoebox(FragTrap & frag);
        void        ninjaShoebox(ScavTrap & scav);
        void        ninjaShoebox(NinjaTrap & ninja);
        void        ninjaShoebox(ClapTrap & clap);
        void        setFragTrapAttackDamage(unsigned int damage);
        void        setScavTrapAttackDamage(unsigned int damage);
        void        setClapTrapAttackDamage(unsigned int damage);
        unsigned int    getFragTrapAttackDamage(void) const;
        unsigned int    getScavTrapAttackDamage(void) const;
        unsigned int    getClapTrapAttackDamage(void) const;

    private:
        unsigned int    _fragTrapAttackDamage;
        unsigned int    _scavTrapAttackDamage;
        unsigned int    _clapTrapAttackDamage;
        void        initValues(void);

};

#endif