# 분할정복을 이용한 1 ~ n 까지의 합 구하기 (재귀 이용)
# 이게 더 고수의 코드^_^

def f(n):  
    
    if(n==1):   # 초기값 (f(n=1)=1) 주기
        return 1  

    return f(n/2)*2 + (n**2)/4
    

def main():
    n=int(input("n을 입력하세요 : "))      # input : n
    return int(f(n))                      # output : f(n) (1 부터 n 까지의 합)


print(main())