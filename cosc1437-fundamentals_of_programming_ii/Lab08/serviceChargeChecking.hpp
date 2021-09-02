/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the serviceChargeChecking class, 
 * 						child of checkingAccount.
 * 	Requires:	bankAccount.hpp, checkingAccount.hpp
 **/
#ifndef serviceChargeChecking_HPP
#define serviceChargeChecking_HPP
 
#include <iostream>
#include <iomanip>
#include <string>
#include "checkingAccount.hpp"

using std::string;
using std::cout;
using std::setw;

class serviceChargeChecking : public checkingAccount {
	 private:
		int checkLimit = 10;
		int checkCounter = 0;
		double serviceCharge = 50.00;
	 
	 public:
		//Check writing limit set and get methods
		void setCheckLimit(int num) {
			checkLimit = num;
		}
		
		int getCheckLimit() {
			return checkLimit;
		}
		
		//Check counter incrementation and get methods
		void incCheckCounter() {
			checkCounter++;
		}
		
		int getCheckCounter() {
			return checkCounter;
		}
		
		//Service charge set and get methods
		void setServiceCharge(double num) {
			serviceCharge = num;
		}
		
		double getServiceCharge() {
			return serviceCharge;
		}
		
		//Monthly service charge payment
		void monthlyServiceCharge() {
			setBalance(getBalance() - serviceCharge);
		}
		
		//Class method for writing a check
		void writeCheck(double amount) {
			
		}
		
		//Method to print an account statement
		void printStatement() {
			cout << "**********************************************\n"
					 << " Acct: " << getAccountNumber()
										 << "       Check No.: " << setw(5) << getCheckCount() << "\n"
					 << " Owner: " << getFirstName() << " " << getLastName() << "\n"
					 << " Account Type: Service Charge Checking\n"
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
