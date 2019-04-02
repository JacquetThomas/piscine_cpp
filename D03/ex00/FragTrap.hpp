/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/28 14:37:11 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap {

    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap const & FragTrap);
        ~FragTrap(void);
        FragTrap & operator=(FragTrap const & rhs);
        
        void        setName(std::string name);
        void        setHitPoints(unsigned int hitPoints);
        void        setMaxHitPoints(unsigned int maxHitPoints);
        void        setEnergyPoints(unsigned int energyPoints);
        void        setMaxEnergyPoints(unsigned int maxEnergyPoints);
        void        setLevel(unsigned int level);
        void        setMeleeAttackDamage(unsigned int meleeAttackDamage);
        void        setRangedAttackDamage(unsigned int rangedAttackDamage);
        void        setArmorDamageReduction(unsigned int armorDamageRedcution);
        void        setNononoCatAttackDamage(unsigned int nononoCatAttackDamage);
        void        setKitlerCatAttackDamage(unsigned int kitlerCatAttackDamage);
        void        setNyanCatAttackDamage(unsigned int nyanCatAttackDamage);
        void        setKeyboardCatAttackDamage(unsigned int keyboardCatAttackDamage);
        void        setCeillingCatAttackDamage(unsigned int ceillingCatAttackDamage);
        
        std::string         getName(void) const;
        unsigned int        getHitPoints(void) const;
        unsigned int        getMaxHitPoints(void) const;
        unsigned int        getEnergyPoints(void) const;
        unsigned int        getMaxEnergyPoints(void) const;
        unsigned int        getLevel(void) const;
        unsigned int        getMeleeAttackDamage(void) const;
        unsigned int        getRangedAttackDamage(void) const;
        unsigned int        getArmorDamageReduction(void) const;
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
        std::string         _name;
        unsigned int        _hitPoints;
        unsigned int        _maxHitPoints;
        unsigned int        _energyPoints;
        unsigned int        _maxEnergyPoints;
        unsigned int        _level;
        unsigned int        _meleeAttackDamage;
        unsigned int        _rangedAttackDamage;
        unsigned int        _armorDamageReduction;
        unsigned int        _nononoCatAttackDamage;
        unsigned int        _kitlerCatAttackDamage;
        unsigned int        _nyanCatAttackDamage;
        unsigned int        _keyboardCatAttackDamage;
        unsigned int        _ceillingCatAttackDamage;
        
        void        initValues(void);

};

#endif