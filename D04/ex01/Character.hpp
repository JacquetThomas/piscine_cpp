/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:55:39 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:08:07 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
# define CHARACTER

# include "Enemy.hpp"
# include "AWeapon.hpp"

class Character
{
    public:
        Character(std::string const & name);
        Character(Character const & rhs);
        ~Character();

        Character & operator=(Character const & rhs);

        std::string const & getName(void) const;
        int                 getActionPoints(void) const;
        AWeapon             *getWeapon(void) const;
        
        void                recoverAP(void);
        void                equip(AWeapon* weapon);
        void                attack(Enemy* enemy);

    
    private:
        Character(void);

        std::string _name;
        int         _actionPoints;
        AWeapon     *_weapon;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif