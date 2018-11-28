#include <iostream>
#include <string>

using namespace std;

int elements = 1;
string key;
int terisi = 2;
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
string status[10] = {"Single", "Jones"};
char jk[10] = {'L', 'L'};

data_kar karyawan[10];

void tambah()
{
    cout << "\nTambah data: \n";
    cout << "Nama: ";
    cin >> karyawan[terisi].nama;
    cout << "Umur: ";
    cin >> karyawan[terisi].umur;
    cout << "Gender: ";
    cin >> karyawan[terisi].jk;
    cout << "Alamat: ";
    cin >> karyawan[terisi].alamat;
    cout << "Status: ";
    cin >> karyawan[terisi].status;
    cout << "Jabatan: ";
    cin >> karyawan[terisi].jabatan;
    terisi++;
    elements++;
    cout << "++++++++++ Tambah data sukses!! ++++++++++\n\n";
}
void refresh(){
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
    refresh();
    cout << "Cari data: ";
    cin >> key;
    for (int i = 0; i < (elements+1); i++)
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
            ketemu = true;
        }
    }
    if (ketemu!=true){
        cout << "########## Data tidak ditemukan ##########\n";
    }
}

void tampil()
{
    int i;
    refresh();
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

int main()
{
    cout << "\n********* Pilih Menu *********\n";
    cout << "1. Lihat Semua Data\n";
    cout << "2. Cari Data\n";
    cout << "3. Tambah Data\n";

    int pilih = 0;
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        tampil();
        return main();
        break;
    case 2:
        cari();
        break;
    case 3:
        tambah();
        return main();
        break;
    }
}