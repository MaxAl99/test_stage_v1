#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

void display_customer(Account p);
void update_balance(Account p);
void sending_address();
void sending_money(Account person_out, Account person_in);
void create_customer();

void adding_customer(Bank& p);
void disp_all_customer(Bank& p);
void disp_customer(Bank& p);

void charge_money(Bank& p);
void sending_money(Bank& p);

int main() {
    

    Bank Stonks_Bank_CORP;

    adding_customer(Stonks_Bank_CORP);
    disp_all_customer(Stonks_Bank_CORP);
    disp_customer(Stonks_Bank_CORP);

    charge_money(Stonks_Bank_CORP);

    sending_money(Stonks_Bank_CORP);


    return 0;
}

