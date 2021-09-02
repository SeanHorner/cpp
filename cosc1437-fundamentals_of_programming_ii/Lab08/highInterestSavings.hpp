/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the highInterestSavings class, 
 * 						child of savingsAccount.
 * 	Requires:	bankAccount.hpp, savingsAccount.hpp
 **/
#ifndef highInterestSavings_HPP
#define highInterestSavings_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "savingsAccount.hpp"

using std::string;
using std::cout;
using std::setw;

class highInterestSavings : public savingsAccount {
	private:
		double interest = 4.95;
		double minimumBalance = 5000;
	
	public:
		//Interest set and get methods
		void setInterest(double num) {
			interest = num;
		}
		
		//Minimum balance set and get methods
		void setMinimumBalance(double num) {
			minimumBalance = num;
		}
		
		double getMinimumBalance() {
			return minimumBalance;
		}
		
		//Method to print an account statement
		void printStatement() {
			cout << "**********************************************\n"
					 << " Acct: " << getAccountNumber() << "\n"
					 << " Owner: " << getFirstName() << " " << getLastName() << "\n"
					 << " Account Type: High Interest Savings Account\n"
					 << " Balance : " << setw(8) << getBalance() << "\n"
					 << "**********************************************\n\n";
		}
		
		//Methods to deposit money into and withdraw money from the account
		void deposit(double amt) {
			setBalance(getBalance() + amt);
		}
		
		void withdraw(double amt) {
			if (getBalance() > amt)
				setBalance(getBalance() - amt);
			else
				cout << "Balance too low.\n\n";
		}
	};
	
#endif
