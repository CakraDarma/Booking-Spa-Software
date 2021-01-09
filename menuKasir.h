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
//                  nama pelanggan dan perulangannya sebelumnya.         //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//                                                 Rev. 2                //
//                                                 Tgl: 28-12-2020       //
// Revisi 2       : Merapikan program untuk tampilan output.             //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//                                                 Rev. 3                //
//                                                 Tgl: 29-12-2020       //
// Revisi 3       : Menambahkan pilihan status member customer dan       //
//                  mengedit totalhargakeseluruhan untuk menambahkan     //
//                  diskon tergantung status member yang dipilih         //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 4                //
//                                                 Tgl: 29-12-2021       //
// Revisi 4       : Menjadikan fungsi yang awalnya terpisah menjadi      //
//                  satu kesatuan fungsi kasir.                          //
//                  Memperbaiki output tampilan Dp.                      //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);
//fungsi untuk mencetak nota pembayaran customer
void cetaknota(const char * namaPelanggan, const char * noHp, int i, int jumlah[100], int harga[100], int totalharga[100], char namapaket[100][30], int totalhargakeseluruhan, int DP, int pembayaran, int kembali, int paket, int sisapembayaran);
//fungsi untuk masuk ke menu pegawai
void menuPegawai(void);

void menuKasir(void){
	menuKasir:
	system("cls");
	char namaPelanggan[100], noHp[100], namapaket[100][30];
	int i, paket, harga[100], jumlah[100], totalharga[100], DP, pembayaran, pilih, totalhargakeseluruhan, sisapembayaran, kembali; 
    totalhargakeseluruhan = 0;
    header();
    //input identitas pelanggan
    printf("Nama Pelanggan              : ");
    scanf(" %[^\n]s",namaPelanggan);
    printf("No Hp                       : ");
    scanf(" %[^\n]s",noHp);

    //input total paket
    printf("====================================================\n");
	printf("Total Jumlah Paket          : ");
	scanf("%i", &paket);
    printf(" \n");

    //perulangan untuk jumlah paket
	for(i=1; i<=paket; i++){
		printf("Nama Paket ke-%i             : ", i);
        scanf(" %[^\n]s",&namapaket[i][i]);
		printf("Harga Paket %i               : Rp. ", i);
		scanf("%i", &harga[i]);
		printf("Jumlah                      : ");
		scanf("%i", &jumlah[i]);
        printf(" \n");
	}

 	//perhitungan harga
	for(i=1; i<=paket; i++){
		totalharga[i] =jumlah[i]*harga[i];
		totalhargakeseluruhan = totalhargakeseluruhan + totalharga[i];
	}

 	//output menampilkan daftar belanja customer
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
 	
 	//pilihan status member untuk mendapatkan diskon
	printf("=====================================================================================\n\n");
	printf ("\t\tPilih Status Member Anda Di Bawah Ini. \n");
	printf ("\t\t  1. Silver \n");
	printf ("\t\t  2. Gold \n");
	printf ("\t\t  3. Non Member\n");
	printf ("\t\tMasukkan status member anda : ");
	scanf  ("%d", &pilih);
	printf ("\n");
 
 	//perhitungan diskon untuk member
	if (pilih == 1){
		totalhargakeseluruhan = 0.95 * totalhargakeseluruhan;
	}
	else if (pilih ==2){
		totalhargakeseluruhan = 0.90 * totalhargakeseluruhan;
	}
	else{
		inputSalah();
	}
 
 	//menampilkan total harga keseluruhan
	printf("=====================================================\n\n");
	printf("Total Harga Keseluruhan     : Rp. %i\n", totalhargakeseluruhan);
 
 	//menghitung besar DP dan menampilkannya
 	DP = totalhargakeseluruhan * 0.5;
	printf("DP                          : Rp. %i\n", DP);
 
 	//menghitung sisa pembayaran dan menampilkannya
	sisapembayaran = totalhargakeseluruhan - DP;
	printf("Sisa Pembayaran	            : Rp. %i\n", sisapembayaran);
 
 	//menampilkan pembayaran
	printf("Pembayaran                  : Rp. ");
	scanf("%i", &pembayaran);
 
	if(pembayaran>=sisapembayaran)                                                 //jika pembayaran>=sisa pembayaran akan ditampilkan total harga keseluruhan dan pembayaran
	{	printf("=====================================================\n");
		printf("Total Harga                 : Rp. %i\n", totalhargakeseluruhan);
		printf("Pembayaran                  : Rp. %i\n", pembayaran);
		if(pembayaran>sisapembayaran){
			kembali = pembayaran - sisapembayaran;                                 //jika pembayaran>sisa pembayaran akan dilakukan perhitungan dan output kembali
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
		printf ("|                  TRANSAKSI GAGAL		              |\n");        //output untuk menampilkan transaksi gagal
		system("pause");
		goto menuKasir;
	}
	cetaknota(namaPelanggan, noHp, i, jumlah, harga, totalharga, namapaket, totalhargakeseluruhan, DP, pembayaran, kembali, paket, sisapembayaran);
	getch();
	menuPegawai();    
}