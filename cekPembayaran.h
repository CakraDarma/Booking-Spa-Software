//=======================================================================//
//***********        Fungsi Untuk Mencetak Pembayaran       *************//
//=======================================================================//
// Nama Fungsi    : cekPembayaran                                        //
// Input Argumen  : void                                                 //
// Output Argumen : const char * bank                                    //
//                  const char * nama                                    //
//                  int noRekening                                       //
//                  int jumlahTransfer                                   //
//                  time_t waktuBayar                                    //
//                  time(&waktuBayar)                                    //
//                  char karakter
// Deskripsi      : Fungsi ini digunakan untuk mengecek pembayaran yang  //
//                  dilakukan oleh customer sebelumnya lalu setelah di   //
//                  cek, pembayaran tersebut akan di cetak dan akan      //
//                  disimpan ke dalam file.                              //
// Dibuat Oleh    : Cakra - 2005551075                                   //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl   : 27-12-2020                              Tgl: -                //
//=======================================================================//

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