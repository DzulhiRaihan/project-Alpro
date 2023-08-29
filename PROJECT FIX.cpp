#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>

using namespace std;
long int nr, isi, ch;
struct node {
   int norek;
   char nama[100];
   string alamat;
   int saldo;
   node *next;//untuk menyimpan alamat selanjutnya
} *front = NULL, *rear, *temp;

void ins() {
   temp = new node;

   cin.ignore(1, '\n');
   cout << "Input nama\t\t: ";
   cin.getline(temp->nama, 100);
   cout << "Input alamat\t\t: ";
   getline(cin, temp->alamat);
   cout << "Input saldo awal\t: ";
   cin >> temp->saldo;

   srand(time(0));
   long int random = 0;
   random = 10000000 + (rand() % 90000000);

   temp->norek = random;
   cout << "Nomor Rekening Anda\t: ";
   cout << temp->norek;
   temp->next = NULL;

   if (front == NULL)
      front = rear = temp;
   else {
      rear->next = temp;
      rear = temp;
   }
   getch();
}

void transaksi() {
   node *temp;
   temp = front;
   int ketemu = 0;
   if (front != NULL) {
      cout << "\n Input no.rekening\t: ";
      cin >> nr;
      cout << endl;
      while (temp != NULL) {
         temp->norek;
         if (nr == temp->norek) {
         cobalagi:
            cout << " 1.Isi Saldo";
            cout << "\n 2.Tarik Tunai";
            cout << "\n Masukkan Pilihan : ";
            cin >> ch;
            if (ch == 1) {
               cout << " Saldo awal\t\t: " << temp->saldo << endl;
               cout << " Input Nominal Setoran\t: ";
               cin >> isi;
               temp->saldo = temp->saldo + isi;
               cout << " Total saldo\t\t: " << temp->saldo << endl;
               cout << " ------------------------------" << endl;
               cout << "\n";
               ketemu = 1;
            } else if (ch == 2) {
               cout << " Saldo awal\t\t: " << temp->saldo;
            lagi:
               cout << "\n Input jumlah penarikan\t: ";
               cin >> isi;
               if (temp->saldo < isi) {
                  cout << " Maaf Saldo Anda Kurang";
                  goto lagi;
               } else {
                  temp->saldo = temp->saldo - isi;
                  cout << " Sisa saldo\t\t: " << temp->saldo << endl;
                  cout << " ------------------------------" << endl;
                  cout << "\n";
               }
               ketemu = 1;
            } else {
               cout << "Pilihan Salah!\n";
               goto cobalagi;
            }
         }
         temp = temp->next;
      }
      if (ketemu == 0) {
         cout << " Data tidak ditemukan";
      }
   } else
      cout << " Belum ada nasabah!";
   getch();
}

void cek() {
   node *temp;
   temp = front;
   int ketemu = 0;
   if (front != NULL) {
      cout << "\n Input no rekening\t: ";
      cin >> nr;
      while (temp != NULL) {
         temp->norek;
         if (nr == temp->norek) {
            cout << " Sisa saldo saat ini\t: " << temp->saldo;
            ketemu = 1;
         }
         temp = temp->next;
      }
      if (ketemu == 0) {
         cout << " Data tidak ditemukan";
      }
   } else
      cout << " Belum ada nasabah!";
   getch();
}

void tampil() {
   if (front == NULL) {
      cout << " Belum ada nasabah!\n";
      getch();
   } else {
      temp = front;
      while (temp != NULL) {
         cout << " No.rek  : " << temp->norek << endl;
         cout << " Nama    : " << temp->nama << endl;
         cout << " Saldo   : " << temp->saldo << endl;
         cout << " Alamat  : " << temp->alamat << endl;
         cout << " ------------------------------" << endl;
         temp = temp->next;
      }
      getch();
   }
}

void cari() {
   node *temp;
   temp = front;
   int caridata;
   int ketemu = 0;
   if (front != NULL) {
      cout << "\n Input no.rekening yang dicari\t: ";
      cin >> caridata;
      while (temp != NULL) {
         temp->norek;
         if (caridata == temp->norek) {
            cout << "\n\n>>>  Data Yang Anda Cari Ditemukan  <<<" << endl;
            cout << " Nama\t: " << temp->nama << endl;
            cout << " Saldo\t: " << temp->saldo << endl;
            cout << " ------------------------------" << endl;
            cout << "\n\n";
            ketemu = 1;
         }
         temp = temp->next;
      }
      if (ketemu == 0) {
         cout << " Data tidak ditemukan";
      }
   } else
      cout << " Belum ada nasabah!";
   getch();
}

void delay() {
   int delay;
   delay = 1;
   while (delay < 100000000) {
      delay++;
   }
}

void loadscr() {
   int i;
   string load[7] = {"L", "O", "A", "D", "I", "N", "G"};
   for (i = 0; i <= 6; i++) {
      cout << load[i];
      delay();
   }
   sleep(2);
}
time_t local;
int main() {
   int ch, nr, isi;

   loadscr();
   while (1) {
      time(&local);
      system("cls");
      cout << "=================================================";
      cout << "\n              PROGRAM DATABASE BANK           ";
      cout << "\n            " << ctime(&local);
      cout << "_________________________________________________";
      cout << "\n                      Menu                    ";
      cout << "\n=================================================";
      cout << "\n 1.Input Data Nasabah ";
      cout << "\n 2.Transaksi";
      cout << "\n 3.Cek Saldo";
      cout << "\n 4.Tampilkan Daftar Nasabah";
      cout << "\n 5.Cari Data Nasabah";
      cout << "\n 6.Keluar";
      cout << "\n\n Masukkan Pilihan (1-6): ";
      cin >> ch;
      cout << "\n=================================================";
      cout << "\n";
      switch (ch) {
         case 1:
            ins();
            break;
         case 2:
            transaksi();
            break;
         case 3:
            cek();
            break;
         case 4:
            tampil();
            break;
         case 5:
            cari();
            break;
         case 6:
            exit(0);
            break;
         default:
            cout << "Input salah, silahkan input ulang!(press any key)";
            getch();
      }
   }
   return 0;
}
