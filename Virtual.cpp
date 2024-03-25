#include <iostream>
using namespace std;

template <typename T>
class CArrayData {
private:
    int size;
    T* data;

public:
    CArrayData(int size_ = 0, const T* pdata = nullptr) : size(size_), data(new T[size]) {
        for (int i = 0; i < size; ++i) {
            data[i] = pdata ? pdata[i] : T();
        }
    }

    void out(bool flag) {
        cout << "RETURN: ";
        for (int i = 0; i < size; ++i) {
            if (flag && data[i] % 2 == 0) {
                cout << data[i] << " ";
            } else if (!flag && data[i] % 2 != 0) {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    void operator()(double) {
        cout << "RETURN: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void operator()(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of range" << endl;
        } else {
            cout << "RETURN: " << data[index] << endl;
        }
    }

    void operator()(int start, int end) {
        cout << "RETURN: ";
        for (int i = start; i < end && i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~CArrayData() {
        delete[] data;
    }
};

void set_pdataINITe(int sizeINIT, int* pdataINIT) {
    cout << "Введите вектор: ";
    for (int i = 0; i < sizeINIT; i++) {
        cin >> pdataINIT[i];
    }
    cout << "Num: " << sizeINIT << "  Data: ";
    for (int i = 0; i < sizeINIT; i++) {
        cout << pdataINIT[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int ss;
    cin >> ss;
    int *a = new int[ss];
    set_pdataINITe(ss, a);

    CArrayData<int> arr(ss, a);
    arr.out(true);
    arr(2.2);
    arr(2);
    arr(2, 5);

    delete[] a;
}
