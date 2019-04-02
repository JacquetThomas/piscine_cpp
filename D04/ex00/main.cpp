/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:27:40 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 13:47:21 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Sorcerer.hpp"
 #include "Peon.hpp"
 #include "Victim.hpp"

 int main()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);
    
    return 0;
}