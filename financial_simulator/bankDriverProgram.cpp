/**
 * 	Creator:	Sean Horner
 * 	Date:			03/06/2020
 *  Updated:	03/23/2020
 * 	Purpose:	This is the driver program to test the functionality
 * 						of all the bank classes.
 * 	Requires:	monthlyFinancials.hpp, bankAccount.hpp, checkingAccount.hpp, 
 * 						certificateOfDeposit.hpp, savingsAccount.hpp,
 * 						highInterestSavings.hpp, serviceChargeChecking.hpp,
 * 						noServiceChargeChecking.hpp, highInterestChecking.hpp
 **/
 
#include <iostream>
#include <string>
#include "bankAccount.hpp"
#include "certificateOfDeposit.hpp"
#include "checkingAccount.hpp"
#include "serviceChargeChecking.hpp"
#include "noServiceChargeChecking.hpp"
#include "highInterestChecking.hpp"
#include "savingsAccount.hpp"
#include "highInterestSavings.hpp"
#include "monthlyFinancials.hpp"

using std::cout;
using std::cin;
using std::endl;

void showBaseMenu();
void showCreationMenu();
void showCheckingMenu();
void showSavingsMenu();
void showUpdateMenu();
void showAccountChoiceMenu();
void showSCCheckingAccountMenu();
void showNoSCCheckingAccountMenu();
void showHICheckingAccountMenu();
void showSavingsAccountMenu();
void showHISavingsAccountMenu();
void showCDAccountMenu();
void showMonthlyVariablesMenu();
void clearScreen();

int main() {
	//Selector variables for the various case statements, time and amount input 
	//variables, and user identification variables.
	int selection = 0;
	int choice = 0;
	int input = 0;
	int num = 0;
	char ch = ' ';
	unsigned int account = 0;
	int timeLength = 0;
	double amount;
	string userFirst;
	string userLast;
	
	//Bank account instances
	monthlyFinancials financials;
	serviceChargeChecking checking;
	noServiceChargeChecking betterChecking;
	highInterestChecking bestChecking;
	savingsAccount savings;
	highInterestSavings highSavings;
	certificateOfDeposit cd;
	
	
	cout << "Please enter your first name: ";
	cin >> userFirst;
	cout << "\n" << "And your last name: ";
	cin >> userLast;
	selection = 0;
	
	do {
		showBaseMenu();
		cout << "Enter your menu selection:  ";
		cin >> selection;
		cout << endl;
		
		switch(selection) {
			case 1:
				do {
					clearScreen();
					choice = 0;
					showCreationMenu();
					cout << "Please enter your choice:  ";
					cin >> choice;
					cout << endl;
				
					switch(choice) {
						case 1:
							do {
								input = 0;
								showCheckingMenu();
								cout << "Please enter your choice:  ";
								cin >> input;
								cout << endl;
								
								switch(input) {
									case 1:
										cout << "What initial balance will this account have?\n"
												 << "(There is no minimum balance):    ";
										cin >> amount;
										cout << endl;
										
										checking.setName(userFirst, userLast);
										checking.setBalance(amount);
										
										clearScreen();
										cout << "A checking account has been created!\n\n";
										
										break;
										
									case 2:
										cout << "What initial balance will this account have?\n"
												 << "(There is a minimum balance of $1500.00) :  ";
										cin >> amount;
										cout << endl;
										
										while(amount < 1500.00) {
											cout << "Initial deposit is too little, please deposit more:  ";
											cin >> amount;
											cout << endl;
										}	
										
										betterChecking.setName(userFirst, userLast);
										betterChecking.setBalance(amount);
										
										clearScreen();
										cout << "A checking account without service charge has been created!\n\n";
										
										break;
										
									case 3:
										cout << "What initial balance will this account have?\n"
												 << "(There is a minimum balance of $5000.00) :  ";
										cin >> amount;
										cout << endl;
										
										while(amount < 5000.00) {
											cout << "Initial deposit is too little, please deposit more:  ";
											cin >> amount;
											cout << endl;
										}	
										
										bestChecking.setName(userFirst, userLast);
										bestChecking.setBalance(amount);
										
										clearScreen();
										cout << "A high-interest checking account has been created!\n\n";
										
										break;
										
									case 9:
										cout << "Returning to previous menu...\n";
										clearScreen();
										
										break;
										
									default:
										cout << "Inappropriate choice, please choose again\n";
										clearScreen();
										
										break;
								}
								
							} while(input != 9);
							
							break;
							
						case 2:
							do {
								input = 0;
								showSavingsMenu();
								cout << "Please enter your choice:  ";
								cin >> input;
								cout << endl;
								
								switch(input) {
									case 1:
										cout << "What initial balance will this account have?\n"
												 << "(There is no minimum balance) :   ";
										cin >> amount;
										cout << endl;
										
										savings.setName(userFirst, userLast);
										savings.setBalance(amount);
										
										clearScreen();
										cout << "A savings account has been created!\n\n";
										
										break;
										
									case 2:
										cout << "What initial balance will this account have?\n"
												 << "(There is a minimum balance of $2500.00) :  ";
										cin >> amount;
										cout << endl;
										
										while(amount < 2500.00) {
											cout << "Initial deposit is too little, please deposit more:  ";
											cin >> amount;
											cout << endl;
										}	
										
										highSavings.setName(userFirst, userLast);
										highSavings.setBalance(amount);
										
										clearScreen();
										cout << "A high interest savings account has been created!\n\n";
										
										break;
										
									case 9:
										cout << "Returning to previous menu...\n";
										clearScreen();
										
										break;
										
									default:
										cout << "Inappropriate choice, please choose again\n";
										clearScreen();
										
										break;
								}
								
							} while(input != 9);
							
							break;
					
						case 3:
							cout << "What initial balance will this account have?\n"
									 << "(There is no minimum balance) :   ";
							cin >> amount;
							cout << endl;
										
							cd.setName(userFirst, userLast);
							cd.setBalance(amount);
										
							clearScreen();
							cout << "A certificate of deposit has been created!\n\n";
							
							break;
					
						case 9:
							cout << "Returning to main menu...\n\n";
							
							break;
						
						default:
							cout << "Inappropriate choice, please choose again\n\n";
							
							break;
					}
					
				} while(choice != 9);
				
				clearScreen();
				break;
				
			case 2:
				do {
					choice = 0;
					showAccountChoiceMenu();
					cout << "Which account did you want to update?: "; 
					cin >> choice;
					cout << endl;
					
					switch(choice) {
						case 1:
							if (checking.getFirstName() != userFirst) {
								clearScreen();
								cout << "You haven't created an account of that type!\n\n";
								
								break;
							}
							
							do {
								input = 0;
								showSCCheckingAccountMenu();
								cin >> input;
								cout << endl;
							
								switch(input) {
									case 1:											//Balance
										cout << "\n\n\nCurrent Balance:   " << checking.getBalance()
												 << "\nWhat would you like to update the balance to?: ";
										cin >> amount;
										cout << endl;
										
										checking.setBalance(amount);
										
										clearScreen();
										cout << "Balance set to: " << checking.getBalance() << endl;
										break;
								
									case 2:											//Check Limit
										cout << "\n\n\nCurrent Check Limit: " << checking.getCheckLimit()
												 << "\nWhat would you like to update the limit to?: ";
										cin >> num;
										cout << endl;
										
										checking.setCheckLimit(num);
								
										clearScreen();
										cout << "Check Limit set to: " << checking.getCheckLimit() << endl;
										break;
								
									case 3:											//Service Charge
										cout << "\n\n\nCurrent Service Charge: " << checking.getServiceCharge()
												 << "\nWhat would you like to update the charge to?: ";
										cin >> amount;
										cout << endl;
										
										checking.setServiceCharge(amount);
										
										clearScreen();
										cout << "Service Charge set to: " << checking.getServiceCharge() << endl;
										break;
								
									case 4:											//Account Number
										cout << "\n\n\nCurrent Account #: " << checking.getAccountNumber()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										checking.setAccountNumber(account);
										
										clearScreen();
										cout << "Account Number set to: " << checking.getAccountNumber() << endl;
										break;
									
									case 5:											//Deposit Account Flag
										cout << "The deposit account flag is currently set to: ";
										if(checking.getDepositAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(checking.getDepositAccountFlag() == true)
												checking.depositAccountOff();
											else
												checking.depositAccountOn();
										}
										
										break;
										
									case 6:											//Withdrawl Account Flag
										cout << "The withdrawl account flag is currently set to: ";
										if(checking.getWithdrawlAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(checking.getWithdrawlAccountFlag() == true)
												checking.withdrawlAccountOff();
											else
												checking.withdrawlAccountOn();
										}
										
										break;
									
									case 9:
										cout << "Returning to previous menu...\n\n";
							
										break;
						
									default:
										cout << "Inappropriate choice, please choose again\n\n";
							
										break;
								}
								
							} while(input != 9);
							
							clearScreen();
							break;
						
						case 2:
							if (betterChecking.getFirstName() != userFirst) {
								clearScreen();
								cout << "You haven't created an account of that type!\n\n";
								
								break;
							}
							
							do {
								input = 0;
								showNoSCCheckingAccountMenu();
								cin >> input;
								cout << endl;
							
								switch(input) {
									case 1:											//Balance
										cout << "\n\n\nCurrent Balance:   " << betterChecking.getBalance()
												 << "\nWhat would you like to update the balance to?: ";
										cin >> amount;
										cout << endl;
										
										betterChecking.setBalance(amount);
										
										clearScreen();
										cout << "Balance set to: " << betterChecking.getBalance() << endl;
										break;
								
									case 2:											//Interest
										cout << "\n\n\nCurrent Interest: " << betterChecking.getInterest()
												 << "\nWhat would you like to update the limit to?: ";
										cin >> amount;
										cout << endl;
										
										betterChecking.setInterest(amount);
										
										clearScreen();
										cout << "Interest set to: " << betterChecking.getInterest() << endl;
										break;
							
									case 3:											//Account Number
										cout << "\n\n\nCurrent Account #: " << betterChecking.getAccountNumber()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										betterChecking.setAccountNumber(account);
										
										
										clearScreen();
										cout << "Account Number set to: " << betterChecking.getAccountNumber() << endl;
										break;
									
									case 9:
										cout << "Returning to previous menu...\n\n";
							
										break;
						
									default:
										cout << "Inappropriate choice, please choose again\n\n";
							
										break;
								}
								
							} while(input != 9);
							
							clearScreen();
							break;
							
						case 3:
							if (bestChecking.getFirstName() != userFirst) {
								clearScreen();
								cout << "You haven't created an account of that type!\n\n";
								
								break;
							}
							
							do {
								input = 0;
								showHICheckingAccountMenu();
								cin >> input;
								cout << endl;
							
								switch(input) {
									case 1:											//Balance
										cout << "\n\n\nCurrent Balance:   " << bestChecking.getBalance()
												 << "\nWhat would you like to update the balance to?: ";
										cin >> amount;
										cout << endl;
										
										bestChecking.setBalance(amount);
										
										clearScreen();
										cout << "Balance set to: " << bestChecking.getBalance() << endl;
										break;
								
									case 2:											//Interest
										cout << "\n\n\nCurrent Interest: " << bestChecking.getInterest()
												 << "\nWhat would you like to update the limit to?: ";
										cin >> amount;
										cout << endl;
										
										bestChecking.setInterest(amount);
										
										clearScreen();
										cout << "Interest set to: " << bestChecking.getInterest() << endl;
										break;
							
									case 3:											//Account Number
										cout << "\n\n\nCurrent Account #: " << bestChecking.getAccountNumber()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										bestChecking.setAccountNumber(account);
										
										clearScreen();
										cout << "Account Number set to: " << bestChecking.getAccountNumber() << endl;
										break;
										
									case 4:											//Deposit Account Flag
										cout << "The deposit account flag is currently set to: ";
										if(bestChecking.getDepositAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(bestChecking.getDepositAccountFlag() == true)
												bestChecking.depositAccountOff();
											else
												bestChecking.depositAccountOn();
										}
										
										break;
										
									case 5:											//Withdrawl Account Flag
										cout << "The withdrawl account flag is currently set to: ";
										if(bestChecking.getWithdrawlAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(bestChecking.getWithdrawlAccountFlag() == true)
												bestChecking.withdrawlAccountOff();
											else
												bestChecking.withdrawlAccountOn();
										}
										
										break;
										
									case 9:
										cout << "Returning to previous menu...\n\n";
							
										break;
						
									default:
										cout << "Inappropriate choice, please choose again\n\n";
							
										break;
								}
								
							} while(input != 9);
							
							clearScreen();
							break;
							
						case 4:
							if (savings.getFirstName() != userFirst) {
								clearScreen();
								cout << "You haven't created an account of that type!\n\n";
								
								break;
							}
							
							do {
								input = 0;
								showSavingsAccountMenu();
								cin >> input;
								cout << endl;
							
								switch(input) {
									case 1:											//Balance
										cout << "\n\n\nCurrent Balance:   " << savings.getBalance()
												 << "\nWhat would you like to update the balance to?: ";
										cin >> amount;
										cout << endl;
										
										savings.setBalance(amount);
										
										clearScreen();
										cout << "Balance set to: " << savings.getBalance() << endl;
										break;
								
									case 2:											//Interest
										cout << "\n\n\nCurrent Interest: " << savings.getInterest()
												 << "\nWhat would you like to update the limit to?: ";
										cin >> amount;
										cout << endl;
										
										savings.setInterest(amount);
										
										clearScreen();
										cout << "Interest set to: " << savings.getInterest() << endl;
										break;
							
									case 3:											//Account Number
										cout << "\n\n\nCurrent Account #: " << savings.getAccountNumber()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										savings.setAccountNumber(account);
										
										clearScreen();
										cout << "Account Number set to: " << savings.getAccountNumber() << endl;
										break;
										
									case 4:											//Deposit Account Flag
										cout << "The deposit account flag is currently set to: ";
										if(savings.getDepositAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(savings.getDepositAccountFlag() == true)
												savings.depositAccountOff();
											else
												savings.depositAccountOn();
										}
										
										break;
										
									case 5:											//Withdrawl Account Flag
										cout << "The withdrawl account flag is currently set to: ";
										if(savings.getWithdrawlAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(savings.getWithdrawlAccountFlag() == true)
												savings.withdrawlAccountOff();
											else
												savings.withdrawlAccountOn();
										}
										
										break;
										
									case 9:
										cout << "Returning to previous menu...\n\n";
							
										break;
						
									default:
										cout << "Inappropriate choice, please choose again\n\n";
							
										break;
								}
								
							} while(input != 9);
							
							clearScreen();
							break;
							
						case 5:
							if (highSavings.getFirstName() != userFirst) {
								clearScreen();
								cout << "You haven't created an account of that type!\n\n";
								
								break;
							}
							
							do {
								input = 0;
								showHISavingsAccountMenu();
								cin >> input;
								cout << endl;
							
								switch(input) {
									case 1:											//Balance
										cout << "\n\n\nCurrent Balance:   " << highSavings.getBalance()
												 << "\nWhat would you like to update the balance to?: ";
										cin >> amount;
										cout << endl;
										
										highSavings.setBalance(amount);
										
										clearScreen();
										cout << "Balance set to: " << highSavings.getBalance() << endl;
										break;
								
									case 2:											//Interest
										cout << "\n\n\nCurrent Interest: " << highSavings.getInterest()
												 << "\nWhat would you like to update the limit to?: ";
										cin >> amount;
										cout << endl;
										
										highSavings.setInterest(amount);
								
										clearScreen();
										cout << "Interest set to: " << highSavings.getInterest() << endl;
										break;
							
									case 3:											//Account Number
										cout << "\n\n\nCurrent Account #: " << highSavings.getAccountNumber()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										highSavings.setAccountNumber(account);
										
										clearScreen();
										cout << "Balance set to: " << highSavings.getAccountNumber() << endl;
										break;
										
									case 4:											//Deposit Account Flag
										cout << "The deposit account flag is currently set to: ";
										if(highSavings.getDepositAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
										
										if(ch == 'y' || ch == 'Y') {
											if(highSavings.getDepositAccountFlag() == true)
												highSavings.depositAccountOff();
											else
												highSavings.depositAccountOn();
										}
										
										break;
										
									case 5:											//Withdrawl Account Flag
										cout << "The withdrawl account flag is currently set to: ";
										if(highSavings.getWithdrawlAccountFlag() == true)
											cout << "true\n\n";
										else
											cout << "false\n\n";
										
										cout << "Would you like to change it? (y/n): ";
										cin >> ch;
										cout << endl;
							
										if(ch == 'y' || ch == 'Y') {
											if(highSavings.getWithdrawlAccountFlag() == true)
												highSavings.withdrawlAccountOff();
											else
												highSavings.withdrawlAccountOn();
										}
										
									case 9:
										cout << "Returning to previous menu...\n\n";
							
										break;
						
									default:
										cout << "Inappropriate choice, please choose again\n\n";
							
										break;
								}
								
							} while(input != 9);
							
							clearScreen();
							break;
							
						case 6:
							if (cd.getFirstName() != userFirst) {
								clearScreen();
								cout << "You haven't created an account of that type!\n\n";
								
								break;
							}
							
							do {
								input = 0;
								showCDAccountMenu();
								cin >> input;
								cout << endl;
							
								switch(input) {
									case 1:											//Balance
										cout << "\n\n\nCurrent Balance:   " << cd.getBalance()
												 << "\nWhat would you like to update the balance to?: ";
										cin >> amount;
										cout << endl;
										
										cd.setBalance(amount);
										
										clearScreen();
										cout << "Balance set to: " << cd.getBalance() << endl;
										break;
								
									case 2:											//Interest
										cout << "\n\n\nCurrent Interest: " << cd.getInterest()
												 << "\nWhat would you like to update the limit to?: ";
										cin >> amount;
										cout << endl;
										
										cd.setInterest(amount);
								
										clearScreen();
										cout << "Interest set to: " << cd.getInterest() << endl;
										break;
							
									case 3:											//Account Number
										cout << "\n\n\nCurrent Account #: " << cd.getAccountNumber()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										cd.setAccountNumber(account);
								
										clearScreen();
										cout << "Account Number set to: " << cd.getAccountNumber() << endl;
										break;
									
									case 4:											//Maturity Months
										cout << "\n\n\nCurrent Maturity Length: " << cd.getMaturityMonths()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										cd.setMaturityMonths(input);
								
										clearScreen();
										cout << "Maturity Length set to: " << cd.getMaturityMonths() << endl;
										break;
									
									case 5:											//Current Maturity Month
										cout << "\n\n\nCurrent Maturity Month: " << cd.getCurrentMonth()
												 << "\nWhat would you like to update the account number to?\n";
										cin >> account;
										cout << endl;
										
										cd.setCurrentMonth(input);
								
										clearScreen();
										cout << "Current set to: " << cd.getCurrentMonth() << " ("
												 << 100*(cd.getCurrentMonth()/cd.getMaturityMonths()) << "%)" 
												 << endl;
										break;
									
									case 9:
										cout << "Returning to previous menu...\n\n";
							
										break;
						
									default:
										cout << "Inappropriate choice, please choose again\n\n";
							
										break;
								}
								
							} while(input != 9);
							
							clearScreen();
							break;
							
						case 9:
							cout << "Returning to main menu...\n\n";
							
							break;
							
						default:
							cout << "Inappropriate choice, please choose again\n";
							
							break;
					}
					
				} while(choice != 9);
			
				clearScreen();
				break;
			
			case 3:
				cout << "Please enter the number of months you would\n"
						 << "like to run the simulation for:  ";
				cin >> timeLength;
				cout << endl;
				
				clearScreen();
				break;
			
			case 4:
				clearScreen();
				choice = 0;
				do {
					showMonthlyVariablesMenu();
					cout << "Enter your choice:  ";
					cin >> choice;
					cout << "\n\n" << endl;
					
					switch(choice) {
						case 1:
							cout << "Please enter your monthly rent:  ";
							cin >> amount;
							cout << endl;
							
							financials.setRent(amount);
							
							break;
							
						case 2:
							cout << "Please enter your monthly utilities:  ";
							cin >> amount;
							cout << endl;
							
							financials.setUtilities(amount);
							
							break;
							
						case 3:
							cout << "Please enter your monthly groceries budget:  ";
							cin >> amount;
							cout << endl;
							
							financials.setGroceries(amount);
							
							break;
							
						case 4:
							cout << "Please enter your monthly gas budget:  ";
							cin >> amount;
							cout << endl;
							
							financials.setGasoline(amount);
							
							break;
							
						case 5:
							cout << "Please enter your monthly entertainment budget:  ";
							cin >> amount;
							cout << endl;
							
							financials.setEntertainment(amount);
							
							break;
							
						case 6:
							cout << "Please enter your monthly income:  ";
							cin >> amount;
							cout << endl;
							
							financials.setIncome(amount);
							
							break;
						
						case 7:
							cout << "Please enter the percenatge of your income you'd like"
									 << " to send to savings (0 - 100): ";
							cin >> amount;
							cout << endl;
							
							while(amount < 0 || amount > 100) {
								cout << "Bad input. Please enter a number between 0 and 100: ";
								cin >> amount;
								cout endl;
							}
							
							financials.setSavingsCut(amount/100);
						
						case 8:
							financials.printStatement();
							
							break;
						
						case 9:
							cout << "Returning to main menu...\n\n";
							
							break;
							
						default:
							cout << "Inappropriate choice, please choose again\n";
							
							break;
					}
				} while(choice != 9);
				
				clearScreen();
				break;
			
			case 5:
				if(checking.getDepositAccountFlag() == true)
					serviceChargeChecking* depositChecking = &checking;
				else if(betterChecking.getDepositAccountFlag() == true)
					noServiceChargeChecking* depositChecking = &betterChecking;
				else if(bestChecking.getDepositAccountFlag() == true)
					highInterestChecking* depositChecking = &bestChecking;
				else {
					cout << "No deposit account set.\n" 
							 << "Please review account settings and set deposit flag.\n\n";
					break;
					clearScreen();
				}
					
				if(savings.getDepositAccountFlag() == true)
					savingsAccount* depositSavings = &savings;
				else if(highSavings.getDepositAccountFlag() == true)
					highInterestSavings* depositSavings = &highSavings;
				else if(savings.getFirstName() == userFirst 
									|| highSavings.getFirstName() == userFirst)
					cout << "No account set for savings deposits.\n\n";
				
				if(checking.getWithdrawlAccountFlag() == true)
					serviceChargeChecking* withdrawlChecking;
				else if(betterChecking.getWithdrawlAccountFlag() == true)
					noServiceChargeChecking* withdrawlChecking;
				else if(bestChecking.getWithdrawlAccountFlag() == true)
					highInterestChecking* withdrawlChecking;
				else {
					cout << "No withdrawl account set.\n"
							 << "Please review account settings and set withdrawl flag.\n\n";
					break;
					clearScreen();
				}
				
				if(savings.getWithdrawlAccountFlag() == true)
					savingsAccount* withdrawlSavings = &savings;
				else if(highSavings.getWithdrawlAccountFlag() == true)
					highInterestSavings* withdrawlSavings = &highSavings;
				else if(savings.getFirstName() == userFirst 
								|| highSavings.getFirstName() == userFirst)
					cout << "No account set for savings withdrawls (overdraft protection).\n\n";
				
				for (int i = 0; i < timeLength; i++) {
					//Loop to handle checking
					//First step deposit paycheck (and savings)
					depositChecking->deposit(financials.getIncome() * (1 - financials.getSavingsCut());
					depositSavings->deposit(financials.getIncome() * financials.getSavingsCut());
					//Second step pay bills
					
					//Third step overdraft protection from savings
					while(depositChecking->getBalance() < 0) {
						double overdraft = withdrawlSavings->getBalance()/3;
						withdrawlSavings->withdraw(overdraft);
						depositChecking->deposit(overdraft);
					}
					
					//If overdraft fails, convert checking account to the next lowest
					//type and set a flag to re-enter the correct balance zone (3 months?)
					
				
					//Loop to handle savings
					//First step take savings payments from deposit/checking
					
					//Second step pay interest
					
				
					//Loop to handle CD interest payments	
					//First step interest payments
					
					//Second step test for maturity, 
					//if complete repurchase and send interest to checking
					
				}
				
				break;
				
			case 6:
				if(checking.getFirstName() == userFirst) {
					checking.printStatement();
				}
				
				if(betterChecking.getFirstName() == userFirst) {
					betterChecking.printStatement();
				}
				
				if(bestChecking.getFirstName() == userFirst) {
					bestChecking.printStatement();
				}
				
				if(cd.getFirstName() == userFirst) {
					cd.printStatement();
				}
				
				if(savings.getFirstName() == userFirst) {
					savings.printStatement();
				}
				
				if(highSavings.getFirstName() == userFirst) {
					highSavings.printStatement();
				}
				
				if(financials.getIncome() != 0) {
					financials.printStatement();
				}
				
				break;
			
			case 9:
				clearScreen();
				cout << "Now exiting the program...\n\n";
				break;
			
			default:
				clearScreen();
				cout << "Inappropriate input, please try again.";
				break;
			}
		
	} while(selection != 9);
	
	return 0;
}

void showBaseMenu() {
	cout << " *****************************************\n"
			 << " * 1: Create a Bank Account              *\n"
			 << " * 2: Update a Bank Account              *\n"
			 << " * 3: Set the Planning Period            *\n"
			 << " * 4: Set Monthly Financial Variables    *\n"
			 << " * 5: Run Financial Simulation           *\n"
			 << " * 6: Print All Accounts Information     *\n"
			 << " * 9: Exit the Program                   *\n"
			 << " *****************************************\n\n";
}

void showCreationMenu() {
	cout << " *****************************************\n"
			 << " * 1: Create a Checking Account          *\n"
			 << " * 2: Create a Savings Account           *\n"
			 << " * 3: Create a Certificate of Deposit    *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showCheckingMenu() {
	cout << "Which checking account type would you like to create?\n\n" 
			 << " *****************************************\n"
			 << " * 1: Service Charge Checking            *\n"
			 << " * 2: No Service Charge Checking         *\n"
			 << " * 3: High Interest Checking             *\n"
			 << " * 9: Return to the Previous Menu        *\n"
			 << " *****************************************\n\n";
}

void showSavingsMenu() {
	cout << "Which savings account type would you like to create?\n\n" 
			 << " *****************************************\n"
			 << " * 1: Regular Savings Account            *\n"
			 << " * 2: High Interest Savings Account      *\n"
			 << " * 9: Return to the Previous Menu        *\n"
			 << " *****************************************\n\n";
}

void showUpdateMenu() {
	cout << " *****************************************\n"
			 << " * 1: Select a Bank Account to Update    *\n"
			 << " * 2: Update Bank Account Balance        *\n"
			 << " * 3: Update Bank Account Interest       *\n"
			 << " * 4: Set Monthly Gas Bill               *\n"
			 << " * 5: Set Monthly Entertainment Budget   *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showAccountChoiceMenu() {
	cout << " *****************************************\n"
			 << " * 1: Service Charge Checking            *\n"
			 << " * 2: No Service Charge Checking         *\n"
			 << " * 3: High Interest Checking             *\n"
			 << " * 4: Regular Savings                    *\n"
			 << " * 5: High Interest Savings              *\n"
			 << " * 6: Certificate of Deposit             *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showSCCheckingAccountMenu() {
	cout << " *****************************************\n"
			 << " * 1: Update Account Balance             *\n"
			 << " * 2: Update Account Check Limit         *\n"
			 << " * 3: Update Monthly Service Charge      *\n"
			 << " * 4: Update Account Number              *\n"
			 << " * 5: Set/Remove as Deposit Account      *\n"
			 << " * 6: Set/Remove as Withdrawl Account    *\n"
			 << " * 9: Return to the Previous Menu        *\n"
			 << " *****************************************\n\n";
}

void showNoSCCheckingAccountMenu() {
	cout << " *****************************************\n"
			 << " * 1: Update Account Balance             *\n"
			 << " * 2: Update Account Interest            *\n"
			 << " * 3: Update Account Number              *\n"
			 << " * 4: Set/Remove as Deposit Account      *\n"
			 << " * 5: Set/Remove as Withdrawl Account    *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showHICheckingAccountMenu() {
	cout << " *****************************************\n"
			 << " * 1: Update Account Balance             *\n"
			 << " * 2: Update Account Interest            *\n"
			 << " * 3: Update Account Number              *\n"
			 << " * 4: Set/Remove as Deposit Account      *\n"
			 << " * 5: Set/Remove as Withdrawl Account    *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showSavingsAccountMenu() {
	cout << " *****************************************\n"
			 << " * 1: Update Account Balance             *\n"
			 << " * 2: Update Account Interest            *\n"
			 << " * 3: Update Account Number              *\n"
			 << " * 4: Set/Remove as Deposit Account      *\n"
			 << " * 5: Set/Remove as Withdrawl Account    *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showHISavingsAccountMenu() {
	cout << " *****************************************\n"
			 << " * 1: Update Account Balance             *\n"
			 << " * 2: Update Account Interest            *\n"
			 << " * 3: Update Account Number              *\n"
			 << " * 4: Set/Remove as Deposit Account      *\n"
			 << " * 5: Set/Remove as Withdrawl Account    *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showCDAccountMenu() {
	cout << " *****************************************\n"
			 << " * 1: Update Account Balance             *\n"
			 << " * 2: Update Account Interest            *\n"
			 << " * 3: Update Account Number              *\n"
			 << " * 4: Update Maturity Term (in Months)   *\n"
			 << " * 5: Update Current Maturity Month      *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void showMonthlyVariablesMenu() {
	cout << " *****************************************\n"
			 << " * 1: Set Monthly Rent                   *\n"
			 << " * 2: Set Monthly Utilities Bill         *\n"
			 << " * 3: Set Monthly Grocery Bill           *\n"
			 << " * 4: Set Monthly Gas Bill               *\n"
			 << " * 5: Set Monthly Entertainment Budget   *\n"
			 << " * 6: Set Monthly Income                 *\n"
			 << " * 7: Set Savings Percentage             *\n"
			 << " * 8: Print Monthly Finances             *\n"
			 << " * 9: Return to the Main Menu            *\n"
			 << " *****************************************\n\n";
}

void clearScreen() {
	cout << "\033[2J\033[H" << endl;
}
