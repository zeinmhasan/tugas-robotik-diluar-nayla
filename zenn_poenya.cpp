#include <iostream>  // ini library input output
#include <vector>    // ini library supaya bisa pake vektor
#include <string>    // ini library supaya bisa main data string
#include <algorithm> //

using namespace std; // ini biar kita nggk repot2 nulis std:: berkali kali

int main()
{
    // Buat baca inputnya seng
    int M, N, P;                                   // ini deklarasinya
    cin >> M >> N;                                 // nah ini untuk bisa input
    vector<vector<char>> peta(M, vector<char>(N)); // pake vektor biar bisa bikin input 2 dimensi
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> peta[i][j];
        }
    } // nah ini harus dipake biar petanya gk kosong btw itu 3 baris harus sepaket
    cin >> P;              // ini buat input jumlah langkahnya yagesya
    cin.ignore();          // Ini buat mengabaikan karakter baris baru dari input sebelumnya (ga wajib sih)
    string gerakan;        // nah ini deklarasi yang pake tipe string
    getline(cin, gerakan); // ini buat bisa input data yang ada spasinya (klo cuma cin doang bakal stop klo nemu spasi)

    // Nah karena kita disuruh input arahnya ada pake spasi (D D R) agar input tidak eror membaca spasi kita bikin ini
    gerakan.erase(remove(gerakan.begin(), gerakan.end(), ' '), gerakan.end()); // ini buat hilangin spasi di input kita biar nggk kebaca

    // Ini set up start nya (ingat semua nilai disini adalah nilai awal yg bisa berubah di kondisi tertentu)
    int baris = 0, kolom = 0; // deklarasi tempat start ny dlu weh
    int kecepatan = 1;        // ini maskudnya 1 langkah gitu
    bool jurusTembus = false; // nah ini tipe data bool besti buat bikin true or false(btw ini di declarasi buat bisa on off nerobos pagar)
    int waktu = 0;            // waktu tempuh di start masih 0 kan blom kemana mana
    bool nabrak = false;      // Ini buat inisiasi klo robotnya nabrak

    // Memproses gerakan
    for (char arah : gerakan)
    {                                             // nah looping ini maksundya arah akan trus jalankan sampai semua input gerakan sudah di proses
        int nextBaris = baris, nextKolom = kolom; // ini deklarasi kita mau pake next baris tapi nilainya baris dan next kolom untuk kolom
        // Disini kita memasukan maksud dari perintah gerakan (simbol + untuk ke bawah dan kanan, simbol - buat apa hayyoo)
        if (arah == 'D')
        {
            nextBaris++; // satu D untuk down +1
        }
        else if (arah == 'U')
        {
            nextBaris--; // satu U untuk up -1
        }
        else if (arah == 'R')
        {
            nextKolom++; // gitu lah mirip konsep diatas
        }
        else if (arah == 'L')
        {
            nextKolom--; // sama aja
        }

        // Ini logika buat kasih output jika robot keluar area (tanda "||" artinya atau)
        if (nextBaris < 0 || nextBaris >= M || nextKolom < 0 || nextKolom >= N)
        {
            cout << "Robot nabrak, silahkan diperbaiki\n";
            return 0;
        }
        // klo ini ketika robot nabrak x
        if (peta[nextBaris][nextKolom] == 'x' && jurusTembus == false) // ini maksudnya kalau di peta koordinat [],[] ada x
        {

            // Klo ini pesan nya pas nabrak seng
            cout << "Robot nabrak, silahkan diperbaiki\n";

            continue; // buat ngelanjutin untuk memproses input berikutnya
        }
        waktu += (2 / kecepatan); // Setiap gerakan menghabiskan 2 menit
        // Jika tidak menabrak, update posisi robot
        baris = nextBaris;
        kolom = nextKolom;

        // Ini kondisi khusus
        char currentCell = peta[baris][kolom]; // kita deklarasi dulu currentCell
        if (currentCell == 'M')                // klo currentCell itu M (mechanic)
        {
            jurusTembus = true;
            cout << "Bertemu dengan mekanik, siap membasmi rintangan\n";
        }
        else if (currentCell == 'E')
        {
            kecepatan = 2;
            cout << "Bertemu dengan electrical, kecepatan roda naik menjadi 200%\n";
        }
        else if (currentCell == 'P')
        {
            cout << "Hi Programmer\n";
        }
        else if (currentCell == 'O')
        {
            waktu *= 2;
            cout << "Bertemu dengan official, diajak ngonten bareng\n";
        }

        // Cek apakah robot mencapai tujuan
        if (currentCell == 'F')
        {
            cout << "Robot berhasil mencapai tujuan\n";
            cout << "Robot telah berjalan selama " << waktu << " menit\n";
            return 0; // Selesai program
        }
    }

    // Jika robot tidak mencapai tujuan setelah semua gerakan
    cout << "Robot gagal dalam mencapai tujuan :(\n";
    cout << "Robot telah berjalan selama " << waktu << " menit\n";

    return 0;
}
