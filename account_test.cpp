#include "account.h"
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
	srand ( time(NULL) );												// use internal clock to control choice of seed for random number 
	
	vector<Account> account_vector;										// initialize new vector of type (class) Account
	vector<Account>::iterator it;										// initialize iterator for vector 
		
	Account *a;															// initialize pointer of account class
	
	int selection, counter, account_check, initial_dollars, initial_cents, transfer_amount, deposit_dollars, deposit_cents, withdraw_dollars, withdraw_cents;
	
	string nickname, source_account_input, destination_account_input;
	
	while (true)
	{	
		system ("CLS"); 												// clear the screen for easier legibility 
		
		cout << "Welcome to Bank++"
			 << "\n\n10% interest applied on all new accounts!"
			 << "\n\nChoose an option below:"
			 << "\n\n1. Open a new account"
			 << "\n2. View account information"
			 << "\n3. Make a deposit"
			 << "\n4. Make a withdrawal"
			 << "\n5. Make a transfer"
			 << "\n6. View transaction history"
			 <<"\n\n--->";
			 
		cin >> selection;
			 
		if (selection == 1)	 
		{
			cout << "\nEnter an account nickname: ";					 // each account is assigned a 10 digit account # but nicknames are easier to use  
			cin >> nickname;
						
			cout << "\nEnter initial deposit of dollars: ";
			cin >> initial_dollars;
			
			cout << "Enter initial deposit of cents (0-99): ";
			cin >> initial_cents;
					
			a = new Account(initial_dollars, initial_cents, nickname);    // create dynamic Account object
			
		    account_vector.push_back(*a);								  // add pointer to object to vector
						
			system ("CLS"); 											  // clear the screen for easier legibility 
		}	
		
		else if (selection == 2)
		{	
			cout << endl << setw(18) << "Acct Number" << setw(18) << "Acct Nickname" << setw(18) << "Balance" << endl;   // title (headers) for each column of data
			
			cout << endl;
			
			counter = 1;
			
			for ( it = account_vector.begin(); it < account_vector.end(); it++, counter++ ) 	// iterate through vector
			{	
				cout<<counter;																	// add number value (i.e. 1 - n) before each account
				it->Display();																	// call Display method of Account class to output account information										
			}
			
			cout<<endl;
			
			system("pause"); 
		}
		
		else if (selection == 3)
		{	
			cout << "Enter account nickname to make deposit into: ";
			cin >> destination_account_input;
			
			cout<<endl;
			
			cout << "Enter amount of dollars: ";
			cin >> deposit_dollars;
			
			cout << "Enter amount of cents: ";
			cin >> deposit_cents;
			
			account_check = 0;
			
			for ( it = account_vector.begin(); it < account_vector.end(); it++ ) 				// iterate through vector
				{
				if ( it->getAcctNickname() == destination_account_input ) 						// if user entered nickname exists in one of the already created accounts 
					{
					it->deposit(deposit_dollars, deposit_cents);								// call deposit method of Account class for account in the current location of the vector
					account_check++;															// increment when account nickname is found
					}
				}
				
			if (account_check == 0)
				cout<<"\nAccount not found!";
			
			cout << endl;		
			system("pause"); 
		}
		
		else if (selection == 4)
		{	
			cout << "Enter account nickname to make withdrawal from: ";
			cin >> destination_account_input;
			
			cout<<endl;
			
			cout << "Enter amount of dollars: ";
			cin >> withdraw_dollars;
			
			cout << "Enter amount of cents: ";
			cin >> withdraw_cents;
			
			account_check = 0;
			
			for ( it = account_vector.begin(); it < account_vector.end(); it++ ) 				// iterate through vector
				{
				if ( it->getAcctNickname() == destination_account_input ) 						// if user entered nickname exists in one of the already created accounts 
					{
					it->withdraw(withdraw_dollars, withdraw_cents);								// call withdraw method of Account class for account in the current location of the vector
					account_check++;															// increment when account nickname is found
					}
				}
				
			if (account_check == 0)
				cout<<"\nAccount not found!";
			
			cout << endl ;		
			system("pause"); 
		}
		
		
		else if (selection == 5)
		{	
		
			cout << "Enter account nickname to transfer from: ";
			cin >> source_account_input;
			
			cout << endl;
			
			cout << "Enter account nickname to transfer to: ";
			cin >> destination_account_input;
			
			cout << endl;
			
			cout << "Enter $ amount to transfer: ";
			cin >> transfer_amount;
			
			cout << endl;
			
			account_check = 0;
			
			for ( it = account_vector.begin(); it < account_vector.end(); it++ ) 							// iterate through vector
			{
				if ( it->getAcctNickname() == source_account_input ) 										// search for nickname of account to transfer from (source account)
					account_check++;																		// iterate if found
				else if ( it->getAcctNickname() == destination_account_input ) 								// search for nickname of account to transfer from (destination account)
					account_check++;																		// iterate if found
			}
			
			if ( account_check == 2 )																		// if both the source and destination accounts were found
			{
				
				Account *source_account;																	// initialize pointer of account class for source account
				Account *destination_account;																// initialize pointer of account class for destination account
			
				for ( it = account_vector.begin(); it < account_vector.end(); it++ ) 						// iterate through vector
				{
					if ( it->getAcctNickname() == source_account_input ) 									// search for nickname of source account
					{
					source_account = new Account();															// create dynamic Account object							
					*source_account = *it;																	// copy data in current location of vector to source_account
					account_vector.erase(it);																// erase current vector element (is replaced by modified source_account below)
					}
				}
				
				for ( it = account_vector.begin(); it < account_vector.end(); it++ ) 						// iterate through vector
				{
					if ( it->getAcctNickname() == destination_account_input ) 								// search for nickname of source account
					{
					destination_account = new Account();													// create dynamic Account object	
					*destination_account = *it;																// copy data in current location of vector to destination_account
					
					account_vector.erase(it);																// erase current vector element (is replaced by modified destination_account below)
					}
				}
							
				it->transfer(*source_account, *destination_account, transfer_amount);						// call transfer method of Account class 
				account_vector.push_back(*source_account);													// add source_account data to vector after its been modified (withdrawn from via transfer method)
				account_vector.push_back(*destination_account);												// add destination_account data to vector after its been modified (deposited into via transfer method)
			
			}
			else
			{
				cout<<"Account(s) not found!"<<endl;
				system("pause"); 
			}
			
		}
		
		else if (selection == 6)
		{
			cout << endl << setw(18) << "Transaction" << setw(18) << "Acct Number" 							// title (headers) for each column of data
				 << setw(18) << "Acct Nickname" << setw(18) << "Balance" << setw(18) 
				 << "Amount" <<endl << endl;  

			for ( it = account_vector.begin(); it < account_vector.end(); it++ ) 							// iterate through vector
			{
			it->display_transaction_history();																// call display_transaction_history method in Account class for each element in vector
			}
			
			cout<<endl;
			system("pause"); 
		}
	}	
}
