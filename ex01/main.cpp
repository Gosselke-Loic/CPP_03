/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:47:14 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/03 10:14:46 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Scavtrap.hpp"

int	main( int argc, char **argv ) {

	ScavTrap	scavTrap1("Humungus");
	ClapTrap	clapTrap1((argc != 2) ? "NoName" : argv[1]);

	clapTrap1.setAttackDamage(11);
	while (scavTrap1.getHitPoints() != 0) {
		scavTrap1.guardGate();
		if (scavTrap1.getGuardMode() == false && clapTrap1.getEnergyPoints() > 0) {
			clapTrap1.attack(scavTrap1.getName());
			scavTrap1.takeDamage(clapTrap1.getAttackDamage());
		} else {
			std::cout << "guardGate has been " << GREEN << "activated" << DEFAULT << \
				", Scavtrap will not take damage this turn" << std::endl;
		}
		if ((scavTrap1.getHitPoints() % 2) != 0 && scavTrap1.getEnergyPoints() > 0
			&& scavTrap1.getGuardMode() == false) {
			scavTrap1.attack(clapTrap1.getName());
			clapTrap1.takeDamage(scavTrap1.getAttackDamage());
			if (clapTrap1.getHitPoints() <= 0) {
				std::cout << "Claptrap: " << clapTrap1.getName() << " has died at the hands of a Scavtrap" \
					<< std::endl;
				return (0);
			}
		}
	}
	return (0);
}