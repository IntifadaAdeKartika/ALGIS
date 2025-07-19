/*
    Fractional Knapsack - Algoritma Greedy
    Nama   : INTIFADA ADE KARTIKA
    NIM    : 23533756
    Kelas  : 4C/TEKNIK INFORMATIKA
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Item {
    int no, w, p;
    double ratio;
};

void showIdentity() {
    cout << "===============================\n";
    cout << "Fractional Knapsack - Greedy\n";
    cout << "Nama : INTIFADA ADE KARTIKA\n";
    cout << "NIM  : 23533756\n";
    cout << "Kelas: 4C/TEKNIK INFORMATIKA\n";
    cout << "===============================\n";
}

int main() {
    showIdentity();

    int n;
    cout << "Masukkan jumlah item: ";
    cin >> n;
    vector<Item> items(n);

    for(int i = 0; i < n; ++i) {
        cout << "Item ke-" << i+1 << ":\n";
        cout << "  Berat: "; cin >> items[i].w;
        cout << "  Profit: "; cin >> items[i].p;
        items[i].no = i+1;
        items[i].ratio = double(items[i].p) / items[i].w;
    }

    int kapasitas;
    cout << "Masukkan kapasitas maksimum knapsack: ";
    cin >> kapasitas;

    // Bubble Sort based on ratio descending
    for(int i=0; i<n-1; ++i)
        for(int j=i+1; j<n; ++j)
            if(items[j].ratio > items[i].ratio)
                swap(items[i],items[j]);

    cout << left << setw(5) << "Obj" << setw(8) << "Berat" << setw(8) << "Profit" << setw(10) << "P/W" << endl;
    for(const auto &it : items)
        cout << setw(5) << it.no << setw(8) << it.w << setw(8) << it.p << setw(10) << fixed << setprecision(2) << it.ratio << endl;

    int remaining = kapasitas;
    double totProfit = 0;
    cout << "\nProses pengambilan item:\n";
    for(const auto &it : items){
        if(it.w <= remaining){
            cout << "- Item " << it.no << " diambil penuh.\n";
            totProfit += it.p;
            remaining -= it.w;
        } else if(remaining > 0){
            cout << "- Item " << it.no << " diambil sebagian (" << remaining << "/" << it.w << ")." << endl;
            totProfit += it.ratio * remaining;
            remaining = 0;
            break;
        }
    }
    cout << "\nTotal profit maksimum yang bisa didapat: " << totProfit << endl;
    cout << "Terima kasih telah menggunakan program ini!\n";
    return 0;
}
