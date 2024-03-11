#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

void display_customer(Account p);
void update_balance(Account p);

int main() {

    Account steve_account {"Steve",1000,1};

    display_customer(steve_account);
    update_balance(steve_account);

    // steve_account.update_balance(deposit_in);
    // steve_account.get_balance();

    return 0;
}

