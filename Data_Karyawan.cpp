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
#include <fstream>

using namespace std;

int idx = 10; //jumlah data struct
char balik;
int dex; //indeks kosong
bool urut = false;

struct data_kar
{
    string jabatan;
    string nama;
    int umur;
    string goldar;
    string alamat;
    string status;
    string jk;
};

struct data_temp //struct data_temp untuk menyimpan data_kar sementara untuk pengurutan
{
    string jabatan;
    string nama;
    int umur;
    string goldar;
    string alamat;
    string status;
    string jk;
};

data_kar karyawan[10];
data_temp temp[1];

void menu();
void simpan();

void bersihkanKonsol() //prosedur untuk menghapus akonsoltau membersihkan isi
{
    system("clear"); //mengirimkan perintah "clear" ke konsol linux
}

void kepala() //menampilkan kepala aplikasi
{
    bersihkanKonsol();
    cout << dex;
    cout << "\n\t\t\tDATA KARYAWAN\n\t\t    PT. PREI KANAN KIRI\n\n";
    cout << "=============================================================\n";
}

void tambah() //prosedur menambah data karyawan
{
    bersihkanKonsol();
    kepala();
    for (int i = 0; i < idx; i++)
    {
        if (karyawan[i].nama == "")
        {
            cout << "\nTambah data: \n";
            cout << "Nama: ";
            cin >> karyawan[i].nama;
            cout << "Umur: ";
            cin >> karyawan[i].umur;
            cout << "Gender: ";
            cin >> karyawan[i].jk;
            cout << "Alamat: ";
            cin >> karyawan[i].alamat;
            cout << "Status: ";
            cin >> karyawan[i].status;
            cout << "Jabatan: ";
            cin >> karyawan[i].jabatan;
            break;
        }
    }
    dex++;
    simpan();
    bersihkanKonsol();
    cout << "++++++++++ Tambah data sukses!! ++++++++++\n\n";
}

//ketika data yang dicari tidak ditemukan
void tidakValid() 
{
    kepala();
    cout << "[404 Not Found]\n";
    cout << "Kembali ke menu? (y/n)";
    cin >> balik;
    if (balik == 'y')
    {
        return menu();
    }
}

void terEdit()
{
    kepala();
    cout << "[Berhasil Diedit]\n";
    cout << "Kembali ke menu? (y/n)";
    cin >> balik;
    if (balik == 'y')
    {
        return menu();
    }
}

void terHapus()
{
    kepala();
    cout << "[Berhasil Dihapus]\n";
    cout << "Kembali ke menu? (y/n)";
    cin >> balik;
    if (balik == 'y')
    {
        return menu();
    }
}


void cari()
{
    kepala();
    bool ketemu = false;
    int ind = 0;
    char hapus, edit;
    string key;
    cout << "Cari data: ";
    cin >> key;
    for (int i = 0; i < dex; i++)
    {
        if (key == karyawan[i].nama)
        {
            bersihkanKonsol();
            kepala();
            cout << ">> "
                 << "\"" << karyawan[i].nama << "\""
                 << " ditemukan\n\n";
            cout << setw(5) << left << "No"
                 << setw(13) << left << "Nama"
                 << setw(8) << left << "Gender"
                 << setw(5) << left << "Umur"
                 << setw(13) << left << "Alamat"
                 << setw(10) << left << "Jabatan"
                 << setw(10) << left << "Status" << endl;
            cout << "=============================================================\n";

            if (karyawan[i].nama != "")
            {
                cout << setw(5) << left << i + 1 << setw(13) << left;
                cout << karyawan[i].nama << setw(8) << left;
                cout << karyawan[i].jk << setw(5) << left;
                cout << karyawan[i].umur << setw(13) << left;
                cout << karyawan[i].alamat << setw(10) << left;
                cout << karyawan[i].jabatan << setw(10) << left;
                cout << karyawan[i].status << endl;
            }
            ind = i;
            ketemu = true;
        }
    }
    if (ketemu == true)
    {
        int pilih;
        cout << "\n=============================================================\n";
        cout << "[1] Hapus Data\n";
        cout << "[2] Edit Data\n";
        cout << "[3] Kembali ke Menu\n";
        cout << "Pilih Aksi: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            cout << "Hapus data? (y/n)";
            cin >> hapus;
            if (hapus == 'y')
            {
                for (int i = 1; i < dex; i++)
                {
                    karyawan[i] = karyawan[i + 1];
                }
                dex--;
                simpan();
                return terHapus();
            }
            else if (hapus == 'n')
            {
                break;
                return menu();
            }
        case 2:
            cout << "Nama: ";
            cin >> karyawan[ind].nama;
            cout << "Umur: ";
            cin >> karyawan[ind].umur;
            cout << "Gender: ";
            cin >> karyawan[ind].jk;
            cout << "Alamat: ";
            cin >> karyawan[ind].alamat;
            cout << "Status: ";
            cin >> karyawan[ind].status;
            cout << "Jabatan: ";
            cin >> karyawan[ind].jabatan;
            simpan();
            return terEdit();
        case 3:
            return menu();
        }
    }
    if (ketemu != true)
    {
        return tidakValid();
    }
}
void parse_baris(string baris, int index)
{
    stringstream ss_baris(baris);
    string tem_umur;
    while (ss_baris.good())
    {
        getline(ss_baris, karyawan[index].nama, '|');
        getline(ss_baris, tem_umur, '|');
        getline(ss_baris, karyawan[index].jk, '|');
        getline(ss_baris, karyawan[index].alamat, '|');
        getline(ss_baris, karyawan[index].jabatan, '|');
        getline(ss_baris, karyawan[index].status, '|');
        karyawan[index].umur = atoi(tem_umur.c_str());
        index++;
    }
    dex = index;
}

void baca_data()
{
    string data_perbaris;
    int no_index = 0;
    ifstream infile;
    infile.open("file.dat", ios::app | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "File Tidak Ada Dan Tidak Dapat Membuat File " << endl;
    }
    else if (infile.is_open())
    {
        while (getline(infile, data_perbaris))
        {
            parse_baris(data_perbaris, no_index);
            no_index++;
        }
    }
}

void tampil()
{
    baca_data();
    ifstream infile;
    infile.open("file.dat", ios::in | ios::out | ios::app);
    int i;
    int no = 1;
    kepala();
    cout << setw(5) << left << "No"
         << setw(13) << left << "Nama"
         << setw(8) << left << "Gender"
         << setw(5) << left << "Umur"
         << setw(13) << left << "Alamat"
         << setw(10) << left << "Jabatan"
         << setw(10) << left << "Status" << endl;
    cout << "=============================================================\n";
    for (i = 0; i < idx; i++)
    {
        if (urut == true)
        {
            for (int j = i + 1; j < (dex-1); j++)
            {
                if (karyawan[i].nama > karyawan[j].nama)
                {
                    temp[1].nama = karyawan[j].nama;
                    karyawan[j].nama = karyawan[i].nama;
                    karyawan[i].nama = temp[1].nama;

                    temp[1].jk = karyawan[j].jk;
                    karyawan[j].jk = karyawan[i].jk;
                    karyawan[i].jk = temp[1].jk;

                    temp[1].umur = karyawan[j].umur;
                    karyawan[j].umur = karyawan[i].umur;
                    karyawan[i].umur = temp[1].umur;

                    temp[1].alamat = karyawan[j].alamat;
                    karyawan[j].alamat = karyawan[i].alamat;
                    karyawan[i].alamat = temp[1].alamat;

                    temp[1].jabatan = karyawan[j].jabatan;
                    karyawan[j].jabatan = karyawan[i].jabatan;
                    karyawan[i].jabatan = temp[1].jabatan;

                    temp[1].status = karyawan[j].status;
                    karyawan[j].status = karyawan[i].status;
                    karyawan[i].status = temp[1].status;
                }
            }
        }

        if (karyawan[i].nama != "")
        {
            cout << setw(5) << left << no << setw(13) << left;
            cout << karyawan[i].nama << setw(8) << left;
            cout << karyawan[i].jk << setw(5) << left;
            cout << karyawan[i].umur << setw(13) << left;
            cout << karyawan[i].alamat << setw(10) << left;
            cout << karyawan[i].jabatan << setw(10) << left;
            cout << karyawan[i].status << endl;
            no++;
            
        }
    }
    simpan();

    cout << endl;
    infile.close();
    urut = false;
}
void simpan()
{
    ofstream outfile;
    outfile.open("file.dat");
    for (int i = 0; i < idx; i++)
    {
        if (karyawan[i].nama != "")
        {
            outfile << karyawan[i].nama << "|";
            outfile << karyawan[i].umur << "|";
            outfile << karyawan[i].jk << "|";
            outfile << karyawan[i].alamat << "|";
            outfile << karyawan[i].status << "|";
            outfile << karyawan[i].jabatan << "|" << endl;
        }
    }
    outfile.close();
}

void menu()
{
    ifstream infile;
    infile.open("file.dat", ios::in | ios::out | ios::app);
    baca_data();
    infile.close();
    kepala();
    cout << "                       Pilih Menu \n";
    cout << "=============================================================\n";
    cout << "[1] Lihat Semua Data\n";
    cout << "[2] Cari Data\n";
    cout << "[3] Tambah Data\n";
    cout << "[4] Urutkan Nama Ascending\n";

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
        break;
    case 3:
        tambah();
        return menu();
        break;
    case 4:
        urut = true;
        return menu();
        break;
    }
}

int main()
{
    menu();
    return 0;
}
