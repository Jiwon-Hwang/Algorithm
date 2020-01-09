def merge_sort(arr):
    if len(arr)>1:
        mid = len(arr)//2
        left = arr[:mid]
        right = arr[mid:]

        l = merge_sort(left)
        r = merge_sort(right)
        return merge(l, r)
    else:
        return arr
        
def merge(left, right):
    i = 0
    j = 0
    arr = []
    
    while (i<len(left)) & (j<len(right)):
        if left[i] < right[j]:
            arr.append(left[i])
            i+=1
        else:
            arr.append(right[j])
            j+=1
    
    while (i<len(left)):
        arr.append(left[i])
        i+=1
    
    while (j<len(right)):
        arr.append(right[j])
        j+=1
        
    return arr


arr = [3, 5, 1, 2, 9, 6, 4, 5, 7]
print(merge_sort(arr))