/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:33:32 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:32:31 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructors/Destructor */

FragTrap::FragTrap( void ): ClapTrap("default") {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap( name ) {
	this->setHitPoints(100);
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	std::cout << GREEN << "[INFO] " << DEFAULT << "Fragtrap: " << name \
		<< " was born to make your life" << RED << " triple insufferable" \
		<< DEFAULT << std::endl;
}

FragTrap::FragTrap( const FragTrap &copy ): ClapTrap(copy) {
	std::cout << "The memory of another Fragtrap was copied" << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "[PUB] All our Fragtraps are made from 85% recycled materials [PUB]" \
		<< RED << " [INFO] Fragtrap: " << this->getName() << " has been recycled" \
		<< DEFAULT << std::endl; 
}

/* Overloads */

FragTrap	&FragTrap::operator=( const FragTrap& copy ) {
	std::cout << "A new Fragtrap for replacement is arrived!" << std::endl;
	ClapTrap::operator=(copy);
	return(*this);
}

/* Methods */

void	FragTrap::highFivesGuys( void ) {
	if (this->getEnergyPoints() > 0) {
		std::cout << YELLOW << "Let all the Claptraps who are going to die give a high five!" \
			<< DEFAULT << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else {
		std::cout << "Fragtrap: " << this->getName() << " have not enough energy points" \
			<< std::endl;
	}
}