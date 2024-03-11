#include "Account.h"

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

void Account::charge_deposit() {
    double deposit;
    std::cout << "Charge new deposit: " << std::endl;
    std::cin >> deposit;
    if (balance-deposit >=0) {
    balance -= deposit;
        std::cout << name << " was successfully charged." << std::endl;
    } else
        std::cout << name << " balance is too low." << std::endl;
        throw 0;
}

void Account::send_credit() {
    double deposit;
    std::cout << "Charge new credit volume: " << std::endl;
    std::cin >> deposit;
    if (balance-deposit >=0) {
    balance -= deposit;
    credit = deposit;
        std::cout << name << " was successfully charged." << std::endl;
    } else
        std::cout << name << " balance is too low." << std::endl;
        throw 0;
}

void Account::get_credit() {
    balance += credit;
        std::cout << name << " credit was successful." << std::endl;
}

void Account::reset_credit() {
    credit = 0;
}

void update_balance(Account p) {
    try {
    p.charge_deposit(); // call member function
    std::cout << "The new balance of " << p.get_name() << " is: " << p.get_balance() << std::endl;
    }
    catch (int &ex) {
    std::cout << "The balance of " << p.get_name() << " was not changed." << std::endl;
    }
}

// sending function

// void sending_money(Account person_out, Account person_in) {
//     try {
//     person_out.send_credit(); // call member function
//     person_in.get_credit(); // call member function
//     std::cout << "The new balance of " << person_out.get_name() << " is: " << person_out.get_balance() << std::endl;
//     std::cout << "The new balance of " << person_in.get_name() << " is: " << person_in.get_balance() << std::endl;
//     person_out.reset_credit(); // call member function
//     person_in.reset_credit(); // call member function
//     }
//     catch (int &ex) {
//     std::cout << "The balance of " << person_out.get_name() << " was not changed." << std::endl;
//     }
// }

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