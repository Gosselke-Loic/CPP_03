/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:25:09 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:34:34 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class	ScavTrap: public virtual ClapTrap {
	private:
		
		bool	_guardMode;
	public:
        ScavTrap( void );
		~ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &copy );

		ScavTrap	&operator=( const ScavTrap &copy);

		bool		getGuardMode( void );
		void		setGuardMode( bool mode );

		void		guardGate( void );
		void		attack( const std::string& target );
};

#endif