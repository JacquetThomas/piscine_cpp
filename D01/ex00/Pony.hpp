/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:01:48 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 10:39:48 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony {

public:

	Pony(void);
	Pony(std::string name);
	~Pony(void);
	
	void		setName(std::string name);
	std::string	getName(void);
	void		setColor(std::string color);
	std::string	getColor(void);
	void		printInfo(void);

private:
	std::string	_name;
	std::string _color;
};

#endif