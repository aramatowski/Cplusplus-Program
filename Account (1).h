/*
 * Account.h
 *
 *  Created on: Oct 4, 2020
 *      Author: 1806291_snhu
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include<string>
using namespace std;

//Object class for account information
class Account {
public:
	//Declare setters
	void SetInitialInvestmentAmount(double initialInvestment); //Starting amount of investment
	void SetMonthlyDeposit(double monthlyDeposit);             //Amount planned to contribute each month
	void SetAnnualInterest(double annualInterest);             //Interest added and previous interest
	void SetNumberOfYears(int years);                             //Number of years to grow

	//Declare getters
	double GetInitialInvestmentAmount();
	double GetMonthlyDeposit();
	double GetAnnualInterest();
	int GetNumberOfYears();

	//Print Reports
	void PrintReportWithoutDeposits();
	void PrintReportWithDeposits();

private:
	double initialDep;
	double monthlyDep;
	double interestRate;
	int numYears;
};



#endif /* ACCOUNT_H_ */
