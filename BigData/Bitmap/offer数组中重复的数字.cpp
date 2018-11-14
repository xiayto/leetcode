#include<vector>
class BitMap {
public:
    BitMap(int num):n(num),mask(31),shift(5),pos(1<<mask),a(1+n/32,0){}
    void set(int i) {
        a[i>>shift] |= (pos>>(i & mask));
    }
    int get(int i) {
        return a[i>>shift] & (pos>>(i & mask));
    }
    void clr(int i) {
        a[i>>shift] &= ~(pos>>(i & mask));     
    }   
private:
    int n;
    const int mask;
    const int shift;
    const unsigned int pos;
    vector<unsigned int> a;
};

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int cnt = 0;
        if(numbers == nullptr || length == 0)
            return false;
        BitMap bitMap(length);
        for(int i = 0; i < length; i++){
            if(bitMap.get(numbers[i])){
                duplication[cnt++] = numbers[i];
                return true;
            }
            else{
                bitMap.set(numbers[i]);
            }
        }
        return false;
        
    }
};
