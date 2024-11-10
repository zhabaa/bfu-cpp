#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>
#include <ranges>

using namespace std;

string cleanWord(const string &word) {
    string result;

    for (char c : word) {
        if (isalpha(c)) {
            result += tolower(c);
        }
    }

    return result;
}

vector<string> readFile(const string &input_path) {
    vector<string> words;
    ifstream input_file(input_path);

    if (!input_file.is_open()) {
        cout << "Cannot read file" << endl;
        return words;
    }

    string word;

    while (input_file >> word) { // Читаем по словам, разделяя по пробелам
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            words.push_back(cleanedWord);
        }
    }

    input_file.close();

    cout << "File read successfully" << endl;

    return words;
}

void writeFile(const string &output_path, const vector<string> &result_words) {
    ofstream output(output_path);

    if (!output) cout << "Cannot open file" << endl;

    for (const string &word : result_words) {
        output << word << endl;
    }

    output.close();
    cout << "File writed successfully!" << endl;
}

bool isSimilarWord(const string& mainWord, const string& testWord) {
    const int ALPHABET_SIZE = 26;

    vector<int> mainCount(ALPHABET_SIZE, 0);
    vector<int> testCount(ALPHABET_SIZE, 0);

    for (char c : mainWord) {
        mainCount[c - 'a']++;
    }

    for (char c : testWord) {
        testCount[c - 'a']++;
    }

    bool extraFound = false;

    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
        if ((testCount[i] && !mainCount[i]) || (!testCount[i] && mainCount[i])) {
            if (extraFound) {
                return false;
            }
            extraFound = true;
        }
    }

    return extraFound;
}

bool compareLenght(const string &a, const string &b) {
    return a.size() > b.size();
}

// bool comparator(char a, char b) {
//     return strcmp(a, b);
// }

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(string &word) {
    int count = 0;
    for (auto ch : word) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}

int first() {
    string input_path = "D:\\bfu-cpp\\lab8\\files\\input.txt";
    string output_path = "D:\\bfu-cpp\\lab8\\files\\output.txt";

    string given_word = "the";

    vector<string> words = readFile(input_path);

    set<string> set_words(words.begin(), words.end());
    vector<string> different_words;

    for (const string &word : set_words) {
        if (isSimilarWord(given_word, word) && !word.empty()) {
            different_words.push_back(word);
        }
    }

    sort(different_words.begin(), different_words.end(), compareLenght);

    writeFile(output_path, different_words);

    return 0;
}

int second() {
    string input_path = "D:\\bfu-cpp\\lab8\\files\\input.txt";

    vector<string> words = readFile(input_path);

    vector<string> words_3vowels;
    vector<string> other_words;

    for (string &word : words) {
        if (countVowels(word) >= 3) {
            words_3vowels.push_back(word);
        } else {
            other_words.push_back(word);
        }
    }

    sort(words_3vowels.rbegin(), words_3vowels.rend());
    vector<string> result;

    for (string word : other_words) {
        string temp;
    
        for (char letter : word) {
            if (!isVowel(letter)) {
                temp += letter;
                temp += letter;
            }
        }
        if (!temp.empty()) {
            result.push_back(temp);
        }
    }

    // set<string> set_first(words_3vowels.begin(), words_3vowels.end());
    // set<string> set_second(other_words.begin(), other_words.end());


    cout << "Words of text containing 3 vowels" << endl;

    for (string word : words_3vowels) {
        cout << word << endl;
    }

    cout << endl << "Other words there are no vowels and duplicated consonants: " << endl;

    for (string word : result) {
        cout << word << endl;
    }

    return 0;

}

int main() {
    second();
    return 0;
}
