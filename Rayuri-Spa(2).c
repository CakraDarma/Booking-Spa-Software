#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

//prtotipe program
//fungsi untuk menampilkan judul program
void judul (void); 
//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void);
//fungsi untuk menampilkan menu jasa dan paket yang tersedia di spa
void menuJasa(void);
//fungsi untuk menampilan menu bantuan apabila user kesulitan dan tidak menegerti dalam penggunaan program
void menuBantuan(void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);
//fungsi untuk menampilkan rincian jasa 1
void tampilkanRincianJasa1(void);
//fungsi untuk menampilkan rincian jasa 2
void tampilkanRincianJasa2(void);
//fungsi untuk menampilkan rincian jasa 3
void tampilkanRincianJasa3(void);
//fungsi untuk menampilkan rincian jasa 4
void tampilkanRincianJasa4(void);
//fungsi untuk menampilkan rincian jasa 5
void tampilkanRincianJasa5(void);
//fungsi untuk menampilkan rincian jasa 6
void tampilkanRincianJasa6(void);
//fungsi untuk menampilkan rincian jasa 7
void tampilkanRincianJasa7(void);
//fungsi untuk mencetak kuitansi pembayaran DP apabila customer sudah selesai memesan
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * alamat, const char * namaJasa, int harga, int bayarDp, const char * waktu1, const char * waktu2);
//fungsi untuk login sebagai pengguna(customer) atau staff
void login(void);
//fungsi untuk menampilkan menu apabila login sebagai pegawai/staff
void menuPegawai(void);
//fungsi untuk menampilkan menu kasir untuk menyelesaikan pembayaran
void menuKasir(void);
//fungsi untuk menampilkan total harga
void tampilkantotalharga(int totalhargakeseluruhan);
//fungsi untuk menghitung sisa pembayaran
int hitungsisapembayaran(int totalhargakeseluruhan, int DP);
//fungsi untuk menampilkan sisa pembayaran
void tampilkansisapembayaran(int sisapembayaran);
//fungsi untuk menghitung kembali
int hitungkembali(int pembayaran, int totalhargakeseluruhan);
//fungsi untuk menampilkan kembali dan akhir dari transaksi
void tampilkankembali(int kembali, int pembayaran, int sisapembayaran, int totalhargakeseluruhan);
//fungsi untuk mencetak nota pembayaran customer
void cetaknota(const char * namaPelanggan, const char * noHp, int i, int jumlah[100], int harga[100], int totalharga[100], char namapaket[100][30], int totalhargakeseluruhan, int DP, int pembayaran, int kembali, int paket, int sisapembayaran);
//fungsi untuk mengkonfirmasi pemesanan
void konfirmasiPemesanan(void);
//syarat mendaftarkan member
void rulesMember(void);
//fungsi untuk mendaftarkan member
void pendaftaranMember(void);
//fungsi untuk menampilkan rekomendasi pembelian paket spa
void menurekomen(void);
//fungsi untuk mwnampilkan informasi tentang Spa kami
void tentangKami(void);
//fungsi mencetak pembayaran
void cekPembayaran(const char * bank, int noRekening, const char * nama, int jumlahTransfer);
//fungsi pendaftaran member
void pendaftaranMember(void);
//fungsi menampilkan daftar transaksi
void daftarTransaksi(void);


char kuitansi[50] = "kuitansi"; 
char username[20];
char password [20];
struct Data{
    char nama[100];
    char password[100];
};
struct Data pengguna;
FILE*out;
int main() {
	judul();
	login();
return 0;
}
 
//fungsi untuk menampilkan judul program
void judul(void){
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t==================================================\n");
	printf("\t\t|            Program Layanan Rayuri SPA          | \n");
	printf("\t\t==================================================\n");
	printf("\t\t|            This Program Created By :           |\n");
	printf("\t\t|                    1. Cakra                    |\n");
	printf("\t\t|                    2. Ayulia                   |\n");
	printf("\t\t|                  3. Sri Yanisa                 |\n");
	printf("\t\t==================================================\n\n\n");
	printf("\t\t\t\t\t\t\t**********************\n");
	printf("\t\t\t\t\t\t\t*Click enter to start*\n");
	printf("\t\t\t\t\t\t\t**********************\n");
	getch();
	system("cls");
	printf ("\t\n\n\n\n\n\n\n\n"); //Halaman awal bagian pemesanan dengan nama hotel
	printf ("\t\t\t\t\t\tSELAMAT DATANG DI RAYURI SPA                       \n");
	printf ("\t\t\t\t\t\t  'WELCOME TO RAYURI SPA'                          \n");
	printf("\t\t\t\t========================================================\n");
	printf("\t\t\t\t\t  Jalan Kenangan No. 666, KOTA SINGASARI              \n");
	printf("\t\t\t\t********* Sehat dan Cantik Bersama Rayuri Spa ********* \n");
	printf("\t\t\t\t\t     >>> Kenyamanan Anda Yang Utama <<<               \n");
	printf("\t\t\t\t\t\t   Hubungi : 08123456789                            \n");
	printf("\t\t\t\t\t\t  Instagram : @rayuri.spa                           \n");
	getch();
}
 
//fungsi untuk menampilkan header program
void header(void){
	printf("\n\n\n\t\t    RAYURI SPA                            \n");
	printf("\t\t Jl. Kenangan No.666                            \n");
	printf("\t\tNo. Telp 08123456789                            \n");
	printf("****************************************************\n");

}
 
//fungsi untuk login sebagai pengguna(customer) atau staff
void login(void){
	login:
	system("cls");
 
	int pilihPengguna;
 
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t*** RAYURI SPA ***\n\n");
	printf("\t\t\t\t\tLogin For : \n");
	printf("\t\t\t\t\t[1] Customer\n");
	printf("\t\t\t\t\t[2] Staff\n");
	printf("\n\n\t\t\tMasukkan pilihan anda :");
	scanf("%d",&pilihPengguna);
 
	if(pilihPengguna == 1){ //jika milih ini maka akan masuk ke login costumer
		loginCostumer:
		system("cls");
		bool masuk;
		int opsi;
 		printf ("\n\n\n\n\n");
 		header();
		printf("\n\n\t\t   1. Register\n");
		printf("\t\t   2. Login\n\n");
		printf("\tOpsi Anda: ");
		scanf("%d", &opsi);
 
		switch(opsi){
			case 1: //buat pengguna
				system("cls");
				out=fopen("pengguna","a+");
				header();
				printf("\nUsername  : ");
				scanf("%s", &pengguna.nama);
				printf("\nPassword  : ");
				scanf("%s", &pengguna.password);
				printf("\n\n\t\t  REGISTER BERHASIL!");
				fprintf(out,"%s\n",pengguna.nama);
	            fprintf(out,"%s\n",pengguna.password);
	            fclose(out);
				getch();
				system("cls");			
				goto loginCostumer; 
			case 2: //masuk setelah buat akun
				cobaMasuk:
				system("cls");
				out = fopen("pengguna","r+");
				masuk = false;
				header();
				printf("\nUsername : ");
				scanf("%s", &username);
				printf("\nPassword : ");
				scanf("%s", &password);
				while(fscanf(out,"\n%s\n%s",pengguna.nama,pengguna.password)!=EOF){
		            if((strcmp(pengguna.nama,username) == 00) && (strcmp(pengguna.password,password)==00)){
		                masuk = true;
		                break;
	           		}
	       		}
	        	if(!masuk){ //kalau salah
		            system("cls");
		            int loginFailed;
		            printf("\n\n\t\t   LOGIN FAILED!!!\n\n\n");
		            printf("Pilih langkah yang akan dilakukan : \n");
		            printf("\n> Pilih 1 untuk keluar\n");
		            printf("> Pilih sembarang untuk coba lagi\n\n");
		            //pilih sembarang artinya pilih nomor berapa saja untuk coba lagi memasukkan username dan password
		            printf("Pilih : ");
		            scanf("%d",&loginFailed);
		            if(loginFailed==1){
		            	goto loginCostumer;
		            }
		            else{
						goto cobaMasuk;
		            }
		    	}
		    	else { //kalau benar
	            printf("\n\n\t Selamat anda berhasil masuk!");
	            getch();
				menuCostumer();
	            system("cls");
	        	}
	    }
	}
	else if(pilihPengguna == 2){ //jika memilih ini maka akan masuk ke login costumer
		loginPegawai:
		system("cls");
		char usernamePegawai [50];
		char passwordPegawai [50];
		printf("\n\n\n\t\t    RAYURI SPA                            \n");
		printf("\t\t Jl. Kenangan No.666                            \n");
		printf("\t\tNo. Telp 08123456789                            \n");
		printf("****************************************************\n");
		printf("\nUsername : ");
        scanf("%s",&usernamePegawai);
        printf("\nPassword : ");
        scanf("%s",&passwordPegawai);
 		//username disini masukkan admin dan untuk password masukkan 123
 
        if(strcmp(usernamePegawai,"admin")==0 && strcmp(passwordPegawai,"123")==0){
			menuPegawai();
		}
		else{
			int gagal;
            printf("\n\nLogin Failed\n\n\n");
            printf("Pilih 1 untuk keluar\n");
            printf("Pilih sembarang untuk coba lagi\n\n");
            printf("Pilih : ");
            scanf("%d",&gagal);
            if(gagal == 1){
                goto login;
            }
            else{
                goto loginPegawai;
			}
		}
	}
}
 
 
//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void){
	menuCostumer:
	system("cls");
	header();
	int menuCostumer;
	printf ("|=============================================|\n");
	printf ("|                  MENU UTAMA                 |\n");
	printf ("|=============================================|\n");
	printf ("|[1] DAFTAR PAKET                             |\n");
	printf ("|[2] KONFIRMASI PEMESANAN                     |\n");
	printf ("|[3] REKOMENDASI                              |\n");
	printf ("|[4] DAFTAR TRANSAKSI                         |\n");
	printf ("|[5] TENTANG KAMI                             |\n");
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
		else if(menuCostumer==2){
			konfirmasiPemesanan();
		}
		else if(menuCostumer==3){
			menurekomen();
		}
		else if(menuCostumer==4){
			daftarTransaksi();
		}
		else if(menuCostumer==5){
			tentangKami();
		}
		else if(menuCostumer==6){
			menuBantuan();	
		}
		else if(menuCostumer==7){
			system("cls");
			system("pause");
			printf("Anda Telah Keluar Dari Program\n");
			exit(0);
		}
		else{
			inputSalah();
			goto menuCostumer;
		}
}
 
//fungsi untuk menampilkan menu jasa dan paket yang tersedia di spa
void menuJasa(void){
	menuJasa:
	system("cls");
	header();
	const  float dp = 0.5;
	const char * namaJasa;
 
	int menuJasa, bayarDp, harga;
	char teruskanPemesanan;
	char dataBenar;
 	int jumlah;
 	int i;
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
	printf ("|[8] KEMBALI                                  |\n"); // Pilihan untuk kembali ke sebelumnya
	printf ("=============================================== \n");
		printf("Silahkan pilih   : "); // Memilih Jasa yang diinginkan
		scanf("%d", &menuJasa);
	 
		system ("cls");
		// insialisasi harga dan nama jasa
		if(menuJasa==1){
			harga = 190000;
			namaJasa = "SIMPLE SENSE";
			system("cls");
			//fungsi untuk menampilkan rincian jasa 1
			tampilkanRincianJasa1();
			getch();
	 	}
		else if(menuJasa==2){
			harga = 205000;
			namaJasa = "SERENITY SENSE";
			system("cls");
			//fungsi untuk menampilkan rincian jasa 2
			tampilkanRincianJasa2();
			getch();
		}
		else if(menuJasa==3){
			harga = 265000;
			namaJasa = "REFRESH SENSE";
			system("cls");
			//fungsi untuk menampilkan rincian jasa 3
			tampilkanRincianJasa3();
			getch();
		}
		else if(menuJasa==4){
			harga = 330000;
			namaJasa = "FIRMING SENSE";
			//fungsi untuk menampilkan rincian jasa 4
			tampilkanRincianJasa4();
			getch();
		}
		else if(menuJasa==5){
			harga = 370000;
			namaJasa = "BALANCE SENSE";
			system("cls");
			//fungsi untuk menampilkan rincian jasa 5
			tampilkanRincianJasa5();
			getch();
		}
		else if(menuJasa==6){
			harga = 530000;
			namaJasa = "DETOX SENSE";
			system("cls");
			//fungsi untuk menampilkan rincian jasa 6
			tampilkanRincianJasa6();
			getch();
		}
		else if(menuJasa==7){
			harga = 580000;
			namaJasa = "ABSOLUTE SENSE";
			system("cls");
			//fungsi untuk menampilkan rincian jasa 7
			tampilkanRincianJasa7();
			getch();
		}
	   	else if(menuJasa == 8){
	   		menuCostumer();
	   	}
	   	else{
	   		inputSalah();
	   		goto menuJasa;
}
 
	//menu untuk melanjutkan ke pembayaran
	bayarDp = dp * harga;
	pembayaran:
	char namaPelanggan[100] ;
	char noHp[20];
	char alamat[50];
	char waktu1[40];
	char waktu2[20];
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
		printf("\n\n\n\t\t    RAYURI SPA                            \n");
		printf("\t\t Jl. Kenangan No.666                            \n");
		printf("\t\tNo. Telp 08123456789                            \n");
		printf("****************************************************\n");
		printf("       Anda Sudah Masuk Ke Menu Pemesanan \n\n");
		printf("\nSilahkan Isi Data Diri Anda\n");
		printf(" Nama                          : "); fflush(stdin);
		gets(namaPelanggan);
		printf(" No Telepon                    : "); fflush(stdin);
		gets(noHp);
		printf(" Alamat                        : "); fflush(stdin);
		gets(alamat);
		printf("\n\nDetail Pemesanan\n");
		printf("Tanggal-Bulan-Tahun Pemesanan: ");
		gets(waktu1);
		printf("Masukan Jam                  : ");
		gets(waktu2);
		printf("|====================================================|\n\n");	
    	printf("Transaksi Sudah Dicatat\n");
    	printf("Silahkan Transfer Dp Transaksi Anda Dan Lanjutkan Ke Konfirmasi pemesanan\n");
    	printf("BCA     : 001122334455\n");
    	printf("BNI     : 009933212122\n");
    	printf("Mandiri : 003242332122\n");
    	cetakKuitansi(namaPelanggan,noHp,alamat,namaJasa,harga,bayarDp,waktu1,waktu2);
    	getchar();
    	menuCostumer();
	}
	
	else if(teruskanPemesanan == 'n'||teruskanPemesanan == 'N'){
		goto menuJasa;
	}
	else{
		inputSalah();
		goto pembayaran;
	}
}

//fungsi menampilkan informasi tentang rayuri spa
void tentangKami(void){
	tentangKami:
	system("cls");
	int tentangKami;
	printf ("\n\n\n\n\n\n\n\n");
	printf ("\t\t\t\t\t\t\t\t\t    RAYURI SPA\n");
	printf ("\t\t\t\t\t\t\t\t\t     ABOUT US\n");
	printf ("\t\t\t\t\t\t\t\t\t  --------------\n");
	printf ("\t\t\t\t\t\t  =================================================================\n");
	printf ("\t\t\t\t\t\t  *    Rayuri SPA telah berdiri sejak tahun 2008 yang merupakan   *\n");
	printf ("\t\t\t\t\t\t  *  tempat perawatan dan relaksasi dengan konsep natural modern  *\n");
	printf ("\t\t\t\t\t\t  *   SPA. SPA yang modern dari segi design interior dan produk,  *\n");
	printf ("\t\t\t\t\t\t  *      tetapi tetap menggunakan banyak unsur yang alami dan     *\n");
	printf ("\t\t\t\t\t\t  *                          tradisional.                         *\n");
	printf ("\t\t\t\t\t\t  *                                                               *\n");
	printf ("\t\t\t\t\t\t  * Sense menyediakan pengalaman spa & reflexology authentik yang *\n");
	printf ("\t\t\t\t\t\t  * memberikan manfaat maksimal bagi seluruh tubuh dan jiwa  atau *\n");
	printf ("\t\t\t\t\t\t  *     terapi seluruh panca indera. Dimana hal ini merupakan     *\n");
	printf ("\t\t\t\t\t\t  * philosophy dari penggunaan nama 'Sense' yang  mengandung arti *\n");
	printf ("\t\t\t\t\t\t  *                   panca indera/perasaan.                      *\n");
	printf ("\t\t\t\t\t\t  =================================================================\n");
	printf ("\n");
	printf ("\t\t\t\t\t\t\t     *** THERAPHY THAT WILL BE IN THE RAYURI SPA ***\n");
	printf ("\t\t\t\t\t\t  *****************************************************************\n");
	printf ("\t\t\t\t\t\t  *  Terapi indera sentuhan dengan teknik  pijatan/sentuhan yang  *\n");
	printf ("\t\t\t\t\t\t  * merilekskan dan  menghilangkan kelelahan tubuh yang dilakukan *\n");
	printf ("\t\t\t\t\t\t  *       oleh terapis yang berpengalaman dan profesional         *\n");
	printf ("\t\t\t\t\t\t  *                                                               *\n");
	printf ("\t\t\t\t\t\t  *Terapi indera pendengaran dengan musik yang menenangkan pikiran*\n");
	printf ("\t\t\t\t\t\t  *                                                               *\n");
	printf ("\t\t\t\t\t\t  *  Terapi indera penglihatan dengan  dekor interior sense yang  *\n");
	printf ("\t\t\t\t\t\t  *   bernuansa tropis  minimalis serta bernuansa alam sehingga   *\n");
	printf ("\t\t\t\t\t\t  *            menciptakan suasana nyaman dan relax               *\n");
	printf ("\t\t\t\t\t\t  *                                                               *\n");
	printf ("\t\t\t\t\t\t  *  Terapi indera penciuman dengan wangi aroma theraphy di area  *\n");
	printf ("\t\t\t\t\t\t  *                 sense spa & reflexology                       *\n");
	printf ("\t\t\t\t\t\t  *                                                               *\n");
	printf ("\t\t\t\t\t\t  *   Terapi indera perasa dimana setiap customer akan disuguhi   *\n");
	printf ("\t\t\t\t\t\t  *  minuman tradisional atau modern yang baik bagi kesehatan di  *\n");
	printf ("\t\t\t\t\t\t  *                      akhir perawatan                          *\n");
	printf ("\t\t\t\t\t\t  *****************************************************************\n\n\n");
	printf ("\t\t\t\t\t\t[1] Pesan Sekarang\n");
	printf ("\t\t\t\t\t\t[2] Kembali Ke Halaman Utama\n\n");
	printf ("\t\t\t\t\t\tPilih : ");
	scanf("%d",&tentangKami);
	if(tentangKami == 1){
		getch();
		menuJasa();
	}
	else if(tentangKami == 2){
		menuCostumer();
	}
	else{
		inputSalah();
		goto tentangKami;
	}
}
 
//fungsi untuk menampilan menu bantuan apabila user kesulitan dan tidak menegerti dalam penggunaan program
void menuBantuan(void){
	menuBantuan:
	system("cls");
	header();
	int bantuan;
	printf("\nMENU BANTUAN\n\n");
 	printf("[1] Tentang program\n"); // Menjelaskan tentang program pemesanan kamar hotel
 	printf("[2] Cara Menggunakan\n"); // Menjelaskan cara menggunakan program pemesanan kamar hotel
 	printf("[3] Reset Program\n");//fungsi ini akan mendelete semua file
 	printf("[4] Kembali\n\n");  // Kembali pada menu utama
 	printf("Silahkan pilih :"); // User diminta untuk memilih pilihan diantara 3 pilihan tersebut
 	scanf("%d",&bantuan);
 
 	//memilih di menu bantuan
 	switch(bantuan){
		 // Penjelasan tentang Program Pemesanan SPA
 		case 1:
		system("cls");
		header();
 		int tentangProgram;
		printf ("|=====================================================|\n");
		printf ("|                    * RAYURI SPA *                   |\n");
		printf ("|                    **************                   |\n");
		printf ("|                                                     |\n");
   		printf ("|Program ini bertujuan untuk memesan SPA dengan mudah.|\n");
   		printf ("|   Pemesanan spa ini diawali dengan sistem booking   |\n");
   		printf ("| terlebih dahulu. Setelah memesan maka customer akan |\n");
   		printf ("|    membayar dp terlebih dahulu agar pesanan tidak   |\n");
   		printf ("|    dibatalkan lalu pada saat hari yang ditentukan   |\n");
   		printf ("|customer akan membayar penuh. Program ini dibuat agar|\n");
   		printf ("|    customer tidak lama menunggu antrian saat ingin  |\n");
   		printf ("|   melakukan spa sehingga tidak banyak yang komplain |\n");
   		printf ("|            terhadap pelayanan di spa.               |\n");
		printf ("|=====================================================|\n");
   		getch ();
   		menuBantuan();
 		// Penjelasan tentang tata cara Program pemesanan SPA  
  		case 2:
		system("cls");
		header();
  		int caraMenggunakan;
  		printf ("\n\n");
		printf ("|=============================================================|\n");
		printf ("|                        * RAYURI SPA *                       |\n");
		printf ("|                        **************                       |\n");
		printf ("|                                                             |\n");
  	    printf ("|Inputkan angka pada menu utama sesuai kebutuhan,             |\n");
   		printf ("|Membuat akun untuk mendapatkan diskon 5 persen,              |\n"); 
   		printf ("|Pengguna kartu member akan diberi discount sebesar 20 persen.|\n");
		printf ("|=============================================================|\n");
   		getch();
   		menuBantuan();
   		//mendelete semua file
   		case 3:
   		system("cls");
   		char input;
   	    printf ("|=============================================================|\n");
		printf ("|                        * RAYURI SPA *                       |\n");
		printf ("|                        **************                       |\n");
		printf ("|                                                             |\n");
		printf ("|- Mendelete Semua data Transaksi Anda Menjadi kosong         |\n");
		printf ("|                                                             |\n");
		printf ("|           PERINGATAN DATA TRANSAKSI ANDA AKAN HILANG        |\n");
		printf ("|               DAN TIDAK BISA DIKEMBALIKAN LAGI              |\n");
		printf ("|=============================================================|\n");
		printf ("Apakah Anda Yakin (y/n): ");
		getchar();
		input=getchar();
		if(input == 'y' || input == 'Y'){
			remove(pengguna.nama);
			remove(kuitansi);
			system("cls");
			printf("\tBerhasil!, Program Akan Diakhiri Silahkan Login Ulang");
			getch();
			exit(0);
		}
		else{
			goto menuBantuan;
		}
   		//kembali ke menu utama
	    case 4:
   		menuCostumer();
   		default:
   		inputSalah();
   		goto menuBantuan;
 	}
 
}
 
 
//fungsi untuk menampilkan apabila input salah
void inputSalah(void){
	system("cls");
	printf("\nINPUT ANDA ADA SALAH\n");
	system("pause");
	}
 
//fungsi untuk mencetak kuitansi pembayaran DP apabila customer sudah selesai memesan
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * alamat, const char * namaJasa, int harga, int bayarDp, const char * waktu1, const char * waktu2){
    //kuitansi

    time_t ambil_waktu1;
    time(&ambil_waktu1);
    FILE * fpointerkuitansiCostumer;
    fpointerkuitansiCostumer=fopen(pengguna.nama, "w");
    fprintf (fpointerkuitansiCostumer,"\n%s",ctime(&ambil_waktu1));
    fprintf (fpointerkuitansiCostumer, "=============================================================================================================\n\n");
	fprintf (fpointerkuitansiCostumer, "                                                  RAYURI SPA                                                   \n");
	fprintf (fpointerkuitansiCostumer, "                                                 Kota Denpasar                                                  \n");
	fprintf (fpointerkuitansiCostumer, "                                                Telp. 08123456789                                               \n");
	fprintf (fpointerkuitansiCostumer, "==============================================================================================================\n\n");
	fprintf (fpointerkuitansiCostumer, "Bukti Pemesanan Paket Spa\n\n");
	fprintf (fpointerkuitansiCostumer, "Jadwal Pemesanan Paket                    : %s\n",waktu1);
	fprintf (fpointerkuitansiCostumer, "Pukul                                     : %s\n",waktu2);
	fprintf (fpointerkuitansiCostumer, "Nama Pelanggan                            : %s\n",namaPelanggan);                
    fprintf (fpointerkuitansiCostumer, "No Telepon                                : %s\n",noHp);                
    fprintf (fpointerkuitansiCostumer, "Alamat                                    : %s\n",alamat);  
    fprintf (fpointerkuitansiCostumer, "----------------------------------------------------------------------------------------------------------------\n"); 
    fprintf (fpointerkuitansiCostumer, "%s\n",namaJasa);     
    fprintf (fpointerkuitansiCostumer, "Total Harga                               : %d\n",harga);
    fprintf (fpointerkuitansiCostumer, "----------------------------------------------------------------------------------------------------------------\n"); 
	fprintf (fpointerkuitansiCostumer, "DP                                                        \n");            
	fprintf (fpointerkuitansiCostumer, "Rp. %d\n", bayarDp);    
	fprintf (fpointerkuitansiCostumer, "----------------------------------------------------------------------------------------------------------------\n");  
	fclose  (fpointerkuitansiCostumer); 
    }
 //fungsi menampilkan daftar transaksi yang lunas
void konfirmasiPemesanan (void){
	konfirmasiPemesanan:
	system("cls");
	int kembali;
	char benar;
    FILE * fpointerkuitansiCostumer;
    fpointerkuitansiCostumer=fopen(pengguna.nama, "r");
    if(fpointerkuitansiCostumer!=NULL){
		printf("\t\t\t\t\tHistory Pemesanan\n");
		char buff[255];
    	while(fgets(buff, sizeof(buff), fpointerkuitansiCostumer)){
    		printf("%s ",buff);
    	}
    fclose(fpointerkuitansiCostumer);
    	printf("[1] Konfirmasi Pembayaran\n");
    	printf(" [2] kembali\n\n");
    	int pilihKonfirmasi;
	   	printf("pilih                               : ");
	    scanf("%d",&pilihKonfirmasi);
	    if (pilihKonfirmasi==1){
	    	konfirmasi:
	        char bank[20];
	        int noRekening;
	        int jumlahTransfer;
	        char idInvoice[20];
	        char nama[60];
	        char nohp[20];

	        printf("Bank                                : "); fflush(stdin);
	        gets(bank);
	        printf("No Rekening Anda                    : "); fflush(stdin);
	        scanf("%d", &noRekening);
	        printf("Atas Nama                           : "); fflush(stdin);
	        gets(nama);             
	        printf("Jumlah Transfer                     : "); fflush(stdin);
	        scanf("%d", &jumlahTransfer);
	        printf("Apakah Data Anda Sudah Benar? (y/n) : \n");
	       	getchar();
	       	benar = getchar();
	        if(benar=='y'||benar=='Y'){
		        printf("----------------------------------------------------------------------------");
		        printf("\nTerimakasih Pesanan Anda Sedang Kami Cek\n\n");
		        cekPembayaran(bank, noRekening, nama, jumlahTransfer);
		        system("pause");
		        menuCostumer();
		    } 
		    else{
		    	printf("\n\nKonfirmasi Telah Dibatalkan !\n\n");
		    	goto konfirmasiPemesanan;
		    }
	    }
	    else if(pilihKonfirmasi==2){
	        menuCostumer();
	    }
	    else{
	        inputSalah();
	        goto konfirmasiPemesanan;
	    }
    }
    
    else{
    	printf("\n\n\nAnda Belum Melakukan Pemesanan Apapun\n\n\n");
    	getch();
    	menuCostumer();
    }
	
}

//fungsi cetak bukti pembayaran
void cekPembayaran(const char * bank, int noRekening, const char * nama, int jumlahTransfer){
	time_t waktuBayar;
    time(&waktuBayar);
	FILE * fpointercekPembayaran;
	fpointercekPembayaran=fopen(pengguna.nama, "a+");
    fprintf (fpointercekPembayaran, "Telah Dibayar               \n");
    fprintf (fpointercekPembayaran,"\n%s",ctime(&waktuBayar));
    fprintf (fpointercekPembayaran, "Bank                         :%s\n",bank);
    fprintf (fpointercekPembayaran, "No Rekening                  :%d\n",noRekening);
    fprintf (fpointercekPembayaran, "Atas Nama                    :%s\n",nama);
    fprintf (fpointercekPembayaran, "Jumlah Transfer              :%d\n",jumlahTransfer);
    fprintf (fpointercekPembayaran, "----------------------------------------------------------------------------------------------------------------\n\n\n");
    fclose  (fpointercekPembayaran);
    //menyalin ke kuitansi.txt
    FILE*fdaftarTransaksi;
    fdaftarTransaksi=fopen(kuitansi, "r");
	if(fdaftarTransaksi==NULL){
		strcat(kuitansi,pengguna.nama);
	}
    FILE *baca, *salin;
	baca = fopen(pengguna.nama, "a+");
	salin = fopen(kuitansi, "a+");
	char karakter;
	while((karakter=fgetc(baca))!=EOF)
	fputc(karakter,salin);
	fclose(baca);
	fclose(salin);
	fclose(fdaftarTransaksi);

	//mendelete di konformasi pemesanan karena data sudah masuk ke daftar transaksi
	FILE * fpointerkuitansiCostumer;
	fpointerkuitansiCostumer=fopen(pengguna.nama,"w");
	fprintf (fpointerkuitansiCostumer,"\n\n\nAnda Belum Melakukan Pemesanan Apapun\n\n\n");
	fclose (fpointerkuitansiCostumer);
}

//fungsi menampilkan daftar transaksi yang sukses
void daftarTransaksi(void){
	system("cls");
	//cek dulu apakah ada flie kutiansi kalau tidak kita buat 
	FILE * fdaftarTransaksi;
    fdaftarTransaksi=fopen(kuitansi, "r"); 
	if(fdaftarTransaksi==NULL){
		strcat(kuitansi,pengguna.nama);
	}
	//cek file yang sudah di buat
    fdaftarTransaksi=fopen(kuitansi, "r"); 
    if(fdaftarTransaksi!=NULL){
		char buff[255];
    	while(fgets(buff, sizeof(buff), fdaftarTransaksi)){
    		printf("%s ",buff);
    	}
    }
    else{
    	printf("Daftar transaksi Anda Kosong");
    }
    	fclose(fdaftarTransaksi);
    	getch();
    	menuCostumer();
}

//fungsi untuk menampilkan rincian jasa
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
 
//fungsi untuk menampilkan menu apabila login sebagai pegawai/staff
void menuPegawai(void){
	menuPegawai:
	system("cls");
	header();
	int menuPegawai;
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|=============================================|\n");
	printf ("|[1] KASIR                                    |\n");
	printf ("|[2] DAFTAR MEMBER                            |\n");
	printf ("|=============================================|\n");
	printf ("|                                             |\n");
	printf ("|[0] KELUAR                                   |\n"); // Pilihan untuk Keluar ke sebelumnya
	printf ("=============================================== \n");
	printf ("Silahkan pilih : "); // Memilih Jasa yang diinginkan
	scanf("%d", &menuPegawai);
 
	if(menuPegawai == 1){
		menuKasir();
	}
	else if(menuPegawai){
		rulesMember();
	}
	else if(menuPegawai == 0){
		system("cls");
		system("pause");
		printf("Anda keluar dari program\n");
		exit(0);
	}
	else{
		inputSalah();
		goto menuPegawai;
	}
}

//fungsi untuk menampilkan rekomendasi pembelian paket spa
void menurekomen(void){
    menurekomen:
    system("cls");
    int keluhanTidakvalid;
    header ();
    printf("ANDA BINGUNG MAU MEMILIH PAKET YANG MANA?\n");
    printf("Tenang, kami bantu\n");
 
  	printf ("|====================================|===========|\n");
    printf ("|            KELUHAN ANDA            |    KODE   |\n");
    printf ("|====================================|===========|\n");
    printf ("|[1]  Stres                          |    100    |\n");
    printf ("|[2]  Cemas                          |    101    |\n");
    printf ("|[3]  Lelah                          |    102    |\n");
    printf ("|[4]  Depresi                        |    103    |\n");
    printf ("|[5]  Penuaan                        |    104    |\n");
    printf ("|[6]  Kulit Kusam                    |    105    |\n");
    printf ("|[7]  Berat Badan Berlebih           |    106    |\n");
    printf ("|[8]  Badan Terasa Kurang Sehat      |    107    |\n");
    printf ("|[9]  Badan Pegal                    |    108    |\n");
    printf ("|[10] Insomnia                       |    109    |\n");
    printf ("|====================================|===========|\n");
    printf("Masukkan 0 untuk mengakhiri\n");
    int total , nilai=0;
    total=0;
    do{
   		total = total + nilai;
        printf("Masukkan Kode Keluhan            :\n");
        scanf("%d",&nilai);
    }while (nilai != 0);
    	if((total==102)||(total==108)||(total==102+108)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("-----------SIMPLE SENSE-----------\n\n");
    	}
    	else if((total==100)||(total==101)||(total==105)||(total==109)||(total==100+105)||(total==100+101+105)||(total==101+105)||(total==102+109)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("-----------SERENITY SENSE---------\n\n");
    	}
    	else if((total==102)||(total==108)||(total==103)||(total==100)||(total==107)||(total==102+108)||(total==100+102+108)||(total==107+108)||(total==100+101+102+107)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("-----------REFRESH SENSE----------\n\n");
    	}
    	else if((total==107)||(total==108)||(total==109)||(total==107+108)||(total==107+108+109)||(total==102)||(total==102+109)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("-----------BALANCE SENSE----------\n\n");
    	}
    	else if((total==105)||(total==106)||(total==107)||(total==108)||(total==106+107)||(total==105+107)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("-----------DETOX SENSE------------\n\n");
    	}
    	else if((total==104)||(total==105)||(total==104+105)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("-----------FIRMING SENSE----------\n\n");
    	}
    	else if((total==105)||(total==100+101+102+103+105+109)||(total==105+109)){
    		printf("       Kami Merekomendasikan        \n");
    		printf("----------ABSOLUTE SENSE----------\n\n");
    	}
      else{
        printf("Keluhan Anda Tidak Valid\n");
        printf("[1] Kembali Ke Menu Utama\n");
        printf("[2] Coba Lagi\n");
        printf("Pilih : ");
        scanf("%d",&keluhanTidakvalid);
        if(keluhanTidakvalid==1){
        	menuCostumer();
        }
        else if(keluhanTidakvalid==2){
	        goto menurekomen;
        }
        else{
        	inputSalah();
        	goto menurekomen;
        }
      }
    printf("Anda Akan Diarahkan ke Menu Jasa\n");
    system("pause");
	menuJasa();
 
}
 
//fungsi untuk menampilkan menu kasir untuk menyelesaikan pembayaran
void menuKasir(void){
	system("cls");
	char namaPelanggan[100], noHp[100], namapaket[100][30];
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
        scanf(" %[^\n]s",&namapaket[i][i]);
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
		printf("%i. %s (Rp.%i) %i       \nRp. %i\n\n", i, &namapaket[i][i], harga[i], jumlah[i], totalharga[i]);
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
 
//fungsi untuk menampilkan total harga
void tampilkantotalharga(int totalhargakeseluruhan){
	printf("========================================================\n\n");
	printf("Total Harga Keseluruhan     : Rp. %i\n", totalhargakeseluruhan);
}
 
//fungsi untuk menghitung sisa pembayaran
int hitungsisapembayaran(int totalhargakeseluruhan, int DP){
	int sisapembayaran;
	sisapembayaran = totalhargakeseluruhan - DP;
	return sisapembayaran;
}
 
//fungsi untuk menampilkan sisa pembayaran
void tampilkansisapembayaran(int sisapembayaran){
	printf("Sisa Pembayaran	            : Rp. %i\n", sisapembayaran);
}
 
//fungsi untuk menghitung kembali
int hitungkembali(int pembayaran, int totalhargakeseluruhan){
	int kembali;
	kembali = pembayaran - totalhargakeseluruhan;
	return kembali;
}
 
//fungsi untuk menampilkan kembali dan akhir dari transaksi
void tampilkankembali(int kembali, int pembayaran, int sisapembayaran, int totalhargakeseluruhan){
	if(pembayaran>=sisapembayaran)
	{	printf("========================================================\n");
		printf("Total Harga                 : Rp. %i\n", totalhargakeseluruhan);
		printf("Pembayaran                  : Rp. %i\n", pembayaran);
		if(pembayaran>totalhargakeseluruhan){
			printf("Kembali                     : Rp. %i\n", kembali);
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
 
 
 
 
//fungsi untuk mencetak nota pembayaran customer
void cetaknota(const char * namaPelanggan, const char * noHp, int i, int jumlah[100], int harga[100], int totalharga[100], char namapaket[100][30], int totalhargakeseluruhan, int DP, int pembayaran, int kembali, int paket, int sisapembayaran){
	time_t ambil_waktu2;
    time(&ambil_waktu2);	
	FILE * fpointernota2;
	fpointernota2 = fopen ("kuitansiKasir.txt", "w+"); //write a file
	fprintf(fpointernota2,"%s", ctime(&ambil_waktu2) );
	fprintf (fpointernota2, "=============================================================================================================\n\n");
	fprintf (fpointernota2, "                                                  RAYURI SPA                                                   \n");
	fprintf (fpointernota2, "                                                 Kota Denpasar                                                  \n");
	fprintf (fpointernota2, "                                                Telp. 08123456789                                               \n");
	fprintf (fpointernota2, "==============================================================================================================\n\n");
	fprintf (fpointernota2, "Bukti Pembayaran Paket Spa\n\n");
	fprintf (fpointernota2, "                                                                                                   Kasir : Siapa\n");
	fprintf (fpointernota2, "Nama Pelanggan                            : %s\n" , namaPelanggan);
	fprintf (fpointernota2, "No Telepon                                : %s\n",noHp);
	fprintf (fpointernota2, "Rincian Belanja                           :\n"); 
	fprintf (fpointernota2, "----------------------------------------------------------------------------------------------------------------\n"); 
    for(i=1; i<=paket; i++){
		fprintf(fpointernota2, "%i. %i %s (Rp.%i) \nRp. %i\n\n", i, jumlah[i], &namapaket[i][i], harga[i], totalharga[i]);
	}            
	fprintf (fpointernota2, "----------------------------------------------------------------------------------------------------------------\n"); 
	fprintf(fpointernota2, "                                               TOTAL PEMBAYARAN                                                  \n");            
	fprintf(fpointernota2, "                                                   Rp. %i\n", totalhargakeseluruhan);    
	fprintf (fpointernota2, "----------------------------------------------------------------------------------------------------------------\n");                                                        
    fclose (fpointernota2); 
} 
 
 void rulesMember(void){
 	rulesMember :
 	header();
	int registrasi;
	int daftar;
	char nama [85];
	char alamat [250];
	char telp [13];
	printf ("\n\n\n\n\n\n\n");
	printf ("\t\t\t\t************* RAYURI SPA MEMBER ************* \n");
 	printf ("\t\t\t\t********************************************* \n");
	printf ("\t\t\t\t|                  RULES                    | \n");
	printf ("\t\t\t\t|                                           | \n");
	printf ("\t\t\t\t|1. Sudah pernah melakukan layanan spa di   | \n");
	printf ("\t\t\t\t|   Rayuri Spa sebelumnya                   | \n");
	printf ("\t\t\t\t|2. Member bersifat pribadi dan tidak bisa  | \n");
	printf ("\t\t\t\t|   dipindah tangankan                      | \n");
	printf ("\t\t\t\t|3. Setiap anggota hanya diperbolehkan      | \n");
	printf ("\t\t\t\t|   memiliki satu akun keanggotaan dan akan | \n");
	printf ("\t\t\t\t|   kartu keanggotaan                       | \n");
	printf ("\t\t\t\t|4. Untuk mendaftar menjadi member dikenakan| \n");
	printf ("\t\t\t\t|   biaya pendaftaran sebesar Rp 50000,00   | \n");
	printf ("\t\t\t\t|5. Keanggotaan berlaku selama 2 tahun dan  | \n");
	printf ("\t\t\t\t|   jika masa keanggotaan sudah habis maka  | \n");
	printf ("\t\t\t\t|   anggota bisa mendaftar kembali atau     | \n");
	printf ("\t\t\t\t|   selesai menjadi member di Rayuri Spa    | \n");
	printf ("\t\t\t\t********************************************* \n");
	printf ("\t\t\t\t********************************************* \n");
	printf ("\t\t\t\t|            KEUNTUNGAN MEMBER              | \n");
	printf ("\t\t\t\t|                                           | \n");
	printf ("\t\t\t\t|(1) Akan mendapat potongan setiap melakukan| \n");
	printf ("\t\t\t\t|    layanan di Rayuri Spa                  | \n");
	printf ("\t\t\t\t|(2) Akan mendapat bonus maupun promo setiap| \n");
	printf ("\t\t\t\t|    hari-hari penting                      | \n");
	printf ("\t\t\t\t|(3) Dapat mengikuti program-program reward | \n");
	printf ("\t\t\t\t|    lainnya                                | \n");
	printf ("\t\t\t\t********************************************* \n");
 	printf ("\t\t\t\tApa yang selanjutnya akan dilakukan? \n");
 	printf ("\t\t\t\t	1. Lanjutkan Pendaftaran Member \n");
 	printf ("\t\t\t\t	2. Kembali ke Menu Utama \n");
 	printf ("\t\t\t\tMasukkan pilihan anda : ");
 	scanf  ("%d", &daftar);
 
 	if (daftar==1){
 		pendaftaranMember();
	}
 	else if (daftar==2){
		menuPegawai();
	}
	else{
		inputSalah();
		goto rulesMember;
	}
 }
 
void pendaftaranMember(void){
	system ("cls");
	pendaftaranMember :
	header();
	char nama [95];
	char alamat [250];
	char telp [13];
	char email [80];
	char konfirmasiPendaftaran;
	printf ("\n\n");
	printf ("\t\t\t\t************* RAYURI SPA MEMBER ************* \n");
 	printf ("\t\t\t\t********************************************* \n");
 	printf ("\nNAMA : ");
    scanf  (" %[^\n]s",nama);
 	printf ("\nALAMAT : ");
 	scanf  (" %[^\n]s",alamat);
 	printf ("\nNOMOR TELEPON : ");
 	scanf  (" %[^\n]s",telp);
 	printf ("\nEMAIL : ");
 	scanf  (" %[^\n]s", email);
 	printf ("\n================================================================================\n");
 	printf ("\n\n\n");
 	printf ("\t\t\t\t\t >>>> Konfirmasi Data Diri Anda <<<< \n");
    printf("\n\t\t\t\t\t  Nama         : %s",nama);
    printf("\n\t\t\t\t\t  Alamat       : %s",alamat);
	printf("\n\t\t\t\t\t  Nomor Telepon: %s",telp);
	printf("\n\t\t\t\t\t  Email        : %s",email);
	printf("\n\n\t\t\t\t\tKonfirmasi Pendaftaran Anda (Y/N) : ");
	getchar();
	konfirmasiPendaftaran = getchar();
 
	if (konfirmasiPendaftaran == 'y' || konfirmasiPendaftaran == 'Y'){
		system ("cls");
		printf ("SELAMAT ANDA SUDAH MENJADI MEMBER DARI RAYURI SPA ^_^ \n");
		getch();
		menuPegawai();
	}
	else if (konfirmasiPendaftaran == 'n' || konfirmasiPendaftaran == 'N'){
		goto pendaftaranMember;
	}
} 
