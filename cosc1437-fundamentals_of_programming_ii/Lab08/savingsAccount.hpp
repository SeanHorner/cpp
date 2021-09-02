/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the savingsAccount base class, 
 * 						child of bankAccount.
 * 	Requires:	bankAccount.hpp
 **/
#ifndef savingsAccount_HPP
#define savingsAccount_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "bankAccount.hpp"

using std::string;
using std::cout;
using std::setw;

class savingsAccount : public bankAccount {
	private:
		double interest = 2.00;
		bool depositAccount = false;
		bool withdrawlAccount = false;
	
	public:
		//Interest set and get methods
		void setInterest(double num) {
			interest = num;
		}
	
		double getInterest() {
			return interest;
		}
			
		//Update the account for interest
		void interestPayment() {
			setBalance(getBalance() * (1 + interest));
		}
		
		//On, off, and get methods for the deposit account designation boolean
		void depositAccountOn() {
			depositAccount = true;
		}
		
		void depositAccountOff() {
			depositAccount = false;
		}
		
		bool getDepositAccountFlag() {
			return depositAccount;
		}
		
		//On, off, and get methods for the withdrawl account designation boolean
		void withdrawlAccountOn() {
			withdrawlAccount = true;
		}
		
		void withdrawlAccountOff() {
			withdrawlAccount = false;
		}
		
		bool getWithdrawlAccountFlag() {
			return withdrawlAccount;
		}
		
		//Method to print an account statement
		void printStatement() {
			cout << "**********************************************\n"
					 << " Acct: " << getAccountNumber() << "\n"
					 << " Owner: " << getFirstName() << " " << getLastName() << "\n"
					 << " Account Type: Savings Account\n"
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
