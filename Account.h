#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
    private:
        std::string name;
        int Balance;
        int customer_id;

    public:
        Account();  // No Arg. Constructor
        Account(std::string name, int Balance, int customer_id); // Constructor

        int get_balance() {return Balance; }
        std::string get_name() {return name; }
        int get_id() {return customer_id; }

        //Account(const Account &source); // Copy Constructor
        ~Account(); // Destructor
};

// Assignment Init
// Account::Account() :name{"None"}, Balance{0}, customer_id{0} {
// }

// // Initialization List
// Account::Account(std::string name_str, int bal, int id)
//     : name{name_str}, Balance{bal}, customer_id{id} {
// }

#endif //_ACCOUNT_H_