#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

//struct node
struct Node{
 int data;
 string waktu;
 string kereta;
 Node *next;
};
Node *head, *tail;

//fungsi
void menu();
void LinkedList();
void penutup();
void inisialisasi();
void insertData();
void removeData();
void bersih();
void tampil();

//pemanggilan fungsi
//fungsi utama
int main(){
 char MENU;
 int ulangMetode = 1;

 do
 {
        printf("||=======================================================================||\n");
        printf("||                      PROGRAM ABSTRAK DATA TYPE                        ||\n");
        printf("||                  (bukan android development Tool)                     ||\n");
        printf("||                      TUGAS STRUKTUR DATA TEORI                        ||\n");
        printf("||= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =||\n");
        printf("||         PROGRAM ANTRIAN KEBERANGKATAN KERETA API INDONESIA            ||\n");
        printf("||_______________________________________________________________________||\n");
        printf("||_______________________________________________________________________||\n");
        printf("||       - - - -   - - - -  - - - -  -     -  - - - -      - - - -       ||\n");
        printf("||       -         -     -  -     -  -     -  -     -            -       ||\n");
        printf("||       - - - -   - - - -  -     -  -     -  - - - -  =>>      -        ||\n");
        printf("||       -     -   -   -    -     -  -     -  -               -          ||\n");
        printf("||       - - - -   -     -  - - - -  - - - -  -              -           ||\n");
        printf("||       C o p y r i g h t @  * * C r a c k 1 2 0 1 5 _ R E V 1 2        ||\n");
        printf("||=======================================================================||\n");

        //menu pilihan
        cout<<"||+++++++++++++++++++++++++++++++++++||\n";
  cout<<"||***          MENU UTAMA         ***||\n";
        cout<<"||-----------------------------------||\n";
  cout<<"|| 1. Pendaftaran Kereta Api Rosie   ||\n";
  cout<<"|| 2. Exit                           ||\n";
        cout<<"||+++++++++++++++++++++++++++++++++++||\n";
  cout<<endl;

  printf("Masukkan Pilihan Anda ?: ");
  MENU = getche();
  printf("\n");
  getch();
        system("cls");

  switch(MENU)
  {
  case '1' :
    LinkedList();
   break;
  case '2' :
    penutup();
   break;
  default :
   {
    puts("\nKode yang dimasukkan salah!\n");
    puts("Press any key for back to the menu");
    getch();
   }
   break;
  }
 }
 while(ulangMetode == 1);
}

//menu dari metode
void menu()
{

    cout<<"||+++++++++++++++++++++++++++++++++++++++++++||\n";
    cout<<"||         ***** PILIHAN MENU *****          ||\n";
    cout<<"||-------------------------------------------||\n";
    cout<<"|| 1. Daftar Antrian Kereta Api<KODE KERETA> ||\n";
    cout<<"|| 2. Keberangkatan                          ||\n";
    cout<<"|| 3. Memberangkatkan Semua Antrian          ||\n";
    cout<<"|| 4. Lihat Daftar Antrian Kereta            ||\n";
    cout<<"|| 5. Exit                                   ||\n";
    cout<<"||+++++++++++++++++++++++++++++++++++++++++++||\n";
    cout<<endl;
}

//metode linked list
void LinkedList()
{
 char pilihMenu;
 int ulang = 1;

 do
 {
  menu();
  printf("Input Menu  : ");
  pilihMenu = getche();
  printf("\n");
  switch(pilihMenu)
  {
  case '1' :
   insertData();
   break;
  case '2' :
   removeData();
   break;
  case '3' :
   bersih();
   break;
  case '4' :
            tampil();
   break;
  case '5' :
      penutup();
   break;
  default :
   {
    puts("Input menu salah!\n");
    puts("Press any key for back to the menu");
    getch();
   }
   break;
  }
 }
 while(ulang == 1);
}

/*fungsi insialisasi bahwa
head dan tail bernilai NULL*/
void inisialisasi()
{
 head = NULL;
 tail = NULL;
}

//fungsi untuk memasukkan data
void insertData()
{
 int angka;
 string nama, jam;
 Node *nodeBaru;
 nodeBaru = new Node;

 cout<<"Masukkan kode Kereta (Angka) : ";
 cin>>angka;
 cout<<"Masukkan Nama Kereta         : ";
 cin>>nama;
 cout<<"Masukkan jam keberangkatan Kereta (HH:MM:SS:pm/am) : ";
 cin>>jam;

 nodeBaru->data = angka;
 nodeBaru->kereta = nama;
 nodeBaru->waktu = jam;
 nodeBaru->next = NULL;

 if(tail == NULL)
 {
  head = tail = nodeBaru;
  tail->next = NULL;
 }
 else
 {
  tail->next = nodeBaru;
  tail = nodeBaru;
 }

 printf("Data kereta %i masuk antrian!\n\n", angka);
 printf("%i antrian Kereta!\n\n", nama);
 printf("%i waktu antrian!\n\n", jam);
 puts("Press any key for back to the menu");
 getch();
 system("cls");
}

/*untuk hapus elemen belakang
      untuk metode LIFO*/
void removeData()
{
 int elDel;
 Node *del, *prevTail;
 del = new Node;

 if(tail != NULL)
 {
  del = tail;
  elDel = del->data;

  if(tail == head)
  {
   inisialisasi();
  }
  else
  {
   prevTail = head;

   while(prevTail->next != tail)
    prevTail = prevTail->next;

   tail = prevTail;
   tail->next = NULL;
  }

  delete del;

  printf("Data %i Kereta Diberangkatkan!\n\n", elDel);
 }
 else
 {
  puts("Data Kosong! Tidak ada data yang dapat diberangkatkan!\n");
 }

 puts("Press any key for back to the menu");
 getch();
 system("cls");
}

//untuk hapus semua elemen
void bersih()
{
 Node *clear, *point;

 if(tail != NULL)
 {
  point = head;

  while(point != NULL)
  {
   clear = point;
   point = point->next;

   delete clear;
  }

  inisialisasi();

  puts("Semua Data Kereta Diberangkatkan!\n");
 }
 else
  puts("Data Masih Kosong!\n");

 puts("Press any key for back to the menu");
 getch();
 system("cls");
}

//untuk menampilkan list data
void tampil()
{
 Node *see;

 see = head;

 if(tail != NULL)
 {
  puts("Daftar Data Antrian Kereta Api :");
  puts("");

  while(see != NULL)
  {
   printf("%i ", see->data);
   puts("");
   see = see->next;
  }
  puts("\n");
 }
 else
  puts("Data masih dalam keadaan kosong!\n");

 puts("Press any key for back to the menu");
 getch();
 system("cls");
}

//fungsi penutup / keluar
void penutup()
{
    cout<<"\n\tPROGRAM EXIT"<<endl;
    cout<<"Matur suwun geh pak dosen wess bimbing kita :"<<endl;
    cout<<" Arvin Wini Putra       : 5160411134"<<endl;
    cout<<" Gema Putranto Sudibyo  : 5160411083"<<endl;
    cout<<" Renanda Dwi Yanto      : 5160411099"<<endl;
    cout<<" 12015 Hoiron           : 5160411096"<<endl;
    cout<<"\n\tSYUKRON MASIH SEDERHANA ^___^ "<<endl;
    exit(0);
}