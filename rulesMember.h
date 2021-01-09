
//=======================================================================//
//*********  Fungsi Untuk Menampilkan Rules Member Rayuri Spa  **********//
//=======================================================================//
// Nama Fungsi    : rulesMember                                          //
// Input Argumen  : int registrasi                                       //
//                  int daftar                                           //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi untuk menampilkan rules member dari rayuri spa//
//                  kepada customer sebelum lanjut ke pendaftaran member.//
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.1                                    Rev. 1                 //
// Tgl   : 22-12-2020                             Tgl: 29-12-2020        //
// Revisi 1       : Mengedit isi dari rules member dari Rayuri Spa       //
// Direvisi Oleh  : Sri - 2005551121.                                    //
//=======================================================================//
//fungsi untuk menampilkan header program
void header(void);
//fungsi pendaftaran member
void pendaftaranMember(void);
//fungsi untuk masuk ke menu pegawai
void menuPegawai(void);

 void rulesMember(void){
 	rulesMember :
 	header();
	int registrasi;
	int daftar;
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
 