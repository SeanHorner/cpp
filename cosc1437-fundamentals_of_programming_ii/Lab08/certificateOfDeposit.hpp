/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the certificateOfDeposit class, 
 * 						child of bankAccount.
 * 	Requires:	bankAccount.hpp
 **/
#ifndef certificateOfDeposit_HPP
#define certificateOfDeposit_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "bankAccount.hpp"

using std::string;
using std::cout;
using std::setw;

class certificateOfDeposit : public bankAccount {
	private:
		double interest;
		int maturityMonths;
		int currentMonth;
	
	public:
		//Interest set and get methods
		void setInterest(double num) {
			interest = num;
		}
		
		double getInterest() {
			return interest;
		}
		
		//Maturity months set and methods
		void setMaturityMonths(int num) {
			maturityMonths = num;
		}
		
		int getMaturityMonths() {
			return maturityMonths;
		}
		
		//Current maturity month set, get, and increment methods
		void setCurrentMonth(int num) {
				currentMonth = num;
		}
		
		int getCurrentMonth() {
			return currentMonth;
		}
		
		void incrementCurrentMonth() {
			currentMonth++;
		}
		
		//Update the account for interest
		void interestPayment() {
			setBalance(getBalance()*(1 + interest)*(currentMonth/maturityMonths));
		}
			
		//Method to print an account statement
		void printStatement() {
			cout << "**********************************************\n"
					 << " Acct: " << getAccountNumber() << "\n"
					 << " Owner: " << getFirstName() << " " << getLastName() << "\n"
					 << " Account Type: Certificate of Deposit\n"
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
