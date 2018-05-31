#include "money.h"
#include <iomanip>
#include <fstream>
#include <sstream>

Money::Money()
{
	dollars = 0;	// initializes dollars to 0 for new object
	cents = 0;		// initializes cents to 0 for new object
}

Money::Money (int new_dollars, int new_cents)
{
	if (new_dollars >= 0)			
		dollars = new_dollars;				// initializes dollars to new_dollars for new object
	if (new_cents >=0 && new_cents < 100)
		cents = new_cents;					// initializes cents to new_cents if cents >= 0 and < 100, for new object
}

void Money::add(int add_dollars, int add_cents)
{
	if (add_dollars >= 0)
		dollars += add_dollars;			        // adds add_dollars to current amount of dollars
	
	if (add_cents >=0 && add_cents < 100)	    // if cents is >= 0 and < dollar
	{
		if (cents + add_cents >= 100)		    // if current cents plus add_cents >= dollar
		{
			dollars++;					     	// increment dollars by 1
			cents = (cents + add_cents) - 100;  // cents to add after incrementing by dollar
		}
		else	
			cents += add_cents;	               
	}
}

void Money::subtract(int sub_dollars, int sub_cents)
{
	dollars -= sub_dollars;						// subtract sub_dollars from dollars
	
	if (sub_cents > cents)						// if subtracting more cents (via sub_cents) than current cents		
	{
		cents = 100 + (cents - sub_cents);		// keep cents part only as if a dollar was subtracted
		dollars--;							 	// reduce dollars by 1
	}
	
	else if (sub_cents == cents)			 
		cents = 0;
	
	else
		cents = cents - sub_cents;
	
	if ( dollars < 0 )							// set minimum dollar and cent value at 0
	{
		dollars = 0;
		cents = 0;	
	}
}

void Money::display() const
{
	cout<<to_string();
}

string Money::to_string() const
{
	
	string total;
	
	stringstream str_dollars_ss;					// convert dollars to string
	str_dollars_ss << dollars;
	string str_dollars = str_dollars_ss.str();
	
	if (dollars >= 1000)							// add commas to dollar amounts > 1000
	{	
		int comma_counter = 1;
	
		for (int i = str_dollars.length() - 1; i > 0; i--, comma_counter++)
		{
			if (comma_counter % 3 == 0)
			{
			str_dollars.insert(i, ",");
			}
		}
		
	}	
	
	stringstream str_cents_ss;					     	// convert cents to string
	str_cents_ss << cents;
	string str_cents = str_cents_ss.str();	
			
	if (cents >= 10)							    	// if cents > 10, format is $dollars.cents
		total = "$" + str_dollars + "." + str_cents;
	else												// if cents < 10, format is $dollars.0cents
		total = "$" + str_dollars + ".0" + str_cents;
		
	return total;
}

int Money::get_dollars() const
{
	return dollars;
}

int Money::get_cents() const
{
	return cents;
}

bool Money::isBigger(const Money &Other)
{
	if ( (dollars + cents) >= (Other.dollars + Other.cents) )   // compare current object's dollar + cents to other object dollar + cents
		return true;
	else 
		return false;
}
