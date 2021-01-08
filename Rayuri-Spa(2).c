#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
 
//PROTOTIPE PROGRAM
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
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * alamat, const char * namaJasa[100][30], int totaljumlahharga, int totalrDp, const char * waktu1, const char * waktu2, int i, int paket);
//fungsi untuk login sebagai pengguna(customer) atau staff
void login(void);
//fungsi untuk menampilkan menu apabila login sebagai pegawai/staff
void menuPegawai(void);
//fungsi untuk menampilkan menu kasir untuk menyelesaikan pembayaran
void menuKasir(void);
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
//fungsi untuk rekap absensi pegawai
void menuAbsensi(void);
//fungsi untuk menggaji pegawai
void penggajianPegawai (void);
 
char kuitansi[50] = "kuitansi"; 
char username[20];
char password [20];
struct Data{
    char nama[100];
    char password[100];
};
struct Data pengguna;
struct pegawai{
    char nama[100][30];
    int bulan, alpha, total;
}pegawai[100];
FILE*out;
 
int main() {
	judul();
	login();
return 0;
}
 
struct karyawan {
	char nama[50];
	int pokok;
	int bonus;
	int pinjaman;
	}gaji[100];
 
//=======================================================================//
//***********         Fungsi Untuk Menampilkan Judul     ****************//
//=======================================================================//
// Nama Fungsi    : judul                                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan judul program. Berisi   //
//                  informasi program ini dibuat oleh siapa dan halaman  //
//                  awal bagian pemesanan dengan nama spa                //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl   : 1-12-2020                               Tgl: 22-12-2020       //
// Revisi 1       : Memperlengkap isinya dan mempercantik. Menambah      //
//                  system color, keterangan informasi program, dan      //
//                  halaman awal bagian pemesanan                        //
// Direvisi Oleh  : Sri - 2005551121                                     //
//=======================================================================//
void judul(void){
	system("cls");
	system("color 79");
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
	printf ("\t\n\n\n\n\n\n\n\n"); //Halaman awal bagian pemesanan dengan nama spa
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
 
//=======================================================================//
//***********  Fungsi Untuk Menampilkan Header Program   ****************//
//=======================================================================//
// Nama Fungsi    : header                                               //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan header program. Berisi  //
//                  informasi berupa nama, alamat, no.telp.              //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.0                                     Rev. 1                //
// Tgl   : 1-12-2020                               Tgl: 22-12-2020       //
// Revisi 1       : Merapikan isi fungsi                                 //
// Direvisi Oleh  : Sri - 2005551121                                     //
//=======================================================================//
//fungsi untuk menampilkan header program
void header(void){
	printf("\n\n\n\t\t    RAYURI SPA                            \n");
	printf("\t\t Jl. Kenangan No.666                            \n");
	printf("\t\tNo. Telp 08123456789                            \n");
	printf("****************************************************\n");
 
}
 
//=======================================================================//
//***********       Fungsi Untuk Menampilkan login       ****************//
//=======================================================================//
// Nama Fungsi    : login                                                //
// Input Argumen  : int pilihPengguna                                    //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan pilihan login sebagai   //
//                  customer atau staff. Jika input 1 akan diarahkan ke  //
//                  customer dan jika input 2 akan diarahkan ke staff    //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.2                                     Rev. 1                //
// Tgl   : 9-12-2020                               Tgl: 10-12-2020       //
// Revisi 1       : Menambahkan agar customer dapat melakukan login dan  //
//                  sign up.                                             //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//                                                 Rev. 2                //
//                                                 Tgl: 27-12-2020       //
// Revisi 2       : Membenahi fungsi login sehingga akses data bisa      //
//                  berdasarkan tiap akun pengguna                       //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//=======================================================================//
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
				printf("\n\n\t\t ********************");
				printf("\n\n\t\t *REGISTER BERHASIL!*");
				printf("\n\n\t\t ********************");
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
	            printf("\n\n\t    Selamat anda berhasil masuk!");
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
 
//=======================================================================//
//***********          Fungsi Untuk Menu Customer        ****************//
//=======================================================================//
// Nama Fungsi    : menuCustomer                                         //
// Input Argumen  : int menuCustomer                                     //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan menu customer apabila   //
//                  sebelumnya di menu login memilih login sebagai       //
//                  customer.                                            //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.2                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 9-12-2020        //
// Revisi 1       : Merapikan.                                           //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 2                //
//                                                 Tgl: 28-12-2020       //
// Revisi 2       : Mengubah urutan.                                     //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
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
	printf ("|[3] DAFTAR TRANSAKSI                         |\n");
	printf ("|[4] REKOMENDASI                              |\n");
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
			daftarTransaksi();
		}
		else if(menuCostumer==4){
			menurekomen();
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
 
//=======================================================================//
//***********            Fungsi Untuk Menu Jasa          ****************//
//=======================================================================//
// Nama Fungsi    : menuJasa                                             //
// Input Argumen  : const char * namaJasa[100][30], int i, int paket,    //
//                  char teruskanPemesanan, char jumlah[100]             //
//                  char namaPelanggan[100], char noHp[20],              //
//                  char alamat[50], char waktu1[40], char waktu2[20]    // 
// Output Argumen : const char * namaJasa[100][30], char jumlah[100]     // 
//                  int i, int harga[100], intbayarDp[100],              //    
//                  char namaPelanggan[100], char noHp[20],              //   
//                  char alamat[50], char waktu1[40], char waktu2[20]    //                
// Deskripsi      : Fungsi ini untuk menampilkan menu jasa yang tersedia //
//                  di spa. User bisa langsung memilih dan memesan       //
//                  paket.                                               //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.2                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 27-12-2020       //
// Revisi 1       : Merapikan fungsi dan menambahkan di teruskan         //
//                  pemesanan.                                           //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//                                                 Rev. 2                //
//                                                 Tgl: 28-12-2020       //
// Revisi 2       : Menambahkan perulangan saat pemesanan paket.         //
//                  Memperbaiki perhitungan dan output yang ditampilkan. //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void menuJasa(void){
	menuJasa:
	system("cls");
	header();
	const  float dp = 0.5;
	const char * namaJasa[100][30];
 
	int i, bayarDp[100], harga[100], paket, menuJasa[100], totaljumlahharga = 0, totalDp = 0;
	char teruskanPemesanan, jumlah[100], dataBenar;
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
 
	printf("Ingin memesan berapa paket? "); //memilih jumlah jasa yang diinginkan
	scanf("%i", &paket);
 
	for(i=1; i<=paket; i++){                 //perulangan dalam memilih jasa
		printf("\n\nPilih paket ke-%i   : " , i);
		scanf("%i", &menuJasa[i]);
		printf("Jumlah             : " , i);
		scanf("%i", &jumlah[i]);
		printf("\n");
	   	// insialisasi harga dan nama jasa
		if(menuJasa[i]==1){
			harga[i]= 190000;
			namaJasa[i][i]= "SIMPLE SENSE";
			//fungsi untuk menampilkan rincian jasa 1
			tampilkanRincianJasa1();
			getch();
	 	}
		else if(menuJasa[i]==2){
			harga[i]= 205000;
			namaJasa[i][i]= "SERENITY SENSE";
			//fungsi untuk menampilkan rincian jasa 2
			tampilkanRincianJasa2();
			getch();
		}
		else if(menuJasa[i]==3){
			harga[i] = 265000;
			namaJasa[i][i] = "REFRESH SENSE";
			//fungsi untuk menampilkan rincian jasa 3
			tampilkanRincianJasa3();
			getch();
		}
		else if(menuJasa[i]==4){
			harga[i] = 330000;
			namaJasa[i][i] = "FIRMING SENSE";
			//fungsi untuk menampilkan rincian jasa 4
			tampilkanRincianJasa4();
			getch();
		}
		else if(menuJasa[i]==5){
			harga[i] = 370000;
			namaJasa[i][i] = "BALANCE SENSE";
			//fungsi untuk menampilkan rincian jasa 5
			tampilkanRincianJasa5();
			getch();
		}
		else if(menuJasa[i]==6){
			harga[i] = 530000;
			namaJasa[i][i] = "DETOX SENSE";
			//fungsi untuk menampilkan rincian jasa 6
			tampilkanRincianJasa6();
			getch();
		}
		else if(menuJasa[i]==7){
			harga[i] = 580000;
			namaJasa[i][i] = "ABSOLUTE SENSE";
			//fungsi untuk menampilkan rincian jasa 7
			tampilkanRincianJasa7();
			getch();
		}
		else if(menuJasa[i]== 8){
	   		menuCostumer();
	   	}
	   	else{
	   		inputSalah();
	   		goto menuJasa;
		}
 
	}
 
	//perhitungan untuk pembayaran
	for(i=1; i<=paket; i++){
		harga[i] = harga[i] * jumlah[i];
		bayarDp[i] = harga[i] * dp;
		totaljumlahharga= totaljumlahharga + harga[i];
		totalDp = totalDp + bayarDp[i];
	}
 
	printf("\n\n");
	printf("================================================================\n");
	printf("%20s", "Pilihan");
	printf("%10s", "Jumlah");
	printf("%15s", "Total Harga");
	printf("%15s\n", "Dp");
	printf("================================================================\n");
 
	for(i=1; i<=paket; i++){
		printf("%20s",namaJasa[i][i]);
		printf("%10i",jumlah[i]);
		printf("%15d",harga[i]);
		printf("%15d\n",bayarDp[i]);
	}
 
	//menampilkan total harga, total dp, dan melanjutkan ke pemesanan
	printf("================================================================\n");
	printf("%30s", "GRAND TOTAL");
	printf("%15d", totaljumlahharga);
	printf("%15d\n", totalDp);
	printf(" Teruskan Pemesanan? (y/n)     : ");
	getchar();
	teruskanPemesanan = getchar();
	printf("|===============================================================|\n\n");	
 
	pembayaran:;
	char namaPelanggan[100] ;
	char noHp[20];
	char alamat[50];
	char waktu1[40];
	char waktu2[20];
 
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
		printf("|====================================================|\n\n");
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
    	cetakKuitansi(namaPelanggan,noHp,alamat,namaJasa,totaljumlahharga,totalDp,waktu1,waktu2,i,paket);
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
 
//=======================================================================//
//***********          Fungsi Untuk Menu Customer        ****************//
//=======================================================================//
// Nama Fungsi    : menuJasa                                             //
// Input Argumen  : int tentangKami                                      //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan informasi tentang       //
//                  Rayuri Spa.                                          //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl: 22-12-2020                                 Tgl: -                //
//=======================================================================//
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
 
 
//=======================================================================//
//***********         Fungsi Untuk Menu Bantuan          ****************//
//=======================================================================//
// Nama Fungsi    : menuBantuan                                          //
// Input Argumen  : int bantuan, int tentangProgram, int caraMenggunakan //
//                  int FAQ, char input                                  //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan menu bantuan apabila    //
//                  user kesulitan dan tidak mengerti dalam penggunaan   //
//                  program                                              //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.3                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 22-12-2020       //
// Revisi 1       : Merapikan dan menambahkan 3 case yaitu tentang       //
//                  program, cara menggunakan, dan kembali ke menu       //
//                  sebelumnya.                                          //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 2                //
//                                                 Tgl: 27-12-2020       //
// Revisi 2       : Menambahkan case 4 yaitu delete yang mana akan       //
//                  membuat user menghapus semua data riwayat transaksi. //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//                                                 Rev. 3                //
//                                                 Tgl: 28-12-2020       //
// Revisi 3       : Menambahkan 1 case yaitu FAQ atau pertanyaan yang    //
//                  kira-kira sering ditanyakan oleh customer.           //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void menuBantuan(void){
	menuBantuan:
	system("cls");
	header();
	int bantuan;
	printf ("|=============================================|\n");
	printf ("|                MENU BANTUAN                 |\n");
	printf ("|=============================================|\n");
	printf ("|[1] TENTANG PROGRAM                          |\n");//Menjelaskan tentang program pemesanan kamar hotel
	printf ("|[2] CARA MENGGUNAKAN                         |\n");//Menjelaskan cara menggunakan program pemesanan kamar hotel
	printf ("|[3] FAQ                                      |\n");//Penjelasan tentang pertanyaan yang kira-kira sering diajukan customer (FAQ)
	printf ("|[4] RESET PROGRAM                            |\n");//fungsi ini akan mendelete semua file
	printf ("|[5] KEMBALI                                  |\n");//Kembali pada menu utama
	printf ("|=============================================|\n");
 	printf("Silahkan pilih :");                                  // User diminta untuk memilih pilihan diantara 5 pilihan tersebut
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
   		printf ("|Pengguna kartu member akan diberi discount sebesar 5 persen  |\n");
   		printf ("|untuk pengguna Member Silver dan 20 persen untuk pengguna    |\n");
   		printf ("|Member Gold                                                  |\n");
		printf ("|=============================================================|\n");
   		getch();
   		menuBantuan();
   		case 3:
   		system("cls");
		header();
		int FAQ;
		printf ("\n\n");
		printf ("|=================================================================================|\n");
		printf ("|                                  * RAYURI SPA *                                 |\n");
		printf ("|                                  **************                                 |\n");
		printf ("|                                                                                 |\n");
		printf ("|                           PERTANYAAN YANG SERING DIAJUKAN                       |\n");
		printf ("|                                                                                 |\n");
		printf ("| [A] Q : Bagaimana jika kulit saya sensitive?                                    |\n");
		printf ("|     A : Kami menyediakan banyak jenis product untuk berbagai jenis kulit,       |\n"); 
		printf ("|         bila anda memiliki masalah khusus dengan kulit anda,                    |\n"); 
		printf ("|         mohon diberitahukan sebelumnya                                          |\n"); 
		printf ("|                                                                                 |\n");
		printf ("| [C] Q : Apakah ada batas usia?                                                  |\n");
		printf ("|     A : Dianjurkan batas usia minimal 12 tahun                                  |\n"); 
		printf ("|                                                                                 |\n");
		printf ("| [E] Q : Apa yang terjadi jika saya membatalkan pemesanan?                       |\n");
		printf ("|     A : Hubungi kontak yang tertera. Pembayaran Anda bisa kembali 100%          |\n");
		printf ("|         apabila Anda melakukan pembatalan dalam kurun waktu kurang dari 24 jam  |\n");
		printf ("|         dari waktu pemesanan                                                    |\n");
		printf ("|=================================================================================|\n");
		getch();
   		menuBantuan();
   		//mendelete semua file
   		case 4:
   		system("cls");
   		header ();
   		char input;
   	    printf ("|=============================================================|\n");
		printf ("|                        * RAYURI SPA *                       |\n");
		printf ("|                        **************                       |\n");
		printf ("|                                                             |\n");
		printf ("|      Mendelete Semua data Transaksi Anda Menjadi koson      |\n");
		printf ("|                                                             |\n");
		printf ("|                      - PERINGATAN DATA -                    |\n");
		printf ("|                    TRANSAKSI ANDA AKAN HILANG               |\n");
		printf ("|                DAN TIDAK BISA DIKEMBALIKAN LAGI             |\n");
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
	    case 5:
   		menuCostumer();
   		default:
   		inputSalah();
   		goto menuBantuan;
 	}
 
}
 
//=======================================================================//
//***********     Fungsi Untuk Menampilkan Input Salah   ****************//
//=======================================================================//
// Nama Fungsi    : inputSalah                                           //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan apabila inputan user    //
//                  salah dan tidak sesuai.                              //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl   : 5-12-2020                               Tgl: 10-12-2020       //
// Revisi 1       : Memperbaiki dan merapikan                            //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//=======================================================================//
void inputSalah(void){
	system("cls");
	printf("\nINPUT ANDA ADA SALAH\n");
	system("pause");
	}
 
//=======================================================================//
//***********        Fungsi Untuk Cetak Kuitansi         ****************//
//=======================================================================//
// Nama Fungsi    : cetakKuitansi                                        //
// Input Argumen  : -                                                    //
// Output Argumen : const char * namaPelanggan,const char * noHp,        //
//                  const char * alamat, const char * namaJasa[100][30], //
//                  int totaljumlahharga, int totalDp,                   //
//                  const char * waktu1, const char * waktu2, int i,     //
//                  int paket, time_t ambil_waktu1, time(&ambil_waktu1)  //
// Deskripsi      : Fungsi untuk mencetak kuitansi apabila customer      //
//                  sudah selesai melakukan pembayaran Dp.               //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.3                                     Rev. 1                //
// Tgl   : 5-12-2020                               Tgl: 14-12-2020       //
// Revisi 1       : Memperbaiki dan merapikan.                           //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//                                                 Rev. 2                //
//                                                 Tgl: 27-12-2020       //
// Revisi 2       : Mengubah file open yang awalnya kuitansi.txt         //
//                  menjadi pengguna.nama serta menambahkan time.        //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//                                                 Rev. 3                //
//                                                 Tgl: 28-12-2020       //
// Revisi 3       : Mengubah pemanggilan total harga dan DP untuk        //
//                  menyesuaikan dengan perulangan di menu jasa.         //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * alamat, const char * namaJasa[100][30], int totaljumlahharga, int totalDp, const char * waktu1, const char * waktu2, int i, int paket){
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
 	for(i=1; i<=paket; i++){
 		 fprintf (fpointerkuitansiCostumer, "%s\n",namaJasa[i][i]);     
 	}
    fprintf (fpointerkuitansiCostumer, "Total Harga                               : %d\n",totaljumlahharga);
    fprintf (fpointerkuitansiCostumer, "----------------------------------------------------------------------------------------------------------------\n"); 
    fprintf (fpointerkuitansiCostumer, "                                                      DP                                                        \n");            
    fprintf (fpointerkuitansiCostumer, "                                                 Rp. %d\n", totalDp);    
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
    	printf("[2] Kembali\n\n");
    	int pilihKonfirmasi;
	   	printf("pilih                               : ");
	    scanf("%d",&pilihKonfirmasi);
	    if (pilihKonfirmasi==1){
	    	konfirmasi:;
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
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa1                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Simple Sense. Di sini dijelaskan keterangan jasa.    //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void tampilkanRincianJasa1(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                          SIMPLE SENSE                                              |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                         Body Massage with aromatherapy and face massage                            |\n");
	printf("|      Perawatan ini disarankan untuk para pekerja yang sibuk dan tetap harus berpenampilan prima.   |\n");
	printf("|     Perawatan dimulai dengan pijat badan dengan aromatherapy dan dilanjutkan dengan pijat wajah.   |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                      | 1.5 hours Rp 190.000,- |                                    |\n");
	printf("|****************************************************************************************************|\n");
}
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa2                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Serenity Sense. Di sini dijelaskan keterangan jasa.  //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void tampilkanRincianJasa2(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                         SERENITY SENSE                                             |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                          Body massage with aromatherphy and Body scrub                             |\n");
	printf("|     Temukan kedamaian dalam diri Anda. Paket perawatan ini didesain untuk pelanggan yang ingin     |\n");
	printf("|    sepenuhnya relaks dan menjaga kesehatan kulit anda. Perawatan dimulai dari aromaterapi pijat    |\n");
	printf("|   badan untuk merilekskan badan dan pikiran, dilanjutkan dengan pilihan lulur untuk membersihkan   |\n");
	printf("|                             kulit mati dan dilanjutkan dengan shower.                              |\n");  
	printf("|****************************************************************************************************|\n");     
	printf("|                                       | 1.5 Hours Rp 205.000,- |                                   |\n");                                
	printf("|****************************************************************************************************|\n"); 
}
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa3                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Refresh Sense. Di sini dijelaskan keterangan jasa.   //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void tampilkanRincianJasa3(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                            REFRESH SENSE                                           |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                     Body Massage (Traditional), Face Massages, Luxury Bath                         |\n");
	printf("|    Perawatan ini membantu untuk mengembalikan kesegaran tubuh anda. Dimulai dengan pilihan pijat   |\n");
	printf("|       badan dan dilanjutkan dengan pijat wajah kemudian dilanjutkan dengan jenis rendaman yang     |\n");
	printf("|                                             diinginkan.                                            |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                       | 1 Hour Rp 265.000,- |                                      |\n");
	printf("|****************************************************************************************************|\n");
}
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa4                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Balance Sense. Di sini dijelaskan keterangan jasa.   //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void tampilkanRincianJasa4(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                         BALANCE SENSE                                              |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                           Body massage, Body steam, Body Mask, Ear Candling                        |\n");
	printf("|        Paket ini didesain untuk menyeimbangkan system tubuh dan menyegarkan tubuh. Perawatan       |\n");
	printf("|      dimulai dengan pijat badan dengan aromatherapy dan dilanjutkan dengan penguapan badan dan     |\n");
	printf("|                              setelahnya dimasker dan terapi telinga.                               |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                     | 2 Hours Rp 370.000,- |                                       |\n");
	printf("|****************************************************************************************************|\n");
}
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa5                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Detox Sense. Di sini dijelaskan keterangan jasa.     //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================// 
void tampilkanRincianJasa5(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                           DETOX SENSE                                              |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                   Body Massage, Body steam, Body Scrub, Body Mask, Bathing                         |\n");
	printf("|       Perawatan ini membantu mengeluarkan racun-racun dan lemak pada tubuh. Dianjurkan untuk       |\n");
	printf("|     mengambil paket ini sebanyak 10 kali unruk hasil yang maksimal dan dilakukan seminggu sekali.  |\n");
	printf("|    Perawatan ini dimulai dari pijat badan dengan aromaterapi, kemudian dilanjutkan dengan, lulur,  |\n");
	printf("|                            masker dan terakhir dengan mandi berendam.                              |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                         | 2.5 Hours Rp 530.000,- |                                 |\n");
	printf("|****************************************************************************************************|\n");   
}
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa6                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Firming Sense. Di sini dijelaskan keterangan jasa.   //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void tampilkanRincianJasa6(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                            FIRMING SENSE                                           |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                  Body scrub, Body mask, Body wrapping                              |\n");
	printf("|   Perawatan ini didesin untuk mengembalikan dan menjaga elastisitas kulit. Paket ini cocok untuk   |\n");
	printf("|   anda yang ingin menjaga kekenyalan kulit selagi menguruskan badan. Perwatan dimulai dari luluran |\n");
	printf("|   untuk mengangkat sel-sel kulit mati, dilanjutkan dengan body masker,kemudian dibungkus dengan    |\n");
	printf("|                                      menggunakan selimut elektrik.                                 |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                         | 1.5 Hours Rp 330.000,- |                                 |\n");
	printf("|****************************************************************************************************|\n");
}
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Rincian Jasa    ****************//
//=======================================================================//
// Nama Fungsi    : tampilkanRincianJasa7                                //
// Input Argumen  : void                                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan rincian jasa 1 yaitu    //
//                  Absolute Sense. Di sini dijelaskan keterangan jasa.  //
//                  terdapat pula jam dan harga dari jasa tersebut.      //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.1                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 28-12-2020       //
// Revisi 1       : Merapikan isi fungsi supaya lebih nyaman dilihat.    //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void tampilkanRincianJasa7(void){
	printf("|****************************************************************************************************|\n");
	printf("|                                           ABSOLUTE SENSE                                           |\n");  
	printf("|****************************************************************************************************|\n");
	printf("|                Body steam, Body scrub, Body mask, Bathing, Body & Face Massage                     |\n");
	printf("|   Ini merupakan perrawatan yang komplit dari kita untuk membantu anda mengembalikan kecantikan     |\n");
	printf("| diri dan ketenangan pikiran. Dimulai dari pijat badan dan muka, dilanjutkan dengan steam dan lulur |\n");
	printf("|   untuk membersihkan kulit-kulit yang mati dan dilanjutkan dengan masker badan untuk               |\n");
	printf("|      mendinginkan kulit dan membuatnya bercahaya dan diakhiri oleh mandi berendam.                 |\n");
	printf("|****************************************************************************************************|\n");
	printf("|                                       | 3 Hours Rp 580.000,- |                                     |\n");
	printf("|****************************************************************************************************|\n");
}
 
//fungsi untuk menampilkan menu apabila login sebagai pegawai/staff
void menuPegawai(void){
	menuPegawai:
	system("cls");
	header();
	int menuPegawai;
	printf ("|=============================================|\n");
	printf ("|            R A Y U R I   S P A              |\n");
	printf ("|=============================================|\n");
	printf ("|[1] KASIR                                    |\n");
	printf ("|[2] DAFTAR MEMBER                            |\n");
	printf ("|[3] ABSEN PEGAWAI                            |\n");
	printf ("|[4] PENGGAJIAN PEGAWAI                       |\n");
	printf ("|=============================================|\n");
	printf ("|[5] KELUAR                                   |\n"); // Pilihan untuk Keluar ke sebelumnya
	printf ("=============================================== \n");
	printf ("Silahkan pilih : "); // Memilih Jasa yang diinginkan
	scanf("%d", &menuPegawai);
 
	if(menuPegawai == 1){
		menuKasir();
	}
	else if(menuPegawai == 2){
		rulesMember();
	}
	else if(menuPegawai == 3){
		menuAbsensi();
	}
	else if(menuPegawai == 4){
		penggajianPegawai();
	}
	else if(menuPegawai == 5){
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
 
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Menu Rekomen    ****************//
//=======================================================================//
// Nama Fungsi    : menurekomen                                          //
// Input Argumen  : int keluhanTidakvalid, int nilai                     //
// Output Argumen : int total                                            //
// Deskripsi      : Fungsi ini untuk menampilkan menu rekomendasi jasa   //
//                  apabila user kebingungan memilih. Nanti akan         //
//                  disesuaikan dengan kode keluhan useer.               //
// Dibuat Oleh    : Ayulia - 2005551059                                  //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl: 5-12-2020                                  Tgl: -                //
//=======================================================================//
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
 
//=======================================================================//
//***********         Fungsi Untuk Menu Kasir            ****************//
//=======================================================================//
// Nama Fungsi    : menuKasir                                            //
// Input Argumen  : char namaPelanggan[100], char noHp[100],             //
//                  char namapaket[100][30], int i, int paket,           //
//                  int harga[100], int jumlah[100], int pembayaran      //
//                  int pilih                                            //
// Output Argumen : int i, char namapaket[100][30], int harga[100],      //
//                  int jumlah[100], int totalharga[100],                //
//                  int totalhargakeseluruhan, int DP,                   //
//                  int sisapembayaran, int pembayaran, int kembali      //
// Deskripsi      : Fungsi ini untuk menampilkan menu bantuan apabila    //
//                  user kesulitan dan tidak mengerti dalam penggunaan   //
//                  program                                              //
// Dibuat Oleh    : Ayulia - 2005551059                                  //
//                                                                       //
// Versi : 1.4                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 14-12-2020       //
// Revisi 1       : Merapikan program karena masih error di output       //
//                  nama pelanggan dan perulangannya.                    //
//                  sebelumnya.                                          //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//                                                 Rev. 2                //
//                                                 Tgl: 28-12-2020       //
// Revisi 2       : Merapikan program untuk tampilan output.             //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//                                                 Rev. 3                //
//                                                 Tgl: 29-12-2020       //
// Revisi 3       : Menambahkan pilihan status member customer untuk     //
//                  menambahkan diskon.                                  //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 4                //
//                                                 Tgl: 8-1-2021         //
// Revisi 4       : Menjadikan fungsi yang awalnya terpisah menjadi      //
//                  satu kesatuan fungsi kasir.                          //
//                  Memperbaiki output tampilan Dp.                      //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void menuKasir(void){
	menuKasir:
	system("cls");
	char namaPelanggan[100], noHp[100], namapaket[100][30];
	int i, paket, harga[100], jumlah[100], totalharga[100], DP, pembayaran, pilih, totalhargakeseluruhan, sisapembayaran, kembali; 
    totalhargakeseluruhan = 0;
    header();
    printf("Nama Pelanggan              : ");
    scanf(" %[^\n]s",namaPelanggan);
    printf("No Hp                       : ");
    scanf(" %[^\n]s",noHp);
 
    printf("====================================================\n");
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
 
    printf("=====================================================================================\n");
    printf("*********************                DAFTAR BELANJA             *********************\n");
    printf("=====================================================================================\n");
    printf("%3s", "No");
    printf("%20s", "Nama Paket");
    printf("%20s", "Harga");
    printf("%20s", "Jumlah");
    printf("%20s\n", "Total Harga");
    printf("=====================================================================================\n");
 
    for(i=1; i<=paket; i++){
        printf("%3i", i);
        printf("%20s", &namapaket[i][i]);
        printf("%20d", harga[i]);
        printf("%20d", jumlah[i]);
        printf("%20d\n", totalharga[i]);
    }
 
	printf("=====================================================================================\n\n");
	printf ("\t\tPilih Status Member Anda Di Bawah Ini. \n");
	printf ("\t\t  1. Silver \n");
	printf ("\t\t  2. Gold \n");
	printf ("\t\t  3. Non Member\n");
	printf ("\t\tMasukkan status member anda : ");
	scanf  ("%d", &pilih);
	printf ("\n");
 
	if (pilih == 1){
		totalhargakeseluruhan = 0.95 * totalhargakeseluruhan;
	}
	else if (pilih ==2){
		totalhargakeseluruhan = 0.90 * totalhargakeseluruhan;
	}
	else{
		inputSalah();
	}
 
	printf("=====================================================\n\n");
	printf("Total Harga Keseluruhan     : Rp. %i\n", totalhargakeseluruhan);
 
 	DP = totalhargakeseluruhan * 0.5;
	printf("DP                          : Rp. %i\n", DP);
 
	sisapembayaran = totalhargakeseluruhan - DP;
	printf("Sisa Pembayaran	            : Rp. %i\n", sisapembayaran);
 
	printf("Pembayaran                  : Rp. ");
	scanf("%i", &pembayaran);
 
	if(pembayaran>=sisapembayaran)
	{	printf("=====================================================\n");
		printf("Total Harga                 : Rp. %i\n", totalhargakeseluruhan);
		printf("Pembayaran                  : Rp. %i\n", pembayaran);
		if(pembayaran>sisapembayaran){
			kembali = pembayaran - sisapembayaran;
			printf("Kembali                     : Rp. %i\n", kembali);
		}
		printf("======================================================\n");
		printf ("|                      TERIMAKASIH                   |\n");
		printf ("|                TELAH MELAKUKAN TRANSAKSI           |\n");
		printf ("|                      DI RAYURI SPA                 |\n");
		printf("======================================================\n");
 
	}
	else
	{
		printf ("|                  TRANSAKSI GAGAL		              |\n");
		system("pause");
		goto menuKasir;
	}
	cetaknota(namaPelanggan, noHp, i, jumlah, harga, totalharga, namapaket, totalhargakeseluruhan, DP, pembayaran, kembali, paket, sisapembayaran);
	getch();
	menuPegawai();    
}
 
//=======================================================================//
//***********          Fungsi Untuk Cetak Nota           ****************//
//=======================================================================//
// Nama Fungsi    : cetaknota                                            //
// Input Argumen  : -                                                    //
// Output Argumen : const char * namaPelanggan,const char * noHp,        //
//                  int i, int jumlah[100], int harga[100],              //
//                  int totalharga[100], char namapaket[100][30],        //
//                  int totalhargakeseluruhan, int DP, int pembayaran,   //
//                  int kembali, int paket, int sisapembayaran           //
//                  time_t ambil_waktu2, time(&ambil_waktu2)             //
// Deskripsi      : Fungsi untuk mencetak nota pembayaran cusromer.      //
// Dibuat Oleh    : Ayulia - 2005551059                                  //
//                                                                       //
// Versi : 1.1                                    Rev. 1                 //
// Tgl   : 5-12-2020                              Tgl: 14-12-2020        //
// Revisi 1       : Memperbaiki dan merapikan.                           //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
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
	printf ("\t\t\t\t|4. Untuk mendaftar menjadi member tidak    | \n");
	printf ("\t\t\t\t|   dikenakan biaya apapun                  | \n");
	printf ("\t\t\t\t|5. Terdapat 2 jenis member dalam Rayuri Spa| \n");
	printf ("\t\t\t\t|   yaitu Member Silver dengan masa aktif 6 | \n");
	printf ("\t\t\t\t|   bulan dan Member Gold dengan masa aktif | \n");
	printf ("\t\t\t\t|   1 tahun                                 | \n");
	printf ("\t\t\t\t|6. Jika masa keanggotaan sudah habis maka  | \n");
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
 
//=======================================================================//
//***********       Fungsi Untuk Pendaftaran Member      ****************//
//=======================================================================//
// Nama Fungsi    : pendaftaranMember                                    //
// Input Argumen  : int member, char nama [100][30],                     //
//                  char alamat [100][100], char telp [50][50]           // 
//                  char email[80][20], char status[50][20]              //                        
// Output Argumen : int i, char nama [100][30],                          //
//                  char alamat [100][100], char telp [50][50]           // 
//                  char email[80][20], char status[50][20]              // 
//                  time_t ambil_waktu2, time(&ambil_waktu2)             //
// Deskripsi      : Fungsi untuk mencetak nota pembayaran cusromer.      //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.                                    Rev. 1                  //
// Tgl   : 22-12-2020                            Tgl: 29-12-2020         //
// Revisi 1       : Memperbaiki dan merapikan.                           //
//                  Menambahkan kuitansi pendaftaran member dalam file.  //
//                  txt.                                                 //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 2                //
//                                                 Tgl: 30-12-2020       //
// Revisi 2       : Memperbaiki ouput karena masih error di bagian nama  //
//                  dan perulangan.                                      //
 //                 Merapikan program dan output dalam file.txt.         //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
void pendaftaranMember(){
        system ("cls");
        pendaftaranMember :
        header();
        char nama [100][30], alamat [100][100], telp [50][50], email[80][20], status[50][20];
        int member;
        int i;
        char konfirmasiPendaftaran;
        printf ("\n\n");
        printf ("\t\t\t\t************* RAYURI SPA MEMBER ************* \n");
        printf ("\t\t\t\t********************************************* \n");
        printf ("\nBerapa jumlah member yang akan ditambahkan ? ");
        scanf  ("%d", &member);
        printf ("\n");
 
        for (i=1; i<=member; i++){
        	printf ("\nMasukkan data diri pelanggan %d: ", i) ;
        	printf("\n");
        	printf ("Nama          : ");
    		scanf  (" %[^\n]s",&nama[i][i]);
        	printf ("Alamat        : ");
        	scanf  (" %[^\n]s",&alamat[i][i]);
        	printf ("No. Telepon   : ");
        	scanf  (" %[^\n]s",&telp[i][i]);
        	printf ("Email Member  : ");
        	scanf  (" %[^\n]s", &email[i][i]);
        	printf ("Status Member : ");
        	scanf  (" %[^\n]s", &status[i][i]);
        	printf("\n");
        }
        	printf ("\n================================================================================\n");
        	printf ("\n\n\n");
            printf ("\t         SELAMAT ANDA SUDAH MENJADI MEMBER DARI RAYURI SPA ^_^ \n");
             FILE * fPointer2;
        		fPointer2 = fopen ("Data Member Rayuri Spa.txt", "a+");
        		fprintf (fPointer2, "\n");
                fprintf (fPointer2, "=====================================================================================================================================\n");
                fprintf (fPointer2, "                                             A N G G O T A  M E M B E R  R A Y U R I  S P A \n");
                fprintf (fPointer2, "=====================================================================================================================================\n");
                fprintf (fPointer2, "%3s", "No");
                fprintf (fPointer2, "%20s", "Nama Customer");
                fprintf (fPointer2, "%20s", "Alamat Customer");
                fprintf (fPointer2, "%20s", "No. Telp");
                fprintf (fPointer2, "%30s", "Email");
                fprintf (fPointer2, "%20s\n", "Status");
                for(i=1; i<=member; i++){
                	fprintf (fPointer2, "%3i", i);
                	fprintf (fPointer2, "%20s", &nama[i][i]);
                	fprintf (fPointer2, "%20s", &alamat[i][i]);
                	fprintf (fPointer2, "%20s", &telp[i][i]);
                	fprintf (fPointer2, "%30s", &email[i][i]);
                	fprintf (fPointer2, "%20s\n", &status[i][i]);}
        		fprintf (fPointer2, "======================================================================================================================================\n");
        		fclose(fPointer2);
        getch(); 
        menuPegawai();     
}
 
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
 
void penggajianPegawai (void){
	system ("cls");
	header();
	int jumlah; 
	int masaKerja;
	int i;
	int lanjutan;
	printf("\n\n\t\t\t\t\t\t\t==========================================\n");
	printf("\t\t\t\t\t\t\t|     PENGGAJIAN KARYAWAN RAYURI SPA   |\n");
	printf("\t\t\t\t\t\t\t========================================\n\n");
	printf("============================================\n");
	printf("MASUKKAN JUMLAH KARYAWAN YANG INGIN DIGAJI : ");
	scanf("%d", &jumlah);
	printf("============================================\n");
 
	for(i=0;i<jumlah; i++){
		printf ("\n");
		printf("MASUKKAN NAMA KARYAWAN KE-%d: ", i+1);
		fflush(stdin);
		gets (gaji[i].nama);
		printf("=============================\n");
		printf("MASUKKAN GAJI POKOK KARYAWAN: Rp. ");
		scanf("%d", &gaji[i].pokok);
		printf("MASUKKAN MASA KERJA(BULAN)  : ");
		scanf("%d", &masaKerja);
 
		if(masaKerja<12){
			gaji[i].bonus=0;
		}
		else if(masaKerja>=12 && masaKerja<36){
			gaji[i].bonus=500000;
		}
		else{
			gaji[i].bonus=1000000;
		}
		printf("MASUKKAN PINJAMAN           : ");
		scanf("%d", &gaji[i].pinjaman);
		printf("==============================\n");
	}
	printf("\n\n\n\t\t\t\t\t            		         =======  GAJI KARYAWAN ======= \n");
    printf("\t\t\t\t=======================================================================================================\n");
    printf("\t\t\t\t  NO |    NAMA           |   GAJI POKOK   |     BONUS    |   PINJAMAN  |  TOTAL GAJI  |  GAJI BERSIH  |\n");
    printf("\t\t\t\t=======================================================================================================\n");
    for (i = 0; i < jumlah; i++){
    	printf("\t\t\t\t  %d     %-15s        %d          %-10d     %-13d %-13d %d  \n", i + 1, gaji[i].nama, gaji[i].pokok, gaji[i].bonus, gaji[i].pinjaman, gaji[i].pokok + gaji[i].bonus, gaji[i].pokok + gaji[i].bonus - gaji[i].pinjaman);
	}
	printf("\t\t\t\t=======================================================================================================\n");
 
	FILE * fPointer;
	fPointer = fopen("Gaji Karyawan Rayuri Spa.txt", "a+");
	fprintf(fPointer, "\n");
 	fprintf(fPointer ,"            		         =======  GAJI KARYAWAN ======= \n");
    fprintf(fPointer ,"=======================================================================================================\n");
    fprintf(fPointer ,"  NO |    NAMA           |   GAJI POKOK   |     BONUS    |   PINJAMAN  |  TOTAL GAJI  |  GAJI BERSIH  |\n");
    fprintf(fPointer ,"=======================================================================================================\n");
 
	for (i = 0; i < jumlah; i++){
    fprintf(fPointer,"  %d     %-15s        %d          %-10d     %-13d %-13d %d  \n", i + 1, gaji[i].nama, gaji[i].pokok, gaji[i].bonus, gaji[i].pinjaman, gaji[i].pokok + gaji[i].bonus, gaji[i].pokok + gaji[i].bonus - gaji[i].pinjaman);
	}
	fprintf(fPointer,"=======================================================================================================\n");
  	fclose(fPointer);
 
	printf ("\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf ("Langkah Apa Yang Ingin Dilakukan Sekarang ? \n");
	printf ("	1. Kembali ke Menu Utama\n");
	printf ("	2. Kembali ke penggajian karyawan\n");
	printf ("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf ("Masukkan pilihan anda : ");
	scanf  ("%d", &lanjutan);
 
 
 
	if(lanjutan == 1){
		menuPegawai();
	}
	else if (lanjutan == 2){
		penggajianPegawai();
	}
	else{
		inputSalah();
	}
}
