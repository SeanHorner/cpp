/**
 * 	Creator:	Sean Horner
 * 	Date:			03/09/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the highServiceChargeChecking 
 * 						class, child of checkingAccount.
 * 	Requires:	bankAccount.hpp, checkingAccount.hpp
 **/
#ifndef highInterestChecking_HPP
#define highInterestChecking_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "noServiceChargeChecking.hpp"

using std::string;
using std::cout;
using std::setw;

class highInterestChecking : public noServiceChargeChecking {
	private:
		double interest = 5.00;
		const double minimumBalance = 5000;
	
	public:		
		//Class method for writing a check
		void writeCheck(double amount) {
			
		}
		
		//Method to print an account statement
		void printStatement() {
			cout << "**********************************************\n"
					 << " Acct: " << getAccountNumber()
										 << "  Last Check No.: " << setw(5) << getCheckCount() << "\n"
					 << " Owner: " << getFirstName() << " " << getLastName() << "\n"
					 << " Account Type: High Interest Checking\n"
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

