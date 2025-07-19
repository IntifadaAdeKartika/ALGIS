/*
    Penukaran Koin - Algoritma Greedy
    Nama   : INTIFADA ADE KARTIKA
    NIM    : 23533756
    Kelas  : 4C/TEKNIK INFORMATIKA
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void showIdentity() {
    cout << "==================================\n";
    cout << "Penukaran Koin - Algoritma Greedy\n";
    cout << "Nama : INTIFADA ADE KARTIKA\n";
    cout << "NIM  : 23533756\n";
    cout << "Kelas: 4C/TEKNIK INFORMATIKA\n";
    cout << "=================================\n";
}

int main() {
    showIdentity();
    int n;
    cout << "Masukkan jumlah jenis koin: ";
    cin >> n;
    vector<int> coin(n);

    cout << "Masukkan nilai masing-masing koin (pisahkan dengan spasi): ";
    for (int &v : coin) cin >> v;

    // Selection Sort, descending
    for(int i=0; i<n-1; ++i)
        for(int j=i+1; j<n; ++j)
            if(coin[j] > coin[i]) swap(coin[i],coin[j]);

    int amount;
    cout << "Masukkan nilai yang ingin ditukarkan: ";
    cin >> amount;

    cout << "\nBreakdown penukaran koin:\n";

    for(int i=0; i<n; ++i){
        int jumlah = amount / coin[i];
        cout << "· " << setw(5) << coin[i] << "-an : " << jumlah << " keping\n";
        amount %= coin[i];
    }

    if(amount > 0) cout << "Sisa nilai yang tidak bisa ditukar: " << amount << endl;
    else cout << "Semua nilai berhasil ditukar! :)\n";
    cout << "Terima kasih telah menggunakan program ini!\n";
    return 0;
}
