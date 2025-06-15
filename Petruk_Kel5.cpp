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
 void inputResponsi() {
        char sudahAda;
        cout << endl << "Input Responsi:" << endl;
        cout << "Sudah ada nilai akhir? (y/n): ";
        cin >> sudahAda;

        double* ptrNilaiResponsi = &nilaiResponsi;
        
        if (sudahAda == 'y' || sudahAda == 'Y') {
            cout << "Nilai akhir responsi: ";
            cin >> *ptrNilaiResponsi;
        } else {
            double* ptrPersenUASResp = &persenUASResponsi;
            double* ptrPersenUTSResp = &persenUTSResponsi;
            double* ptrPersenQuizResp = &persenQuizResponsi;
            double* ptrPersenTugasResp = &persenTugasResponsi;
            
            cout << endl << "Persentase Komponen:" << endl;
            cout << "UAS (%): ";
            cin >> *ptrPersenUASResp;
            cout << "UTS (%): ";
            cin >> *ptrPersenUTSResp;
            cout << "Quiz (%): ";
            cin >> *ptrPersenQuizResp;
            cout << "Tugas (%): ";
            cin >> *ptrPersenTugasResp;

            double totalPersenResponsi = *ptrPersenUASResp + *ptrPersenUTSResp + *ptrPersenQuizResp + *ptrPersenTugasResp;
            if (totalPersenResponsi != 100) {
                cout << "Total: " << totalPersenResponsi << "% (tidak 100%)" << endl;
            } else {
                cout << "Total: " << totalPersenResponsi << "% (Valid)" << endl;
            }
            
            double* ptrNilaiUASResp = &nilaiUASResponsi;
            double* ptrNilaiUTSResp = &nilaiUTSResponsi;
            double* ptrNilaiQuizResp = &nilaiQuizResponsi;
            double* ptrNilaiTugasResp = &nilaiTugasResponsi;
            
            cout << endl << "Nilai Komponen:" << endl;
            cout << "UAS: ";
            cin >> *ptrNilaiUASResp;
            cout << "UTS: ";
            cin >> *ptrNilaiUTSResp;
            
            int jumlahQuizResponsi;
            cout << "Jumlah quiz: ";
            cin >> jumlahQuizResponsi;
            
            vector<double> daftarNilaiQuizResponsi;
            for (int i = 0; i < jumlahQuizResponsi; i++) {
                double nilai;
                cout << "Quiz " << (i + 1) << ": ";
                cin >> nilai;
                daftarNilaiQuizResponsi.push_back(nilai);
            }  
            *ptrNilaiQuizResp = hitungRataRata(daftarNilaiQuizResponsi);
            cout << "Rata-rata quiz: " << *ptrNilaiQuizResp << endl;
            
            int jumlahTugasResponsi;
            cout << "Jumlah tugas: ";
            cin >> jumlahTugasResponsi;
            
            vector<double> daftarNilaiTugasResponsi;
            for (int i = 0; i < jumlahTugasResponsi; i++) {
                double nilai;
                cout << "Tugas " << (i + 1) << ": ";
                cin >> nilai;
                daftarNilaiTugasResponsi.push_back(nilai);
            }
            *ptrNilaiTugasResp = hitungRataRata(daftarNilaiTugasResponsi);
            cout << "Rata-rata tugas: " << *ptrNilaiTugasResp << endl;
            
            double kontribusiUASResponsi = (*ptrNilaiUASResp * *ptrPersenUASResp) / 100;
            double kontribusiUTSResponsi = (*ptrNilaiUTSResp * *ptrPersenUTSResp) / 100;
            double kontribusiQuizResponsi = (*ptrNilaiQuizResp * *ptrPersenQuizResp) / 100;
            double kontribusiTugasResponsi = (*ptrNilaiTugasResp * *ptrPersenTugasResp) / 100;
            
            *ptrNilaiResponsi = kontribusiUASResponsi + kontribusiUTSResponsi + kontribusiQuizResponsi + kontribusiTugasResponsi;
            cout << endl << "Hasil Responsi:" << endl;
            cout << fixed << setprecision(2);
            cout << "UAS: " << *ptrNilaiUASResp << " x " << *ptrPersenUASResp << "% = " << kontribusiUASResponsi << endl;
            cout << "UTS: " << *ptrNilaiUTSResp << " x " << *ptrPersenUTSResp << "% = " << kontribusiUTSResponsi << endl;
            cout << "Quiz: " << *ptrNilaiQuizResp << " x " << *ptrPersenQuizResp << "% = " << kontribusiQuizResponsi << endl;
            cout << "Tugas: " << *ptrNilaiTugasResp << " x " << *ptrPersenTugasResp << "% = " << kontribusiTugasResponsi << endl;
            cout << "Nilai akhir: " << *ptrNilaiResponsi << endl;
        }
        cout << endl;
    }   
}

double hitungRataRata(vector<double> nilai) {
        if (nilai.empty()) {
            return 0.0;
        }
        double hasil = hitungRataRataDivideConquer(nilai, 0, nilai.size() - 1);
        return hasil;
    }
    
    void inputUASUTS() {
        cout << endl << "Input Nilai UAS dan UTS:" << endl;
        double* ptrUAS = &nilaiUAS;
        double* ptrUTS = &nilaiUTS;
        
        cout << "UAS: ";
        cin >> *ptrUAS;
        cout << "UTS: ";
        cin >> *ptrUTS;
        cout << endl;
    }
    
    void inputQuiz() {
        cout << endl << "Input Nilai Quiz:" << endl;
        int jumlahQuiz;
        cout << "Jumlah quiz: ";
        cin >> jumlahQuiz;
        
        vector<double> daftarNilaiQuiz;
        for (int i = 0; i < jumlahQuiz; i++) {
            double nilai;
            cout << "Quiz " << (i + 1) << ": ";
            cin >> nilai;
            daftarNilaiQuiz.push_back(nilai);
        }
        double* ptrNilaiQuiz = &nilaiQuiz;
        *ptrNilaiQuiz = hitungRataRata(daftarNilaiQuiz);
        cout << "Rata-rata quiz: " << *ptrNilaiQuiz << endl;
        cout << endl;
    }
    void inputTugas() {
        cout << endl << "Input Nilai Tugas:" << endl;
        int jumlahTugas;
        cout << "Jumlah tugas: ";
        cin >> jumlahTugas;
        
        vector<double> daftarNilaiTugas;
        for (int i = 0; i < jumlahTugas; i++) {
            double nilai;
            cout << "Tugas " << (i + 1) << ": ";
            cin >> nilai;
            daftarNilaiTugas.push_back(nilai);
        }
        double* ptrNilaiTugas = &nilaiTugas;
        *ptrNilaiTugas = hitungRataRata(daftarNilaiTugas);
        cout << "Rata-rata tugas: " << *ptrNilaiTugas << endl;
        cout << endl;
    }
    void inputAbsensi() {
        cout << endl << "Input Absensi:" << endl;
        int jumlahPertemuan;
        cout << "Jumlah pertemuan: ";
        cin >> jumlahPertemuan;
    
        int jumlahHadir = 0;
        int* ptrJumlahHadir = &jumlahHadir;
        
        cout << "Kehadiran (H=Hadir, T=Tidak Hadir):" << endl;
        for (int i = 0; i < jumlahPertemuan; i++) {
            char kehadiran;
            cout << "Pertemuan " << (i + 1) << ": ";
            cin >> kehadiran;
            if (kehadiran == 'H' || kehadiran == 'h') {
                (*ptrJumlahHadir)++;
            }
        }
        double* ptrNilaiAbsensi = &nilaiAbsensi;
        *ptrNilaiAbsensi = (double)*ptrJumlahHadir / jumlahPertemuan * 100;
        cout << "Nilai absensi: " << *ptrNilaiAbsensi << endl;
        cout << endl;
    }




int main() {

}
