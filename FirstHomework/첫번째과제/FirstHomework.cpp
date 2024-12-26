#include <iostream>
#include <algorithm> // bubbleSort�Լ������ ���� <algorithm>���̺귯�� �ʿ�.

using namespace std;

// ��� ��� �Լ�
double getAvg(int num1, int num2, int num3, int num4, int num5)
//����� ����ϱ� ���� double �Ǽ� �ڷ����� �ҷ��԰�(����� �Ҽ������� ��Ÿ���� ����), 
//getAvg��� �Լ��� ����� �� �ȿ�num1���� num5���� �־���.
{
    return (num1 + num2 + num3 + num4 + num5) / 5.0f;
    //getAvg�Լ��� ���� �� ���ؼ� 5�� ������ ��ȯ�Ѵ�.5.0f���� f�� �Ǽ��� ǥ���ϱ����� float�� f
}

// �������� ��������/��������
void bubbleSort(int arr[], int size, bool isAscending)
//arr�� ���� �Է��� �� 5��
//seize�� ���� �����ϰ� �ִ� ������ ex) {n,n,n,n,n}
//isAscending�� ���������� ���������� ����ϱ����� �Լ� bool���
{
    for (int i = 0; i < size - 1; i++)
        /* i��� ���� ���� �����Ұǵ� ������ �ϸ鼭 ��üsize(�迭�� ũ��)
        ���� -1�� �Ѵ�.(�ѹ� ������ �ϱ� ������ -1)*/
    {
        for (int j = 0; j < size - 1 - i; j++)
            /* ������ i�� �ѹ� ������ ������ �ѹ��� j�� ����� �ѹ� �� ������ �ϰ�
            �� j�� �� ������ ���� ū���� �ڷΰ����̰�, �� �ڷ� �� ū���� i�� ����
            ������ ���� j < size - 1���ٰ� �ѹ��� - i�� �Ѵ�.*/
        {
            if ((isAscending && arr[j] > arr[j + 1]) || (!isAscending && arr[j] < arr[j + 1]))
                /* isAscending �� arr[j] > arr[j + 1]�� ���� true�̰�, arr[j] < arr[j + 1]�϶���
                false��� ������ �� ������ �� ���� �ؿ��ִ� temp�� swap�ȴ�.*/
            {
                // ���� if���� �ִ� ���� ����
                int temp = arr[j];
                //temp�� arr[j + 1]���� �� ū ���� arr[j]�� �Էµ� ���� �����ϰ�,
                arr[j] = arr[j + 1];
                //arr[j]�� ��ġ����  arr[j + 1](�� �۾Ҵ� ��)�� �ִ� ���� ���� �ǰ�,
                arr[j + 1] = temp;
                //arr[j + 1]���� �Ʊ� temp�� ������ �ξ��� arr[j](�� ū��)�� ���´�.
            }
        }
    }
}

// ���� ���� �� ��� �� ��� �Լ�
void printFrequencies(int arr[], int size)
//printFrequencies�� ���� �迭���� ���� ���ڰ� �� �� ���Դ��� ����ϰ� ����ϴ� �Լ��̴�.
{
    bool a[5] = { false };
    bool b = false;
    //�Է��� ���� 5���� �迭�� ũ��� 5�̰�, ��� ���� false�� �ʱ�ȭ�� �ǰ� �����.
    //a�� �Է��� ���ڵ� �� �ߺ�Ȯ�� �Ǿ����� ǥ���ϱ� ���� �뵵�� ������.
    //b�� �Ʒ��� �ߺ��� ���� ���� ���� ���� ���� ������.

        cout << "�ߺ� �� �� : ";
    for (int i = 0; i < size; i++)
        //�迭�� ��� ���ڸ� Ȯ���ϱ� ���� for�ݺ���
        //i�� ���� �˻����� ����
    {
        if (a[i]) continue;
        //���� ���� i�� �̹� �ߺ� Ȯ�εȻ���(i = true)���, �� ���ڴ� �ǳ� �ڴ�.

        int count = 1;
        //���� Ȯ������ ���� arr[i]�� �󵵸� ������ ������ �⺻���� 1�� �����Ѵ�.
        for (int j = i + 1; j < size; j++)
            //���� ���� arr[i]�� ������ ���ڵ��� ���Ѵ�.
            //j = i + 1���� �����ϴ� ������ ���� ���� ������ ���ڵ��� �� Ȯ���ؼ��̴�.
        {
            if (arr[i] == arr[j])
                //���� arr[i]�� arr[j]�� ������ �����Ѵ�.
            {
                a[j] = true;
                //arr[j]�� arr[i]�� ������, visited[j]�� true�� �����Ͽ� �ߺ� Ȯ���� ǥ���Ѵ�.
                count++;
                //���� ���ڸ� �߰��߱⿡ count�� 1�� ���Ѵ�.
            }
        }

        if (count > 1)
            //���� �ߺ��� ���� ���� count�� �⺻���� 1���� �������� �Ʒ� �޽��� ���
        {
            cout << arr[i] << "(" << count << "��) ";
            b = true; // �ߺ��� ���� ���� �� b������ true�� ����� �ȵǰ� �Ѵ�.
        }
    }
    if (!b)
       //�� ��ü ���� Ȯ���ϰ� b��� ������ false��� �Ʒ� �޽����� ��µȴ�.
    {
        cout << "�ߺ��� ���� �����ϴ�.";
    }
    cout << endl;
}

int main() {
    int num[5]; // �Է� ���� ���ڵ�
    int sum = 0; //�Է¹��� ���ڵ��� ���� sum�̶�� ������ �����ҰŰ�, �⺻���� 0�̴�.

    cout << "5���� ���ڸ� �Է����ּ���." << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "��° �Է��Դϴ�. : ";
        cin >> num[i];
        sum += num[i]; // num�� �Է��� ���� sum�� ��� ���Ѵ�.
    }

    cout << "�Է��� ���ڵ��� ��: " << sum << endl; 
     
    cout << "�Է��� ���ڵ��� ���: " << getAvg(num[0], num[1], num[2], num[3], num[4]) << endl;

    // �������� ����
    int numAscending[5];
    //numAscending�̶�� ������ ����� ���⿡ ���������� �� ������ �����Ѵ�.
    copy(begin(num), end(num), begin(numAscending));
    /*copy�� <algorithm>���̺귯���� ���ǵ� �Լ��� ���Լ���
    ���� �迭�� �����͸� �ٸ� �迭�� ������ �� ���ȴ�.*/

    //begin(num)�� �迭�� ���� ù�� ° ������ �����Ѵٴ� ��(�Է��� ���� �� ���� ù��° ����)

    /*end(num)�� ���� �Է��� ���ڵ��� ��������� ������
    begin(num)�� end(num)�� ����� ���۰� ���� ��Ÿ����. */

    //begin(numAscending)�� �迭�� ���� ��ġ�� numAscending�� ���� ó���� �����Ѵٴ� ���̴�.

    bubbleSort(numAscending, 5, true);
    //���� ������ bubbleSort�� �����´�. ���Ǵ� numAscending�� 5���̸� true�� �ҷ��´�.
    cout << "�������� ����: ";
    for (int i = 0; i < 5; i++)
        //���� 5���� �Է��ϱ����� for�ݺ���
    {
        cout << numAscending[i] << " ";
        //numAscending[i]�� �Էµ� ��[i]���� ���
    }
    cout << endl;
    //��ĭ �Ʒ��� ������.

    // �������� ���ķ� ���� �������� ���Ŀ��� true�� false�� �и��ȴ�.
    int numDescending[5];
    copy(begin(num), end(num), begin(numDescending));
    bubbleSort(numDescending, 5, false); // false: ��������
    cout << "�������� ����: ";
    for (int i = 0; i < 5; i++) {
        cout << numDescending[i] << " ";
    }
    cout << endl;

    // �ߺ��� �� ���
    printFrequencies(num, 5);

    return 0;
}
