# 在python中用数组实现bitmap

class Bitmap():
    def __init__(self, maxNum):
        '确定需要多少个int的数组，一个int32位可以存储32个整数'
        self.size = int((maxNum + 32) >> 5)
        self.array = [0 for i in range(self.size)]
    
    def bitIndex(self, num):
        '确定数字在数组中的位置'
        return num % 32
    
    def setNum(self, num):
        arrayIndex = num >> 5
        byteIndex = num % 32
        self.array[arrayIndex] = ((1 << byteIndex) | self.array[arrayIndex])
    
    def getNum(self, num):
        arrayIndex = num >> 5
        byteIndex = num % 32
        if self.array[arrayIndex] & (1 << byteIndex):
            return True
        else:
            return False
