#include <iostream>
#include <string>
using namespace std;

void getNext(char *needle, int next[])
{// self match to contruct next array
    int nlen = strlen(needle);
    int j = -1;     // slow pointer
    int i = 0;      // fast pointer
    next[i] = -1;    //init next has one element
    while(i < nlen-1)
    {
        if(j == -1 || needle[i] == needle[j])
        {
            j ++;
            i ++;           //thus the condition (i < nlen-1)
            next[i] = j;    //if position i not match, jump to position j
        }
        else
        {
            j = next[j];    //jump to the previous position to try matching
        }
    }
}

int strStr(char *haystack, char *needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    int* next = new int[nlen];
    getNext(needle, next);
    int i = 0;
    int j = 0;
    while(i < hlen && j < nlen)
    {
        if(j == -1 || haystack[i] == needle[j])
        {// match current position, go next
            i ++;
            j ++;
        }
        else
        {// jump to the previous position to try matching
            j = next[j];
        }
    }
    if(j == nlen)
        // all match
        return i-nlen;
    else
        return -1;
}

int main(){
    char a[] = "hello";
    char b[] = "ll";
    cout<<strStr(a, b)<<endl;
}
