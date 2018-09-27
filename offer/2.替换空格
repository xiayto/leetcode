# 从后往前替换，不需要退位

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL || length <= 0)
            return;
        int numberOfBlank = 0;
        int originalLength = 0;
        for(int i = 0; str[i] != '\0'; i++){
            originalLength++;
            if(str[i] == ' ')
                numberOfBlank++;
        }
        int newLength = numberOfBlank * 2 + originalLength;
        str[newLength] = '\0';
        int oldIndex = originalLength;
        int newIndex = newLength;
        while(oldIndex >= 0 && oldIndex < newIndex){
            if(str[oldIndex] == ' '){
                str[newIndex --] = '0';
                str[newIndex --] = '2';
                str[newIndex --] = '%';
            }
            else
                str[newIndex --] = str[oldIndex];
            oldIndex --;
        }
	}
};
