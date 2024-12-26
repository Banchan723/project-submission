#include <iostream>
#include <algorithm> // bubbleSort함수사용을 위해 <algorithm>라이브러리 필요.

using namespace std;

// 평균 계산 함수
double getAvg(int num1, int num2, int num3, int num4, int num5)
//평균을 계산하기 위해 double 실수 자료형을 불러왔고(평균을 소수점까지 나타내기 위해), 
//getAvg라는 함수를 만들어 그 안에num1부터 num5까지 넣었다.
{
    return (num1 + num2 + num3 + num4 + num5) / 5.0f;
    //getAvg함수의 값을 다 더해서 5로 나누어 반환한다.5.0f에서 f는 실수를 표현하기위한 float의 f
}

// 버블정렬 오름차순/내림차순
void bubbleSort(int arr[], int size, bool isAscending)
//arr는 내가 입력한 수 5개
//seize는 현재 정렬하고 있는 포지션 ex) {n,n,n,n,n}
//isAscending은 오름차순과 내림차순을 출력하기위한 함수 bool사용
{
    for (int i = 0; i < size - 1; i++)
        /* i라는 값을 먼저 정렬할건데 정렬을 하면서 전체size(배열의 크기)
        에서 -1을 한다.(한번 정렬을 하기 때문에 -1)*/
    {
        for (int j = 0; j < size - 1 - i; j++)
            /* 위에서 i를 한번 정렬한 곳에서 한번더 j를 만들어 한번 더 정렬을 하고
            그 j를 또 돌려서 가장 큰수는 뒤로갈것이고, 맨 뒤로 간 큰수인 i를 뺴기
            때문에 기존 j < size - 1에다가 한번다 - i를 한다.*/
        {
            if ((isAscending && arr[j] > arr[j + 1]) || (!isAscending && arr[j] < arr[j + 1]))
                /* isAscending 이 arr[j] > arr[j + 1]일 때는 true이고, arr[j] < arr[j + 1]일때는
                false라고 설정할 때 나오는 그 값이 밑에있는 temp로 swap된다.*/
            {
                // 위에 if문에 있는 값을 들고와
                int temp = arr[j];
                //temp는 arr[j + 1]보다 더 큰 수인 arr[j]에 입력된 수를 저장하고,
                arr[j] = arr[j + 1];
                //arr[j]의 위치에는  arr[j + 1](더 작았던 수)에 있던 수가 가게 되고,
                arr[j + 1] = temp;
                //arr[j + 1]에는 아까 temp에 저장해 두었던 arr[j](더 큰수)를 들고온다.
            }
        }
    }
}

// 같은 수의 빈도 계산 및 출력 함수
void printFrequencies(int arr[], int size)
//printFrequencies는 숫자 배열에서 같은 숫자가 몇 번 나왔는지 계산하고 출력하는 함수이다.
{
    bool a[5] = { false };
    bool b = false;
    //입력한 수가 5개라서 배열의 크기는 5이고, 모든 값을 false로 초기화가 되게 만든다.
    //a는 입력한 숫자들 중 중복확인 되었는지 표시하기 위한 용도의 변수다.
    //b는 아래에 중복된 수가 없을 때를 위해 만든 변수다.

        cout << "중복 된 수 : ";
    for (int i = 0; i < size; i++)
        //배열의 모든 숫자를 확인하기 위한 for반복문
        //i는 현재 검사중인 숫자
    {
        if (a[i]) continue;
        //만약 숫자 i가 이미 중복 확인된상태(i = true)라면, 그 숫자는 건너 뛴다.

        int count = 1;
        //현재 확인중인 숫자 arr[i]의 빈도를 저장할 변수로 기본값을 1로 설정한다.
        for (int j = i + 1; j < size; j++)
            //현재 숫자 arr[i]와 나머지 숫자들을 비교한다.
            //j = i + 1부터 시작하는 이유는 현재 숫자 이전에 숫자들은 다 확인해서이다.
        {
            if (arr[i] == arr[j])
                //만약 arr[i]와 arr[j]가 같으면 실행한다.
            {
                a[j] = true;
                //arr[j]가 arr[i]와 같으면, visited[j]를 true로 설정하여 중복 확인을 표시한다.
                count++;
                //같은 숫자를 발견했기에 count에 1씩 더한다.
            }
        }

        if (count > 1)
            //만약 중복된 수가 나와 count가 기본값인 1보다 높아지면 아래 메시지 출력
        {
            cout << arr[i] << "(" << count << "번) ";
            b = true; // 중복된 수가 있을 때 b변수는 true로 출력이 안되게 한다.
        }
    }
    if (!b)
       //가 전체 수를 확인하고 b라는 변수가 false라면 아래 메시지가 출력된다.
    {
        cout << "중복된 수가 없습니다.";
    }
    cout << endl;
}

int main() {
    int num[5]; // 입력 받을 숫자들
    int sum = 0; //입력받은 숫자들의 합을 sum이라는 변수에 저장할거고, 기본값은 0이다.

    cout << "5개의 숫자를 입력해주세요." << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "번째 입력입니다. : ";
        cin >> num[i];
        sum += num[i]; // num에 입력한 값을 sum에 계속 더한다.
    }

    cout << "입력한 숫자들의 합: " << sum << endl; 
     
    cout << "입력한 숫자들의 평균: " << getAvg(num[0], num[1], num[2], num[3], num[4]) << endl;

    // 오름차순 정렬
    int numAscending[5];
    //numAscending이라는 변수를 만들어 여기에 오름차순을 할 수들을 저장한다.
    copy(begin(num), end(num), begin(numAscending));
    /*copy는 <algorithm>라이브러리에 정의된 함수로 이함수는
    원본 배열의 데이터를 다른 배열에 복사할 때 사용된다.*/

    //begin(num)은 배열의 가장 첫번 째 수부터 시작한다는 뜻(입력한 숫자 중 가장 첫번째 숫자)

    /*end(num)은 내가 입력한 숫자들의 끝까지라는 뜻으로
    begin(num)과 end(num)을 사용해 시작과 끝을 나타낸다. */

    //begin(numAscending)은 배열의 시작 위치로 numAscending에 가장 처음에 복사한다는 뜻이다.

    bubbleSort(numAscending, 5, true);
    //위에 정의함 bubbleSort를 가져온다. 정의는 numAscending과 5개이며 true를 불러온다.
    cout << "오름차순 정렬: ";
    for (int i = 0; i < 5; i++)
        //숫자 5객를 입력하기위한 for반복문
    {
        cout << numAscending[i] << " ";
        //numAscending[i]은 입력된 수[i]들을 출력
    }
    cout << endl;
    //한칸 아래로 내린다.

    // 내림차순 정렬로 위에 오름차순 정렬에서 true와 false로 분리된다.
    int numDescending[5];
    copy(begin(num), end(num), begin(numDescending));
    bubbleSort(numDescending, 5, false); // false: 내림차순
    cout << "내림차순 정렬: ";
    for (int i = 0; i < 5; i++) {
        cout << numDescending[i] << " ";
    }
    cout << endl;

    // 중복된 수 출력
    printFrequencies(num, 5);

    return 0;
}
