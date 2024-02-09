#ifndef arrayClass_h
#define arrayClass_h



class Array{
    
private:
    //Pointer to array
    int* data;
    
    //Number of elements in array
    size_t size;
    
    //Current capacity of array
    size_t currentCapacity;
    
//    //Function that gets the beginning capacity of the array
//    static const size_t initialCapacity = 10;
    
public:
    //Constructor for array
    Array(size_t beginSize);
    
    //Destructor for array
    ~Array();
    
    //Function to check if array contains certain integer
    int doesItExist(int value) const;
    
    //Function that can modify array at an index returns old value and new value
    std::pair<int, int> modifyValue(int index, int value);
    
    //Function that adds new value to end of array
    void addToEnd(int value);
    
    //Function that replaces index with 0 or removes it
    void replaceOrRemove(int index, bool remove = false);
    
    //Function that accesses array at given index
    int& operator[](size_t index);
    
    //Function that returns size of array
    size_t getSize() const;
    
    
    
};

#endif /* arrayClass_h */
