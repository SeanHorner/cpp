/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/18/2020
 * 	Purpose:	This is the header file defining the abstract bankAccount 
 * 						parent class.
 * 	Requires:	None
 **/
#ifndef bankAccount_HPP
#define bankAccount_HPP

#include <string>

using std::string;

class bankAccount {
	private:
		unsigned int accountNumber;
		string firstName;
		string lastName;
		double balance;
		
	public:
		//Account number set and get methods
		void setAccountNumber(unsigned int n) {
			accountNumber = n;
		}
		
		unsigned int getAccountNumber() {
			return accountNumber;
		}
		
		//Account owner name set and get methods
		void setName(string first, string last) {
			firstName = first;
			lastName = last;
		}
		
		string getFirstName() {
			return firstName;
		}
		
		string getLastName() {
			return lastName;
		}
		
		//Account balance set and get functions
		void setBalance(double amount) {
			balance = amount;
		}
		
		double getBalance() {
			return balance;
		}
		
		bool checkBalanceGT(double amt) {
			if (balance > amt) 
				return true;
			else
				return false;
		}
				
		bool checkBalanceLT(double amt) {
			if (balance < amt) 
				return true;
			else
				return false;
		}
		
		//Pure virtual function to withdraw money
		virtual void withdraw(double amt) = 0;
		
		//Pure virtual function to deposit money
		virtual void deposit(double amt) = 0;
		
		//Pure virtual function to print a monthly statement
		virtual void printStatement() = 0; 
		
		//Pure virtual function to explain the account type
		//virtual void printExplainer() = 0;
	};

#endif
