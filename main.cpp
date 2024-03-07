#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

void display_customer(Account p);

int main() {
    // cout.precision(2);
    // cout << fixed;

    Account steve_account {"Steve",1000,1};

    display_customer(steve_account);

    return 0;
}

void display_customer(Account p) {
	std::cout << "Name: " << p.get_name() << std::endl;
	std::cout << "ID: " << p.get_id() << std::endl;
    std::cout << "Balance: " << p.get_balance() << std::endl;
}

