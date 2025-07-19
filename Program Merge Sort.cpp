/*
    Merge Sort - Divide and Conquer
    Nama   : INTIFADA ADE KARTIKA
    NIM    : 23533756
    Kelas  : 4C/TEKNIK INFORMATIKA
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void showIdentity() {
    cout << "===============================\n";
    cout << "Merge Sort - Divide & Conquer\n";
    cout << "Nama : INTIFADA ADE KARTIKA\n";
    cout << "NIM  : 23533756\n";
    cout << "Kelas: 4C/TEKNIK INFORMATIKA\n";
    cout << "===============================\n";
}

void merge(vector<int>& v, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    vector<int> L(v.begin()+l, v.begin()+m+1), R(v.begin()+m+1, v.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
        v[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while(i<n1) v[k++] = L[i++];
    while(j<n2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int l, int r) {
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,l,m,r);
    }
}

int main() {
    showIdentity();
    int n;
    cout << "Masukkan jumlah data yang ingin diurutkan: ";
    cin >> n;
    vector<int> v(n);
    cout << "Masukkan data (pisahkan dengan spasi): ";
    for(int &x:v) cin >> x;

    // Tampilkan waktu sebelum & sesudah pengurutan
    time_t now = time(0);
    cout << "Waktu mulai: " << ctime(&now);

    mergeSort(v,0,n-1);

    now = time(0);
    cout << "Waktu selesai: " << ctime(&now);

    cout << "Data setelah diurutkan: ";
    for(int x: v) cout << x << " ";
    cout << endl;

    cout << "Terima kasih telah menggunakan program ini!\n";
    return 0;
}
