#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>
#include <queue>
using namespace std;

class MataKuliah {
private:
    string nama;
    int sks;
    double nilaiAkhir;
    string hurufMutu;
    double bobotMutu;
    char komentar[100];

 double komponenNilai[6];
 char komentar[100];
    
    queue<string> urutanInput;
    double persenUAS, persenUTS, persenQuiz, persenTugas, persenAbsensi, persenResponsi;
    double nilaiUAS, nilaiUTS, nilaiQuiz, nilaiTugas, nilaiAbsensi, nilaiResponsi;
    
    double persenUASResponsi, persenUTSResponsi, persenQuizResponsi, persenTugasResponsi;
    double nilaiUASResponsi, nilaiUTSResponsi, nilaiQuizResponsi, nilaiTugasResponsi;

    double hitungRataRataDivideConquer(vector<double>& nilai, int mulai, int akhir) {
        if (mulai == akhir) {
            return nilai[mulai];
        }
        int tengah = mulai + (akhir - mulai) / 2;
        double rataKiri = hitungRataRataDivideConquer(nilai, mulai, tengah);
        double rataKanan = hitungRataRataDivideConquer(nilai, tengah + 1, akhir);
        int jumlahKiri = tengah - mulai + 1;
        int jumlahKanan = akhir - tengah;
        
        return (rataKiri * jumlahKiri + rataKanan * jumlahKanan) / (jumlahKiri + jumlahKanan);
    }
    void setupUrutanInput() {
        while (!urutanInput.empty()) {
            urutanInput.pop();
        }
        urutanInput.push("Persentase");
        urutanInput.push("UAS_UTS");
        urutanInput.push("Quiz");
        urutanInput.push("Tugas");
        urutanInput.push("Absensi");
        
        if (sks == 3) {
            urutanInput.push("Responsi");
        }
        urutanInput.push("Hitung");
        urutanInput.push("Tampilkan");
    }
public:
    MataKuliah() {
        sks = 0;
        nilaiAkhir = 0, bobotMutu = 0, hurufMutu = "", 
        persenUAS = 0, persenUTS = 0, persenQuiz = 0, persenTugas = 0, persenAbsensi = 0, persenResponsi = 0, 
        nilaiUAS = 0, nilaiUTS = 0, nilaiQuiz = 0, nilaiTugas = 0, nilaiAbsensi = 0, nilaiResponsi = 0;
    }
void setNama(string n) { 
        nama = n;
    }
    void setSKS(int s) { 
        sks = s; 
    }
    string getNama() { 
        return nama; 
    }
    int getSKS() { 
        return sks; 
    } 
    double getNilaiAkhir() { 
        return nilaiAkhir; 
    }
    string getHurufMutu() { 
        return hurufMutu; 
    }
    double getBobotMutu() { 
        return bobotMutu; 
    }

void inputPersentase() {
        cout << endl << "Input Persentase:" << endl;
        
        double* ptrPersenUAS = &persenUAS;
        double* ptrPersenUTS = &persenUTS;
        double* ptrPersenQuiz = &persenQuiz;
        double* ptrPersenTugas = &persenTugas;
        double* ptrPersenAbsensi = &persenAbsensi;
        double* ptrPersenResponsi = &persenResponsi;
        
        cout << "UAS (%): ";
        cin >> *ptrPersenUAS;
        cout << "UTS (%): ";
        cin >> *ptrPersenUTS;
        cout << "Quiz (%): ";
        cin >> *ptrPersenQuiz;
        cout << "Tugas (%): ";
        cin >> *ptrPersenTugas;
        cout << "Absensi (%): ";
        cin >> *ptrPersenAbsensi;
        
        if (sks == 3) {
            cout << "Responsi (%): ";
            cin >> *ptrPersenResponsi;
        }
        
        double totalPersen = *ptrPersenUAS + *ptrPersenUTS + *ptrPersenQuiz + *ptrPersenTugas + *ptrPersenAbsensi;
        if (sks == 3) {
            totalPersen += *ptrPersenResponsi;
        }
        if (totalPersen != 100) {
            cout << "Total: " << totalPersen << "% (tidak 100%)" << endl;
        } else {
            cout << "Total: " << totalPersen << "% (Valid)" << endl;
        }
        cout << endl;
    }

void konversiNilai(double nilai) {
        if (nilai >= 85) {
            hurufMutu = "A+";
            bobotMutu = 4.0;
        } else if (nilai >= 80) {
            hurufMutu = "A";
            bobotMutu = 4.0;
        } else if (nilai >= 75) {
            hurufMutu = "B+";
            bobotMutu = 3.5;
        } else if (nilai >= 70) {
            hurufMutu = "B";
            bobotMutu = 3.0;
        } else if (nilai >= 65) {
            hurufMutu = "C+";
            bobotMutu = 2.5;
        } else if (nilai >= 60) {
            hurufMutu = "C";
            bobotMutu = 2.0;
        } else if (nilai >= 50) {
            hurufMutu = "D";
            bobotMutu = 1.0;
        } else {
            hurufMutu = "E";
            bobotMutu = 0.0;
        }
    }
    
}




int main() {

}
