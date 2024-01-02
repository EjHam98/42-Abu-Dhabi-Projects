#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	return ;
}

Account::Account( int initial_deposit )
{
	_accountIndex	= Account::_nbAccounts++;
	_amount			= initial_deposit;
	Account::_totalAmount	+= _amount;
	_nbWithdrawals	= 0;
	_nbDeposits		= 0;
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";";
	std::cout	<< "amount:" << _amount << ";";
	std::cout	<< "created\n";
}

Account::~Account( void )
{
	Account::_totalAmount -= _amount;
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";";
	std::cout	<< "amount:" << _amount << ";";
	std::cout	<< "closed\n";
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::Account::_displayTimestamp( void )
{
	char		stamp[20];
	time_t		now;

	now = time(0);
	if (std::strftime(stamp, 20, "[%G%m%d_%H%M%S] ", std::localtime(&now)))
		std::cout	<< stamp;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts << ";";
	std::cout	<< "total:" << Account::_totalAmount << ";";
	std::cout	<< "deposits:" << Account::_totalNbDeposits << ";";
	std::cout	<< "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";";
	std::cout	<< "p_amount:" << _amount << ";";
	std::cout	<< "deposit:" << deposit << ";";
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout	<< "amount:" << _amount << ";";
	std::cout	<< "nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";";
	std::cout	<< "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout	<< "withdrawal:refused\n";
		return (false);
	}
	else
		std::cout	<< "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout	<< "amount:" << _amount << ";";
	std::cout	<< "nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";";
	std::cout	<< "amount:" << _amount << ";";
	std::cout	<< "deposits:" << _nbDeposits << ";";
	std::cout	<< "withdrawals:" << _nbWithdrawals << "\n";
}
