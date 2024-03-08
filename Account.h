#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
    private:
        std::string name;
        double balance;
        int id;

    public:
        Account();  // No Arg. Constructor
        Account(std::string n, double b, int i); // Constructor

        double get_balance() const;
        std::string get_name() const;
        int get_id() const;

        //Account(const Account &source); // Copy Constructor
        //~Account(); // Destructor
};

#endif //_ACCOUNT_H_
