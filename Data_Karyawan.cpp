/*
Kelompok 5 (Data Karyawan)
Abu Mushonnip [1805001]
Ade Irawan [1805003]
Aldini Eka Putri [1805004]
Faisal Basri [1805010]
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int idxKosong = 1;
string key;
bool ketemu = true;
char balik;
struct data_kar
{
    string jabatan;
    string nama;
    int umur;
    string goldar;
    string alamat;
    string status;
    char jk;
};

string jabatan[10] = {"Kepala", "Anggota"};
string nama[10] = {"Abu", "Ade"};
int umur[10] = {19, 20};
string goldar[10] = {"O", "A"};
string alamat[10] = {"Indramayu", "Indramayu"};
string status[10] = {"Mbuh", "Mbuh"};
char jk[10] = {'L', 'L'};

data_kar karyawan[10];
void menu();
void ndas()
{
    system("clear");
    cout << "\n\t\t\tDATA KARYAWAN\n\t\t    PT. PREI KANAN KIRI\n\n";
    cout << "=============================================================\n";
}
void tambah()
{
    system("clear");
    ndas();
    cout << "\nTambah data: \n";
    cout << "Nama: ";
    cin >> karyawan[idxKosong + 1].nama;
    cout << "Umur: ";
    cin >> karyawan[idxKosong + 1].umur;
    cout << "Gender: ";
    cin >> karyawan[idxKosong + 1].jk;
    cout << "Alamat: ";
    cin >> karyawan[idxKosong + 1].alamat;
    cout << "Status: ";
    cin >> karyawan[idxKosong + 1].status;
    cout << "Jabatan: ";
    cin >> karyawan[idxKosong + 1].jabatan;
    //terisi++;
    idxKosong++;
    system("clear");
    cout << "++++++++++ Tambah data sukses!! ++++++++++\n\n";
}
void refresh()
{
    for (int i = 0; i <= 1; i++)
    {
        karyawan[i].nama = nama[i];
        karyawan[i].jabatan = jabatan[i];
        karyawan[i].umur = umur[i];
        karyawan[i].goldar = goldar[i];
        karyawan[i].alamat = alamat[i];
        karyawan[i].status = status[i];
        karyawan[i].jk = jk[i];
    }
}
void raKetemu()
{
    ndas();
    cout << "[404 Not Found]\n";
    cout << "Kembali ke menu? (y/n)";
        cin >> balik;
        if (balik == 'y')
        {
            return menu();
        }
}
void diedit(){
    cout << "[Berhasil Diedit]\n";
    cout << "Kembali ke menu? (y/n)";
        cin >> balik;
        if (balik == 'y')
        {
            return menu();
        }
}
void cari()
{
    ndas();
    ketemu = false;
    int ind, anu = 0;
    char hapus, edit;
    cout << "Cari data: ";
    cin >> key;
    for (int i = 0; i < (idxKosong + 1); i++)
    {
        if (key == karyawan[i].nama)
        {
            cout << "[Data ditemukan]\n";
            cout << "Nama\t: " << karyawan[i].nama << endl;
            cout << "Umur\t: " << karyawan[i].umur << endl;
            cout << "Goldar\t: " << karyawan[i].goldar << endl;
            cout << "Alamat\t: " << karyawan[i].alamat << endl;
            cout << "Status\t: " << karyawan[i].status << endl;
            cout << "Gender\t: " << karyawan[i].jk << endl;
            cout << "Jabatan\t:" << karyawan[i].jabatan << endl;
            cout << endl;
            ind = i;
            ketemu = true;
        }
        anu = i;
    }
    if (ketemu == true)
    {
        char pilih;
        cout << "=============================================================\n";
        cout << "[1] Hapus Data\n";
        cout << "[2] Edit Data\n";
        cout << "[3] Kembali ke Menu\n";
        cout << "Pilih Aksi: ";
        cin >> pilih;
        if (pilih == '1')
        {
            cout << "Hapus data? (y/n)";
            cin >> hapus;
            if (hapus == 'y')
            {
                for (int i = ind; i < (idxKosong + 1); i++)
                {
                    karyawan[i] = karyawan[i + 1];
                }
                idxKosong--;
                //system("clear");
                cout << "--------- Berhasil Dihapus ------------\n";
            }
            else if (hapus== 'n'){
                return menu();
            }
        }
        else if (pilih == '2')
        {
            for (int i = ind; i < idxKosong; i++)
            {
                cout << "Nama: ";
                cin >> karyawan[anu - 1].nama;
                cout << "Umur: ";
                cin >> karyawan[anu - 1].umur;
                cout << "Gender: ";
                cin >> karyawan[anu - 1].jk;
                cout << "Alamat: ";
                cin >> karyawan[anu - 1].alamat;
                cout << "Status: ";
                cin >> karyawan[anu - 1].status;
                cout << "Jabatan: ";
                cin >> karyawan[anu - 1].jabatan;
                //idxKosong++;
            }
            //idxKosong--;
            //system("clear");
            return diedit();
        }
        else if (pilih == '3')
        {
            return menu();
        }
    }

    if (ketemu != true)
    {
        return raKetemu();
    }
}

void tampil()
{
    int i;
    ndas();
    //cout << "\n\t\t\tDATA KARYAWAN\n\t\t    PT. PREI KANAN KIRI\n\n";
    //cout << "=============================================================\n";
    cout << setw(5) << left << "No"
         << setw(13) << left << "Nama"
         << setw(8) << left << "Gender"
         << setw(5) << left << "Umur"
         << setw(13) << left << "Alamat"
         << setw(10) << left << "Jabatan"
         << setw(10) << left << "Status" << endl;
    cout << "=============================================================\n";
    for (i = 0; i < (idxKosong + 1); i++)
    {
        cout << setw(5) << left << i + 1 << setw(13) << left << karyawan[i].nama << setw(8) << left << karyawan[i].jk << setw(5) << left << karyawan[i].umur;
        cout << setw(13) << left << karyawan[i].alamat << setw(10) << left << karyawan[i].jabatan << setw(10) << left << karyawan[i].status << endl;
    }
    cout << endl;
    /*
    for (int i = 0; i <= idxKosong; i++)
    {   
        cout << "[" << i + 1 << "] =========" << endl;
        cout << "Nama\t:" << karyawan[i].nama << endl;
        cout << "Gender\t:" << karyawan[i].jk << endl;
        cout << "Umur\t:" << karyawan[i].umur << endl;
        cout << "Alamat\t:" << karyawan[i].alamat << endl;
        cout << "Jabatan\t:" << karyawan[i].jabatan << endl;
        cout << "Status\t:" << karyawan[i].status << endl;
        cout << endl;
        

    }*/
}
void menu()
{
    ndas();
    //cout << "=============================================================\n";
    cout << "                       Pilih Menu \n";
    cout << "=============================================================\n";
    cout << "[1] Lihat Semua Data\n";
    cout << "[2] Cari Data\n";
    cout << "[3] Tambah Data\n";

    int pilih = 0;
    cout << "\nPilih Menu: ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        tampil();
        cout << "Kembali ke menu? (y/n)";
        cin >> balik;
        if (balik == 'y')
        {
            return menu();
        }
        break;
    case 2:
        cari();
        //return raKetemu();
        break;
    case 3:
        tambah();
        return menu();
        break;
    }
}
int main()
{
    refresh();
    menu();
    return (0);
}