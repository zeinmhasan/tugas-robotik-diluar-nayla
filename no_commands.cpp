#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    int M, N, P;
    cin >> M >> N;
    vector<vector<char>> peta(M, vector<char>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> peta[i][j];
        }
    }
    cin >> P;
    cin.ignore();
    string gerakan;
    getline(cin, gerakan);

    gerakan.erase(remove(gerakan.begin(), gerakan.end(), ' '), gerakan.end());

    int baris = 0, kolom = 0;
    int kecepatan = 1;
    bool jurusTembus = false;
    int waktu = 0;
    bool nabrak = false;

    for (char arah : gerakan)
    {
        int nextBaris = baris, nextKolom = kolom;
        if (arah == 'D')
        {
            nextBaris++;
        }
        else if (arah == 'U')
        {
            nextBaris--;
        }
        else if (arah == 'R')
        {
            nextKolom++;
        }
        else if (arah == 'L')
        {
            nextKolom--;
        }

        if (nextBaris < 0 || nextBaris >= M || nextKolom < 0 || nextKolom >= N)
        {
            cout << "Robot nabrak, silahkan diperbaiki\n";
            return 0;
        }
        if (peta[nextBaris][nextKolom] == 'x' && jurusTembus == false)
        {

            cout << "Robot nabrak, silahkan diperbaiki\n";

            continue;
        }
        waktu += (2 / kecepatan);
        baris = nextBaris;
        kolom = nextKolom;

        char currentCell = peta[baris][kolom];
        if (currentCell == 'M')
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

        if (currentCell == 'F')
        {
            cout << "Robot berhasil mencapai tujuan\n";
            cout << "Robot telah berjalan selama " << waktu << " menit\n";
            return 0;
        }
    }

    cout << "Robot gagal dalam mencapai tujuan :(\n";
    cout << "Robot telah berjalan selama " << waktu << " menit\n";

    return 0;
}
