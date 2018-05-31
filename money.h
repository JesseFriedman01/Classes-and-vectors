#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef MONEY
#define MONEY

class Money
{
	private:
		
		int dollars, cents;		// stores dollar and cent amounts
			
	public:
		
		//#####################################################################  
		// Money();
		// Purpose: Default Constructor: initializes a new object with dollars 
		// and cents equal to zero
		// Pre-conditions: none 
		// Post-conditions: none
		//######################################################################  
		Money();
		
		//#####################################################################  
		// Money (int new_dollars, int new_cents);
		// Purpose: Specific Constructor: sets dollars and cents to inputs
		// Pre-conditions: new_dollars is a positive integer, new_cents is a 
		// positive integer value 0 - 99 
		// Post-conditions: none
		//######################################################################  
		Money (int new_dollars, int new_cents);
		
		//#####################################################################  
		// void add(int add_dollars, int add_cents);
		// Purpose: increment dollars and cents by inputs
		// Pre-conditions: add_dollars is a positive integer, add_cents is a 
		// positive integer value 0 - 99 
		// Post-conditions: none
		//######################################################################  		
		void add(int add_dollars, int add_cents);
		
		//#####################################################################  
		// void subtract(int sub_dollars, int sub_cents);
		// Purpose: decrement dollars and cents by inputs with a minimum value 
		// of 0 cents and 0 dollars
		// Pre-conditions: sub_dollars is a positive integer, sub_cents is a 
		// positive integer value 0 - 99 
		// Post-conditions: none
		//###################################################################### 
		void subtract(int sub_dollars, int sub_cents);
		
		//#####################################################################  
		// void display() const;
		// Purpose: output amount of money in $dollar.cents format with commas
		// for amounts > 1000
		// Pre-conditions: none
		// Post-conditions: display amount
		//######################################################################
		void display() const;
		
		//#####################################################################  
		// string to_string() const;
		// Purpose: returns a string of the amount of money in $dollar.cents 
		// format with commas for amounts > 1000
		// Pre-conditions: none
		// Post-conditions: returns string
		//######################################################################
		string to_string() const;
		
		//#####################################################################  
		// int get_dollars() const;
		// Purpose: returns dollar amount 
		// Pre-conditions: none
		// Post-conditions: returns integer of dollar amount
		//######################################################################
		int get_dollars() const;
		
		//#####################################################################  
		// int get_cents() const;
		// Purpose: returns amount of cents 
		// Pre-conditions: none
		// Post-conditions: returns integer of amount of cents
		//######################################################################
		int get_cents() const;
		
		//#####################################################################  
		// bool isBigger (const Money &Other);
		// Purpose: returns true/false if amount of current dollars+cents in 
		// current Money object is >= to another Money object (via input) 
		// Pre-conditions: Other is a valid object of class Money
		// Post-conditions: returns true/false
		//######################################################################
		bool isBigger (const Money &Other);
		
	
};

#endif
