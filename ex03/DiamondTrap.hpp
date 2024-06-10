/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:23:41 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:36:33 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "Scavtrap.hpp"

# define RED "\033[1;31m"
# define DEFAULT "\033[0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"

class	DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		~DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap &copy );

		void		whoAmI( void );
		std::string	getDiamondName( void );
		void		setDiamondName( std::string name );
		void		attack( const std::string& target );

		DiamondTrap	&operator=( const DiamondTrap& copy );
};

#endif