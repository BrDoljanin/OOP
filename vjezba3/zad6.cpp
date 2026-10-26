#include<iostream>
#include<vector>
#include<string>

std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> rici;
    size_t i = 0;
    
    while (i < text.length()) {
        
        while (i < text.length() && text[i] == ' ') {
            i++;
        }
        if (i >= text.length()) break;
        
        
        size_t j = text.find(' ', i);
        if (j == std::string::npos) {
            rici.push_back(text.substr(i));
            break;
        } else {
            
            rici.push_back(text.substr(i, j - i));
            i = j;
        }
    }
    return rici;
}

int main() {
    std::string rec;
    std::getline(std::cin, rec);
    std::vector<std::string> ric = split_words(rec);

    std::string najdulja = ric[0];
    for (int i = 0; i < ric.size(); i++) {
        if (ric[i].length() > najdulja.length()) {
            najdulja = ric[i];
        }
    }
    std::cout << "broj rici: " << ric.size() << "\n";
    std::cout << "najdulja: " << najdulja << "\n";

    std::string obrni = "";
    for (int i = (int)ric.size() - 1; i >= 0; --i) {
        obrni += ric[i];
        if (i > 0) {
            obrni += "-";
        }
    }
    std::cout << obrni << "\n";

    std::string prva_abeceda = ric[0];
    for (const auto& r : ric) {
        if (r < prva_abeceda) {
            prva_abeceda = r;
        }
    }
    std::cout << "prva po abecedi: " << prva_abeceda << "\n";

    return 0;
}