#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>
#include <vector>
class Account
{
    private:
        std::string name;
        double balance;
        //double credit;
        int id;
        // double *val_d;
        // double *val_b;

    public:
        Account();  // No Arg. Constructor
        Account(std::string n);  // String Constructor
        Account(std::string n, double b, int i); // Constructor

        std::vector<Account> customers;

        // methods
        double get_balance() const;
        double get_deposit() const;
        std::string get_name() const;
        int get_id() const;
        void charge_deposit();
        double send_credit();
        void get_credit(double *credit_ptr);
        void reset_credit();

        void create_customer(int number_customer);

        //Account(const Account &source); // Copy Constructor
        //~Account(); // Destructor
};

#endif //_ACCOUNT_H_
