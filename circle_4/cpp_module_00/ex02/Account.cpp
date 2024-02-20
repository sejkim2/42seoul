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
	Account::_totalAmount += checkAmount();
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "createded";
	std::cout << '\n';	
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "closed";
	std::cout << '\n';	
}

void	Account::makeDeposit(int desposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << desposit << ";";
	_amount += desposit;
	Account::_totalAmount += desposit;
	std::cout << "amount:" << checkAmount() << ";";
	_nbDeposits++;
	std::cout << "nb_deposits:" << getNbDeposits();
	std::cout << '\n';
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	if (checkAmount() <= 0)
		std::cout << "refused";
	else
	{
		std::cout << "amount:" << checkAmount() << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawals" << _nbWithdrawals;
	}
	std::cout << '\n';
	Account::_totalNbWithdrawals++;
}

int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << '\n';
}

void	Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
}

Account::Account()
{
}