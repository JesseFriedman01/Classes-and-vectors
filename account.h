#include <iostream>
#include <cstdlib>
#include "money.h"
#include <vector>

using namespace std;

#ifndef ACCOUNT
#define ACCOUNT

class Account
{
	private:
		
		Money amount; 							// created object name amount of class Money
		string account_id, account_nickname;	// stores random 10 digit account number, stores user assigned nickname for account(s)
		vector<string> transaction_history;		// stores data for all transactions made on all accounts
		
		//#####################################################################  
		// void rand_num ();
		// Purpose: creates random 10 digit number, converts it a string, 
		// assigns the string to account_id
		// Pre-conditions: none  
		// Post-conditions: none
		//######################################################################  
		void rand_num ();						
		
	public:
		
		//#####################################################################  
		// Account() 
		// Purpose: Default Constructor: initializes account_id of new Account 
		// object via rand_num, nickname as "None", dollars and cents to 0
		// Pre-conditions: none  
		// Post-conditions: Outputs confirmation message to console  
		//######################################################################  
		Account();
		
		//#####################################################################  
		// Account(int start_dollars, int start_cents, string nickname);	
		// Purpose: Specific Constructor: initializes account_id of new Account 
		// object via rand_num, assigns user entered nickname to account
		// calls add method of amount object to add start_dollars and start_cents 
		// to account, sends data to compile_transaction_history, calls interest
		// method
		// Pre-conditions: start_dollars is a positive integer, start_cents is 
		// an integer value 0 - 99   
		// Post-conditions: Outputs confirmation message to console
		//######################################################################  
		Account(int start_dollars, int start_cents, string nickname);	
		
		//#####################################################################  
		// Display() 
		// Purpose: output basic information for all opened accounts
		// Pre-conditions: none  
		// Post-conditions: Outputs information to console  
		//###################################################################### 				
		void Display();
		
		//#####################################################################  
		// void withdraw(int minus_dollars, int minus_cents); 
		// Purpose: subtract user entered amount from account if balance of account
		// is sufficient, via subtract method of Money class
		// Pre-conditions: minus_dollars is a positive integer, start_cents is 
		// an integer value 0 - 99
		// Post-conditions: Outputs confirmation message to console  
		//###################################################################### 
		void withdraw(int minus_dollars, int minus_cents); 
		
		//#####################################################################  
		// void deposit (int minus_dollars, int minus_cents); 
		// Purpose: add user entered from account, via add method of Money class
		// Pre-conditions: plus_dollars is a positive integer, plus_cents is 
		// an integer value 0 - 99
		// Post-conditions: Outputs confirmation message to console  
		//###################################################################### 
		void deposit(int plus_dollars, int plus_cents); 
		
		//#####################################################################  
		// void interest(); 
		// Purpose: add 10% to the starting amount of an account
		// Pre-conditions: none
		// Post-conditions: none
		//###################################################################### 
		void interest();
		
		//#####################################################################  
		// void transfer(Account &source, Account &destination, int amount); 
		// Purpose: transfer user entered amount from source account to destination
		// Pre-conditions: source and destination are valid objects of Account 
		// class
		// Post-conditions: Outputs confirmation message to console 
		//###################################################################### 		
		void transfer(Account &source, Account &destination, int amount);
		
		//#####################################################################  
		// void compile_transaction_history(string transaction, int dollars...);
		// Purpose: compile data for each transaction and add it to 
		// transaction_history vector
		// Pre-conditions: transaction is a string, dollars in a positive integer,
		// cents is a positive integer
		// Post-conditions: none
		//###################################################################### 		
		void compile_transaction_history(string transaction, int dollars, int cents);
		
		//#####################################################################  
		// void display_transaction_history();
		// Purpose: display all transactions for all accounts from 
		// transaction_history vector
		// Pre-conditions: none
		// Post-conditions: none
		//###################################################################### 
		void display_transaction_history();
		
		//#####################################################################  
		// is_valid(Account &source, int sub_dollars, int sub_cents);
		// Purpose: returns true if current balance of account is greater than 
		// sub_dollars plus sub_cents
		// Pre-conditions: source is an object of Account class, sub_dollars is
		// a positive integer, sub_cents is a positive integer value 0 - 99. 
		// Post-conditions: returns true or false
		//###################################################################### 
		bool is_valid(Account &source, int sub_dollars, int sub_cents);
		
		//#####################################################################  
		// string money_to_string(string transaction, int dollars, int cents);
		// Purpose: converts dollars and cents to one string in format, 
		// $dollars.cents. Includes commas if dollars > 1000 and appends a 
		// "-" in front of string if transaction type is withdrawal. 
		// Pre-conditions: transaction is a string, dollars is a positive 
		// integer, cents is a positive integer 0 - 99. 
		// Post-conditions: returns string of $dollars.cents
		//######################################################################
		string money_to_string(string transaction, int dollars, int cents);
		
		//#####################################################################  
		// string getAcctNickname();
		// Purpose: simply returns nickname of account
		// Pre-conditions: none
		// Post-conditions: returns nickname of account
		//######################################################################
		string getAcctNickname();
};

#endif
