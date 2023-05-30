#include <iostream>
#include <fstream>


using namespace std;

struct mobil {
    string nama, brand, seri;
    string admin, username;
    // int tahun;
    float harga;    
};

int main() {
    mobil dijual[20];
    int pilihan, cicilan12, cicilan24, cicilan36;
    string password, username, inputn, inputpw;
    bool loop = true;
    bool adminn = false;

    while (loop == true) {
    // system ("cls");

    cout << "==== TOKO MOBIL BEKAS ABADI SEJAHTERA ====" << endl;
    cout << "\nSilahkan pilih menu" << endl;
    cout << "1. Tambah mobil" << endl;
    cout << "2. Lihat daftar mobil" << endl;
    cout << "3. Simulasi Cicilan Mobil" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu (1-4): ";
    cin >> pilihan;
    
    if (pilihan == 1) {
        int i; 
        system ("cls");
        ifstream admin;
            admin.open("loginadmin.txt", ios::binary);
            cout << "\t=====Login Admin=====" << endl;
            cout << "Username : ";
            cin >> inputn;
            cout << "Password : ";
            cin >> inputpw;
            cout << endl;

        while (!admin.eof()) {
            admin >> username >> password;
           
            if (inputn == username && inputpw == password){
                cout << "=====Tambah Mobil=====" << endl;
                cout << "Masukkan Input : ";
                cin >> i;
                cout << endl;
                    ofstream datakeluar;
                    datakeluar.open("datamobil.txt",ios::binary|ios::app);
                        cout << "Nama Brand : ";
                        cin >> dijual[i-1].brand;
                        cout << "Nama Mobil : ";
                        cin >> dijual[i-1].nama;
                        cout << "Nomor Seri : ";
                        cin >> dijual[i-1].seri;
                        cout << "Harga bekas : ";
                        cin >> dijual[i-1].harga;
                    datakeluar << dijual[i-1].brand << " " << dijual[i-1].nama << " " << dijual[i-1].seri << " " << dijual[i-1].harga << endl;
                    datakeluar.close();
                system("cls");
                adminn = true;
            }
        }

        if (adminn == false){
            cout << "Login gagal." << endl;
        }
    } else if (pilihan == 2) {
        system ("cls");
            ifstream datamasuk;
            datamasuk.open("datamobil.txt", ios::binary);
                int i = 0;
                cout << "\n=====Daftar Mobil=====\n";
                while (!datamasuk.eof() ) {
                    datamasuk >> dijual[i].brand >> dijual[i].nama >> dijual[i].seri >> dijual[i].harga;
                        cout << "Urutan ke " << i+1 << endl;
                        cout << "Nama Brand :  " << dijual[i].brand << endl;
                        cout << "Nama Mobil :  " << dijual[i].nama << endl;
                        cout << "Nomor Seri : " << dijual[i].seri << endl;
                        cout << "Harga Bekas : " << dijual[i].harga << endl;
                        cout << endl;
                    i++;
                }
            datamasuk.close();

        
    } else if (pilihan == 3) {
         ifstream datamasuk;
            datamasuk.open("datamobil.txt", ios::binary);
                int i = 0, opsicicilan, input;
                cout << "\nPilih Nomor urut mobil yang ingin dibeli\n";
                cout << "Input : ";
                cin >> input;
                
                system ("cls");
                while (!datamasuk.eof() ) {
                    datamasuk >> dijual[i].brand >> dijual[i].nama >> dijual[i].seri >> dijual[i].harga;
                    if(input-1 == i){
                        cout << "Urutan ke " << i+1 << endl;
                        cout << "Nama Brand :  " << dijual[i].brand << endl;
                        cout << "Nama Mobil :  " << dijual[i].nama << endl;
                        cout << "Nomor Seri : " << dijual[i].seri << endl;
                        cout << "Harga Bekas : " << dijual[i].harga << endl;
                        cout << endl;

                        cout << "Masukkan simulasi cicilan yang ingin dicari. \n1. 12 Bulan. \n2. 24 Bulan. \n3. 36 bulan." << endl;
                        cout << "Input : ";
                        cin >> opsicicilan;

                        if(opsicicilan == 1)
                        {
                            cicilan12 = (dijual[i].harga * 5/100 + dijual[i].harga) / 12;
                            cout << "Cicilan per bulan : ";
                            cout << cicilan12  << endl;
                        } else if(opsicicilan == 2) {
                            cicilan24 = (dijual[i].harga * 7/100 + dijual[i].harga) / 24;
                            cout << "Cicilan per bulan : ";
                            cout << cicilan24 << endl;
                        } else if(opsicicilan == 3) {
                             cicilan36 = (dijual[i].harga * 9/100 + dijual[i].harga) / 12;
                             cout << "Cicilan per bulan : ";
                            cout << cicilan36 << endl;
                        }
                    }
                    i++;
                }
            datamasuk.close();

    } else if (pilihan == 4) {
        loop = false;
        cout << "Exit";
    }
    }   
}
