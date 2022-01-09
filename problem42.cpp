// The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
// By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
// For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
// Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

int getWordValue(std::string word)
{
    int wordValue = 0;
    for (char c : word) {
        wordValue += c - 64;
    }
    return wordValue;
}

bool isTriangleWord(std::string word)
{
    int n = getWordValue(word);
    int x = std::sqrt(2 * n);
    return x * (x + 1) / 2 == n;
}

int main()
{
    std::string words;
    std::ifstream input("problem42.txt");
    std::getline(input, words);
    input.close();
    std::stringstream ss;
    ss.str(words);
    std::string word;
    int numTriangleWords = 0;
    while (std::getline(ss, word, ',')) 
    {
        numTriangleWords += isTriangleWord(std::string(word, 1, word.length() - 2));
    }
    std::cout << numTriangleWords << std::endl;

    return 0;
}