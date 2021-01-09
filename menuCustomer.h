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

//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk menampilkan menu jasa dan paket yang tersedia di spa
void menuJasa(void);
//fungsi untuk menampilan menu bantuan apabila user kesulitan dan tidak menegerti dalam penggunaan program
void menuBantuan(void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);
//fungsi untuk mengkonfirmasi pemesanan
void konfirmasiPemesanan(void);
//fungsi untuk rekap absensi pegawai
void daftarTransaksi(void);
//fungsi menampilkan daftar transaksi
void daftarTransaksi(void);
//fungsi untuk menampilkan rekomendasi pembelian paket spa
void menurekomen(void);
//fungsi untuk mwnampilkan informasi tentang Spa kami
void tentangKami(void);


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