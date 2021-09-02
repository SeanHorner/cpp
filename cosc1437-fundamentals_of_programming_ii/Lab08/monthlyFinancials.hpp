/**
 * 	Creator:	Sean Horner
 * 	Date:			03/11/2020
 *  Updated:	03/23/2020
 * 	Purpose:	This is the header file defining the monthlyFinancials class type,
 * 						used to hold monthly expenditures.
 * 	Requires:	None
 **/
#ifndef monthlyFinancials_HPP
#define monthlyFinancials_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;

class monthlyFinancials {
	private:
		double rent;
		double utilities;
		double groceries;
		double gasoline;
		double entertainment;
		double income;
		double savingsCut;
		
	public:
		monthlyFinancials() {
			rent = 0;
			utilities = 0;
			groceries = 0;
			entertainment = 0;
			income = 0;
			savingsCut = 0;
		}
		
		//Set and get methods for the rent variable
		void setRent(double num) {
			rent = num;
		}
		
		double getRent() {
			return rent;
		}
		
		//Set and get variables for the utilities variable
		void setUtilities(double num) {
			utilities = num;
		}
		
		double getUtitlities() {
			return utilities;
		}
		
		//Set and get variables for the groceries variable
		void setGroceries(double num) {
			groceries = num;
		}
		
		double getGroceries() {
			return groceries;
		}
		
		//Set and get variables for the gasoline variable
		void setGasoline(double num) {
			gasoline = num;
		}
		
		double getGasoline() {
			return gasoline;
		}
		
		//Set and get variables for the entertainment variable
		void setEntertainment(double num) {
			entertainment = num;
		}
		
		double getEntertainment() {
			return entertainment;
		}
		
		//Set and get variables for the income variable
		void setIncome(double num) {
			income = num;
		}
		
		double getIncome() {
			return income;
		}
		
		//Set and get variables for the savingsCut variable
		void setSavingsCut(double num) {
			savingsCut = num;
		}
		
		double getSavingsCut() {
			return savingsCut;
		}
		
		//Method for printing monthly financial variables
		void printStatement() {
			cout << " Income:         " << "\033[32m" << income * (1 - savingsCut) << "\033[0m\n"
					 << " Savings:        " << "\033[32m" << income * savingsCut << "\033[0m\n"
					 << " Rent:           " << "\033[31m" << rent << "\033[0m\n"
					 << " Utilities:      " << "\033[31m" << utilities << "\033[0m\n"
					 << " Groceries:      " << "\033[31m" << groceries << "\033[0m\n"
					 << " Gas :           " << "\033[31m" << gasoline << "\033[0m\n"
					 << " Entertainment:  " << "\033[31m" << entertainment << "\033[0m\n\n";
		}
	};
	
#endif
