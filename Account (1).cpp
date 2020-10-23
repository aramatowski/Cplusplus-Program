/*
 * Account.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: 1806291_snhu
 */

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#include "Account.h"


void Account::SetInitialInvestmentAmount(double initialInvestment){
	initialDep = initialInvestment;                                 //user input initialDep
}

void Account::SetMonthlyDeposit(double monthlyDeposit) {
	monthlyDep = monthlyDeposit;                                    //user input monthlyDep
}

void Account::SetAnnualInterest(double annualInterest) {
	interestRate = annualInterest;                                  //user input interestRate
}

void Account::SetNumberOfYears(int years){
	numYears = years;                                               //user input numYears
}

double Account::GetInitialInvestmentAmount(){
	return initialDep;
}

double Account::GetMonthlyDeposit(){
	return monthlyDep;
}

double Account::GetAnnualInterest(){
	return interestRate;
}

int Account::GetNumberOfYears(){
	return numYears;
}

//Prints report without additional deposits
void Account::PrintReportWithoutDeposits(){
	int currentYear = 1;
	double yearEndBalance = this->initialDep;
	double interestEarned = 0.0;

	//Print heading
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << "==================================================================" << endl;
	cout << "  Year          Year End Balance        Year End Earned Interest  " << endl;
	cout << "------------------------------------------------------------------" << endl;

	while (currentYear <= this->numYears){
		//Calculate interest
		interestEarned = yearEndBalance * this->interestRate / 100;
		//Add interest to balance
		yearEndBalance = yearEndBalance + interestEarned;
		//Print results and increment year
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20)
				<< yearEndBalance << setw(35) << interestEarned << endl;
		currentYear++;
	}
}

//Prints report with additional deposits
void Account::PrintReportWithDeposits() {
	int currentYear = 1;
	int month = 1;
	double yearEndBalance = this->initialDep;
	double interestEarned = 0.0;
	double monthEndBalance = 0.0;
	double monthlyInterest = 0.0;
	int i;

	//Print heading
	cout << "       Balance and Interest With Additional Monthly Deposits      " << endl;
	cout << "==================================================================" << endl;
	cout << "  Year          Year End Balance        Year End Earned Interest  " << endl;
	cout << "------------------------------------------------------------------" << endl;

	while (currentYear <= this->numYears){
		monthEndBalance = yearEndBalance;
		//calculate interest monthly
		for (i = 1; i <= 12; i++){
			//Add monthly deposit
			monthEndBalance += this->monthlyDep;
			//Calculate monthly interest
			monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
			//Add monthly interest to yearly interest
			interestEarned = interestEarned + monthlyInterest;
			//Add interest to month end balance
			monthEndBalance = monthEndBalance + monthlyInterest;
			//Increment month by 1
			month++;
		}
		//Total balance after 12 months
		yearEndBalance = monthEndBalance;
		//Print results and increment year
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20)
				<< yearEndBalance << setw(35) << interestEarned << endl;
		currentYear++;
	}
}
