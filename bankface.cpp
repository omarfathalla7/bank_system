#include <iostream>
#include "account.h"
#include "data.h"
#include<fstream>
#include<cctype>
#include "empioyee.h"
using namespace std;



void write_account(); //function to write record in binary file
void deposit_withdraw(int n, int option);// function to deposit and withdraw amounts
void display_sp(int); //function to display account details given by user
void modify_account(int n);// function to modify record of file
void display_all();// function to display all accounts deposit listvoid delete_account(int n);//function to delete record of file


int main()
;data d {
;)(d.intro
;char ch
;int num
do
{
;system("cls")
;"cout << " \n\n\n\t\t\t\tYOUR SYSTEM MANAGMENT BANK
cout << "
SERVICES IN BANK \n\n\n\t\t\t YOUR
;" \n
;" cout << " \n\n\t 01: open New Account
;"cout << " \n\n\t 02: Deposet Amount to Money
;"cout << " \n\n\t 03: Withdraw Amount to Money
;" cout << " \n\n\t 04: Balanc Enquiry
;"cout << " \n\n\t 05: Veiw ALL ACCOUNT in bank
;" cout << " \n\n\t 06: Close an Account
;" cout << " \n\n\t 07: Modify an Account
;" cout << " \n\n\t 08: EXIT AND END\n\n\n
;" cout << "\n\n Select Your Option (1-8) to opration
;cin >> ch
;system("cls")
switch (ch)
{
:'case '1
;system("cls")
;)(write_account
;break
:'case '2
;system("cls")
;cout << "\n\n\tEnter The account national id. : "; cin >> num
;deposit_withdraw(num, 1)
;break
:'case '3
;system("cls");cout << "\n\n\tEnter The account national id. : "; cin >> num
;deposit_withdraw(num, 2)
;break
:'case '4
;system("cls")
;cout << "\n\n\tEnter The account national id. : "; cin >> num
;display_sp(num)
;break
:'case '5
;system("cls")
;)(display_all
;break
:'case '6
;system("cls")
;cout << "\n\n\tEnter The account national id : "; cin >> num
;delete_account(num)
;break
:'case '7
;system("cls")
;cout << "\n\n\tEnter The account national id. : "; cin >> num
;modify_account(num)
;break
:'case '8
;system("cls")
;"cout << "\n\n\t\t\t\a\a\a THANKS YOUR IN IN YUOR BANK MANAGMENT SYSTEM
;break
;"default:cout << "\a
}
;)(cin.ignore
;)(cin.get
;)'while (ch != '8 }
;return 0
}
void write_account() // to add anew account in file
{account ac; // object
;ofstream outFile
;outFile.open("account.dat", ios::binary | ios::app)
;)(ac.create_account
;outFile.write(reinterpret_cast<char *> (&ac), sizeof(account))
;)(outFile.close
}
function to display account details given by user//
function to read specific record from file //
void display_sp(int n)
{
;account ac
;bool flag = false
;ifstream inFile
;inFile.open("account.dat", ios::binary)
if (!inFile)
{
;"...cout << "File could not be open !! Press any Key
;return
}
;"cout << "\n Balance Detais \n
while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
{
if (ac.retnationalID() == n) //function to return national id
{
;)(ac.show_account
;flag = true
} }
;)(inFile.close
if (flag == false)
;"cout << "\n\n\aAccount number does not exist
}
function to display all accounts deposit list //
)(void display_all
{
;account ac
;ifstream inFile;inFile.open("account.dat", ios::binary)
if (!inFile)
{
;"...cout << "File could not be open !! Press any Key
;return
}
;"cout << "\n\n\t\tAccount list in bank \n\n
;"cout << "****************** *********************************************\n
;"cout << "A/cnational id. NAME Type Balance\n
;"cout << "******************* *********************************************\n
while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
{
;)(ac.report
}
;)(inFile.close
}
function to deposit and withdraw amounts //
void deposit_withdraw(int n, int option)
{
;int amt
;bool found = false
;account ac
;fstream File
;File.open("account.dat", ios::binary | ios::in | ios::out)
if (!File)
{
;"...cout << "File could not be open !! Press any Key
;return
}
while (!File.eof() && found == false)
{
;File.read(reinterpret_cast<char *> (&ac), sizeof(account))
if (ac.retnationalID() == n)
{
;)(ac.show_account
if (option == 1)
{
;" cout << "\n\n\tTO DEPOSITE AMOUNT;"cout << "\n\nEnter The amount to be deposited
;cin >> amt
;ac.dep(amt)
}
if (option == 2)
{
;" cout << "\n\n\tTO WITHDRAW AMOUNT
;"cout << "\n\nEnter The amount to be withdraw
;cin >> amt
;int bal = ac.retdeposit() - amt
if ((bal<500 && ac.rettype() == 'S') || (bal<1000 && ac.rettype() == 'C'))
;"cout << "Insufficience balance
else
;ac.draw(amt)
}
;int pos = (-1)*static_cast<int>(sizeof(ac))
;File.seekp(pos, ios::cur)
;File.write(reinterpret_cast<char *> (&ac), sizeof(account))
;"cout << "\n\n\t Record Updated
;found = true
} }
;)(File.close
if (found == false)
;" cout << "\n\n Record Not Found
}
function to modify record of file //
void modify_account(int n)
{
;bool found = false
;account ac
;fstream File
;File.open("account.dat", ios::binary | ios::in | ios::out)
if (!File)
{
;"...cout << "File could not be open !! Press any Key
;return
}while (!File.eof() && found == false)
{
;File.read(reinterpret_cast<char *> (&ac), sizeof(account))
if (ac.retnationalID() == n)
{
ac.show_account(); // to show data of account in bank
;cout << "\n\nEnter The New Details of account" << endl
ac.modify();// function to modify class account
;int pos = (-1)*static_cast<int>(sizeof(account))
;File.seekp(pos, ios::cur)
;File.write(reinterpret_cast<char *> (&ac), sizeof(account))
;"cout << "\n\n\t Record Updated
;found = true
} }
;)(File.close
if (found == false)
;"cout << "\n\n Record Not Found \n
}
function to delete record of file //
void delete_account(int n)//function to delete record of file
{
account ac; // object ac from class account
;ifstream inFile
;ofstream outFile
;inFile.open("account.dat", ios::binary)
if (!inFile)
{
;"...cout << "File could not be open !! Press any Key
;return
}
;outFile.open("Temp.dat", ios::binary)
;inFile.seekg(0, ios::beg)
while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
{
if (ac.retnationalID() != n){
;outFile.write(reinterpret_cast<char *> (&ac), sizeof(account))
} }
;)(inFile.close
;)(outFile.close
;remove("account.dat")
;rename("Temp.dat", "account.dat")
;".. cout << "\n\n\tRecord Deleted
}
      
