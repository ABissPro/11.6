
#include <iostream>



std::string encrypt_caesar(const std::string& text, int shift) {
    std::string result;
    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            result += 'a' + (c - 'a' + shift) % 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            result += 'A' + (c - 'A' + shift) % 26;
        }
        else {
            result += c;
        }
    }
    return result;
}

int main() {
    system("chcp 1251"); // Установить кодировку
    std::string text;
    int shift;
    std::cout << "Введите текст и шаг кодировки:\n";
    std::cin >> text >> shift;
    std::string encrypted = encrypt_caesar(text, shift);
    std::cout << "Зашифрованный текст: " << encrypted << std::endl;
    return 0;
}