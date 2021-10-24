#include "account.h"
#include<iostream>
#include<iomanip>
using namespace std;
account::account()
{
}


void account::create_account()
{      
       try{// exception handing by used try and catch;
	   
       cout << "\n\n\nEnter your National ID : ";
       cin >>nationalID;
       if (nationalID <= 0)
	   {
	   	throw " enter correct namber";
	   } else 
	   { 
       //cout << "\n\n\n Enter anew your National ID : ";
       //cin >>nationalID;
	   }
         }  catch( const char *err) 
		   {
		 	cout<<"\n exception :"<<err;
		 	cout << "\n\n\n Enter anew your National ID : ";
              cin >>nationalID;
			}   // end try and catch and exception handing of national id
       cout << "\n\nEnter The Name of The account in Bank  : ";
       cin.ignore();
       cin.getline(accname, 50);
       cout << "\nEnter Type of The account (Current or Saving) : ";
       cin >> type;
       type = toupper(type); //t==T
       try{
       cout << "\nEnter The Initial amount(>=500 for Saving (s/S)\n"
	     << "\n\t and >=1000 for current  (c/C) enter balanc account :  ";
       cin >>deposit;
	  
       if (deposit<=0)
	   {
	   	throw " enter correct namber";
	   }//else// {continue;}
         }  catch( const char *err) 
		   {
		 	cout<<" exception :"<<err;
		 	cout<< " anew nember courct \n:";
		 	 cin >>deposit;
			}  //// end try and catch and exception handing of deposit
       cout << "\n\n\n  Account Created   ";
}


void account::modify()
{
       cout << "\n nationalID your Account  : " << nationalID;
       
       cout << "\nModify Account  Name : ";
         cin.ignore();// used becouse getline
       cin.getline(accname, 50);
       cout << "\n Modify Type of Account(Current or Saving ) : ";
       cin >> type;
       type = toupper(type);
  
             try{
     cout << "\n Modify Balance amount  (C >1000/S>500): ";
       cin >>deposit;
	  
       if (deposit<=0)
	   {
	   	throw " enter correct namber";
	   }//else// {continue;}
         }  catch( const char *err) 
		   {
		 	cout<<" exception :"<<err;
		 	cout<< " anew nember courct \n:";
		 	 cin >>deposit;
			}  //// end try and catch and exception handing of deposit
}


void account::dep(int x)
{
       deposit += x;// when deposit
}

void account::draw(int x)
{
       deposit -= x;//When withdraw
}

void account::show_account() const
{
       cout << "\nAccount national ID :   " <<nationalID ;
       cout << "\nAccount  Name  in bank: ";
       cout << accname;
       cout << "\nType of Account : " << type;
       cout << "\nBalance amount : " << deposit;
}


