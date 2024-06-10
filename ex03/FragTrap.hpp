/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:33:39 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/09 10:35:19 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class	FragTrap: public virtual ClapTrap {
	private:
		
	public:
		FragTrap( void );
		~FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &copy );

		void		highFivesGuys(void);

		FragTrap	&operator=( const FragTrap& copy );
};

#endif