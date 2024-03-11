#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account
{
    private:
        std::string name;
        double balance;
        int id;
        double *val_d;
        double *val_b;

    public:
        Account();  // No Arg. Constructor
        Account(std::string n, double b, int i); // Constructor

        // methods
        double get_balance() const;
        double get_deposit() const;
        std::string get_name() const;
        int get_id() const;
        void charge_deposit();

        //Account(const Account &source); // Copy Constructor
        //~Account(); // Destructor
};

#endif //_ACCOUNT_H_
