/*
 * main.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: 1806291_snhu
 */

#include<iostream>
#include<string>
using namespace std;

#include "Account.h"

int main(){
	Account newAccount;
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int years;
	char key;
	char yesNo = 'y';

	//Print user menu and receive input
	while (yesNo == 'y'){
		cout << "**************************************" << endl;
		cout << "************* DATA INPUT *************" << endl;
		cout << "Initial Investment Amount: $" << endl;
		cin >> initialInvestment;
		cout << "Monthly Deposit: $" << endl;
		cin >> monthlyDeposit;
		cout << "Annual Interest: %" << endl;
		cin >> annualInterest;
		cout << "Number of Years: " << endl;
		cin >> years;
		cout << "Press 'c' to continue..." << endl;
		cin >> key;

		//User continue
		if (key == 'c'){
			//set account based on user input
			newAccount.SetInitialInvestmentAmount(initialInvestment);
			newAccount.SetMonthlyDeposit(monthlyDeposit);
			newAccount.SetAnnualInterest(annualInterest);
			newAccount.SetNumberOfYears(years);

			//print reports
			//Report without additional deposits
			newAccount.PrintReportWithoutDeposits();
			//Report with additional monthy deposits
			newAccount.PrintReportWithDeposits();


		}
		cout << "Would you like to edit your account information? (enter y or n)" << endl;
		cin >> yesNo;
	}
	return 0;
}


