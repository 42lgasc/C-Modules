/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:04:43 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/11 18:42:04 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

// # `public:` #################################################################

// ## `static` methods                  ########################################

int	Account::getNbAccounts(void)	{ return _nbAccounts;			}
int	Account::getTotalAmount(void)	{ return _totalAmount;			}
int	Account::getNbDeposits(void)	{ return _totalNbDeposits;		}
int	Account::getNbWithdrawals(void)	{ return _totalNbWithdrawals;	}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp(), std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// ## Lifetime                          ########################################

Account::Account	(const int initial_deposit) : _amount (initial_deposit)
//,_nbDeposits (0), _nbWithdrawals (0)
{
	static int	new_index = 0;

	_accountIndex = new_index ++;
	_nbAccounts = getNbAccounts() + 1;
	_totalAmount = getTotalAmount() + checkAmount();
	_displayTimestamp(), std::cout << "index:" << _accountIndex
		<< ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account	(void) {
	_nbAccounts = getNbAccounts() - 1;
	_totalAmount = getTotalAmount() - checkAmount();
	// _totalNbDeposits -= _nbDeposits, _totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp(), std::cout << "index:" << _accountIndex
		<< ";amount:" << checkAmount() << ";closed" << std::endl;
}

// ## Instance methods                  ########################################

void	Account::makeDeposit(const int deposit) {
	_displayTimestamp(), std::cout << "index:" << _accountIndex << ";p_amount:"
		<< checkAmount() << ";deposit:" << deposit << ";amount:";
	_amount = checkAmount() + deposit,
		_totalAmount = getTotalAmount() + deposit;
	std::cout << checkAmount() << ";nb_deposits:"
		<< (++ _totalNbDeposits, ++ _nbDeposits) << std::endl;
}

///FIXME: Should the return value indicate the presence of an error,
///							or should it indicate the success of the operation?
bool	Account::makeWithdrawal(const int withdrawal) {
	_displayTimestamp(), std::cout << "index:" << _accountIndex << ";p_amount:"
		<< checkAmount() << ";withdrawal:";
	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return (true);
	}
	_amount = checkAmount() - withdrawal,
		_totalAmount = getTotalAmount() - withdrawal;
	std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:"
		<< (++ _totalNbWithdrawals, ++ _nbWithdrawals) << std::endl;
	return (false);
}

int	Account::checkAmount(void) const { return _amount; }

void	Account::displayStatus(void) const {
	_displayTimestamp(), std::cout << "index:" << _accountIndex
		<< ";amount:" << checkAmount() << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

// # `private:` ################################################################

// ## `static`                          ########################################

// ### Information                                          ####################

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

// ### Methods                                              ####################

void	Account::_displayTimestamp(void) {
	const std::time_t	time_since_epoch = std::time(NULL);
	const std::tm		*now = std::gmtime(& time_since_epoch);

	std::cout << '[' << now->tm_year + 1900 << std::setfill('0')
		<< std::setw(2) << now->tm_mon << std::setw(2) << now->tm_mday << '_'
		<< std::setw(2) << now->tm_hour << std::setw(2) << now->tm_min
		<< std::setw(2) << now->tm_sec << "] ";
}
