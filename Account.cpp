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
    balance -= deposit;
}

void update_balance(Account p) {
    p.charge_deposit(); // call member function
    std::cout << "The new balance of: " << p.get_name() << " is: " << p.get_balance() << std::endl;
}