#include <iostream>
#include <map>
#include <string>
bool check (std::map<std::string, std::string>& a) {
    std::map<std::string, std::string>::iterator it = a.begin();
    std::string tempo_f = it -> first, tempo_s = it -> second;
    int len_f = tempo_f.length(), len_s = tempo_s.length();
    if (len_f == len_s) {
        for (int i = 0; i < len_f; i++) {
            for (int j = 0; j < len_s; j++) {
                if (tempo_f[i] == tempo_s[j]) {
                    tempo_s[j] = (char) '0';
                    break;
                }
                else if (j == (len_s - 1)) {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        return false;
    }

}
int main() {
    std::string f_word, s_word;
    std::map<std::string, std::string> anagram;
    std::cout << "Enter the words to check: ";
    std::cin >> f_word >> s_word;
    anagram.insert(std::pair<std::string, std::string> (f_word, s_word));
    std::cout << check (anagram);

    return 0;
}
