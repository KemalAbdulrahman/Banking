//
//  BankAccount2.cpp
//  MySmallBank2
//
//  Created by Kemal Abdulrahman on 7/13/18.
//  Copyright © 2018 Kemal Abdulrahman. All rights reserved.
//

#include "BankAccounts.h"
#include <iostream>

using namespace std;
#define Year 2018

BankAccount::BankAccount()
{
   m_balance = 0;
   m_name = " ";
}

BankAccount::BankAccount(string initialName, double initialBalance)
{
   m_balance = initialBalance ;
   m_name = initialName;
}

bool   BankAccount::deposit(double amount)
{
   m_balance += amount ;
   return true;
}

bool     BankAccount::withdraw(double amount)
{
   m_balance  -= amount ;
   return true;
}

double   BankAccount::balance() const
{
   return ( m_balance ) ;
}

void     BankAccount::print() const
{
   cout << "Name: " << m_name << endl;
   cout << "Balance: " << m_balance << endl;
}

void BankAccount::setID(int id) {
   m_id = id;
}

int BankAccount::getID() {
   return m_id;
}

double BankAccount::getBalance() {
   return m_balance;
}

void BankAccount::setBalance(double Bal) {
   m_balance = Bal;
}

void BankAccount::setName(string name) {
   m_name = name;
}

string BankAccount::getName() {

   return m_name;
}

BankAccount::~BankAccount() {
   //empty
}


// Note: must call super class constructor in the initializer list
SavingAccount::SavingAccount(string initialName, double initialBalance, int year, double rate) :
BankAccount(initialName, initialBalance)
{
   // BankAccount(initialBalance);   doesn't work
   m_year_opened = year;
   m_interest_rate = rate;
}

void     SavingAccount::print() const
{
   // cout << "Balance: " << m_balance << endl;
   cout << BankAccount::m_id << endl;   // compiling error if m_id is private
   BankAccount::print();
   cout << " Year opened: " << m_year_opened << "\t interest rate: "
   << m_interest_rate << endl;
}

void SavingAccount::setYear(int year) {

   m_year_opened = year;
}

int SavingAccount::getYear() {
   return m_year_opened;
}

void SavingAccount::setInterestRate(double rate) {

   m_interest_rate = rate;
}

double SavingAccount::getInterest() {
   return m_interest_rate;
}

void SavingAccount::toString() {
   cout<<"Account Balance: "<< this->getBalance()<<endl;
   cout<<"Interest: " << std::to_string(this->m_interest_rate*m_balance*(Year-m_year_opened))<<endl;
}

SavingAccount::SavingAccount() {
   this->m_year_opened = 0;
   this->m_interest_rate=0;
}


void Checking::changeBalance(BankAccount &acct)
{
   acct.m_id = 99;// it works because Checking is a friend of BankAccount
}

