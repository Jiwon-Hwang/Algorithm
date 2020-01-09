# s=list(map(int, input('배열에 넣을 값들을 입력하세요 : ').split()))
# split()함수에 아무런 인자를 주지 않으면 디폴트 : space 기준으로 자름
# 근데 여기서 input()의 리턴값은 각각 문자열!! => 따라서 int형으로 변환?! map() 함수!
# *** map(func, x) *** 의 형태로 사용을 하는 방식으로, 
# 리스트 같은 x의 각 요소에 func을 적용시켜 주는 함수.
# s=list(map(int, input().split())) 형태로 써주면 됨~ (map의 원래 리턴값은 객체이므로, 배열로 변환해줘야함)

# 두번째 방법 : 가변 인자!
# a, *b = map(int, input().split())  => a:입력받을 개수, b: 리스트 형태로 받아짐(a의 개수에 따라서)

# print(s) : 입력받은 값들 (문자열말고 숫자로!!) 배열에 잘 들어갔나 확인

"""
n=len(S)
h=int(n/2)
U=S[:h]
print(U)
"""


def merge_sort(n, S):
    h=int(n/2)
    m=n-h
    U=[], V=[]

    if(n>1):
        U=S[:h]  # 슬라이싱 자체가 복사! 원본값 바뀌지 x
        V=S[h+1:]
        merge_sort(h,U)
        merge_sort(m,V)
    else:
        return merge(h,m,U,V,S)
    
    
def merge(h, m, U, V, S):
    i=j=k=1
    while(i<=h and j<=m):
        if(U[i] < V[j]):
            S[k] = U[i]
            i+=1
        else:
            S[k]=V[j]
            j+=1
        k+=1
    if(i>h):
        S[k:h+m]=V[j:m]
    else:
        S[k:h+m]=U[i:h]


def main():
    s=list(map(int, input('배열에 넣을 값들을 입력하세요 : ').split()))
    n=len(s)
    merge_sort(n, s)


print(main())