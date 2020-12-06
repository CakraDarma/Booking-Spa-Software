#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
 
 
//prtotipe program
void judul (void);
void header(void);
void menuCostumer(void);
void menuJasa(void);
void menuBantuan(void);
void inputSalah(void);
void tampilkanRincianJasa1(void);
void tampilkanRincianJasa2(void);
void tampilkanRincianJasa3(void);
void tampilkanRincianJasa4(void);
void tampilkanRincianJasa5(void);
void tampilkanRincianJasa6(void);
void tampilkanRincianJasa7(void);
void cetakKuitansi(const char * namaPelanggan, const char * noHp, const char * alamat, const char * namaJasa, int harga, int bayarDp);
void login(void);
void menuPegawai(void);
void menuKasir(void);
void tampilkantotalharga(int totalhargakeseluruhan);
int hitungsisapembayaran(int totalhargakeseluruhan, int DP);
void tampilkansisapembayaran(int sisapembayaran);
int hitungkembali(int pembayaran, int totalhargakeseluruhan);
void tampilkankembali(int kembali, int pembayaran, int sisapembayaran, int totalhargakeseluruhan);
void cetaknota(const char * namaPelanggan, const char * noHp, int i, int jumlah[100], int harga[100], int totalharga[100], char namapaket[100], int totalhargakeseluruhan, int DP, int pembayaran, int kembali, int paket, int sisapembayaran);
void detailpembelian(char namaPelanggan[100], char noHp[100], char namapaket[100], int i, int paket, int harga[100], int jumlah[100], int totalharga[100], int totalhargakeseluruhan, int DP, int pembayaran);
 
int main() {
	judul();
	login();
return 0;
}
 
 //tampil awal
void judul(void){
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t|================================================|\n");
	printf("\t\t|              Program Pemesanan SPA             | \n");
	printf("\t\t|================================================|\n");
	getch();
	system("cls");
	printf ("\t\n\n\n\n\n\n\n\n\t\t\tSELAMAT DATANG DI RAYURI SPA \n"); //Halaman awal bagian pemesanan dengan nama hotel
	printf("\t\t\t   WELCOME TO RAYURI SPA");
	getch();
}
 
//header program
void header(void){
	printf("\n\n\nRayuri SPA\n");
	printf("Jl. Kenangan No.666\n");
	printf("No. Telp 08123456789\n");
	printf("****************************************************\n");
}
 
void login(void){
	//login belum selesai
	system("cls");
 
	int pilihPengguna;
	char UsernamePegawai [50];
	char UsernameCostumer [50];
	char passwordPegawai [50];
	char passwordCostumer [50];
 
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tRayuri Spa\n\n");
	printf("\t\t\t\t[1] Costumer\n");
	printf("\t\t\t\t[2] Staff\n");
	scanf("%d",&pilihPengguna);
	if(pilihPengguna == 1){
		menuCostumer();
	}
	else if(pilihPengguna == 2){
		menuPegawai();
	}
}
 
//main menu
void menuCostumer(void){
	system("cls");
	header();
	int menuCostumer;
	printf ("|=============================================|\n");
	printf ("|                  MENU UTAMA                 |\n");
	printf ("|=============================================|\n");
	printf ("|[1] DAFTAR PAKET                             |\n");
	printf ("|[2] DAFTAR HISTORI                           |\n");
	printf ("|[3] GATAU                                    |\n");
	printf ("|[4] GATAU                                    |\n");
	printf ("|[5] GATAU                                    |\n");
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|[6] BANTUAN                                  |\n"); // Jika bingung dengan program ini, dapat menggunakan tombol bantuan
	printf ("|[7] KELUAR                                   |\n"); // Pilihan exit yang dapat digunakan user sebagai pilihan untuk menutup program
	printf ("=============================================== \n");
	printf ("Silahkan pilih : "); // Memilih Jasa yang diinginkan
	scanf("%d", &menuCostumer);
	//memilih menu
		if(menuCostumer==1){
			menuJasa();
		}
		else if(menuCostumer==6){
			menuBantuan();
		}
		else if(menuCostumer==7){
			system("cls");
			printf("Anda Telah Keluar Dari Program\n");
			exit(0);
		}
		else{
 
   			inputSalah();
		}
}
 
//menu jasa
void menuJasa(void){
	system("cls");
	header();
	const  float dp = 0.5;
	const char * namaJasa;
 
	int menuJasa, bayarDp, harga;
	char teruskanPemesanan;
 
	printf ("|=============================================|\n");
	printf ("|                  DAFTAR PAKET               |\n");
	printf ("|=============================================|\n");
	printf ("|[1] SIMPLE SENSE             Rp.  190.000,-  |\n");
	printf ("|[2] SERENITY SENSE           Rp.  205.000,-  |\n");
	printf ("|[3] REFRESH SENSE            RP.  265.000,-  |\n");
	printf ("|[4] FIRMING SENSE            Rp.  330.000,-  |\n");
	printf ("|[5] BALANCE SENSE            Rp.  370.000,-  |\n");
	printf ("|[6] DETOX SENSE              Rp.  530.000,-  | \n");
	printf ("|[7] ABSOLUTE SENSE           Rp.  580.000,-  |\n");
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|[8] RINCIAN                                  |\n"); // Pilih untuk melihat rincian jasa
	printf ("|[9] KEMBALI                                  |\n"); // Pilihan untuk kembali ke sebelumnya
	printf ("=============================================== \n");
	printf ("Silahkan pilih : "); // Memilih Jasa yang diinginkan
	scanf("%d", &menuJasa);
 
	system ("cls");
	// insialisasi harga dan nama jasa
	if(menuJasa==1){
		harga = 190000;
		namaJasa = "SIMPLE SENSE";
		system("cls");
		tampilkanRincianJasa1();
		getch();
 	}
	else if(menuJasa==2){
		harga = 205000;
		namaJasa = "SERENITY SENSE";
		system("cls");
		tampilkanRincianJasa2();
		getch();
	}
	else if(menuJasa==3){
		harga = 265000;
		namaJasa = "REFRESH SENSE";
		system("cls");
		tampilkanRincianJasa3();
		getch();
	}
	else if(menuJasa==4){
		harga = 330000;
		namaJasa = "FIRMING SENSE";
		tampilkanRincianJasa4();
		getch();
	}
	else if(menuJasa==5){
		harga = 370000;
		namaJasa = "BALANCE SENSE";
		system("cls");
		tampilkanRincianJasa5();
		getch();
	}
	else if(menuJasa==6){
		harga = 530000;
		namaJasa = "DETOX SENSE";
		system("cls");
		tampilkanRincianJasa6();
		getch();
	}
	else if(menuJasa==7){
		harga = 580000;
		namaJasa = "ABSOLUTE SENSE";
		system("cls");
		tampilkanRincianJasa7();
		getch();
	}
	else if(menuJasa==8){
   		int pilih;
   		printf("gatau ni mau isi apa kaden");
   		printf ("\n\n[1] KEMBALI \n");
   		if(pilih == 1){
   			menuCostumer();
   		}
   	}
   	else if(menuJasa == 9){
   		menuCostumer();
   	}
 
	//lanjut ke pembayaran
	bayarDp = dp * harga;
	char namaPelanggan[100] ;
	char noHp[20];
	char alamat[50];
	printf("|====================================================|\n");	
	printf(" Anda Memilih                  : %s\n",namaJasa);
	printf(" Total Harga                   : %d\n",harga);
	printf("|====================================================|\n\n");	
	printf(" DP                            : %d\n",bayarDp);
	printf(" Teruskan Pemesanan? (y/n)     : ");
	getchar();
	teruskanPemesanan = getchar();
	printf("|====================================================|\n\n");	
 
	if(teruskanPemesanan == 'y'||teruskanPemesanan == 'Y'){
		system("cls");
		printf("\n\n");
		printf("       Anda Sudah Masuk Ke menu Pemsesanan \n\n");
		printf("Silahkan Isi Data Diri Anda\n");
		printf(" Nama                          : "); fflush(stdin);
		gets(namaPelanggan);
		printf(" No Telepon                    : "); fflush(stdin);
		gets(noHp);
		printf(" Alamat                        : "); fflush(stdin);
		gets(alamat);
		printf("|====================================================|\n\n");	
		printf("Transaksi Sudah Dicatat\n");
		printf("Pastikan Anda Datang Tepat Waktu\n");
		cetakKuitansi(namaPelanggan,noHp,alamat,namaJasa,harga,bayarDp);
		getchar();
		menuCostumer();
	}
	else if(teruskanPemesanan == 'n'||teruskanPemesanan == 'N'){
		menuCostumer();
	}
 
}
 
 
void menuBantuan(void){
	system("cls");
	header();
	int bantuan;
	printf("\n    MENU BANTUAN\n\n");
 	printf("[1] Tentang program\n"); // Menjelaskan tentang program pemesanan kamar hotel
 	printf("[2] Cara Menggunakan\n"); // Menjelaskan cara menggunakan program pemesanan kamar hotel
 	printf("[3] Kembali\n\n");  // Kembali pada menu utama
 	printf("Silahkan pilih :"); // User diminta untuk memilih pilihan diantara 3 pilihan tersebut
 	scanf("%d",&bantuan);
 
 	//memilih di menu bantuan
 	switch(bantuan){
		 // Penjelasan tentang Program Pemesanan SPA
 		case 1:
		system("cls");
		header();
 		int tentangProgram;
		printf ("|====================================================|\n");
   		printf ("|Program ini bertujuan untuk memesan SPA dengan mudah|\n");
		printf ("|====================================================|\n");
   		printf ("|[1] KEMBALI                                         |\n");
		printf ("|                                                    |\n");
		printf ("|====================================================|\n");
   		printf("\nSILAHKAN PILIH: ");
 		scanf("%d",&tentangProgram);
	 		if(tentangProgram==1){
	 			menuCostumer();
	 		}
 		// Penjelasan tentang tata cara Program pemesanan SPA  
  		case 2:
		system("cls");
		header();
  		int caraMenggunakan;
		printf("|=============================================================|\n");
  	    printf("|Inputkan angka pada menu utama sesuai kebutuhan,             |\n");
   		printf("|Membuat akun untuk mendapatkan diskon 5 persen,              |\n"); 
   		printf("|Pengguna kartu member akan diberi discount sebesar 20 persen.|\n");
		printf("|=============================================================|\n");
   		printf("|[1] KEMBALI                                                  |\n");
		printf("|                                                             |\n");
		printf("|=============================================================|\n");
   		printf("\nSILAHKAN PILIH: ");
 		scanf("%d",&caraMenggunakan);
	   		if(caraMenggunakan==1){
	 			menuCostumer();
	 		}
   		//kembali ke menu utama
	    case 3:
   		menuCostumer();
 
 	}
 
}
 
//input salah
void inputSalah(void){
	system("cls");
	header();
	int inputSalah;
	printf("\nINPUT ANDA SALAH");
	printf("\n\n\n");
	printf("[1] KEMBALI\n\n");
	printf("SILAHKAN PILIH");
	scanf("%d",&inputSalah);
	if(inputSalah==1){
		menuCostumer();
	}	
}
 
//cetak kuitansi
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * alamat, const char * namaJasa, int harga, int bayarDp){
    //kuitansi
    time_t ambil_waktu1;
    time(&ambil_waktu1);
    FILE * fpointer;
    fpointer=fopen("kuitansi.txt", "w+"); 
    fprintf(fpointer,"%s",ctime(&ambil_waktu1));
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"|                    RAYURI SPA                        |\n");
    fprintf(fpointer,"|                 Kota Denpasar                        |\n");
    fprintf(fpointer,"|                Telp. 08123456789                     |\n");
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"| Bukti Pemesanan Paket Spa                            |\n");                
    fprintf(fpointer,"  Nama Pelanggan                            : %s\n",namaPelanggan);                
    fprintf(fpointer,"  No Telepon                                : %s\n",noHp);                
    fprintf(fpointer,"  Alamat                                    : %s\n",alamat);                
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"  %s\n",namaJasa);                
    fprintf(fpointer,"| Total Harga                               : %d\n",harga);
    fprintf(fpointer,"| DP                                        : %d\n",bayarDp);
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"| LUNAS                                                |\n");
    fprintf(fpointer,"========================================================\n");
    fclose(fpointer);
 }
 
//menampilkan rincian jasa
void tampilkanRincianJasa1(void){
	printf("                                   SIMPLE SENSE\n\n");
	printf("                 Body Massage with aromatherapy and face massage\n\n");
	printf("Perawatan ini disarankan untuk para pekerja yang sibuk dan tetap harus berpenampilan prima.\n");
	printf("Perawatan dimulai dengan pijat badan dengan aromatherapy dan dilanjutkan dengan pijat wajah.\n");
	printf("                               1.5 hours Rp 190.000,-\n");
}
 
void tampilkanRincianJasa2(void){
	printf("                                  SERENITY SENSE\n\n");
	printf("                     Body massage with aromatherphy and Body scrub\n\n");
	printf("Temukan kedamaian dalam diri Anda. Paket perawatan ini didesain untuk pelanggan yang ingin\n");
	printf("sepenuhnya relaks dan menjaga kesehatan kulit anda. Perawatan dimulai dari aromaterapi pijat\n");
	printf("badan untuk merilekskan badan dan pikiran, dilanjutkan dengan pilihan lulur untuk membersihkan\n");
	printf("                      kulit mati dan dilanjutkan dengan shower.\n\n");
	printf("                                1.5 Hours Rp 205.000,-\n\n");
}
 
void tampilkanRincianJasa3(void){
	printf("                                  REFRESH SENSE\n\n");
	printf("                Body Massage (Traditional), Face Massages, Luxury Bath\n\n");
	printf("Perawatan ini membantu untuk mengembalikan kesegaran tubuh anda. Dimulai dengan pilihan pijat\n");
	printf("  badan dan dilanjutkan dengan pijat wajah kemudian dilanjutkan dengan jenis rendaman yang\n");
	printf("                                 diinginkan.\n\n");
	printf("                             1 Hour Rp 265.000,-\n\n");
}
 
void tampilkanRincianJasa4(void){
	printf("                                 BALANCE SENSE\n\n");
	printf("                 Body massage, Body steam, Body Mask, Ear Candling\n\n");
	printf("Paket ini didesain untuk menyeimbangkan system tubuh dan menyegarkan tubuh. Perawatan\n");
	printf("dimulai dengan pijat badan dengan aromatherapy dan dilanjutkan dengan penguapan badan dan\n");
	printf("                   setelahnya dimasker dan terapi telinga.\n\n");
	printf("                              2 Hours Rp 370.000,- \n\n");
}
 
void tampilkanRincianJasa5(void){
	printf("                                 DETOX SENSE\n\n");
	printf("              Body Massage, Body steam, Body Scrub, Body Mask, Bathing\n\n");
	printf("Perawatan ini membantu mengeluarkan racun-racun dan lemak pada tubuh. Dianjurkan untuk\n");
	printf("mengambil paket ini sebanyak 10 kali unruk hasil yang maksimal dan dilakukan seminggu sekali.\n");
	printf("Perawatan ini dimulai dari pijat badan dengan aromaterapi, kemudian dilanjutkan dengan, lulur,\n");
	printf("                 masker dan terakhir dengan mandi berendam.\n\n");
	printf("                             2.5 Hours Rp 530.000,- \n\n");
 
}
 
void tampilkanRincianJasa6(void){
	printf("                                FIRMING SENSE\n\n");
	printf("                      Body scrub, Body mask, Body wrapping\n\n");
	printf("Perawatan ini didesin untuk mengembalikan dan menjaga elastisitas kulit. Paket ini cocok untuk\n");
	printf("anda yang ingin menjaga kekenyalan kulit selagi menguruskan badan. Perwatan dimulai dari luluran\n");
	printf("untuk mengangkat sel-sel kulit mati, dilanjutkan dengan body masker,kemudian dibungkus dengan\n");
	printf("                          menggunakan selimut elektrik.\n");
	printf("                              1.5 Hours Rp 330.000,- \n\n");
}
 
void tampilkanRincianJasa7(void){
	printf("                              ABSOLUTE SENSE\n\n");
	printf("     Body steam, Body scrub, Body mask, Bathing, Body & Face Massage\n\n");
	printf("Ini merupakan perrawatan yang komplit dari kita untuk membantu anda mengembalikan kecantikan\n");
	printf("diri dan ketenangan pikiran. Dimulai dari pijat badan dan muka, dilanjutkan dengan steam dan lulur\n");
	printf("   untuk membersihkan kulit-kulit yang mati dan dilanjutkan dengan masker badan untuk\n");
	printf("      mendinginkan kulit dan membuatnya bercahaya dan diakhiri oleh mandi berendam.\n\n");
	printf("                           3 Hours Rp 580.000,- \n\n");
}
 
void menuPegawai(void){
	system("cls");
	header();
	int menuJasa;
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|=============================================|\n");
	printf ("|[1] KASIR                                    |\n");
	printf ("|[2]   |\n");
	printf ("|[3]   |\n");
	printf ("|[4]   |\n");
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|[8] RINCIAN                                  |\n"); // Pilih untuk melihat rincian jasa
	printf ("|[9] KELUAR                                   |\n"); // Pilihan untuk Keluar ke sebelumnya
	printf ("=============================================== \n");
	printf ("Silahkan pilih : "); // Memilih Jasa yang diinginkan
	scanf("%d", &menuJasa);
 
	if(menuJasa == 1){
		menuKasir();
	}
	else if(menuJasa == 9){
 
	}
}
 
void menuKasir(void){
	system("cls");
	char namaPelanggan[100], noHp[100], namapaket[100];
	int i, paket, harga[100], jumlah[100], totalharga[100], totalhargakeseluruhan = 0, DP, pembayaran;
    //detailpembelian(namaPelanggan, noHp, namapaket, i, paket, harga, jumlah, totalharga, totalhargakeseluruhan, DP, pembayaran);
    totalhargakeseluruhan = 0;
	header();
    printf("Nama Pelanggan              : ");
    scanf(" %[^\n]s",namaPelanggan);
    printf("No Hp                       : ");
    scanf(" %[^\n]s",noHp);
 
    printf("========================================================\n");
	printf("Total Jumlah Paket          : ");
	scanf("%i", &paket);
    printf(" \n");
 
	for(i=1; i<=paket; i++){
		printf("Nama Paket ke-%i             : ", i);
        scanf(" %[^\n]s",&namapaket[i]);
		printf("Harga Paket %i               : Rp. ", i);
		scanf("%i", &harga[i]);
		printf("Jumlah                      : ");
		scanf("%i", &jumlah[i]);
        printf(" \n");
	}
 
	for(i=1; i<=paket; i++){
		totalharga[i] =jumlah[i]*harga[i];
		totalhargakeseluruhan = totalhargakeseluruhan + totalharga[i];
	}
	printf("Daftar Belanja Anda         :\n");
	for(i=1; i<=paket; i++){
		printf("%i. %s (Rp.%i) x%i       : Rp. %i\n", i, &namapaket[i], harga[i], jumlah[i], totalharga[i]);
	}
	tampilkantotalharga(totalhargakeseluruhan);
 
	printf("DP                          : Rp. ");
	scanf("%i", &DP);
 
	int sisapembayaran = hitungsisapembayaran (totalhargakeseluruhan, DP);
	tampilkansisapembayaran(sisapembayaran);
 
	printf("Pembayaran                  : Rp. ");
	scanf("%i", &pembayaran);
 
	int kembali = hitungkembali(pembayaran, totalhargakeseluruhan);
	tampilkankembali(kembali, pembayaran, sisapembayaran, totalhargakeseluruhan);
 
	cetaknota(namaPelanggan, noHp, i, jumlah, harga, totalharga, namapaket, totalhargakeseluruhan, DP, pembayaran, kembali, paket, sisapembayaran);
 
	getch();
	menuPegawai();    
}
 
void tampilkantotalharga(int totalhargakeseluruhan){
	printf("========================================================\n\n");
	printf("Total Harga Keseluruhan     : Rp. %i\n", totalhargakeseluruhan);
}
 
int hitungsisapembayaran(int totalhargakeseluruhan, int DP){
	int sisapembayaran;
	sisapembayaran = totalhargakeseluruhan - DP;
	return sisapembayaran;
}
 
void tampilkansisapembayaran(int sisapembayaran){
	printf("Sisa Pembayaran	            : Rp. %i\n", sisapembayaran);
}
 
int hitungkembali(int pembayaran, int totalhargakeseluruhan){
	int kembali;
	kembali = pembayaran - totalhargakeseluruhan;
	return kembali;
}
 
void tampilkankembali(int kembali, int pembayaran, int sisapembayaran, int totalhargakeseluruhan){
	if(pembayaran>=sisapembayaran)
	{	printf("========================================================\n");
		printf("Total Harga                 : Rp. %i\n", totalhargakeseluruhan);
		printf("Pembayaran                  : Rp. %i\n", pembayaran);
		if(pembayaran>totalhargakeseluruhan){
			printf("Kembali                    : Rp. %i\n", kembali);
		}
		printf("========================================================\n");
		printf ("|                      TERIMAKASIH                     |\n");
		printf ("|                TELAH MELAKUKAN TRANSAKSI             |\n");
		printf ("|                      DI RAYURI SPA                   |\n");
		printf("========================================================\n");
 
	}
	else
	{
		printf ("|          TRANSAKSI GAGAL					|\n");
	}
}
 
void cetaknota(const char * namaPelanggan, const char * noHp, int i, int jumlah[100], int harga[100], int totalharga[100], char namapaket[100], int totalhargakeseluruhan, int DP, int pembayaran, int kembali, int paket, int sisapembayaran){
	time_t ambil_waktu2;
    time(&ambil_waktu2);	
	FILE * fpointernota;
	fpointernota = fopen("nota.txt", "w+");
    fprintf(fpointernota,"%s", ctime(&ambil_waktu2) );
    fprintf(fpointernota,"========================================================\n");
    fprintf(fpointernota,"|                    RAYURI SPA                        |\n");
    fprintf(fpointernota,"|                 Kota Denpasar                        |\n");
    fprintf(fpointernota,"|                Telp. 08123456789                     |\n");
    fprintf(fpointernota,"========================================================\n");
    fprintf(fpointernota,"| Bukti Pembayaran Paket Spa                           |\n");                
    fprintf(fpointernota,"  Nama Pelanggan                            : %s\n",namaPelanggan);                
    fprintf(fpointernota,"  No Telepon                                : %s\n",noHp);                
    fprintf(fpointernota,"========================================================\n");
    fprintf(fpointernota,"Daftar Belanja Anda 	                      :\n");    
    for(i=1; i<=paket; i++){
		fprintf(fpointernota, "%i. %i %s (Rp.%i)		    : Rp. %i\n", i, jumlah[i], &namapaket[i], harga[i], totalharga[i]);
	}            
	if(pembayaran>=sisapembayaran){
		fprintf(fpointernota, "=========================================================\n");
		fprintf(fpointernota, "TOTAL HARGA 			: Rp. %i\n", totalhargakeseluruhan);
		fprintf(fpointernota, "DP						: Rp. %i\n", DP);
		fprintf(fpointernota, "PEMBAYARAN 				: Rp. %i\n", pembayaran);
 
		if(pembayaran>totalhargakeseluruhan){
			fprintf(fpointernota, "KEMBALIAN			    : Rp. %i\n", kembali);
		}
 
		fprintf(fpointernota,"========================================================\n");
		fprintf(fpointernota,"|                     TERIMAKASIH                      |\n");
		fprintf(fpointernota,"|              TELAH MELAKUKAN TRANSAKSI               |\n");
		fprintf(fpointernota,"|                    DI RAYURI SPA                     |\n");
		fprintf(fpointernota,"========================================================\n");
		fclose(fpointernota);
 
	}
	else
	{
		fprintf (fpointernota,"|                    TRANSAKSI SALAH                   |\n");
	}
   fclose (fpointernota);
}
