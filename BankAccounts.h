//
//  BankAccount2.h
//  MySmallBank2
//
//  Created by Kemal Abdulrahman on 7/09/18.
//  Copyright © 2018 Kemal Abdulrahman. All rights reserved.
//
//

#include <stdio.h>




//



#include <string>
#include <ctime>

using namespace std;

class BankAccount
{
protected:
   //protected:
   int         m_id ;

protected:
   string      m_name;
   double      m_balance;

public:
   BankAccount() ;
   BankAccount(string initialName, double initialBalance);
   void setID(int id);
   int  getID();
   double getBalance();
   void   setBalance(double Bal);
   void   setName(string name);
   string getName();
   bool     deposit(double amount);
   bool     withdraw(double amount);
   double   balance() const;
   virtual void     print() const;
   ~BankAccount();   // destructor

   friend class Checking;
};

class SavingAccount : public BankAccount
{
private:

   int         m_year_opened ;
   double      m_interest_rate;
   struct transcations{
      string b_type;
      double amount;
      time_t t_time = time(nullptr);
   }Savingtransactions;
   transcations *tranarray=new transcations[100];
public:



   SavingAccount();
   SavingAccount(string, double, int, double);
   void     setYear(int year);
   int      getYear();
   void     setInterestRate(double rate);
   double   getInterest();
   void     print() const ;  // Override super's class method
   void     toString();
};

class Checking
{
public:
   void changeBalance(BankAccount &);
};


