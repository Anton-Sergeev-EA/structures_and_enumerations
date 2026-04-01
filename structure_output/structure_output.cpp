#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

struct Адрес {
    std::string город;
    std::string улица;
    int номерДома;
    int номерКвартиры;
    int почтовыйИндекс;
    
    Адрес(const std::string& г, const std::string& у, int дом, int кв, int индекс)
        : город(г), улица(у), номерДома(дом), номерКвартиры(кв), почтовыйИндекс(индекс) {}
    
    void вывести() const {
        std::cout << "Город: " << город << std::endl;
        std::cout << "Улица: " << улица << std::endl;
        std::cout << "Номер дома: " << номерДома << std::endl;
        std::cout << "Номер квартиры: " << номерКвартиры << std::endl;
        std::cout << "Индекс: " << почтовыйИндекс << std::endl;
        std::cout << std::endl;
    }
    
    std::string получитьПолныйАдрес() const {
        return город + ", ул. " + улица + ", д. " + std::to_string(номерДома) +
               ", кв. " + std::to_string(номерКвартиры) + ", " + std::to_string(почтовыйИндекс);
    }
};

void вывестиАдрес(const Адрес& адрес) {
    std::cout << "Город: " << адрес.город << std::endl;
    std::cout << "Улица: " << адрес.улица << std::endl;
    std::cout << "Номер дома: " << адрес.номерДома << std::endl;
    std::cout << "Номер квартиры: " << адрес.номерКвартиры << std::endl;
    std::cout << "Индекс: " << адрес.почтовыйИндекс << std::endl;
    std::cout << std::endl;
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
    
    std::cout << "========== Программа 'Вывод структуры' ==========" << std::endl;
    std::cout << std::endl;
    
    Адрес адрес1("Москва", "Арбат", 12, 8, 123456);
    Адрес адрес2("Ижевск", "Пушкина", 59, 143, 953769);
    Адрес адрес3("Санкт-Петербург", "Невский проспект", 28, 15, 191186);
    
    std::vector<Адрес> адреса = {адрес1, адрес2, адрес3};
    
    std::cout << "Вывод адресов с помощью отдельной функции:" << std::endl;
    std::cout << std::endl;
    
    for (size_t i = 0; i < адреса.size(); ++i) {
        std::cout << "Адрес #" << (i + 1) << ":" << std::endl;
        вывестиАдрес(адреса[i]);
    }
    
    std::cout << "Вывод адресов с помощью метода структуры:" << std::endl;
    std::cout << std::endl;
    
    for (size_t i = 0; i < адреса.size(); ++i) {
        std::cout << "Адрес #" << (i + 1) << ":" << std::endl;
        адреса[i].вывести();
    }
    
    std::cout << "Полные адреса одной строкой:" << std::endl;
    std::cout << std::endl;
    
    for (const auto& адрес : адреса) {
        std::cout << адрес.получитьПолныйАдрес() << std::endl;
    }
    
    return 0;
}
