//=======================================================================//
//***********         Fungsi Untuk Menu Bantuan          ****************//
//=======================================================================//
// Nama Fungsi    : menuBantuan                                          //
// Input Argumen  : int bantuan, int tentangProgram, int caraMenggunakan //
//                  int FAQ, char input.                                 //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan menu bantuan apabila    //
//                  user kesulitan dan tidak mengerti dalam penggunaan   //
//                  program.                                             //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.4                                     Rev. 1                //
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
//                                                 Rev. 4                //
//                                                 Tgl: 30-12-2020       //
// Revisi 4       : Mengedit isi pada menu cara menggunakan di menu      //
//                  bantuan dan menambahkan header pada menu reset       //
//                  program.                                             //
// Direvisi Oleh  : Sri - 2005551121                                     //
//=======================================================================//

//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);

char kuitansi[50] = "kuitansi"; 

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