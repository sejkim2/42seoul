#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int		Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int		Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int		Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void		Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
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
	std::cout << "created";
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
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << '\n';
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (checkAmount() - withdrawal <= 0)
		std::cout << "refused";
	else
	{
		std::cout << withdrawal << ";";
		_amount -= withdrawal;
		std::cout << "amount:" << checkAmount() << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
	}
	std::cout << '\n';
	return (true);
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