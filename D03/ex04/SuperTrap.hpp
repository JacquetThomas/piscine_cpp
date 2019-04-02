/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:17:05 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap , public NinjaTrap {

    public:
        SuperTrap(void);
        SuperTrap(std::string name);
        SuperTrap(SuperTrap const & SuperTrap);
        ~SuperTrap(void);
        SuperTrap & operator=(SuperTrap const & rhs);

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);

    private:
        void        initValues(void);

};

#endif