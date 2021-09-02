/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the abstract checkingAccount 
 * 						base class, child class of bankAccount.
 * 	Requires:	bankAccount.hpp
 **/
#ifndef checkingAccount_HPP
#define checkingAccount_HPP

#include <string>
#include "bankAccount.hpp"

using std::string;

class checkingAccount : public bankAccount {
	private:
		int checkCount;
		bool depositAccount = false;
		bool withdrawlAccount = false;
	
	public:
		//Check counter set and get methods
		void setCheckCount(int num) {
			checkCount = num;
		}
		
		int getCheckCount() {
			return checkCount;
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
		
		//Check writing method
		virtual void writeCheck(double amount) = 0;
	};

#endif
