/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:56:01 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 18:55:01 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
# define Weapon_HPP

# include <iostream>
class Weapon {

public:

	Weapon(std::string type);
	Weapon(void);
	~Weapon(void);
	void			setType(std::string type);
	std::string&	getType();
 
private:
	std::string	_type;

};

#endif