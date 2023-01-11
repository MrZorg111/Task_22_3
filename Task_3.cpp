#include <iostream>
#include <map>
#include <string>

bool check (std::map<char, int>& anagram, std::string& a, std::string& b) {
    for (int i = 0; i < a.length(); i++) {
        if(anagram.count(a[i]) > 0) {
            std::map<char, int> :: iterator it = anagram.find(a[i]);
            it -> second += 1;
        }
        else {
            anagram.insert(std::pair<char, int> (a[i], 1));
        }
    }
    if (!anagram.empty()) {
        for (int i = 0; i < b.length(); i++) {
            std::map<char, int>::iterator it = anagram.find(b[i]);
            if (it->first == b[i]) {
                if (it->second == 1) {
                    anagram.erase(b[i]);
                } else {
                    it->second -= 1;
                }
            }
        }
    }
    else {
        std::cout << "The first word is not set!\n";
    }

    if (anagram.begin() == anagram.end()) {
        return true;
    }
    else {
        return false;
    }
};

int main() {
    std::string word_s, word_f;
    std::map<char, int> anagram;
    std::cout << "Enter the words to check:";
    std::cin >> word_f >> word_s;
    std::cout << check(anagram, word_f, word_s);
    return 0;
}
