//
//  main.cpp
//  grocerApp
//
//  Created corey, Hamilton. on 4/16/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Product {
private:
    string productName;
    int purchasesCount;

public:
    Product() {
        productName = "";
        purchasesCount = 0;
    }

    ~Product() {}

    string getName() {
        return productName;
    }

    void setProductName(string name) {
        productName = name;
    }

    void setNumPurchased(int num) {
        purchasesCount = num;
    }

    int getNumPurchased() {
        return purchasesCount;
    }

    void printProduct() {
        cout << "Product: " << productName << ", Purchases: " << purchasesCount << endl;
    }
};

class PurchasedProducts {
private:
    map<string, int> productsList;

public:
    void recordProducts(ifstream& inFS) {
        ofstream outFS("frequency.dat");
        string productName;

        while (!inFS.eof()) {
            inFS >> productName;

            // Convert the product name to lowercase and add 's' to the end
            productName[0] = toupper(productName[0]);
            for (int i = 1; i < productName.length(); i++) {
                productName[i] = tolower(productName[i]);
            }
            if (productName[productName.length() - 1] != 's') {
                productName += "s";
            }

            // Add the product to the map or increment its count if it already exists
            if (productsList.count(productName) == 0) {
                productsList[productName] = 1;
            } else {
                productsList[productName]++;
            }
        }

        // Write the map to the output file
        for (auto it = productsList.begin(); it != productsList.end(); ++it) {
            outFS << it->first << " " << it->second << endl;
        }
    }

    void printProducts() {
        cout << "Products List:" << endl;
        cout << "-----------------------------" << endl;

        for (auto it = productsList.begin(); it != productsList.end(); ++it) {
            int numSpaces = 20 - ((it->first).length() + to_string(it->second).length() + 1) / 2;
            cout << string(numSpaces, ' ') << it->first << " " << it->second << endl;
        }

        cout << endl;
    }

    void displayHistogram() {
        cout << "Products Histogram:" << endl;
        cout << "-----------------------------" << endl;

        for (auto it = productsList.begin(); it != productsList.end(); ++it) {
            int numSpaces = 20 - ((it->first).length() + to_string(it->second).length() + 1) / 2;
            cout << string(numSpaces, ' ') << it->first << " ";
            for (int i = 0; i < it->second; i++) {
                cout << "*";
            }
            cout << endl;
        }

        cout << endl;
    }

    map<string, int> getAllProducts() {
        return productsList;
    }
};

string modifyName(string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    if (str[str.length() - 1] != 's') {
        str += "s";
    }
    return str;
}

int main() {
    ifstream inFile("CS210_Project_Three_Input_File.txt");
    
}

