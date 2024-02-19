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
	_accountIndex = Account::_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

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

void	Account::makeDeposit(int desposit)
{
	Account::_displayTimestamp();
	
}

bool	Account::makeWithdrawal(int withdrawal)
{

}

int		Account::checkAmount() const
{

}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << '\n';
}

void	Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
}

Account::Account()
{
}