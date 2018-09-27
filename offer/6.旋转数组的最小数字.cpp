class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //用二分查找非方法
        //注意两个边界情况，一个是没有旋转，旋转数量是0，一个是begin==end==mid只能用顺序查找
        int length = rotateArray.size();
        if(length == 0) return NULL;
        int begin = 0, end = length - 1, mid;
        if (rotateArray[begin] < rotateArray[end])
            return rotateArray[0]; //旋转数量为0
        while(end - begin > 1){
            mid = (begin + end) / 2;
            if(rotateArray[begin] == rotateArray[end] 
               && rotateArray[begin] == rotateArray[mid]){
                return findMinNumber(rotateArray, begin, end);
            }
            if(rotateArray[begin] <= rotateArray[mid])
                begin = mid;
            else if(rotateArray[mid] <= rotateArray[end])
                end = mid;
        }
        return rotateArray[end];
    
    }
    int findMinNumber(vector<int> rotateArray, int begin, int end){
        int minNumber = rotateArray[begin];
        for(int i = begin; i <= end; i++){
            if(rotateArray[i] < minNumber)
                minNumber = rotateArray[i];
        }
        return minNumber;
    }
};
