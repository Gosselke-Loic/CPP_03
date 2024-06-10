/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:47:14 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/02 11:18:09 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( int argc, char **argv ) {

	int		poisonDamage = 1;
	bool	poisoned = false;
	ClapTrap	clapTrap2("Roland");
	ClapTrap	clapTrap1((argc != 2) ? "NoName" : argv[1]);

	clapTrap1.setAttackDamage(2);
	while (clapTrap2.getHitPoints() != 0) {
		if (clapTrap1.getEnergyPoints() > 0) {
			clapTrap1.attack(clapTrap2.getName());
			clapTrap2.takeDamage(clapTrap1.getAttackDamage());
			if (!poisoned) {
				std::cout << YELLOW << clapTrap2.getName() << " has been poisoned and loses one " \
					"hit point per turn" << DEFAULT << std::endl;
				poisoned = true;
			}
		}
		if (clapTrap2.getEnergyPoints() > 0)
			clapTrap2.beRepaired(2);
		if (poisoned)
			clapTrap2.takeDamage(poisonDamage);
	}
	return (0);
}