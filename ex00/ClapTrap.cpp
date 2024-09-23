/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:35:28 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/17 13:28:57 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() : _name("default"), _hit_points(10), _energy(10), _attack_damage(0)
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
}



ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy(10), _attack_damage(0)
{
	std::cout << "Named ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Assignation operator ClapTrap called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_energy = src._energy;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called" << std::endl;
}

std::string ClapTrap::getName()const
{
	return (this->_name);
}

unsigned int ClapTrap::getHP()const
{
    return (this->_hit_points);
}

unsigned int ClapTrap::getEnergy()const
{
    return (this->_energy);
}

unsigned int ClapTrap::getAD()const
{
    return (this->_attack_damage);
}

void	ClapTrap::printStat(void)
{
	std::cout << "Name:          " << this->_name << std::endl;
	std::cout << "Hit points:    " << this->_hit_points << std::endl
;
	std::cout << "Energy:        " << this->_energy << std::endl
;
	std::cout << "Attack damage: " << this->_attack_damage << std::endl
;
}

void	ClapTrap::attack(const std::string& target)
{
	if ((this->_energy != 0) && (this->_hit_points != 0))
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " can´t do anything, because doesn´t have enough ENERGY or HIT POINTS." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	if (this->_hit_points >= amount) 
	{
		this->_hit_points -= amount;
	}
	else
	{
		this->_hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->_energy != 0) && (this->_hit_points != 0))
	{
		std::cout << "ClapTrap " << this->_name << " repairs for " << amount << " points!" << std::endl;
		this->_hit_points += amount;
		this->_energy -= 1;
	}
	else
    {
		std::cout << "ClapTrap " << this->_name << " can´t do anything, because doesn´t have enough ENERGY or HIT POINTS." << std::endl;
	}
}
