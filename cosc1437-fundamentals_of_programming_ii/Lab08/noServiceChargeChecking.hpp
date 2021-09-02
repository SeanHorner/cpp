/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the noServiceChargeChecking 
 * 						class, child of checkingAccount.
 * 	Requires:	bankAccount.hpp, checkingAccount.hpp
 **/
#ifndef noServiceChargeChecking_HPP
#define noServiceChargeChecking_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "checkingAccount.hpp"

using std::string;
using std::cout;
using std::setw;

class noServiceChargeChecking : public checkingAccount {
	private:
		double interest = 0.50;
		double minimumBalance = 1500.00;
	
	public:
		//Account interest rate set and get methods
		void setInterest(double num) {
			interest = num;
		}
		
		double getInterest() {
			return interest;
		}
		
		//Minimum account balance set and get functions
		void setMinimumBalance(double num) {
			minimumBalance = num;
		}
		
		double getMinimumBalance() {
			return minimumBalance;
		}
		
		//Updates the account balance for an interest payment
		void interestPayment() {
			setBalance(getBalance()*(1 + interest));
		}
		
		//Prints out the check image to the console
		void showCheck(double amount) {
			
		}
		
		//Method for writing a check from the account
		void writeCheck(double amount) {
			
		}
		
		//Method to print an account statement
		void printStatement() {
			cout << "**********************************************\n"
					 << " Acct: " << getAccountNumber()
										 << " Last Check No.: " << setw(5) << getCheckCount() << "\n"
					 << " Owner: " << getFirstName() << " " << getLastName() << "\n"
					 << " Account Type: No Service Charge Checking\n"
					 << " Balance : " << setw(8) << getBalance() << "\n"
					 << "***********************************************\n\n";
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
