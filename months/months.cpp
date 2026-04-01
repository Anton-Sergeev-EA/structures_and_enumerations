#include <iostream>
#include <limits>
#include <array>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

enum class Month : int {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

[[nodiscard]] std::string_view getMonthName(Month month) {
    static const std::array<std::string_view, 12> monthNames = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };
    
    int index = static_cast<int>(month) - 1;
    return monthNames[index];
}

[[nodiscard]] int getSafeNumberInput() {
    int number;
    std::cin >> number;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    
    std::cout << "Программа 'Месяцы' от Сергеева Антона!" << std::endl;
    std::cout << "Введите номер месяца (1-12) или 0 для выхода." << std::endl;
    
    while (true) {
        std::cout << "Введите номер месяца: ";
        
        int userInput = getSafeNumberInput();
        
        if (userInput == 0) {
            std::cout << "До свидания!" << std::endl;
            break;
        }
        
        if (userInput >= static_cast<int>(Month::January) && 
            userInput <= static_cast<int>(Month::December)) {
            
            Month month = static_cast<Month>(userInput);
            std::cout << getMonthName(month) << std::endl;
        } else {
            std::cout << "Неправильный номер!" << std::endl;
        }
    }
    
    return 0;
}
