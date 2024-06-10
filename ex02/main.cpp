/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:47:14 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/03 10:16:52 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "Scavtrap.hpp"

int	main( int argc, char **argv ) {

	ScavTrap	scavTrap1("Humungus");
	FragTrap	fragTrap1((argc != 2) ? "NoName" : argv[1]);

	fragTrap1.highFivesGuys();
	while (scavTrap1.getHitPoints() != 0) {
		scavTrap1.guardGate();
		if (scavTrap1.getGuardMode() == false && fragTrap1.getEnergyPoints() > 0) {
			fragTrap1.attack(scavTrap1.getName());
			scavTrap1.takeDamage(fragTrap1.getAttackDamage());
		} else {
			std::cout << "guardGate has been " << GREEN << "activated" << DEFAULT << \
				", Scavtrap will not take damage this turn" << std::endl;
		}
		if (scavTrap1.getEnergyPoints() > 0 && scavTrap1.getGuardMode() == false) {
			scavTrap1.attack(fragTrap1.getName());
			fragTrap1.takeDamage(scavTrap1.getAttackDamage());
			if (fragTrap1.getHitPoints() <= 0) {
				std::cout << "Fragtrap: " << fragTrap1.getName() << " has died at the hands of a Scavtrap" \
					<< std::endl;
				return (0);
			}
		}
		//scavTrap1.setAttackDamage(fragTrap1.getEnergyPoints());
		//fragTrap1.setAttackDamage(scavTrap1.getEnergyPoints());
	}
	return (0);
}