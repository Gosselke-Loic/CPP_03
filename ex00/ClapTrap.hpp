/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:46:59 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:17:46 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

# define RED "\033[1;31m"
# define DEFAULT "\033[0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"

class	ClapTrap {
	private:
		std::string 	_name;
		int				_hitPoints;
		int				_attackDamage;
		int				_energyPoints;
	public:
		ClapTrap( void );
		~ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &copy );

		std::string		getName( void );
		int				getHitPoints( void );
		int				getAttackDamage( void );
		int				getEnergyPoints( void );

		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			attack( const std::string& target );

		ClapTrap		&operator=( const ClapTrap& copy );
		
		void			setHitPoints( int value );
		void			setName( std::string name );
		void			setAttackDamage( int value );
		void			setEnergyPoints( int value );
};

#endif