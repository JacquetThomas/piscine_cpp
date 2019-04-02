/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:54:07 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/28 15:47:30 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
int main( void ) {
    FragTrap    robot1 = FragTrap("toto");
    FragTrap    robot2 = FragTrap(robot1);
    ScavTrap    robot3 = ScavTrap("tata");
    ScavTrap    robot4 = ScavTrap(robot3);

    robot1.meleeAttack("Tata");
    robot3.challengeNewcomer();
    robot2.setName("Hunter");
    robot4.setName("Princess");
    robot1.vaulthunter_dot_exe("giraphe");
    robot2.rangedAttack(robot1.getName());
    robot1.takeDamage(robot2.getRangedAttackDamage());
    std::cout << "-- Remaining energy for robot1 = " << robot1.getEnergyPoints() << " --" << std::endl;
    std::cout << "-- Remaining energy for robot3 = " << robot3.getEnergyPoints() << " --" << std::endl;
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for robot1 = " << robot1.getHitPoints() << " --" << std::endl;
    robot3.meleeAttack(robot1.getName());
    robot1.takeDamage(robot3.getMeleeAttackDamage());
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for robot1 = " << robot1.getHitPoints() << " --" << std::endl;
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for robot1 = " << robot1.getHitPoints() << " --" << std::endl;
    robot4.challengeNewcomer();


    return (0);
}