// #1 - 내가 생각한 기본 방법!  (피벗보다 작으면 새로 생성한 배열의 front부터 차례대로 넣고(++), 피벗보다 크면 맨 뒤 end부터 뒤에서부터 차례대로 넣기(--) ==> 따라서 별도의 추가 배열 있어야 함...)

int arr[8] = {3, 2, 5, 7, 8, 1, 9, 4};
int tmp[8];   // 임시배열. arr 정렬하고 난 후 최종 정렬된 배열 tmp(s')을 다시 arr(s)에 덮어쓰기 해줘야함!

void copy(int low, int high);
int partition(int low, int high);
void quicksort(int low, int high);


void copy(int low, int high)  // 전역변수로 선언한 입력받은 원본 배열 arr에 tmp에다가 정렬해놓은 데이터들을 덮어쓰기!
{
    for (int i = low; i <= high; i++)
    {
        arr[i] = tmp[i];
    }
}

int partition(int low, int high)  // ***partition에서는 그냥 피벗 위치만 하나씩 정해준다!! 좌우로는 "정렬 안된" 배열들임!! /  그치만 이걸 반복하면 실질적으로 정렬됨! 이 파티션을 반복하다보면...***
{
    int pivotitem = arr[low];       // 원소 값(피벗의 값. 피벗을 배열의 첫번째부분에 위치한 애로 정한 것.), low=0번지부터 시작
    int front = low, end = high;    // 인덱스 (front&end : "tmp[]"의 인덱스 / low&high : "arr[]"의 인덱스)

    for (int i = low + 1; i <= high; i++)  // 피벗 바로 다음 값부터 대소비교 시작(i=low+1), low+1=1번지부터 시작. i=high 즉, 배열의 맨 마지막값까지 다 대소비교 끝나면 for문 끝. ==> 피벗 위치 확정.
    {
        if (arr[i] < pivotitem)
        {
            tmp[front] = arr[i];  // 피벗보다 작은 값 ==> 새로 만든 배열인 tmp[0] 0번지에부터 값 넣어주기!
            front++;
        }
        else
        {
            tmp[end] = arr[i];  // 피벗보다 큰 값 ==> 새로 만든 배열인 tmp[end] 끝 번지(end=high) 부터 값 넣어주기!
            end--;
        }
    }
    tmp[front] = pivotitem; // 이미 front++ 한 상태로 for문 끝났기 때문에, front부분은 비어있을 것! ==> 여기가 피벗아이템 위치~확정~
    copy(low, high);      // 덮어쓰기(tmp에 넣었던 값들을 이제 피벗하나 위치 확정된상태... 이 tmp배열을 arr에 복붙하기)
    return front;         // tmp[front]에 넣은 pivot의 위치(인덱스 값:front) 반환 ==> pivot의 위치 확정됨!!~~(=pivotpoint)
}



void quicksort(int low, int high)  // quicksort함수를 재귀로 불러와서 퀵소트 함수 실행하는게 ==> ***결국 partition을 계속 반복하는거!!!*** ==> 결국 partition에서 피벗들 위치 정해주다보면 모든 값들이 피벗이 되어서 자리들이 차례로 정해짐 ==> 정렬 끝
{
    if (low < high)         // low=high되는 순간 퀵소트 끝(배열에 값 하나 남았다는 말)
    {
        int pivot = partition(low, high);  // partition 함수의 반환값인 "피벗 위치"의 "인덱스"를 "pivot" 이라는 변수에 저장 / ***partition에서는 그냥 피벗 위치만 하나씩 정해준다!! 좌우로는 정렬 안된 배열들임!!***
        quicksort(low, pivot - 1);         // 피벗 기준 ***왼쪽 부분부터*** 쭉 배열 정렬하러 ㄱㄱ (반환값은 없음) /  ***퀵소트 : "깊이우선탐색!" (머지소트도) ***
        quicksort(pivot + 1, high);        // 왼쪽들 다 끝나고(low=high되면) 피벗 기준 ***오른쪽 부분*** 배열 정렬하러 ㄱㄱ (반환값은 없음)
    }
}


int main()    // main에서 큰 흐름 짜기(input과 output 잘 보이게!)
{
    // 1. 처음에 일단 초기 배열(arr) 값들 출력해보기 (Input)
    for (int i = 0; i < 8; i++)
    {
        printf("%3d", arr[i]);
    }

    // 2. 퀵 소트 시작. 초기 인자 값 : (low, high) --> 인덱스 값
    quicksort(0, 7);
    

    // 3. 퀵 소트 끝나고나서 tmp를 arr에 다 복사한담에 정렬된 배열로 바뀐 arr 다시 출력해보기 (Output)
    for (int i = 0; i < 8; i++)
    {
        printf("%3d", arr[i]);
    }
}