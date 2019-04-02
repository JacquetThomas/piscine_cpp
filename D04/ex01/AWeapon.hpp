/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 14:44:48 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const & rhs);
        ~AWeapon();

        AWeapon & operator=(AWeapon const & rhs);

        std::string const & getName() const;
        unsigned int        getAPCost() const;
        unsigned int        getDamage() const;

        virtual void attack() const = 0;

    private:
        AWeapon(void);
        std::string     _name;
        unsigned int    _apcost;
        unsigned int    _damage;
};

#endif