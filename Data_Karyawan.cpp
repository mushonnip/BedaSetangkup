/*
Kelompok 5 (Data Karyawan)
Abu Mushonnip [1805001]
Ade Irawan [1805003]
Aldini Eka Putri [1805004]
Faisal Basri [1805010]
*/

#include <iostream>
#include <string>

using namespace std;

int elements = 1;
string key;
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

void tambah()
{
    cout << "\nTambah data: \n";
    cout << "Nama: ";
    cin >> karyawan[elements + 1].nama;
    cout << "Umur: ";
    cin >> karyawan[elements + 1].umur;
    cout << "Gender: ";
    cin >> karyawan[elements + 1].jk;
    cout << "Alamat: ";
    cin >> karyawan[elements + 1].alamat;
    cout << "Status: ";
    cin >> karyawan[elements + 1].status;
    cout << "Jabatan: ";
    cin >> karyawan[elements + 1].jabatan;
    //terisi++;
    elements++;
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
void cari()
{
    bool ketemu = false;
    int ind = 0;
    char hapus;
    cout << "Cari data: ";
    cin >> key;
    for (int i = 0; i < (elements + 1); i++)
    {
        if (key == karyawan[i].nama)
        {
            cout << "########## Data ditemukan ##########\n";
            cout << "Nama: " << karyawan[i].nama << endl;
            cout << "Umur: " << karyawan[i].umur << endl;
            cout << "Golongan Darah: " << karyawan[i].goldar << endl;
            cout << "Alamat: " << karyawan[i].alamat << endl;
            cout << "Status: " << karyawan[i].status << endl;
            cout << "Jenis Kelamin: " << karyawan[i].jk << endl;
            cout << "Jabatan : " << karyawan[i].jabatan << endl;
            cout << endl;
            ind=i;
            ketemu = true;
        }
    }
    if (ketemu == true)
    {
        cout<<"Hapus data? (y/n)";
        cin>>hapus;
        if (hapus == 'y')
        {
            for (int i = ind; i < (elements + 1); i++)
            {
                karyawan[i] = karyawan[i + 1];
            }
            elements--;
            //system("clear");
            cout<<"--------- Berhasil Dihapus ------------\n";
        }
    }
    if (ketemu != true)
    {
        //system("clear");
        cout << "########## Data tidak ditemukan ##########\n";
    }
}

void tampil()
{
    for (int i = 0; i <= elements; i++)
    {
        cout << "[" << i + 1 << "] =========" << endl;
        cout << "Nama\t:" << karyawan[i].nama << endl;
        cout << "Gender\t:" << karyawan[i].jk << endl;
        cout << "Umur\t:" << karyawan[i].umur << endl;
        cout << "Alamat\t:" << karyawan[i].alamat << endl;
        cout << "Jabatan\t:" << karyawan[i].jabatan << endl;
        cout << "Status\t:" << karyawan[i].status << endl;
        cout << endl;
    }
}
void menu()
{
    cout << "\n********* Pilih Menu *********\n";
    cout << "1. Lihat Semua Data\n";
    cout << "2. Cari dan Hapus Data\n";
    cout << "3. Tambah Data\n";

    int pilih = 0;
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        tampil();
        return menu();
        break;
    case 2:
        cari();
        return menu();
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
    return(0);
}