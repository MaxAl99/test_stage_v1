#ifndef _BANK_H_
#define _BANK_H_
#include "Account.h"
#include <string>
#include <iostream>
#include <vector>

static int number_customer = 1;

class Bank
{
    private:
        std::vector<Account> customers;

    public:

    void create_customer(int number_customer) {
    std::string *customer_name = nullptr;
    customer_name = new std::string;
    //*customer_name = 
    std::cout << "Name of new customer: " << std::endl;
    std::cin >> *customer_name;

    double *customer_balance = nullptr;
    customer_balance = new double;
    //*customer_name = 
    std::cout << "Name of new customer: " << std::endl;
    std::cin >> *customer_balance;

    //Account new_account {*customer_name, *customer_balance, number_customer};
    Account new_customer(*customer_name, *customer_balance, number_customer);
    customers.push_back(new_customer);
    number_customer += 1;
    std::cout << "Customer added successfully!" << std::endl;
    }

    // Get a reference to a single customer by index
    Account& get_customer(int index) {
        return customers.at(index);
    }

};

#endif //_BANK_H_