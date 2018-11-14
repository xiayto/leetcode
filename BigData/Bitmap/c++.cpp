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
