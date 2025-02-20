
#include <iostream>
#include <string>

bool isValidFirstPart(const std::string& firstPart) { //проверка первой части
    if (firstPart.empty() || firstPart.length() > 64 || firstPart[0] == '.') {
        return false;
    }

    std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_`{|}~.-";

    for (char c : firstPart) {
        if (validChars.find(c) == std::string::npos) {
            return false;
        }
        if (c == '.' && (firstPart.front() == '.' || firstPart.back() == '.' 
            || firstPart.find("..") != std::string::npos)) {
            return false;
        }
    }

    return true;
}

bool isValidSecondPart(const std::string& secondPart) { //проверка второй части
    if (secondPart.empty() || secondPart.length() > 63) {
        return false;
    }

    std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";

    for (char c : secondPart) {
        if (validChars.find(c) == std::string::npos) {
            return false;
        }
        if (c == '.' && (secondPart.front() == '.' || secondPart.back() == '.' 
            || secondPart.find("..") != std::string::npos)) {
            return false;
        }
    }

    return true;
}

//разделение на две части
void splitEmail(const std::string& email, std::string& firstPart, std::string& secondPart) {
    size_t atPos = email.find('@');
    if (atPos == std::string::npos) {
        firstPart = email;
        secondPart = "";
    }
    else {
        firstPart = email.substr(0, atPos);
        secondPart = email.substr(atPos + 1);
    }
}

bool isValidEmail(const std::string& email) { //основная проврка
    std::string firstPart, secondPart;
    splitEmail(email, firstPart, secondPart);

    return isValidFirstPart(firstPart) && isValidSecondPart(secondPart);
}

int main() {
    std::string email;
    std::cout << "Input email: ";
    std::getline(std::cin, email);

    if (isValidEmail(email)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

}
   
