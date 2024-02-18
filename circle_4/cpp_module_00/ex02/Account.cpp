#include "Account.hpp"
#include <iostream>

int		Account::getNbAccounts()
{
	return _nbAccounts;
}

int		Account::getTotalAmount()
{
	return _totalAmount;
}

int		Account::getNbDeposits()
{
	return _totalNbDeposits;
}

//
int		Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void		Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << '\n';
}

Account::Account(int initial_deposit)
{
	_nbDeposits = initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "createded";
	std::cout << '\n';	
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << '\n';	
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << '\n';
}