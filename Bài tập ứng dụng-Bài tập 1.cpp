#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 1000; // Kích thước tối đa của mảng

// Cấu trúc dữ liệu danh sách để lưu mảng
struct ds {
    int data[MAX_SIZE];
    int size;

    void chen(int gtri) {
        if (size < MAX_SIZE) {
            data[size++] = gtri;
        }
    }

    void xoatai(int index) {
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
};

// Hàm tìm vị trí của k phần tử lớn nhất
void vitriklonnhat(const ds& arr, int k, int vtri[]) {
    int temp[MAX_SIZE], chiso[MAX_SIZE];
    for (int i = 0; i < arr.size; i++) {
        temp[i] = arr.data[i];
        chiso[i] = i;
    }

    for (int i = 0; i < arr.size - 1; i++) {
        for (int j = i + 1; j < arr.size; j++) {
            if (temp[i] < temp[j]) {
                swap(temp[i], temp[j]);
                swap(chiso[i], chiso[j]);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        vtri[i] = chiso[i];
    }
}

// Hàm tính tổng chữ số của một số nguyên
int tongcs(int n) {
    int tong = 0;
    n = abs(n);
    while (n > 0) {
        tong += n % 10;
        n /= 10;
    }
    return tong;
}

// Hàm sắp xếp mảng theo tổng chữ số của từng phần tử
void sxtheotong(ds& arr) {
    for (int i = 0; i < arr.size - 1; i++) {
        for (int j = i + 1; j < arr.size; j++) {
            if (tongcs(arr.data[i]) > tongcs(arr.data[j])) {
                swap(arr.data[i], arr.data[j]);
            }
        }
    }
}

// Hàm kiểm tra số nguyên tố
bool kt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm xóa các số nguyên tố khỏi mảng
void xoasnt(ds& arr) {
    int newSize = 0;
    for (int i = 0; i < arr.size; i++) {
        if (!kt(arr.data[i])) {
            arr.data[newSize++] = arr.data[i];
        }
    }
    arr.size = newSize;
}

int main() {
    ds arr;
    arr.size = 0;
    int n, k;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        int gtri;
        cin >> gtri;
        arr.chen(gtri);
    }

    cout << "Nhap so luong phan tu lon nhat can tim: ";
    cin >> k;

    int vtri[MAX_SIZE];
    vitriklonnhat(arr, k, vtri);
    cout << "Vi tri cua " << k << " phan tu lon nhat: ";
    for (int i = 0; i < k; i++) {
        cout << vtri[i] << " ";
    }
    cout << endl;

    sxtheotong(arr);
    cout << "Day sau khi sap xep theo tong chu so: ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;

    xoasnt(arr);
    cout << "Day sau khi xoa so nguyen to: ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;

    return 0;
}

