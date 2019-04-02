/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 11:15:14 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap const & FragTrap);
        ~FragTrap(void);
        FragTrap & operator=(FragTrap const & rhs);

        void        setNononoCatAttackDamage(unsigned int nononoCatAttackDamage);
        void        setKitlerCatAttackDamage(unsigned int kitlerCatAttackDamage);
        void        setNyanCatAttackDamage(unsigned int nyanCatAttackDamage);
        void        setKeyboardCatAttackDamage(unsigned int keyboardCatAttackDamage);
        void        setCeillingCatAttackDamage(unsigned int ceillingCatAttackDamage);
        
        unsigned int        getNononoCatAttackDamage(void) const;
        unsigned int        getKitlerCatAttackDamage(void) const;
        unsigned int        getNyanCatAttackDamage(void) const;
        unsigned int        getKeyboardCatAttackDamage(void) const;
        unsigned int        getCeillingCatAttackDamage(void) const;

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        vaulthunter_dot_exe(std::string const & target);
        void        nononoCatAttack(std::string const & target);
        void        kitlerCatAttack(std::string const & target);
        void        nyanCatAttack(std::string const & target);
        void        keyboardCatAttack(std::string const & target);
        void        ceillingCatAttack(std::string const & target);

    private:
        unsigned int        _nononoCatAttackDamage;
        unsigned int        _kitlerCatAttackDamage;
        unsigned int        _nyanCatAttackDamage;
        unsigned int        _keyboardCatAttackDamage;
        unsigned int        _ceillingCatAttackDamage;
        
        void        initValues(void);

};

#endif