/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:54:35 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 13:29:08 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
class Zombie {

public:

	Zombie(void);
	Zombie(std::string name, std::string type);
	~Zombie(void);

	void		announce(void);
	void		setName(std::string name);
	void		setType(std::string type);
	std::string	getName(void);
	std::string	getType(void);

private:
	std::string	_type;
	std::string	_name;
};

#endif