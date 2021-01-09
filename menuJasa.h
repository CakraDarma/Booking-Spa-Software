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

//fungsi untuk menampilkan header program
void header(void);
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
//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void);
//fungsi untuk mencetak kuitansi pembayaran DP apabila customer sudah selesai memesan
void cetakKuitansi(const char * namaPelanggan,const char * noHp, const char * alamat, const char * namaJasa[100][30], int totaljumlahharga, int totalrDp, const char * waktu1, const char * waktu2, int i, int paket);


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