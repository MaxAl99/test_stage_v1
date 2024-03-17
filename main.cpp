#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

void adding_customer(Bank& p);
void disp_all_customer(Bank& p);
void disp_customer(Bank& p);

void charge_money(Bank& p);
void sending_money(Bank& p);

void user_console(Bank& p);

int main() {
    

    Bank Stonks_Bank_CORP;

    user_console(Stonks_Bank_CORP);

    return 0;
}

