#include <stdio.h>
#include "arrayClass.h"
#include <iostream>

using namespace std;

Array::Array(size_t beginSize){
    size = beginSize;
    data = new int[size];
}

Array::~Array(){
    delete[] data;
}

//Function to check if array contains certain integer
int Array::doesItExist(int value) const {
    
    // Interate through array
    for (size_t i = 0; i < size; i++){
        //Check if found, return index if found
        if (data[i] == value){
            return static_cast<int>(i);
        }
    }
    //If not found
    return -1;
}

//Function that can modify array at an index returns old value and new value
pair<int, int> Array::modifyValue(int index, int value){
    
    int oldValue;
    //Check if index is within the array
    if (index >= 0 && index < size){
        
        oldValue = data[index];
        data[index] = value;
        
        //return pair of the old value and new value
        return make_pair(oldValue, value);
    }
    
    
    return make_pair(0, false);
}

//Function that adds new value to end of array
void Array::addToEnd(int value){
    
    //Create pointer to array increasing the size
    int* newData = new int[size + 1];
    
    //Iterate over array adding old array value to new array
    for(size_t i = 0; i < size; i++){
        
        newData[i] = data[i];
    }
    
    //Add value to end of new array
    newData[size] = value;
    
    //Delete old array
    delete[] data;
    
    //Make old array equal new array
    data = newData;
    
    ++size;
}

//Function that replaces index with 0 or removes it
void Array::replaceOrRemove(int index, bool remove){
    
    //Check if value should be removed
    if (remove){
        
        //Remove value
        for(size_t i = index; i < size - 1; i++){
            
            data[i] = data[i + 1];
        }
        --size;
    }
    //Otherwise replace value
    else {
        
        data[index] = 0;
    }
}

//Function that accesses the index of an array
int& Array::operator[](size_t index){
    
    if(index >= size){
        throw out_of_range
        ("index to operator[] is out of range");
        
    }
    return data[index];
}


//Function that returns the size of array
size_t Array::getSize() const {
    return size;
}
