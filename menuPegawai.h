
//=======================================================================//
//***********    Fungsi Untuk Menampilkan Menu Staff     ****************//
//=======================================================================//
// Nama Fungsi    : menuPegawai                                          //
// Input Argumen  : int menuPegawai                                      //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini digunakan untuk menampilkan  menu, yang   //
//                  terdiri dari kasir yang digunakan saat melakukan     //
//                  pembayaran. Setelah itu, di menu pegawai juga kita   //
//                  bisa melakukan pendaftaran member dan absensi pegawai//
//                  serta penggajian pegawai.                            //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.3                                     Rev. 1                //
// Tgl: 5-12-2020                                  Tgl: 22-12-2020       //
// Revisi 1       : Menambahkan menu daftar member.                      //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 2                //
//                                                 Tgl: 28-12-2020       //
// Revisi 1       : Menambahkan menu absen pegawai.                      //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//                                                 Rev. 3                //
//                                                 Tgl: 29-12-2020       //
// Revisi 1       : Menambahkan menu penggajian pegawai.                 //
// Direvisi Oleh  : Sri - 2005551121                                     //
//=======================================================================// 
//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk menampilkan menu kasir untuk menyelesaikan pembayaran
void menuKasir(void);
//syarat mendaftarkan member
void rulesMember(void);
//fungsi untuk rekap absensi pegawai
void menuAbsensi(void);
//fungsi untuk menggaji pegawai
void penggajianPegawai (void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);

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