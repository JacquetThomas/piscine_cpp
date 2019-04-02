/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:34:44 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & ClapTrap);
        ~ClapTrap(void);
        ClapTrap & operator=(ClapTrap const & rhs);
        
        void        setName(std::string name);
        void        setType(std::string name);
        void        setHitPoints(unsigned int hitPoints);
        void        setMaxHitPoints(unsigned int maxHitPoints);
        void        setEnergyPoints(unsigned int energyPoints);
        void        setMaxEnergyPoints(unsigned int maxEnergyPoints);
        void        setLevel(unsigned int level);
        void        setMeleeAttackDamage(unsigned int meleeAttackDamage);
        void        setRangedAttackDamage(unsigned int rangedAttackDamage);
        void        setArmorDamageReduction(unsigned int armorDamageRedcution);
    
        std::string         getName(void) const;
        std::string         getType(void) const;
        unsigned int        getHitPoints(void) const;
        unsigned int        getMaxHitPoints(void) const;
        unsigned int        getEnergyPoints(void) const;
        unsigned int        getMaxEnergyPoints(void) const;
        unsigned int        getLevel(void) const;
        unsigned int        getMeleeAttackDamage(void) const;
        unsigned int        getRangedAttackDamage(void) const;
        unsigned int        getArmorDamageReduction(void) const;

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

    protected:
        std::string         _name;
        std::string         _type;
        unsigned int        _hitPoints;
        unsigned int        _maxHitPoints;
        unsigned int        _energyPoints;
        unsigned int        _maxEnergyPoints;
        unsigned int        _level;
        unsigned int        _meleeAttackDamage;
        unsigned int        _rangedAttackDamage;
        unsigned int        _armorDamageReduction;
        
        void        initValues(void);

};

#endif