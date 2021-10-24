#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
class account
{   private:  
       int nationalID;
       char accname[50];
       int deposit;
       char type;
	public:
		account();
	
     
       
		  void create_account();     //function to get data from user and this called in write account
      void show_account() const; //function to show data on screen
       void modify();       //function to add new data
       void dep(int);       //function to accept amount and add to balance amount
       void draw(int);      //function to accept amount and subtract from balance amount
      /// void report() const; //function to show data in tabular format
   ///    int retnationalID() const; //function to return account number
///	   char rettype() const;
//	  int retdeposit() const;    //function to return balance amount
	  
      
	   
int retnationalID() const//function to return account number
{
       return nationalID ;
}

	    
int retdeposit() const//function con
{
       return deposit;
}

char rettype() const//function const 
{
       return type;
}

    

void report() const// when check
{
       cout << nationalID << setw(10) << " " << accname << setw(10) << " " << type << setw(6) << deposit << endl;
}
  


            // functions   frirnd in class account bank


	  friend  void write_account();  
	  friend  void display_sp();
	  friend  void modify_account();
	  friend  void display_all();
	  friend  void deposit_withdraw();
	  friend  void delete_account();
	    
};

#endif
