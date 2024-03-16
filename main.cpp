#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

static int number_customer = 1;

void display_customer(Account p);
void update_balance(Account p);
void sending_address();
void sending_money(Account person_out, Account person_in);
void create_customer(int number_customer);

int main() {
    Account bank;
    bank.create_customer(int number_customer);

    // Accounts
    // Account steve_account {"Steve",1000,1};
    // display_customer(steve_account);
    // Account tim_account {"Tim",500,2};
    // display_customer(steve_account);
    // display_customer(tim_account);

    // update_balance(steve_account);
    // sending_money(steve_account, tim_account);

    return 0;
}

