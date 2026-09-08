#include <iostream>

using namespace std;

int hitunglangkah(int totalbarang, int kapasitas){
    if(totalbarang == 0) return 0;
    
    int N = totalbarang/3;
    int M = totalbarang/3;

    int tripN = (N + kapasitas - 1) / kapasitas;
    int tripM = (M + kapasitas - 1) / kapasitas;

    int langkah = 2*tripN + 2*tripM;

    int sisaN = N % kapasitas;
    int sisaM = M % kapasitas;

    if(sisaN > 0 && sisaM > 0 && sisaN + sisaM <= kapasitas){
        langkah -= 1;
    }

    return langkah;
}

int main() {
    int k, n, m;

    cout<<"Sebuah dok logistik otomatis memiliki 3 kotak penyimpanan utama (Kotak 1, Kotak 2,"<<endl;
    cout<<"Kotak 3) dan 1 unit Robot Angkut berkapasitas maksimal k kg. Kondisi awal barang di"<<endl;
    cout<<"gudang adalah sebagai berikut:"<<endl;
    cout<<"● Kotak 1: Berisi n buah barang, masing-masing berbobot 2 kg."<<endl;
    cout<<"● Kotak 2: Berisi m buah barang, masing-masing berbobot 1 kg."<<endl;
    cout<<"● Kotak 3: Mula-mula dalam keadaan kosong (0 barang, 0 kg)."<<endl;
    cout<<"Robot ditugaskan memindahkan barang antar-kotak agar pada kondisi akhir, ketiga kotak"<<endl;
    cout<<"memiliki jumlah barang yang sama dan total berat barang yang sama persis."<<endl;

    cout<<"Masukkan nilai k,n, dan m: ";
    cin>>k>>n>>m;

    int duakg = k / 2;
    int satukg = k;

    if(n==0&& m==0){
        cout<<0<<endl;
        return 0;
    }

    if(n%3 != 0 || m%3 != 0){
        cout<<-1<<endl;
        return 0;
    }

    if(n>0 && duakg==0){
        cout<<-1<<endl;
        return 0;
    }

    int step2kg = hitunglangkah(n, duakg);
    int step1kg = hitunglangkah(m, satukg);

    cout<<step1kg+step2kg<<endl;

    return 0;
}