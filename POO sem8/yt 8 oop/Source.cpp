#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

class Compare {
public:
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};

int main() {
    string myString;
    ifstream myFile("input.txt");
    if (!myFile) {
        printf("error la deschiderea fisierului: input.txt");
        return 0;
    }
    // citim prima linie din fisier
    if (!getline(myFile, myString)) {
        printf("error la citirea din fisier: input.txt");
        return 0;
    }
    map<string, int> myMap;
    printf("Sirul de caractere citit este: %s\n", myString.c_str());

    char* word = strtok(const_cast<char*>(myString.c_str()), " ,.:!?;");
    while (word != NULL) {
        string str(word);
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
        if (myMap.count(str) != 0) {
            myMap[str] += 1;
        }
        else {
            myMap[str] = 1;
        }
        word = strtok(NULL, " ,.:!?;");
    }

    for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        printf("%s : %d \n", mapIterator->first.c_str(), mapIterator->second);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
    for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        myQueue.push(make_pair(mapIterator->first, mapIterator->second));
    }

    printf("\n\nSortate\n");
    // Golim coada
    while (!myQueue.empty()) {
        printf("%s => %d\n", myQueue.top().first.c_str(), myQueue.top().second);
        myQueue.pop();
    }
    return 0;
}