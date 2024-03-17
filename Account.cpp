#include "Account.h"
#include <memory>

Account::Account(std::string n, double b, int i) : name(n), balance(b), id(i) {};

// *** calling functions of class member functions ***
void adding_customer(Bank& p) {
            int flag = 1;
            while (flag == 1) {
                p.create_customer();
                std::cout << "Do you want another customer?: " << std::endl;
                std::cout << " Yes: 1 " << std::endl;
                std::cout << " No: 0 " << std::endl;
                std::cin >> flag;
                std::cout << " " << std::endl;
            }
}

void disp_all_customer(Bank& p) {
    p.display_customers();
    std::cout << " " << std::endl;
}

template<typename Function>
void perform_action(const std::string& prompt, Function action) {
    int index;
    int flag = 1;
    while (flag == 1) {
        std::cout << prompt << std::endl;
        std::cin >> index;
        action(index); // Call the function passed as argument
        std::cout << "Do you want to perform another action?: " << std::endl;
        std::cout << " Yes: 1 " << std::endl;
        std::cout << " No: 0 " << std::endl;
        std::cin >> flag;
        std::cout << " " << std::endl;
    }
}

void disp_customer(Bank& p) {
    perform_action("Provide Customer ID to be displayed: ", [&](int index) {
        p.display_single_customer(index);
    });
}

void charge_money(Bank& p) {
    perform_action("Provide Customer ID to be charged: ", [&](int index) {
        p.charge_customer(index);
    });
}

void sending_money(Bank& p) {
    int index_out;
    int index_in;
    int flag = 1;
    while (flag == 1) {
        std::cout << "Provide Customer ID to be charged: " << std::endl;
        std::cin >> index_out;
        std::cout << "Provide Customer ID for credit note: " << std::endl;
        std::cin >> index_in;
        p.credit_customer(index_out, index_in);
        std::cout << "Do you want to charge another customer?: " << std::endl;
        std::cout << " Yes: 1 " << std::endl;
        std::cout << " No: 0 " << std::endl;
        std::cin >> flag;
        std::cout << " " << std::endl;
    }
}
// *** ***

// *** user console ***
    void user_console(Bank& p) {
        int flag = 1;
        while (flag != 0) {
            std::cout << "*** Select an Action: ***" << std::endl;
            std::cout << " 1 - Add new Customer " << std::endl;
            std::cout << " 2 - Display a Customer " << std::endl;
            std::cout << " 3 - Display all Customers " << std::endl;
            std::cout << " 4 - Charge a Withdrawal " << std::endl;
            std::cout << " 5 - Send a Credit " << std::endl;
            std::cout << " 0 - Quit Programm " << std::endl;
            std::cout << "-------------------------" << std::endl;
            std::cin >> flag;
            std::cout << " " << std::endl;
            if (flag == 1) {
                adding_customer(p);
            }
            if (flag == 2) {
                disp_customer(p);
            }
            if (flag == 3) {
                disp_all_customer(p);
            }
            if (flag == 4) {
                charge_money(p);
            }
            if (flag == 5) {
                sending_money(p);
            }
        }
    }
// *** ***