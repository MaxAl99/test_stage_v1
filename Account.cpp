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
