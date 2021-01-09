 
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
// Versi : 1.2                                    Rev. 1                 //
// Tgl   : 5-12-2020                              Tgl: 6-12-2020         //
// Revisi 1       : Menampilkan waktu atau tanggal pada cetak nota.      //
// Direvisi Oleh  : Sri - 2005551121.                                    //
//                                                Rev. 2                 //
//                                                Tgl: 14-12-2020        //
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