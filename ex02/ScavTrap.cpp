/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:49:57 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/17 16:31:30 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
	this->_guard_mode = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Named ScavTrap constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
	this->_guard_mode = false;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	this->_guard_mode = copy._guard_mode;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "Assignation operator ScavTrap called" << std::endl;
	if (this != &src)
    {
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_energy = src._energy;
		this->_attack_damage = src._attack_damage;
		this->_guard_mode = src._guard_mode;
    }
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
    if ((this->_energy != 0) && (this->_hit_points != 0))
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy -= 1;
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " can´t do anything, because doesn´t have enough ENERGY or HIT POINTS." << std::endl;
    }
}

void	ScavTrap::printStat(void)
{
	std::cout << GREEN << "***" << YELLOW << "SCAV_STAT" << GREEN "***" << std::endl;
	std::cout << "Name:          " << this->_name << std::endl;
	std::cout << "Hit points:    " << this->_hit_points << std::endl;
	std::cout << "Energy:        " << this->_energy << std::endl;
	std::cout << "Attack damage: " << this->_attack_damage << std::endl;
	std::cout << "Guard mode:    " << this->_guard_mode << std::endl;
	std::cout << "***************" << RESET << std::endl;
}

bool	ScavTrap::getGM()const
{
	return (this->_guard_mode);
}

void	ScavTrap::guardGate()
{
	if (this->_guard_mode == false)
	{
		std::cout << "Scav Trap " << this->_name << " is now in Gate keeper mode" << std::endl;
		this->_guard_mode = true;
	}
	else
	{
		std::cout << "Scav Trap " << this->_name << " is already in Gate keeper mode" << std::endl;
	}
}
