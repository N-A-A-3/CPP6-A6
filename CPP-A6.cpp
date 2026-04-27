#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num) {
    int i;
    if (num < 2) {
        return false;
    }
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes() {
    ifstream myFile;
    int num, count;

    count = 0;
    myFile.open("NUMS.TXT");

    if (!myFile.is_open()) {
        cout << "Cannot open file." << endl;
        return 0;
    }

    while (myFile >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    myFile.close();
    return count;
}

int main() {
    int result;
    result = countPrimes();
    cout << "Number of prime numbers: " << result << endl;
    return 0;
}