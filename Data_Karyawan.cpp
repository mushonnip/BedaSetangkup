#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

#include <fstream>
#include <sstream>

#ifdef __unix__                    /* __unix__ is usually defined by compilers targeting Unix systems */

    #define OS_Windows 0
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

#elif defined(_WIN32) || defined(WIN32)     /* _Win32 is usually defined by compilers targeting 32 or   64 bit Windows systems */

    #define OS_Windows 1
    #include <windows.h>
    #include <stdio.h>
    #include <tchar.h>
    #define DIV 1048576
    #define WIDTH 7

#endif

using namespace std;

char balik;
int dex;
int jumStruct = 10; //jumlah data struct
bool urut = false;

void menu();
void simpan();
void simpan();
void baca_data();
void menu2();
void simpanS();
void baca_pass();
void kepala();
void bersihkanKonsol();

struct data_kar
{
    string jabatan;
    string nama;
    int umur;
    string goldar;
    string alamat;
    string status;
    string jk;
    string user;
    string pass;
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

void daftar()
{
    bersihkanKonsol();
    for (int i = 0; i < jumStruct; i++)
    {
        if (karyawan[i].user == "")
        {
            cout << "\nTambah Pengguna: \n";
            cout << "Username: ";
            cin >> karyawan[i].user;
            cout << "Password: ";
            cin >> karyawan[i].pass;
            break;
        }
    }
    dex++;
    simpanS();
    bersihkanKonsol();
    cout << "++++++++++ Tambah data sukses!! ++++++++++\n\n";
}

void menu()
{
    bersihkanKonsol();
    kepala();
    ifstream infile;
    infile.open("file2.dat", ios::in | ios::out | ios::app);
    baca_pass();
    infile.close();

    string username, password, a;
    int i;
    int login = 0;
    i = 1;
    char c;
    cout << "                       Selamat Datang \n";
    cout << "=============================================================\n";
    cout << "[1] Login\n";
    cout << "[2] Daftar\n";
    cout << "[3] Exit\n";

    int pilih = 0;
    cout << "Pilih Menu: ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        kepala();
         cout << "                          LOGIN \n";
        cout << "=============================================================\n";
        cout << "| Username : ";
        cin >> username;
        cout << "| Password : ";
        cin >> password;

        login = 0;
        for (int s = 0; s < jumStruct; s++)
        {
            if (username == karyawan[s].user && password == karyawan[s].pass) // seleksi DUA KONDISI
            {
                
                login = 1;
            }
           
        }
        if (login == 1)
        {
            cout << "Anda Berhasil Login" << endl;
        }
        else
        {
            i = i + 1;
            cout << "\nUsername atau Password Salah!" << endl;
            cout << endl;
            cout << "Coba lagi? (y)  ";
            cin >> a;
            bersihkanKonsol();
            return menu();
        }
        bersihkanKonsol();
        return menu2();
        break;
    case 2:
        daftar();
        return menu();
        break;
    case 3:
        bersihkanKonsol();
        exit;
        break;
    }
}

// =================================================================================
void bersihkanKonsol() //untuk menghapus konsol atau membersihkan isi
{
    if(OS_Windows)
    {
       system("cls"); //mengirimkan perintah "cls" ke cmd
    }

    else if(!OS_Windows) // if OS is unix

    {
        system("clear"); //mengirimkan perintah "clear" ke konsol linux

    }
}

void kepala() //menampilkan kepala aplikasi
{
    bersihkanKonsol();
    cout << "\t\t\tDATA KARYAWAN\n\t\t    PT. PREI KANAN KIRI\n\n";
    cout << "=============================================================\n";
}

void tambah() //prosedur menambah data karyawan
{
    bersihkanKonsol();
    kepala();
    for (int i = 0; i < jumStruct; i++)
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
        return menu2();
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
        return menu2();
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
        return menu2();
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
//Menghapus Data
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
                return menu2();
            }
        case 2:
//Mengedit data
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
//Kembali ke menu
        case 3:
            return menu2();
        }
    }
    if (ketemu != true) //jika yang dicari tidak ada
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

void parse_pas(string baris, int index)
{
    stringstream ss_baris(baris);
    while (ss_baris.good())
    {
        getline(ss_baris, karyawan[index].user, '|');
        getline(ss_baris, karyawan[index].pass, '|');
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
void baca_pass()
{
    string data_perbaris;
    int no_index = 0;
    ifstream infile;
    infile.open("file2.dat", ios::app | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "File Tidak Ada Dan Tidak Dapat Membuat File " << endl;
    }
    else if (infile.is_open())
    {
        while (getline(infile, data_perbaris))
        {
            parse_pas(data_perbaris, no_index);
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
         << setw(10) << left << "Status"
         << setw(10) << left << "Jabatan" << endl;
    cout << "=============================================================\n";
    for (i = 0; i < jumStruct; i++)
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
            cout << karyawan[i].jabatan<< setw(10) << left;
            cout << karyawan[i].status << endl;
            no++;
            
        }
    }
    simpan();
    cout << endl;
    infile.close();
    urut = false;
}

void simpanS()
{
    ofstream outfile;
    outfile.open("file2.dat");
    for (int i = 0; i < jumStruct; i++)
    {
        if (karyawan[i].user != "")
        {
            outfile << karyawan[i].user << "|";
            outfile << karyawan[i].pass << "|" << endl;
        }
    }
    outfile.close();
}

void simpan()
{
    ofstream outfile;
    outfile.open("file.dat");
    for (int i = 0; i < jumStruct; i++)
    {
        if (karyawan[i].nama != "")
        {
            outfile << karyawan[i].nama << "|";
            outfile << karyawan[i].umur << "|";
            outfile << karyawan[i].jk << "|";
            outfile << karyawan[i].alamat << "|";
            outfile << karyawan[i].jabatan << "|";
            outfile << karyawan[i].status << "|" << endl;
        }
    }
    outfile.close();
}

void menu2()
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
    cout << "[5] Logout\n";
    cout << "[6] Exit\n";

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
            return menu2();
        }
        break;
    case 2:
        cari();
        break;
    case 3:
        tambah();
        return menu2();
        break;
    case 4:
        urut = true;
        return menu2();
        break;
    case 5:
        return menu();
        break;
    case 6:
        bersihkanKonsol();
        exit;
    }
}

int main()
{
    menu();
}
