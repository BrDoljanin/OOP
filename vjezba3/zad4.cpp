#include<iostream>
#include<string>

bool split_email(const std::string& email, std::string& user, std::string& domain) {
    size_t prva = email.find('@');

    size_t zadnja = email.rfind('@');

    if (prva == std::string::npos || prva != zadnja) {

        return false;

    }

    if (prva == 0 || prva == email.length() - 1) {

        return false;

    }

    user = email.substr(0, prva);

    domain = email.substr(prva + 1);

    if (domain.find('.') == std::string::npos) {

        return false;

    }

    return true;

}

int main() {
    std::string email;

    std::cout << "Unesite e-mail adresu: ";
    
    if (std::getline(std::cin, email)) {

        std::string user, domain;
        
        if (split_email(email, user, domain)) {
            std::cout << "korisnik: " << user << ", domena: " << domain << '\n';
        } else {
            std::cout << "neispravna adresa\n";
        }
    }

    return 0;
}