#include "Account.h"
#include <memory>

Account::Account(std::string n, double b, int i) : name(n), balance(b), id(i) {};

std::string Account::get_name() const {
    return name;
}

int Account::get_id() const {
    return id;
}

double Account::get_balance() const {
    return balance;
}

void display_customer(Account p) {
	std::cout << "Name: " << p.get_name() << std::endl;
	std::cout << "ID: " << p.get_id() << std::endl;
    std::cout << "Balance: " << p.get_balance() << std::endl;
}

void Account::create_customer(int number_customer) {
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

    Account new_account {*customer_name, *customer_balance, number_customer};
    number_customer += 1;
    customers.push_back(new_account);

    std::cout << "Customer added successfully!" << std::endl;
}

void new_customer(Account p) {
    std::cout << "*** creating new customer ***" << std::endl;
    p.create_customer(number_customer);
}

void Account::charge_deposit() {
    double deposit;
    std::cout << "Charge new deposit: " << std::endl;
    std::cin >> deposit;
    if (balance-deposit >= 0) {
    balance -= deposit;
        std::cout << name << " was successfully charged." << std::endl;
    } else {
        std::cout << name << " balance is too low." << std::endl;
        throw 0;
    }
}

double Account::send_credit() {
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

void Account::get_credit(double *credit_ptr) {
    balance += *credit_ptr;
        std::cout << name << " credit was successful." << std::endl;
}

// void Account::reset_credit() {
//     credit = 0;
// }

void update_balance(Account p) {
    try {
    p.charge_deposit(); // call member function
    std::cout << "The new balance of " << p.get_name() << " is: " << p.get_balance() << std::endl;
    }
    catch (...) {
    std::cout << "The balance of " << p.get_name() << " was not changed." << std::endl;
    }
}

// sending function

void sending_money(Account person_out, Account person_in) {
    try {
    double *credit_ptr = nullptr;
    credit_ptr = new double;
    *credit_ptr = person_out.send_credit(); // call member function
    person_in.get_credit(credit_ptr); // call member function
    std::cout << "The new balance of " << person_out.get_name() << " is: " << person_out.get_balance() << std::endl;
    std::cout << "The new balance of " << person_in.get_name() << " is: " << person_in.get_balance() << std::endl;
    delete credit_ptr;
    }
    catch (int &ex) {
    std::cout << "The balance of " << person_out.get_name() << " was not changed." << std::endl;
    //delete credit_ptr;
    }
}

// void sending_address() {
//     //static double person_in;
//     std::string person_in;
//     std::string *in_ptr = nullptr;
//     std::cout << "To whom do you want to send a credit?" << std::endl;
//     std::cin >> person_in;
//     in_ptr = &person_in;
//     //static double person_out;
//     std::string person_out;
//     std::string *out_ptr = nullptr;
//     std::cout << "Who will be charged?" << std::endl;
//     std::cin >> person_out;
//     out_ptr = &person_out;
//     sending_money(std::string out_ptr, std::string in_ptr);
// }