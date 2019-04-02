/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:23:24 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 21:27:39 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy {
    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const & rhs);
        virtual ~Enemy();

        Enemy & operator=(Enemy const &rhs);

        std::string const & getType() const;
        int                 getHP() const;
        
        virtual void takeDamage(int damage);
    
    private:
        Enemy(void);
        int         _hitPoints;
        std::string _type;

};

#endif