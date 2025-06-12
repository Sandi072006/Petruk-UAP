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
}


int main() {

}