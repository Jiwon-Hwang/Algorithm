# 분할정복을 이용한 1 ~ n 까지의 합 구하기 (재귀 이용)

def f(n):  # n: 사용자가 입력한, 몇까지 더할지.. 더할 마지막 수 (ex. n=8)
    
    if (n>1):
        return f(n/2)*2 + (n**2)/4
    else:  # 초기값 (f(n=1)=1) 주기
        return 1
    
    # return 1 (걍 이렇게 else 대신 함수 f의 return 값으로 1 줘도 똑같음)


n=int(input("n을 입력하세요 : "))      # input : n
print(int(f(n)))                      # output : f(n) (1 부터 n 까지의 합)


#main()