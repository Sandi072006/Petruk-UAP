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
const char* getKomentar() {
        return komentar;
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
        if (nilai = 100) {
            hurufMutu = "A+";
            bobotMutu = 4.0;
        } else if (nilai >= 76) {
            hurufMutu = "A";
            bobotMutu = 4.0;
        } else if (nilai >= 71) {
            hurufMutu = "B+";
            bobotMutu = 3.5;
        } else if (nilai >= 66) {
            hurufMutu = "B";
            bobotMutu = 3.0;
        } else if (nilai >= 61) {
            hurufMutu = "C+";
            bobotMutu = 2.5;
        } else if (nilai >= 56) {
            hurufMutu = "C";
            bobotMutu = 2.0;
        } else if (nilai >= 45) {
            hurufMutu = "D";
            bobotMutu = 1.0;
        } else if(nilai < 45 ) {
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
 void hitungNilaiAkhir() {
        komponenNilai[0] = nilaiUAS;
        komponenNilai[1] = nilaiUTS;
        komponenNilai[2] = nilaiQuiz;
        komponenNilai[3] = nilaiTugas;
        komponenNilai[4] = nilaiAbsensi;
        komponenNilai[5] = nilaiResponsi;
        
        double* ptrKomponen = komponenNilai;
        double kontribusiUAS = (*(ptrKomponen + 0) * persenUAS) / 100;
        double kontribusiUTS = (*(ptrKomponen + 1) * persenUTS) / 100;
        double kontribusiQuiz = (*(ptrKomponen + 2) * persenQuiz) / 100;
        double kontribusiTugas = (*(ptrKomponen + 3) * persenTugas) / 100;
        double kontribusiAbsensi = (*(ptrKomponen + 4) * persenAbsensi) / 100;
        
        double* ptrNilaiAkhir = &nilaiAkhir;
        *ptrNilaiAkhir = kontribusiUAS + kontribusiUTS + kontribusiQuiz + kontribusiTugas + kontribusiAbsensi;
        
        if (sks == 3) {
            double kontribusiResponsi = (*(ptrKomponen + 5) * persenResponsi) / 100;
            *ptrNilaiAkhir += kontribusiResponsi;
        }
        konversiNilai(*ptrNilaiAkhir);
        buatKomentar();
    }


void buatKomentar() {
        if (strcmp(hurufMutu.c_str(), "A+") == 0) {
            strcpy(komentar, "Gantiin Dosen ngajar");
        } else if (strcmp(hurufMutu.c_str(), "A") == 0) {
            strcpy(komentar, "Sesuai keinginan");
        } else if (strcmp(hurufMutu.c_str(), "B+") == 0) {
            strcpy(komentar, "Yahh Dikit lagi A");
        } else if (strcmp(hurufMutu.c_str(), "B") == 0) {
            strcpy(komentar, "Kebanyakan skroll tiktok");
        } else if (strcmp(hurufMutu.c_str(), "C+") == 0) {
            strcpy(komentar, "Kebanyakan Tidur");
        } else if (strcmp(hurufMutu.c_str(), "C") == 0) {
            strcpy(komentar, "Antara males atau dosenya gabut");
        } else if (strcmp(hurufMutu.c_str(), "D") == 0) {
            strcpy(komentar, "UTBK Lagi aja");
        } else {
            strcpy(komentar, "Gak usah kuliah");
        }
    }

void tampilkanHasil() {
        cout << endl << "Hasil Perhitungan:" << endl;
        cout << fixed << setprecision(2);
        
        double* ptrKomponen = komponenNilai;
        cout << "UAS: " << *(ptrKomponen + 0) << " x " << persenUAS << "% = " << (*(ptrKomponen + 0) * persenUAS) / 100 << endl;
        cout << "UTS: " << *(ptrKomponen + 1) << " x " << persenUTS << "% = " << (*(ptrKomponen + 1) * persenUTS) / 100 << endl;
        cout << "Quiz: " << *(ptrKomponen + 2) << " x " << persenQuiz << "% = " << (*(ptrKomponen + 2) * persenQuiz) / 100 << endl;
        cout << "Tugas: " << *(ptrKomponen + 3) << " x " << persenTugas << "% = " << (*(ptrKomponen + 3) * persenTugas) / 100 << endl;
        cout << "Absensi: " << *(ptrKomponen + 4) << " x " << persenAbsensi << "% = " << (*(ptrKomponen + 4) * persenAbsensi) / 100 << endl;
        if (sks == 3) {
            cout << "Responsi: " << *(ptrKomponen + 5) << " x " << persenResponsi << "% = " << (*(ptrKomponen + 5) * persenResponsi) / 100 << endl;
        }
        
        cout << "Nilai akhir: " << nilaiAkhir << endl;
        cout << "Huruf: " << hurufMutu << " (Bobot: " << bobotMutu << ")" << endl;
        cout << "Komentar: " << komentar << endl; // Tampilkan komentar
    }
    
    void prosesInputNilaiDenganQueue() {
        setupUrutanInput();
        
        while (!urutanInput.empty()) {
            string tahapanSaatIni = urutanInput.front();
            urutanInput.pop();
            
            if (tahapanSaatIni == "Persentase") {
                inputPersentase();
            } else if (tahapanSaatIni == "UAS_UTS") {
                inputUASUTS();
            } else if (tahapanSaatIni == "Quiz") {
                inputQuiz();
            } else if (tahapanSaatIni == "Tugas") {
                inputTugas();
            } else if (tahapanSaatIni == "Absensi") {
                inputAbsensi();
            } else if (tahapanSaatIni == "Responsi") {
                inputResponsi();
            } else if (tahapanSaatIni == "Hitung") {
                hitungNilaiAkhir();
            } else if (tahapanSaatIni == "Tampilkan") {
                tampilkanHasil();
            }
        }
    }
    
    void prosesInputNilai() {
        prosesInputNilaiDenganQueue();
    }
};
class SistemPenilaian {
private:
    vector<MataKuliah> daftarMataKuliah;
    vector<string> historyOperasi;

public:
    void tambahMataKuliah() {
        MataKuliah mk;
        string nama;
        int sks;
        
        cout << endl << "Nama Mata Kuliah: ";
        getline(cin, nama);
        mk.setNama(nama);
    
        cout << "SKS: ";
        cin >> sks;
        cin.ignore();
        mk.setSKS(sks);
        
        mk.prosesInputNilai();
        daftarMataKuliah.push_back(mk);
        historyOperasi.push_back("Ditambah: " + nama);
    }
    
    double hitungIPK() {
        double totalSKSxBobot = 0;
        int totalSKS = 0;
        for (int i = 0; i < daftarMataKuliah.size(); i++) {
            totalSKSxBobot += daftarMataKuliah[i].getSKS() * daftarMataKuliah[i].getBobotMutu();
            totalSKS += daftarMataKuliah[i].getSKS();
        }
        return (totalSKS > 0) ? totalSKSxBobot / totalSKS : 0.0;
    }
void tampilkanHistory() {
        cout << endl << "History Operasi:" << endl;
        for (int i = 0; i < historyOperasi.size(); i++) {
            cout << (i + 1) << ". " << historyOperasi[i] << endl;
        }
    }
    
    void tampilkanRingkasan() {
        cout << endl << "Ringkasan Nilai Mata Kuliah:" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << left << setw(20) << "Mata Kuliah" 
             << setw(5) << "SKS" 
             << setw(10) << "Nilai" 
             << setw(8) << "Huruf" 
             << setw(8) << "Bobot" 
             << setw(30) << "Komentar" << endl;
        cout << "------------------------------------------------------------------------" << endl;

        for (int i = 0; i < daftarMataKuliah.size(); i++) {
            cout << fixed << setprecision(2);
            cout << left << setw(20) << daftarMataKuliah[i].getNama()
                 << setw(5) << daftarMataKuliah[i].getSKS()
                 << setw(10) << daftarMataKuliah[i].getNilaiAkhir()
                 << setw(8) << daftarMataKuliah[i].getHurufMutu()
                 << setw(8) << daftarMataKuliah[i].getBobotMutu() 
                 << setw(30) << daftarMataKuliah[i].getKomentar() << endl;
        }
        cout << "------------------------------------------------------------------------" << endl;

        double ipk = hitungIPK();
        cout << "IPK: " << fixed << setprecision(2) << ipk << endl;
        cout << "Prestasi: ";
        if (ipk >= 3.5) {
            cout << "Cum Laude" << endl;
        } else if (ipk >= 3.0) {
            cout << "Sangat Memuaskan" << endl;
        } else if (ipk >= 2.5) {
            cout << "Memuaskan" << endl;
        } else if (ipk >= 2.0) {
            cout << "Cukup" << endl;
        } else {
            cout << "Kurang" << endl;
        }
        tampilkanHistory();
    }
    
    void jalankanProgram() {
        char lanjut;
        cout << "===================================================" << endl;
        cout << "       PROGRAM PERHITUNGAN NILAI MATA KULIAH" << endl;
        cout << "===================================================" << endl;
        do {
            cout << endl; 
            tambahMataKuliah();
            
            cout << endl << "Tambah mata kuliah lain? (y/n): ";
            cin >> lanjut;
            
        } while (lanjut == 'y' || lanjut == 'Y');
        
        tampilkanRingkasan();
    }
};



int main() {
    SistemPenilaian sistem;
    sistem.jalankanProgram();
}
