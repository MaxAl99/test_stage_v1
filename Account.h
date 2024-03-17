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
        int id;

    public:
        Account();  // No Arg. Constructor
        Account(std::string n);  // String Constructor
        Account(std::string n, double b, int i); // Constructor


        // methods
        // double get_balance() const;
        // std::string get_name() const;
        // int get_id() const;

        //Account(const Account &source); // Copy Constructor
        //~Account(); // Destructor

        std::string get_name() const {
            return name;
        }

        int get_id() const {
            return id;
        }

        double get_balance() const {
            return balance;
        }

        void charge_deposit() {
            double deposit;
            std::cout << "State deposit to be charged: " << std::endl;
            std::cin >> deposit;
            if (balance-deposit >= 0) {
            balance -= deposit;
                std::cout << name << " was successfully charged." << std::endl;
            } else {
                std::cout << name << " balance is too low." << std::endl;
                throw 0;
            }
        }

        double send_credit() {
            double deposit;
            std::cout << "Charge new credit volume: " << std::endl;
            std::cin >> deposit;
            if (balance-deposit >= 0) {
            balance -= deposit;
            double credit = deposit;
            return credit;
                std::cout << name << " was successfully charged." << std::endl;
            } else {
                std::cout << name << " balance is too low." << std::endl;
                throw 0;
            }
        }

        void get_credit(double *credit_ptr) {
            balance += *credit_ptr;
                std::cout << name << " credit was successful." << std::endl;
        }
        
};

class Bank
{
    private:
        std::vector<Account> customers;
        int number_customer;

    public:
        
        Bank() : number_customer(1) {}

        void create_customer() {
            std::cout << "*** creating new customer ***" << std::endl;
            std::string *customer_name = new std::string;
            std::cout << "Name of new customer: " << std::endl;
            std::cin >> *customer_name;

            double *customer_balance = new double;
            std::cout << "Balance of new customer: " << std::endl;
            std::cin >> *customer_balance;

            Account new_account(*customer_name, *customer_balance, number_customer);
            number_customer += 1;
            customers.push_back(new_account);

            std::cout << "Customer added successfully!" << std::endl;

            delete customer_name;
            delete customer_balance;
        }

        void display_customers() {
            if (customers.empty()) {
                std::cout << "No customers available." << std::endl;
                return;
            }

            std::cout << "*** List of Customers ***" << std::endl;
            for (const auto& customer : customers) {
                std::cout << "Customer Name: " << customer.get_name() << std::endl;
                std::cout << "Customer Balance: " << customer.get_balance() << std::endl;
                std::cout << "Customer Number: " << customer.get_id() << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }

        void display_single_customer(int index) {
            if (customers.empty()) {
                std::cout << "No customers available." << std::endl;
                return;
            }
            if (index >= 0 && index < customers.size()) {
                std::cout << "*** Customer with ID " << index << " ***" << std::endl;
                std::cout << "Customer Name: " << customers.at(index).get_name() << std::endl;
                std::cout << "Customer Balance: " << customers.at(index).get_balance() << std::endl;
                std::cout << "Customer Number: " << customers.at(index).get_id() << std::endl;
                std::cout << "-------------------------" << std::endl; 
            } else {
                // Throw an exception or handle the error appropriately
                throw std::out_of_range("Index out of bounds");
            }
        }

        void charge_customer(int index) {
                if (customers.empty()) {
                    std::cout << "No customers available." << std::endl;
                    return;
                }
            try {
                if (index >= 0 && index < customers.size()) {
                    customers.at(index).charge_deposit(); // call member function
                    std::cout << "The new balance of " << customers.at(index).get_name() << " is: " << customers.at(index).get_balance() << std::endl;
                }
                else {
                    // Throw an exception or handle the error appropriately
                    throw std::out_of_range("Index out of bounds");
                    }
            }
            catch (...) {
            std::cout << "The balance of " << customers.at(index).get_name() << " was not changed." << std::endl;
            }
        }

        void credit_customer(int index_out, int index_in) {
                if (customers.empty()) {
                    std::cout << "No customers available." << std::endl;
                    return;
                }
            try {
                if (index_out >= 0 && index_out < customers.size() && index_in >= 0 && index_in < customers.size()) {
                    double *credit_ptr = nullptr;
                    credit_ptr = new double;
                    *credit_ptr = customers.at(index_out).send_credit(); // call member function
                    customers.at(index_in).get_credit(credit_ptr); // call member function
                    std::cout << "*** Transaction Summary ***" << std::endl;
                    std::cout << "The new balance of " << customers.at(index_out).get_name() << " is: " << customers.at(index_out).get_balance() << std::endl;
                    std::cout << "The new balance of " << customers.at(index_in).get_name() << " is: " << customers.at(index_in).get_balance() << std::endl;
                    std::cout << "-------------------------" << std::endl; 
                    delete credit_ptr;
                }
                else {
                    // Throw an exception or handle the error appropriately
                throw std::out_of_range("Index out of bounds");
                    }
                }
            catch (...) {
                std::cout << "The balance of " << customers.at(index_out).get_name() << " and " << customers.at(index_in).get_name() << " was not changed." << std::endl;
            }
        }

        // void update_balance_customer(int index) {
        //             if (customers.empty()) {
        //                 std::cout << "No customers available." << std::endl;
        //                 return;
        //             }
        //             if (index >= 0 && index < customers.size()) {
        //                 std::cout << "*** Customer with ID " << index << " ***" << std::endl;
        //                 std::cout << "Customer Name: " << customers.at(index).get_name() << std::endl;
        //                 std::cout << "Customer Balance: " << customers.at(index).get_balance() << std::endl;
        //                 std::cout << "Customer Number: " << customers.at(index).get_id() << std::endl;
        //                 std::cout << "-------------------------" << std::endl; 
        //             } else {
        //                 // Throw an exception or handle the error appropriately
        //                 throw std::out_of_range("Index out of bounds");
        //             }

};

#endif //_ACCOUNT_H_
