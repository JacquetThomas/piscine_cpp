/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:56:05 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 18:48:06 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
# define HumanA_HPP

# include "Weapon.hpp"

class HumanA {

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void	attack(void);

private:
	std::string	_name;
	Weapon&		_weapon;

};

#endif