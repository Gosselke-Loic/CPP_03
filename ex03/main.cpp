/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:47:14 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/03 15:05:49 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( int argc, char **argv ) {

	DiamondTrap	diamondTrap1((argc != 2) ? "NoName" : argv[1]);

	diamondTrap1.whoAmI();
	std::cout << "Diamondtrap name: " << diamondTrap1.getDiamondName() << std::endl;
    std::cout << "Claptrap name: " << diamondTrap1.getName() << std::endl;
    std::cout << "DiamondTrap hitPoints: " << diamondTrap1.getHitPoints() << std::endl;
    std::cout << "DiamondTrap energyPoints: " << diamondTrap1.getEnergyPoints() << std::endl;
    std::cout << "DiamondTrap attackdamage: " << diamondTrap1.getAttackDamage() << std::endl;
    diamondTrap1.attack("Ash");
	return (0);
}