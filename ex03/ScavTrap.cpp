/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:25:02 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:34:47 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scavtrap.hpp"

/* Constructors/Destructor */

ScavTrap::ScavTrap( void ): ClapTrap("default") {
	std::cout << "Scavtrap default constructor calles" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name ) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setGuardMode(false);
	std::cout << GREEN << "[INFO] " << DEFAULT << "Scavtrap: " << name \
		<< " was born to make your life" << RED << " twice insufferable" \
		<< DEFAULT << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy ): ClapTrap(copy) {
	this->setGuardMode(copy._guardMode);
	std::cout << "The memory of another Scavtrap was copied" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "[PUB] All our Scavtraps are made from 95% recycled materials [PUB]" \
		<< RED << " [INFO] Scavtrap: " << this->getName() << " has been recycled" \
		<< DEFAULT << std::endl; 
}

/* Overloads */

ScavTrap	&ScavTrap::operator=( const ScavTrap& copy ) {
	std::cout << "A new Scavtrap for replacement is arrived!" << std::endl;
	ClapTrap::operator=(copy);
	this->setGuardMode(copy._guardMode);
	return (*this);
}

/* Getters */

bool	ScavTrap::getGuardMode( void ) {
	return (this->_guardMode);
}

/* Setters */

void	ScavTrap::setGuardMode( bool mode ) {
	this->_guardMode = mode;
}

/* Methods */

void	ScavTrap::attack( const std::string& target ) {
	if (this->getEnergyPoints() > 0) {
		std::cout << "Scavtrap: " << this->getName() << " unleashes his fury and made " \
			<< RED << this->getAttackDamage() << DEFAULT << " of damage to " \
			<< target << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else {
		std::cout << "Scavtrap: " << this->getName() << " have not enough energy points" \
			<< std::endl;
	}
}

void	ScavTrap::guardGate( void ) {
	if (this->getEnergyPoints() > 0) {
		this->setGuardMode(!this->getGuardMode());
		std::cout << "Switching guardGate to " << YELLOW << (this->getGuardMode() ? "true" : "false") \
			<< DEFAULT << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else {
		std::cout << "Scavtrap: " << this->getName() << " have not enough energy points" \
			<< std::endl;
	}
}