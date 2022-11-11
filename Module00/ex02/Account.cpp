/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:06:23 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/11 16:04:37 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <functional>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <ctime>

/* Constructor */ 
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit),
                                        _nbDeposits(0), _nbWithdrawals(0) 
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
    
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;

}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}

/* Non member attributes init */ 
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Non member functions */
int Account::getNbAccounts( void ) { return (Account::_nbAccounts); }
int Account::getTotalAmount( void ) { return (Account::_totalAmount); }
int Account::getNbDeposits( void ) { return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals( void ) { return (Account::_totalNbWithdrawals); }

/* displays global accounts infos - non member attributes */
void    Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
    return;
}

/* displays infos for one account - member attributes */
void    Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
    return ;
}

void    Account::_displayTimestamp( void )
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "[" << 1900 + ltm->tm_year;
    std::cout << 1 + ltm->tm_mon;
    std::cout << ltm->tm_mday;
    std::cout << "_" << ltm->tm_hour;
    std::cout << ltm->tm_min;
    std::cout << ltm->tm_sec << "] ";
    return ;
}

int Account::checkAmount( void ) const
{
    return this->_amount;
}

void    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    int p_amount;
    p_amount = this->_amount;
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << p_amount;
    if (deposit <= 0)
    {
        std::cout << "error : invalid amount for deposit " << std::endl;
        return ;
    }
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    std::cout << ";deposit:" << deposit; 
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl; 
    
    return ;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    int p_amount;
    p_amount = this->_amount;
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << p_amount;
    std::cout << ";withdrawal:";
    if (withdrawal <= 0)
    {
        std::cout << "error: invalid amount for withdrawal" << std::endl;
        return false; 
    }
    if (withdrawal > this->_amount)
        std::cout << "refused" << std::endl;
    else
        {
            this->_amount -= withdrawal;
            Account::_totalAmount -= withdrawal;
            this->_nbWithdrawals++;
            Account::_totalNbWithdrawals++;

            std::cout << withdrawal; 
            std::cout << ";amount:" << this->_amount;
            std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        }
    return true;
}