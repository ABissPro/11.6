#include <iostream>
#include <string>

//извлечение одного октета
std::string get_octet(const std::string& ip, int octet_num) {
    int startOct = 0;
    int dotСount = 0;

    for (int i = 0; i < ip.length(); ++i) {
        if (ip[i] == '.') {
            if (dotСount == octet_num) {
                return ip.substr(startOct, i - startOct); //метод для подстроки
            }
            startOct = i + 1;
            ++dotСount;
        }
    }

    //возврат последнег октета
    return ip.substr(startOct); //возвращает подстроку строки с индекса startOct
}

//проверка октета
bool is_valid_octet(const std::string& octet) {
    if (octet.empty() || octet.length() > 3) {
        return false;
    }

    //проверка ведущего 0
    if (octet.length() > 1 && octet[0] == '0') {
        return false;
    }

    //проверка на цифры
    for (char c : octet) {
        if (c < '0' || c > '9') {
            return false;
        }
    }

    
    int value = stoi(octet); //преобразование строки в целое число
    return value >= 0 && value <= 255;
}

//полная проверка
void check_ip(std::string ip) {
    //длина строки
    if (ip.length() > 15) {
        std::cout << "Длина строки превышает 15 символов\n";
        return;
    }

    //проверка правильности каждого октета
    for (int i = 0; i < 4; ++i) {
        std::string octet = get_octet(ip, i);
        if (!is_valid_octet(octet)) {
            std::cout << "Невалидный октет\n";
            return;
        }
    }


    std::cout << "Valid\n";
}

int main() {
    system("chcp 1251"); // Установить кодировку
    std::string ip;
    std::cout << "Введите IP-адрес:\n";
    std::cin >> ip;
    check_ip(ip);
}
