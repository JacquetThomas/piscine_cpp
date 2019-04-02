/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:54:07 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 10:29:21 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

#include <iostream>
int main( void ) {
    FragTrap    robot1 = FragTrap("toto");
    FragTrap    robot2 = FragTrap(robot1);
    ScavTrap    robot3 = ScavTrap("tata");
    ScavTrap    robot4 = ScavTrap(robot3);
    NinjaTrap   ninja1 = NinjaTrap("Robert");
    NinjaTrap   ninja2 = NinjaTrap("Leonard");
    SuperTrap   awsome = SuperTrap("Alfred");

    FragTrap    toto;
    toto = robot1;

    std::cout << std::endl;
    std::cout << std::endl;
    robot1.meleeAttack("Tata");
    robot3.challengeNewcomer();
    robot2.setName("Hunter");
    robot4.setName("Princess");
    robot1.vaulthunter_dot_exe("giraphe");
    std::cout << std::endl;
    std::cout << std::endl;
    robot2.rangedAttack(robot1.getName());
    robot1.takeDamage(robot2.getRangedAttackDamage());
    std::cout << "-- Remaining energy for " << robot1.getName() << " = " << robot1.getEnergyPoints() << " --" << std::endl;
    std::cout << "-- Remaining energy for " << robot3.getName() << " = " << robot3.getEnergyPoints() << " --" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for " << robot1.getName() << " = " << robot1.getHitPoints() << " --" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    robot3.meleeAttack(robot1.getName());
    robot1.takeDamage(robot3.getMeleeAttackDamage());
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for " << robot1.getName() << " = " << robot1.getHitPoints() << " --" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    robot2.meleeAttack(robot1.getName());
    robot1.takeDamage(robot2.getMeleeAttackDamage());
    std::cout << "-- Remaining HP for " << robot1.getName() << " = " << robot1.getHitPoints() << " --" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    robot4.challengeNewcomer();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--- Ninja enterred in the GAME ! ---" << std::endl;
    ClapTrap    clapclap;
    clapclap.setName("Victim");
    ninja1.ninjaShoebox(robot4);
    ninja2.ninjaShoebox(toto);
    ninja1.ninjaShoebox(ninja2);
    ninja2.ninjaShoebox(clapclap);

    std::cout << std::endl;
    std::cout << std::endl;
    awsome.meleeAttack("you");
    awsome.rangedAttack("you");
    awsome.ninjaShoebox(robot1);
    awsome.vaulthunter_dot_exe("you");

    robot1.printInfo();
    awsome.printInfo();
    ninja1.printInfo();
    std::cout << "--- END OF THE GAME ! ---" << std::endl;

    return (0);
}