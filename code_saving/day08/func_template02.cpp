#include <iostream>

using namespace std;

template <typename T>
void MySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void MySort(T *arr, int len) {
    // 选择排序
    // 从小到大
    for (int i=0; i<len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if (arr[i] > arr[j]) {
                MySwap<T>(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
void MyPrint(T *arr, int len) {
    for (int i=0; i<len; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    int arr_1[] = {24, 7, 19, 4, 88, 122, 70};
    char arr_2[] = "fahoighaffjaifh";
    
    MySort<int>(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));
    MyPrint<int>(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));

    MySort<char>(arr_2, sizeof(arr_2)/sizeof(arr_2[0])-1);
    MyPrint<char>(arr_2, sizeof(arr_2)/sizeof(arr_2[0])-1);
	return 0;
}