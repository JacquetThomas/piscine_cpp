/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:54:07 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/28 14:35:16 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>
int main( void ) {
    FragTrap    robot1 = FragTrap("toto");
    FragTrap    robot2 = FragTrap("Tata");
    FragTrap    robot3 = FragTrap(robot2);

    robot1.meleeAttack("Tata");
    robot3.vaulthunter_dot_exe("toto");
    robot1.vaulthunter_dot_exe("giraphe");
    robot2.rangedAttack(robot1.getName());
    robot1.takeDamage(robot2.getRangedAttackDamage());
    std::cout << "-- Remaining energy for robot1 = " << robot1.getEnergyPoints() << " --" << std::endl;
    std::cout << "-- Remaining energy for robot3 = " << robot3.getEnergyPoints() << " --" << std::endl;
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for robot1 = " << robot1.getHitPoints() << " --" << std::endl;
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for robot1 = " << robot1.getHitPoints() << " --" << std::endl;
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for robot1 = " << robot1.getHitPoints() << " --" << std::endl;


    return (0);
}