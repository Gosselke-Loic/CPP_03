/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:46:51 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:27:05 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors/Destructor */

ClapTrap::ClapTrap( void ) {
	std::cout << "Claptrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hitPoints(10),
	_attackDamage(0), _energyPoints(10)
{	
	std::cout << GREEN << "[INFO] " << DEFAULT << "Claptrap: " << name \
		<< " was born to make your life" << RED << " insufferable" \
		<< DEFAULT << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy ) {
	std::cout << "The memory of another Claptrap was copied" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "[PUB] All our Claptraps are made from 100% recycled materials [PUB]" \
		<< RED << " [INFO] " << this->getName() << " has been recycled" \
        << DEFAULT << std::endl;	
}

/* Overloads */

ClapTrap	&ClapTrap::operator=( const ClapTrap& copy ) {
	std::cout << "A new Claptrap for replacement is arrived!" << std::endl;
	this->setName(copy._name);
	this->setHitPoints(copy._hitPoints);
	this->setEnergyPoints(copy._energyPoints);
	this->setAttackDamage(copy._attackDamage);
	return (*this);
}

/* Getters */

std::string ClapTrap::getName( void ) {
    return (this->_name);
}

int    ClapTrap::getHitPoints( void ) {
    return (this->_hitPoints);
}

int    ClapTrap::getAttackDamage( void ) {
    return (this->_attackDamage);
}

int    ClapTrap::getEnergyPoints( void ) {
    return (this->_energyPoints);
}

/* Setters */

void    ClapTrap::setName(std::string name) {
    this->_name = name;
}

void    ClapTrap::setHitPoints( int value ) {
    this->_hitPoints = value;
}

void    ClapTrap::setAttackDamage( int value ) {
    this->_attackDamage = value;
}

void    ClapTrap::setEnergyPoints( int value ) {
    this->_energyPoints = value;
}

/* Methods */

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->getHitPoints() == 0) {
		std::cout << "Stop! " << this->getName() << " is already dead!" \
			<< std::endl;
	} else {
		std::cout << this->getName() << " takes " << RED \
			<< amount << DEFAULT << " points of damage" << std::endl;
		if ((this->getHitPoints() - (int)amount) > 0)
			this->setHitPoints(this->getHitPoints() - (int)amount);
		else
			this->setHitPoints(0);
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->getEnergyPoints() > 0) {
		std::cout << GREEN << this->getName() << " has been repaired" \
			<< DEFAULT << std::endl;
		this->setHitPoints(this->getHitPoints() + (int)amount);
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else {
		std::cout << this->getName() << " have not enough energy points" \
			<< std::endl;
	}
}

void	ClapTrap::attack( const std::string& target ) {
	if (this->getEnergyPoints() > 0) {
		std::cout << this->getName() << " attack and made " \
			<< RED << this->getAttackDamage() << DEFAULT << " of damage to " \
			<< target << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else {
		std::cout << this->getName() << " have not enough energy points" \
			<< std::endl;
	}
}