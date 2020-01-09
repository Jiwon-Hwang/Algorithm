def factorial(n):
    if(n==1):
        return 1
    else:
        return n*factorial(n-1)

N=int(input("n을 입력하세요 : ")) # ***파이썬에서는 input()받은 값을 문자열로 인식ㅠㅠ
                                 #int(input()) 이렇게 int로 감싸주지 않으면 계산시 문제가 생김! (ex. + 연산시에는 그냥 문자열로 취급해서 이어서 1+2 = 12로 입력해버림)

print(factorial(N))

#print(factorial(5))