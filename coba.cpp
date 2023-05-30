#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct node
{
    char name[100];
    int tahun;
    long long harga;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;

struct node *createNode(char name[], int tahun, long long harga)
{
    struct node *newNode = new node;
    strcpy(newNode->name, name);
    newNode->tahun = tahun;
    newNode->harga = harga;
    newNode->next = NULL;
    return newNode;
}

void insert(char name[], int tahun, long long harga)
{
    struct node *newNode = createNode(name, tahun, harga);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *current = head;
        struct node *previous = NULL;
        while (current != NULL)
        {
            if (strcmp(current->name, name) == 0)
            {
                newNode->next = current->next;
                current->next = newNode;
                cout << "Data Berhasil Ditambahkan" << endl;
                // return;
            }
            previous = current;
            current = current->next;
        }
        newNode->next = previous->next;
        previous->next = newNode;
    }
}

void saveDataToFile()
{
    ofstream outputFile("datamobil.txt"); // Nama file yang akan digunakan, bisa disesuaikan

    if (!outputFile)
    {
        cout << "Gagal membuka file!" << endl;
        // return;
    }

    struct node *temp = head;
    while (temp != NULL)
    {
        outputFile << "Nama: " << temp->name << endl;
        outputFile << "Usia: " << temp->tahun << endl;
        outputFile << "Harga: " << temp->harga << endl;
        outputFile << "-----------------" << endl;
        temp = temp->next;
    }

    outputFile.close();
    cout << "Data berhasil disimpan ke dalam file!" << endl;
}

void deleteByName(char name[])
{
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (previous == NULL)
            {
                head = current->next;
                delete current;
                cout << "Data berhasil dihapus" << endl;
                return;
            }
            else
            {
                previous->next = current->next;
                delete current;
                cout << "Data berhasil dihapus" << endl;
                return;
            }
        }
        previous = current;
        current = current->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

void update(char name[], char newName[], long long newHarga, int newTahun)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            strcpy(current->name, newName);
            current->tahun = newTahun;
            current->harga = newHarga;
            cout << "Data berhasil diubah" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

void displayData()
{
    ifstream inputFile("datamobil.txt"); // Nama file yang akan dibaca, bisa disesuaikan

    if (!inputFile)
    {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    char line[100];
    while (inputFile.getline(line, 100))
    {
        cout << line << endl;
    }

    inputFile.close();
}

int main()
{
    int choice, adminchoice;
    char name[100], adminloop;
    int tahun;
    long long harga;
    char newName[100];
    int newTahun;
    long long newHarga;
    bool adminn = false;
    string inputn, inputpw, password, username;

    do
    {
        // system("cls");
        cout << "==== TOKO MOBIL BEKAS ABADI SEJAHTERA ====" << endl;
        cout << "\nSilahkan pilih menu" << endl;
        cout << "0. Login Admin" << endl;
        cout << "1. Tampilkan data" << endl;
        // cout << "2. Simulasi Cicilan Mobil" << endl;
        cout << "2. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            system("cls");
            ifstream adminlogin;
            adminlogin.open("loginadmin.txt", ios::binary);
            cout << "\t=====Login Admin=====" << endl;
            cout << "Username : ";
            cin >> inputn;
            cout << "Password : ";
            cin >> inputpw;
            cout << endl;

            while (!adminlogin.eof())
            {
                adminlogin >> username >> password;

                if (inputn == username && inputpw == password)
                {
                    do { 
                    cout << "1. Tambah Mobil" << endl;
                    cout << "2. Hapus data" << endl;
                    cout << "3. Ubah data" << endl;
                    cout << "Masukkan pilihan Anda: ";
                    cin >> adminchoice;
                    cin.ignore();

                    switch (adminchoice)
                    {
                    case 1:
                        cout << "Masukkan Nama Mobil: ";
                        // cin.ignore();
                        cin.getline(name, 30);
                        cout << "Masukkan Tahun Pembuatan : ";
                        cin >> tahun;
                        cout << "Masukkan Harga Mobil : ";
                        cin >> harga;
                        insert(name, tahun, harga);
                        saveDataToFile();
                        cout << "Data berhasil ditambahkan!" << endl;
                        system("cls");
                        break;

                    case 2:
                        cout << "Masukkan Nama Mobil yang ingin dihapus datanya : ";
                        // cin.ignore();
                        cin.getline(name, 30);
                        deleteByName(name);
                        cout << "Data berhasil dihapus!" << endl;
                        break;

                    case 3:
                        cout << "Masukkan Nama Mobil yang ingin diubah datanya : ";
                        // cin.ignore();
                        cin.getline(name, 30);
                        cout << "Masukkan Nama Mobil Baru: ";
                        cin.getline(newName, 30);
                        cout << "Masukkan Tahun Pembuatan : ";
                        cin >> newTahun;
                        cout << "Masukkan Harga Mobil Baru : ";
                        cin >> newHarga;
                        update(name, newName, newHarga, newTahun);
                        cout << "Data berhasil diubah!" << endl;
                        break;
                    } 
                        cout << "Tekan y untuk menambahkan lagi!" ;
                        cin >> adminloop;
                        } while (adminloop == 'y');

                    }
                    adminn = true;
                }
            if (!adminn)
            {
                cout << "Login gagal." << endl;
            }
            adminlogin.close();
        }
        break;
        case 1:
        {
            system("cls");
            cout << "==== List Mobil Yang Tersedia ====" << endl;
            displayData();
        }
        break;
        // case 2:
        // {
        //     system("cls");
        // }
        // break;
        case 2:
        {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 2);

    return 0;
}
