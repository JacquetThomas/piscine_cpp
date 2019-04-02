/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:54:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 14:26:34 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {

public:

	ZombieHorde(void);
	ZombieHorde(int n);
	~ZombieHorde(void);

	void		setZombieType(std::string zombieType);
	std::string	randomChump(void);
	void		announce(void);
private:
	std::string	_zombieType;
	Zombie		*_horde;
	int			_nb;
};

#endif