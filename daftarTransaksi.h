
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Daftar Transaksi   *************//
//=======================================================================//
// Nama Fungsi    : daftarTransaksi                                      //
// Input Argumen  : void                                                //
// Output Argumen : char buff [255]                                      //
// Deskripsi      : Fungsi ini digunakan untuk menampilkan daftar        //
//                  transaksi yang telah dipesan oleh customer.          //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl   : 27-12-2020                              Tgl: -                //
//=======================================================================//

//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void);

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
 