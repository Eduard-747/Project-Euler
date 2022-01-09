// Using problem22.txt , a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order.
// Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
// For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
// So, COLIN would obtain a score of 938 × 53 = 49714.
// What is the total of all the name scores in the file?

  
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string &s, char divider) 
{
    std::vector<std::string> elems;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, divider)) 
    {
        elems.push_back(item);
    }
    return elems;
}

unsigned long int nameValue(const std::string &s) 
{
    unsigned long int value = 0;
    for (char c : s) {
        if (c != '\"') {
            value += c - 64;
        }
    }
    return value;
}

int main() 
{

    std::ifstream input("problem22.txt");
    std::vector<std::string> names;
    std::string namesString;
    std::getline(input, namesString);
    input.close();

    names = split(namesString, ',');
    std::sort(names.begin(), names.end());

    unsigned long long int sum = 0;
    for (int i = 0; i < names.size(); ++i) {
        sum += nameValue(names[i]) * (i + 1);
    }

    std::cout << sum << std::endl;

    return 0;
}