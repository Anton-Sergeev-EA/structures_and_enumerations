#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

struct Address {
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
    int postalCode;
    
    Address(const std::string& c, const std::string& s, int house, int apt, int code)
        : city(c), street(s), houseNumber(house), apartmentNumber(apt), postalCode(code) {}
};

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
    
    Address addr1("Москва", "Арбат", 12, 8, 123456);
    Address addr2("Ижевск", "Пушкина", 59, 143, 953769);
    Address addr3("Санкт-Петербург", "Невский проспект", 28, 15, 191186);
    
    std::vector<Address> addresses = {addr1, addr2, addr3};
    
    std::cout << "Адресация" << std::endl;
    std::cout << std::endl;
    
    for (size_t i = 0; i < addresses.size(); ++i) {
        std::cout << "Адрес #" << (i + 1) << ":" << std::endl;
        std::cout << "Город: " << addresses[i].city << std::endl;
        std::cout << "Улица: " << addresses[i].street << std::endl;
        std::cout << "Номер дома: " << addresses[i].houseNumber << std::endl;
        std::cout << "Номер квартиры: " << addresses[i].apartmentNumber << std::endl;
        std::cout << "Индекс: " << addresses[i].postalCode << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}
