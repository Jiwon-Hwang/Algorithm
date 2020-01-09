s=[10, 12, 13, 14, 18, 20, 25, 27, 30, 35, 40, 45, 47]

x=int(input("찾고 싶은 키값을 입력하세요 : "))  

def binarySearch_recursion(low, high):  
    if(low>high):   
        return 0
    else:       
        mid=int((low+high)/2) 
        if (x==s[mid]):
            return mid

        elif (x < s[mid]):  
            return binarySearch_recursion(low, mid-1)

        else : 
            return binarySearch_recursion(mid+1, high)

print(binarySearch_recursion(0, len(s)-1))  