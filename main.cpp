//
//  main.cpp
//  MySmallBank2
//
//  Created by Kemal Abdulrahman on 7/09/18.
//  Copyright © 2018 Kemal Abdulrahman. All rights reserved.
//
/*Name: Kamal Abdulrahman
 *Project: My small Bank
 *Editor: Xcode
 */
#include <iostream>
#include<ctime>
#include <string>
#include"BankAccounts.h"
#include <vector>
#include <fstream>
using namespace std;



void menu(){
   cout<<"Press o: Open an account"<<endl;
   cout<<"Press d: Deposit to account"<<endl;
   cout<<"Press w: Withdraw from account"<<endl;
   cout<<"Press s: Account show balance"<<endl;
   cout<<"Press t: Account transactions"<<endl;
};


int main() {

   struct transcations{
      string b_type;
      double amount;
      time_t t_time = time(nullptr);
   };


//    fstream outAccountFile("acounts.txt",ios::in| ios::out|ios::binary);
//    outAccountFile<<<<endl;
//   int account;
//   string data;
//   ofstream outAccountFile;
//   outAccountFile.open("accounts.dat",ios::binary);
//   cout<<"Write this in file"<<endl;
//   cin>>data;
//   outAccountFile<<data<<endl;
//   if(account<100)
//      cout<<"You are in the right range"<<endl;
//   else
//      cout<<"You are out of the range"<<endl;
//
//   cout<<"Enter account "<<endl;
//   outAccountFile.close();
//   ifstream inAccountFile;
//   inAccountFile.open("account.dat");
//   cout<<"Read to the file"<<endl;
//   inAccountFile>>data;
//   cout<<data<<endl;
//   inAccountFile.close();




   vector<transcations> all_transcations;

   int check_password = 1;
   cout<<"Welcome to my small bank app"<<endl;
   string password ;
   while(check_password <4){
      cout<<"Please enter the correct password"<<endl;
      cin>>password;
      if(password == "abc123") {
         cout << "Valid password" << endl;
         break;
      }
      check_password++;
      cin.clear();
      cin.ignore();
   }
   if(check_password == 4){
      cout<<"incorrect password, please try again later"<<endl;
      return 1;
   }
   char option;
   string name;
   int balance;
   int year_open;
   int account_number;
   int interest_rate;
   int check_if_account_open = 0;
   SavingAccount *new_account = new SavingAccount();

   do{
      menu();
      cin>>option;
      //open account
      if(option == 'o'){
         if(check_if_account_open ==0){
            cout<<"Please enter your account number from 1-100";
            cin>>account_number;
            while(account_number>100 || account_number<0)
            {
               cout<<"Out of range"<<endl;
               cout<<"Please enter your account number from 1-100 again";
               cin>>account_number;
            }

            cout<<"Please enter your name"<<endl;
            cin>>name;
            cout<<"Please enter your initial balance"<<endl;
            cin>> balance;
            cout<<"Please enter your year open"<<endl;
            cin>> year_open;
            cout<<"Please enter your interest rate"<<endl;
            cin>> interest_rate;
            new_account->setName(name);
            new_account->setBalance(balance);
            new_account->setYear(year_open);
            new_account->setInterestRate(interest_rate);
            check_if_account_open++;
         }
         else{
            cout<<"Error! Account already exits"<<endl;
         }
      }

      //Deposit money to the account
      else if(option == 'd'){
         if(check_if_account_open == 0){
            cout<<"Error! No account has been created"<<endl;

         }
         else{
            if(new_account->getBalance()>0){
               double n_amount;
               cout<<"Please enter the amount"<<endl;
               cin>>n_amount;
               if(n_amount<0)
                  cout<<"deposit cant be made"<<endl;
               else{
                  new_account->deposit(n_amount);
                  transcations deposit;
                  deposit.amount = n_amount;
                  deposit.b_type = "Deposit";
                  all_transcations.push_back(deposit);
                  cout<<"Success! The amount has been added"<<endl;
               }
            }
            else{
               cout<<"Error! The balance is less Zero"<<endl;
            }
         }
      }

      else if(option == 'w'){
         if(check_if_account_open == 0){
            cout<<"Error! No account has been created"<<endl;

         }
         else{
            cout<<"Please enter your account number and amount"<<endl;
            cin>>account_number;
            cout<<"Please enter the amount to withdraw"<<endl;
            double withdraw;
            cin>>withdraw;
            if(withdraw < new_account->getBalance()){
               new_account->withdraw(withdraw);
               transcations widthdraw_transcations;
               widthdraw_transcations.b_type = "Widthraw";
               widthdraw_transcations.amount = withdraw;
               all_transcations.push_back(widthdraw_transcations);
               cout<<"Success! The amount has been deducted from your account"<<endl;
            }
            else{
               cout<<"Error! Insufficient balance"<<endl;
            }
         }
      }

      else if(option == 's'){
         if(check_if_account_open == 0){
            cout<<"Error! No account has been created"<<endl;
         }
         else{
            cout<<"Please enter your account number ";
            cin>>account_number;
            new_account->toString();
         }
      }

      else if(option == 't'){
         cout<<"Transaction Type\t  Amount  \t Date  / Time"<<endl;

         for(auto i: all_transcations){
            cout<<i.b_type<<"\t"<<i.amount<<"\t"<<ctime(&i.t_time)<<endl;
         }
      }



   }while(option != 'y' && option != 'Y');
   return 0;
}

