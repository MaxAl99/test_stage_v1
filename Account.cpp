#include "Account.h"
#include <memory>

Account::Account(std::string n, double b, int i) : name(n), balance(b), id(i) {};

void adding_customer(Bank& p) {
            int flag = 1;
            while (flag == 1) {
                p.create_customer();
                std::cout << "Do you want another customer?: " << std::endl;
                std::cout << " Yes: 1 " << std::endl;
                std::cout << " Yes: 0 " << std::endl;
                std::cin >> flag;
            }
}

void disp_all_customer(Bank& p) {
    p.display_customers();
}

void disp_customer(Bank& p) {
    int index;
    int flag = 1;
    while (flag == 1) {
        std::cout << "Provide Customer ID to be displayed: " << std::endl;
        std::cin >> index;
        p.display_single_customer(index);
        std::cout << "Do you want to display another customer?: " << std::endl;
        std::cout << " Yes: 1 " << std::endl;
        std::cout << " Yes: 0 " << std::endl;
        std::cin >> flag;
    }
}



// *** calling functions of class member functions ***

void charge_money(Bank& p) {
    int index;
    int flag = 1;
    while (flag == 1) {
        std::cout << "Provide Customer ID to be charged: " << std::endl;
        std::cin >> index;
        p.charge_customer(index);
        std::cout << "Do you want to charge another customer?: " << std::endl;
        std::cout << " Yes: 1 " << std::endl;
        std::cout << " Yes: 0 " << std::endl;
        std::cin >> flag;
    }
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
        std::cout << " Yes: 0 " << std::endl;
        std::cin >> flag;
    }
}

// *** ***

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