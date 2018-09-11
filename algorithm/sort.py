# 冒泡排序
# 时间复杂度：O(N^2)
# 空间复杂度：O(1)
def bubbleSort(aList, mode):
    res_list = aList.copy()
    for i in range(len(res_list)):
        for j in range(len(res_list)-i-1):
            if mode == "des":
                if res_list[j] < res_list[j+1]:
                    res_list[j], res_list[j+1] = res_list[j+1], res_list[j]
            if mode == "asc":
                if res_list[j] > res_list[j+1]:
                    res_list[j], res_list[j+1] = res_list[j+1], res_list[j]
    return res_list
#------------------------------------------------------    
# 插入排序
# 时间复杂度：O(N^2)
# 空间复杂度：O(1)
def insertSort(aList, mode):
    res_list = aList.copy()
    for i in range(len(res_list)):
        tmp = res_list[i]
        for j in range(i):
            if mode == "des":
                if res_list[j] < res_list[i]:
                    for k in range(i, j, -1):
                        res_list[k] = res_list[k-1]
                    res_list[j] = tmp
            if mode == "asc":
                if res_list[j] > res_list[i]:
                    for k in range(i, j, -1):
                        res_list[k] = res_list[k-1]
                    res_list[j] = tmp
    
    return res_list
#------------------------------------------------------    
# 快速排序
# 时间复杂度：O(NlogN)
# 空间复杂度：O(NlogN)
def partition(aList, begin, end):
    x = aList[end]
    j = begin-1
    for i in range(begin, end):
        if aList[i] <= x:
            j += 1
            aList[i], aList[j] = aList[j], aList[i]
    aList[j+1], aList[end] = aList[end], aList[j+1]
    return i+1

def quickSort(aList):
    res_list = aList.copy()
    
    def quickSort_(tmp_list, begin, end):
        if begin < end:
            mid = partition(tmp_list, begin, end)
            quickSort_(tmp_list, begin, mid - 1)
            quickSort_(tmp_list, mid+1, end)
    
    quickSort_(res_list, 0, len(res_list)-1)
    return res_list
#------------------------------------------------------
# 选择排序
# 时间复杂度：O(N^2)
# 空间复杂度：O(1)
def selectSort(aList, mode):
    res_list = aList.copy()
    if mode == "asc":
        for i in range(len(aList)):
            top = i
            for j in range(i+1, len(res_list)):
                if res_list[j] < res_list[top]:
                    top = j
            res_list[i], res_list[top] = res_list[top], res_list[i]
    else:
        for i in range(len(aList)):
            top = i
            for j in range(i+1, len(res_list)):
                if res_list[j] > res_list[top]:
                    top = j
            res_list[i], res_list[top] = res_list[top], res_list[i]
    return res_list
#------------------------------------------------------
# 归并排序
# 时间复杂度：O(NlogN)
# 空间复杂度：O(N)
def merge(light, right):
    l, r = 0, 0
    res = []
    while l < len(light) and r < len(right):
        if light[l] > right[r]:
            res.append(right[r])
            r += 1
        else:
            res.append(light[l])
            l += 1
    res += light[l:]
    res += right[r:]
    return res
        
def mergeSort(res_list):
    if len(res_list) <= 1:
        return res_list
    mid = int(len(res_list) / 2)
    light = mergeSort(res_list[0:mid])
    right = mergeSort(res_list[mid:])
    return merge(light, right)

#------------------------------------------------------

# 堆排序
# 时间复杂度：O(nlogn)
# 空间复杂度：O(1)
def adjust_heap(aList, i, size):
    lchild = i * 2 + 1
    rchild = i * 2 + 2
    max_ = i
    if i < size / 2:
        if lchild < size and aList[lchild] > aList[max_]:
            max_ = lchild
        if rchild < size and aList[rchild] > aList[max_]:
            max_ = rchild
        if max_ != i:
            aList[max_], aList[i] = aList[i], aList[max_]
            adjust_heap(aList, max_, size)
                
def build_heap(aList, size):
    for i in range(int(size/2), -1, -1):
        adjust_heap(aList, i, size)

def heap_sort(aList, mode):
    size = len(aList)
    res_list = aList.copy()
    build_heap(res_list, size)
    if mode == 'asc':
        for i in range(size-1, -1, -1):
            res_list[i], res_list[0] = res_list[0], res_list[i]
            adjust_heap(res_list, 0, i)
    if mode == 'des':
        for i in range(size-1, -1, -1):
            res_list[i], res_list[0] = res_list[0], res_list[i]
            adjust_heap(res_list, 0, i)
        res_list.reverse()
    return res_list
