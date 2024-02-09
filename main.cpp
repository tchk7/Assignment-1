#include <iostream>
#include <fstream>
#include "arrayClass.h"
#include "arrayClass.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //Create path to input file
    const char* file = "A1input.txt";
    // Create input variable
    ifstream input;
    //Get file
    input.open(file);
    int number;
    //Initialize array
    Array array(0);
    //CHeck if file is open
    if (!input.is_open()){
        throw runtime_error("File not open");
    }
    //Prime first input number
    input >> number;
    //Add first number to array
    array.addToEnd(number);
    //Add rest of input file to array
    while (!input.eof()) {
        
        input >> number;
        array.addToEnd(number);
    }
    
    //Try user input to modify index
    try {
        int num;
        int newValue;
        //Get user input
        cout << "Which index do you want to modify? ";
        cin >> num;
        
        //If index is negative throw error
        if (num < 0){
            throw range_error("Negatve index does not exist");
        }
        //If index is greater than array size
        else if (num > array.getSize()){
            throw range_error("Out of range");
        }
        //Else code can continue
        else {
            cout << "What is the new value: ";
            cin >> newValue;
            cout << endl;
            pair<int, int> modify = array.modifyValue(num, newValue);
            cout << "Old value: " << modify.first << ". New value: " << modify.second << "." << endl;
        }
        //Catch the error and abort
    } catch (const exception& e) {
        cerr << "Cannot proceed: " << e.what() << endl;
        abort();
    }
    
    //Try to add number to array
    try {
        int add;
        //Get user input
        cout << "What num would you like to add: ";
        cin >> add;
        //If input not a number throw error
        if(!cin){
            throw runtime_error("Not a number");
        }
        //Else code can continue
        else {
            array.addToEnd(add);
        }
        //Cath the error and abort
    } catch (const exception& e) {
        cerr << "Cannot proceed: " << e.what() << endl;
        abort();
    }
    
    return 0;
}
