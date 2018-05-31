#include "account.h"
#include "money.h"
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <iomanip>

Account::Account()
{
	rand_num();	                                             // call rand_num to create new 10 digit ID for account
	
	amount.add(0, 0);										 // initialize starting dollar and cents amounts as 0
	account_nickname = "None";								
	compile_transaction_history("New account", 0, 0);		 // send info to compile_transaction_history
}

Account::Account(int start_dollars, int start_cents, string nickname)
{
	rand_num();																// call rand_num to create new 10 digit ID for account	
				
	amount.add(start_dollars, start_cents);									// initialize starting dollar and cents amounts based on inputs
	account_nickname = nickname;											// assign nickname via input 
			
	compile_transaction_history("New account", start_dollars, start_cents);	// send info to compile_transaction_history
																		
	interest();															    // add interest as its a new account
	
	cout << "\nNew account created!" << endl;
	cout << endl;
	system("pause");
}

void Account::interest()
{
	
	double dollars_interest = amount.get_dollars() * 1.1;                           				// calculate 10% interest on dollars
	
	int dollar_interest_to_add =  (int)dollars_interest - amount.get_dollars(); 					// determine the actual dollar amount to add 
	
	amount.add(dollar_interest_to_add, 0 );															// add the dollar amount to existing balance
	
	int cents_from_dollars = (dollars_interest - (int)dollars_interest) * 100;						// determine the cents to add based on the interest on the dollars only

	double cents_interest = amount.get_cents() * 1.1;												// calculate 10% interest on cents
	
	int current_cents = amount.get_cents();															// get current amount of cents (before interest is applied)
	
	int cents_interest_to_add = 0;

	if (cents_interest >= 100)																		// if current amount of cents plus interest >= dollar
		{
		cents_interest_to_add = int(cents_interest - 100) + cents_from_dollars;     				// take cents part only after dollar (e.g. $1.08 will just be 8 cents)
		amount.add( 0, cents_interest_to_add );														// add cents to existing account balance
		}
	else
		{
		cents_interest_to_add =  ( (int)cents_interest - current_cents  ) + cents_from_dollars ;	// if current amount of cents plus interest < dollar, determine actual cent amount to add
		amount.add( 0, cents_interest_to_add);														// add cents to existing account balance
		}
		
	compile_transaction_history("Interest", dollar_interest_to_add, cents_interest_to_add);			// send info to compile_transaction_history
	
}

void Account::rand_num()
{
	int rand_num;

	rand_num = rand() % 9000000000 + 1000000000; 	// create a 10 digit random number
	
	stringstream str_ss;							// convert it to a string
	str_ss << rand_num;
	string str = str_ss.str();

	account_id = str;								// assign string to account_id
}

void Account::withdraw(int minus_dollars, int minus_cents)
{
	int balance = amount.get_dollars() + amount.get_cents();					// balance of account is dollars + cents (not in dollar.cents form) so 10 dollars and 10 cents is a balance of 20
	
	if (balance >= minus_dollars + minus_cents)									// if balance > than user entered minus dollar + minus cents
	{
		amount.subtract(minus_dollars, minus_cents);							// subtract the dollars and cents via subtract method of Money class
		
		compile_transaction_history("Withdrawal", minus_dollars, minus_cents);	// send info to compile_transaction_history
		
		cout << "Withdrawal successful!"<<endl;
	}
		
	else																		// if balance < than user entered minus dollar + minus cents
	{
		cout << "\nThe account balance is too small to withdraw that amount. \n\nThe maximum that you can withdraw is: ";
		amount.display();
	}
}

void Account::deposit(int plus_dollars, int plus_cents)
{
	amount.add(plus_dollars, plus_cents);										// call add method of Money class to plus_dollars and plus_cents to account
	
	compile_transaction_history("Deposit", plus_dollars, plus_cents);			// send info to compile_transaction_history
	
	cout << "\nDeposit successful!"<<endl;		
}

void Account::transfer (Account &source, Account &destination, int amount)
{
	if ( is_valid (source, amount, 0) )											// call is_valid to check if balance in source account >= amount
		{
		source.withdraw(amount, 0);												// call withdraw method from source object to subtract amount
		destination.deposit(amount, 0);											// call deposit method from destination object to add amount
		cout << "\nTransfer successful!" << endl;
		}
	else
		{
		cout << "Transfer failed! The account balance in the source account has insufficient funds. \n\nThe maximum that you can withdraw is: ";
		source.amount.display();
		cout << endl << endl;
		}
	cout << endl;
	system("pause");
}

void Account::Display()
{
	cout <<  setw(18) << account_id << setw(18) << account_nickname << setw(18); amount.display();		
	cout << endl;
}

string Account::getAcctNickname()
{
	return account_nickname;
}

void Account::compile_transaction_history(string transaction, int dollars, int cents)
{
	string trans_amount = money_to_string(transaction, dollars, cents);		// converts amount of transaction to string
	
	transaction_history.push_back(transaction);
	transaction_history.push_back(account_id);
	transaction_history.push_back(account_nickname);
	transaction_history.push_back(amount.to_string());
	transaction_history.push_back(trans_amount);
}

void Account::display_transaction_history()
{
	int col_count = 4;
	
	for (int i = 0; i < transaction_history.size(); i++ )					// iterate through transaction_history vector
		{
			cout << setw(18) << transaction_history[i];
			
			if (i == col_count)												// output a newline every 5 increments of i as there are 5 pieces of data for each account being outputted
			{
				cout << endl;
				col_count = col_count + 5;
			}
			
		}
}

bool Account::is_valid(Account &source, int sub_dollars, int sub_cents)
{	
	int balance = source.amount.get_dollars() + source.amount.get_cents();		// balance of account is dollars + cents (not in dollar.cents form) so 10 dollars and 10 cents is a balance of 20

	if (balance >= sub_dollars + sub_cents)										// if balance is greater >= dollars + cents, return true
		return 1;
	else
		return 0;
}

string Account::money_to_string(string transaction, int dollars, int cents) 
{
	string total;
	
	stringstream str_dollars_ss;												// convert dollars to string
	str_dollars_ss << dollars;
	string str_dollars = str_dollars_ss.str();
	
	if (dollars >= 1000)														// add commas if dollar amount is >= 1000 by starting at the end of the number and inserting commas every 3 spaces
	{
		int comma_counter = 1;
	
		for (int i = str_dollars.length() - 1; i > 0; i--, comma_counter++)
		{
			if (comma_counter % 3 == 0)
				str_dollars.insert(i, ",");
		}
		
	}	
	
	stringstream str_cents_ss;													// convert cents to string
	str_cents_ss << cents;
	string str_cents = str_cents_ss.str();	
		
	if (cents >= 10)															// if cents > 10, format is $dollars.cents
		total = "$" + str_dollars + "." + str_cents;
	else																		// if cents < 10, format is $dollars.0cents
		total = "$" + str_dollars + ".0" + str_cents;
	
	if (transaction == "Withdrawal")									 		// append a "-" in front of string if transaction type is a withdrawal
		total = "-" + total;
		
	return total;
}

