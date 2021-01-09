//=======================================================================//
//***********    Fungsi Untuk Menampilkan Menu Absensi   ****************//
//=======================================================================//
// Nama Fungsi    : menuAbsensi                                          //
// Input Argumen  : int i, int jumlah, int jumlahhari, int tahun,        //
//                  struct pegawai { char nama[100][30], int bulan,      //
//                  int alpha, int total }                               //
// Output Argumen : int i, pegawai.nama[i], pegawai.bulan[i],            //
//                  pegawai.total[i]                                     //
// Deskripsi      : Fungsi ini untuk menampilkan menu absensi pegawai    //
// Dibuat Oleh    : Ayulia - 2005551059                                  //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl: 28-12-2020                                 Tgl: -                //
//=======================================================================//
//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk masuk ke menu pegawai
void menuPegawai(void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);

struct pegawai{
    char nama[100][30];
    int bulan, alpha, total;
}pegawai[100];

void menuAbsensi(){
	system("cls");
    menuAbsensi:;
    header();
 
    int i, jumlah, jumlahhari, tahun;
 
    printf("==================================================================\n");
    printf("***************           ABSENSI PEGAWAI          ***************\n");
    printf("==================================================================\n");
 
    printf("\nMasukkan jumlah pegawai     : ");
    scanf("%d", &jumlah);
 
    //input untuk masing-masing pegawai seperti nama dan bulannya
    printf("\n");
    for(i=1; i<=jumlah; i++){
        printf("Nama Pegawai ke-%i           : ", i);
        scanf(" %[^\n]s", &pegawai[i].nama[i][i]); fflush(stdin);
        printf("Masukkan Bulan              : ");
        scanf("%i", &pegawai[i].bulan);
 
        if(pegawai[i].bulan==1||pegawai[i].bulan==3||pegawai[i].bulan==5||pegawai[i].bulan==7||pegawai[i].bulan==8||pegawai[i].bulan==10||pegawai[i].bulan==12){
            jumlahhari=31;                                        //jika input bulan di antara bulan 1, 3, 5, 7, 8, 10, 12 yang memiliki 31 hari maka diarahkan ke sini
            printf("Masukkan Ketidakhadiran     : ");            
            scanf("%d", &pegawai[i].alpha);
            if(pegawai[i].alpha<=31){ 
                pegawai[i].total=jumlahhari-pegawai[i].alpha;
            }
            else{
                inputSalah();                                     //jika input ketidakhadiran melebihi 31 maka dianggap salah
                goto menuAbsensi;
            }
 
        }
        else if(pegawai[i].bulan==4||pegawai[i].bulan==6||pegawai[i].bulan==9||pegawai[i].bulan==11){
            jumlahhari=30;                                       //jika input bulan di antara bulan 4, 6, 9, 11 yang memiliki 30 hari maka diarahkan ke sini
            printf("Masukkan Ketidakhadiran     : ");
            scanf("%d", &pegawai[i].alpha);
            if(pegawai[i].alpha<=30){
                pegawai[i].total=jumlahhari-pegawai[i].alpha;
            }
            else{                                                //jika input ketidakhadiran melebihi 30 maka dianggap salah
                inputSalah();
                goto menuAbsensi;
            }
        }
        else if(pegawai[i].bulan==2){                            //jika input bulan 2 maka diarahkan ke sini
            printf("Masukkan Tahun              : ");
            scanf("%d", &tahun);
            if(tahun%4==0){  
            	jumlahhari=29;                                   //jika input tahun yang habis dibagi 4(kabisat) akan diarahkan ke kondisi total jumlah hari 29                                   
                printf("Masukkan Ketidakhadiran     : ");
                scanf("%d", &pegawai[i].alpha);
                if(pegawai[i].alpha<=29){
                pegawai[i].total=jumlahhari-pegawai[i].alpha;
                }
                else{
                    inputSalah();                                //jika input ketidakhadiran melebihi 29 maka dianggap salah
                    goto menuAbsensi;
                }    
            }
            else{
                jumlahhari=28;
                printf("Masukkan Ketidakhadiran     : ");
                scanf("%d", &pegawai[i].alpha);
                if(pegawai[i].alpha<=28){                        //jika input tahun yang tidak habis dibagi 4 akan diarahkan ke kondisi total jumlah hari 28
                pegawai[i].total=jumlahhari-pegawai[i].alpha;
                }
                else{
                    inputSalah();                                //jika input ketidakhadiran melebihi 28 maka dianggap salah
                    goto menuAbsensi;
                }
            }
        }
        else{
            inputSalah();
            goto menuAbsensi;
        }
 
        printf("\n");
    }
 
    //output untuk perhitungan rekap absensi
    printf("\n");
    printf("==================================================================\n");
    printf("***************          REKAP ABSENSI             ***************\n");
    printf("==================================================================\n");
    printf("%3s", "No");
    printf("%20s", "Nama Pegawai");
    printf("%20s", "Periode Bulan");
    printf("%20s\n", "Total Kehadiran");
    printf("==================================================================\n");
 
    for(i=1; i<=jumlah; i++){
        printf("%3i", i);
        printf("%20s", &pegawai[i].nama[i][i]);
        printf("%20d", pegawai[i].bulan);
        printf("%20d\n", pegawai[i].total);
    }
    printf("==================================================================\n");
 
    //rekap absensi dicetak ke file txt
    FILE * fpointerabsensi;
    fpointerabsensi=fopen("RekapAbsensi.txt", "w+");
    fprintf (fpointerabsensi, "==================================================================\n");
    fprintf (fpointerabsensi, "***************          REKAP ABSENSI             ***************\n");
    fprintf (fpointerabsensi, "==================================================================\n");
    fprintf (fpointerabsensi, "%3s", "No");
    fprintf (fpointerabsensi, "%20s", "Nama Pegawai");
    fprintf (fpointerabsensi, "%20s", "Periode Bulan");
    fprintf (fpointerabsensi, "%20s\n", "Total Kehadiran");
    for(i=1; i<=jumlah; i++){
        fprintf (fpointerabsensi, "%3i", i);
        fprintf (fpointerabsensi, "%20s", &pegawai[i].nama[i][i]);
        fprintf (fpointerabsensi, "%20d", pegawai[i].bulan);
        fprintf (fpointerabsensi, "%20d\n", pegawai[i].total);
    }
    fprintf (fpointerabsensi, "==================================================================\n");
    fclose (fpointerabsensi);
 
    system("pause");
	menuPegawai();
}