# 이진탐색 : sorted array(지금은 오름차순)에서 찾고자 하는 값의 index 찾기

s=[10, 12, 13, 14, 18, 20, 25, 27, 30, 35, 40, 45, 47]

x=int(input("찾고 싶은 키값을 입력하세요 : "))  # x는 내가 찾고 싶은 키 값 ==> ***파이썬에서는 input()만 하면 문자열로 인식하므로, int(input())으로 꼭!!! 해야함!!***

def binarySearch_recursion(low, high):  # 찾을 키값이 위치하는 곳의 인덱스 반환해주는 함수
    while(low<=high):  # 종료 조건. low=high 같을 때까지는 반복문 가능! 만약 ex) 파라미터가 low=0, high=mid-1=-1이 들어오면 low>high이므로 종료~!!!(더이상 비교할게 없다는 뜻.)
        mid=int((low+high)/2)  # 파이썬 최신 버전에서는 10/3하면 3.3333 이렇게 소수점까지 나옴(int말고 float형으로 나옴ㅠㅠ) ==> 따라서 int(10/3) 이런식으로 감싸줘야댐..(버림 시)
        if (x==s[mid]):
            return mid

        elif (x < s[mid]):  # 파이썬은 else if 가 아니라 elif
            return binarySearch_recursion(low, mid-1)  # 앞부분 탐색

        else : 
            return binarySearch_recursion(mid+1, high) # 뒷부분 탐색
    return 0

print(binarySearch_recursion(0, len(s)-1))  # 초기값 : low = 0, high = len(s)-1 = 13-1 = 12 (배열의 맨 마지막 값의 index가 len보다 1 작음)