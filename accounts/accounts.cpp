#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

struct BankAccount {
    int accountNumber;
    std::string ownerName;
    double balance;
};

[[nodiscard]] int getSafeIntInput() {
    int number;
    while (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите целое число: ";
    }
    return number;
}

[[nodiscard]] double getSafeDoubleInput() {
    double number;
    while (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите число: ";
    }
    return number;
}

[[nodiscard]] std::string getStringInput() {
    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    return input;
}

void updateBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

void printAccountInfo(const BankAccount& account) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Ваш счёт: " << account.ownerName << ", "
              << account.accountNumber << ", "
              << std::fixed << std::setprecision(2) 
              << account.balance << " руб." << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    // Настройка кодировки для Windows
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
    
    BankAccount account;
    
    std::cout << "Программа 'Банковский счёт'" << std::endl;
    std::cout << "Пожалуйста, введите данные счёта:" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    std::cout << "Введите номер счёта: ";
    account.accountNumber = getSafeIntInput();
    
    std::cout << "Введите имя владельца: ";
    account.ownerName = getStringInput();
    
    std::cout << "Введите баланс: ";
    account.balance = getSafeDoubleInput();
    
    std::cout << "Введите новый баланс: ";
    double newBalance = getSafeDoubleInput();
    
    updateBalance(account, newBalance);
    
    printAccountInfo(account);
    
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    
    return 0;
}
