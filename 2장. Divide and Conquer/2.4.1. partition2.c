// #2 - 교수님 방법(한 방향 / 책에 있는 방법)

int arr[8] = {3, 2, 5, 7, 8, 1, 9, 4};
int tmp[8];   

void copy(int low, int high);
void partition(int low, int high);
void quicksort(int low, int high);


void copy(int low, int high)  
{
    for (int i = low; i <= high; i++)
    {
        arr[i] = tmp[i];
    }
}



void exchange(int *a, int *b)
{
    int t = *a;   // *a는 a가 가리키고 있는 곳의 값!!! ==> a에 담겨져있는 주소를 통해 가서 a가 가리키고 있는 변수가 갖고있는 값을 t에다가 담기!
    *a = *b;
    *b = t;
}


// 여기서부터 교수님 방법 partition! (책에 있는 방법) ------------------------------------
                                                
void partition(int low, int high, int *pivot)           // ***아마 index& pivot 은 반환할 값의 형태를 나타낸 듯!
{
    int i,j;                                 // i : 배열 탐색할 index들 쭈루룱 (i,j,low,high는 모두 index)
    int pivotitem;                           // (수도코드) 들어 온 값에 따른 자료형(keytype) , 여기서 pivotitem은 피벗의 값 자체!(인덱스 말고 실제 피벗값)

    pivotitem = arr[low];                      // 첫번째 값을 pivot으로!
    j=low;

    for(i=low+1; i<=high; i++){
        if(arr[i] < pivotitem) {
            j++;
            exchange(&arr[i], &arr[j]);
        }
    }
    pivot = j;
    exchange(&arr[low], &arr[*pivot]);    
    
}

// *** pivotpoint...라는 인덱스 값 자체를(숫자를) 다시 반환하지는 않지만, 이 partition함수를 거치면 index& pivotpoint 이므로, "피벗의 위치"인 ""인덱스값"" 자체가 계속 변함!!~~~~(포인터...주소...)

//--------------------------------------------------------------------------------------

void quicksort(int low, int high)  
{
    int pivot=0;  // 피벗의 index!! (일단 임시로 0 넣어놓고 첫번째 partition 함수로 넘기기)

    if (low < high)        
    {
        partition(low, high, &pivot);   // 주소를 보내기(partition함수 실행 끝나면 실제 값도 바꾸기 위해)))
        quicksort(low, pivot - 1);        
        quicksort(pivot + 1, high);        
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


