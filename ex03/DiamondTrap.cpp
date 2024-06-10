/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:23:33 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:38:01 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* Constructors/Destructor */

DiamondTrap::DiamondTrap( void ): ClapTrap( "default" ), ScavTrap( "default" ), FragTrap( "default" ) {
	this->setDiamondName("default");
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap( name + "_clap_trap" ),  ScavTrap( name ), FragTrap( name ) {
    this->setDiamondName(name);
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	std::cout << GREEN << "[INFO] " << DEFAULT << "Diamondtrap: " << name \
		<< " was born to make your life" << RED << " quadruple insufferable" \
		<< DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &copy ): ClapTrap( copy ), ScavTrap( copy ), FragTrap( copy ) {
	this->setDiamondName(copy._name);
	std::cout << "The memory of another Diamondtrap was copied" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "[PUB] All our Diamondtraps are made from 0.05% recycled materials [PUB]" \
		<< RED << " [INFO] Diamondtrap: " << this->getName() << " has been recycled" \
		<< DEFAULT << std::endl; 
}

/* Overloads */

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap& copy ) {
	FragTrap::operator=(copy);
	this->setDiamondName(copy._name);
	std::cout << "A new Diamondtrap for replacement is arrived!" << std::endl;
	return (*this);
}	

/* Getters */

std::string	DiamondTrap::getDiamondName( void ) {
	return (this->_name);
}

/* Setters */

void	DiamondTrap::setDiamondName( std::string name ) {
	this->_name = name;
}

/* Methods */

void	DiamondTrap::whoAmI( void ) {
	if (this->getEnergyPoints() > 0) {
		std::cout << GREEN << "[INFO] " << DEFAULT << "Who am I? " \
			<< "Diamondtrap name is: " << RED << this->getDiamondName() \
			<< DEFAULT  << " and Claptrap name is: " << YELLOW << \
			this->getName() << DEFAULT << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else {
		std::cout << "Diamondtrap: " << this->getName() << " have not enough energy points" \
			<< std::endl;
	}
}

void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}