//=======================================================================//
//***********          Fungsi Untuk Tentang Kami         ****************//
//=======================================================================//
// Nama Fungsi    : tentangKami                                             //
// Input Argumen  : int tentangKami                                      //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan informasi tentang       //
//                  Rayuri Spa.                                          //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl: 22-12-2020                                 Tgl: -                //
//=======================================================================//

//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void);
//fungsi untuk menampilkan menu jasa dan paket yang tersedia di spa
void menuJasa(void);
//fungsi untuk menampilkan apabila input salah
void inputSalah(void);

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