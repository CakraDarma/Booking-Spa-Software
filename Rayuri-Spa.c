#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//prtotipe program
void judul (void);
void header(void);
void menuUtama(void);
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
//void cetakKuitansi(const char * namaJasa, int harga, int bayarDp);
void cetakKuitansi(const char * namaPelanggan, const char * noHp, const char * namaJasa, int harga, int bayarDp);

int main() {
	judul();
	menuUtama();
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

//main menu
void menuUtama(void){
	system("cls");
	header();
	int menuUtama;
	printf ("|                  MENU UTAMA                 |\n");
	printf ("|=============================================|\n");
	printf ("|[1] MENU PEMESANAN                           |\n");
	printf ("|[2] GATAU                                    |\n");
	printf ("|[3] GATAU                                    |\n");
	printf ("|[4] GATAU                                    |\n");
	printf ("|[5] GATAU                                    |\n");
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|[6] BANTUAN                                  |\n"); // Jika bingung dengan program ini, dapat menggunakan tombol bantuan
	printf ("|[7] KELUAR                                   |\n"); // Pilihan exit yang dapat digunakan user sebagai pilihan untuk menutup program
	printf ("=============================================== \n");
	printf ("Silahkan pilih : "); // Memilih Jasa yang diinginkan
	scanf("%d", &menuUtama);
	//memilih menu
		if(menuUtama==1){
			menuJasa();
		}
		else if(menuUtama==6){
			menuBantuan();
		}
		else if(menuUtama==7){
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
   			menuUtama();
   		}
   	}
   	else if(menuJasa == 9){
   		menuUtama();
   	}
	
	//lanjut ke pembayaran
	bayarDp = dp * harga;
	char namaPelanggan[100] ;
	char noHp[20];
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
		printf("|====================================================|\n\n");	
		printf("Transaksi Sudah Dicatat\n");
		printf("Pastikan Anda Datang Tepat Waktu\n");
		cetakKuitansi(namaPelanggan,noHp,namaJasa,harga,bayarDp);
		getchar();
		menuUtama();
	}
	else if(teruskanPemesanan == 'n'||teruskanPemesanan == 'N'){
		menuUtama();
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
	 			menuUtama();
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
	 			menuUtama();
	 		}
   		//kembali ke menu utama
	    case 3:
   		menuUtama();
   
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
		menuUtama();
	}	
}

//cetak kuitansi
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * namaJasa, int harga, int bayarDp){
    //kuitansi
    FILE * fpointer;
    fpointer=fopen("kuitansi.txt", "w+"); 
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"|                    RAYURI SPA                          |\n");
    fprintf(fpointer,"|                 Kota Denpasar                        |\n");
    fprintf(fpointer,"|                Telp. 08123456789                     |\n");
    fprintf(fpointer,"========================================================\n");
    fprintf(fpointer,"| Bukti Pemesanan Paket Spa                            |\n");                
    fprintf(fpointer,"  Nama Pelanggan                            : %s\n",namaPelanggan);                
    fprintf(fpointer,"  No Telepon                                : %s\n",noHp);                
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
