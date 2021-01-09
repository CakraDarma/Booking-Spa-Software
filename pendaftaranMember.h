//=======================================================================//
//***********       Fungsi Untuk Pendaftaran Member      ****************//
//=======================================================================//
// Nama Fungsi    : pendaftaranMember                                    //
// Input Argumen  : int member, char nama [100][30],                     //
//                  char alamat [100][100], char telp [50][50]           // 
//                  char email[80][20], char status[50][20]              //                        
// Output Argumen : int i, char nama [100][30],                          //
//                  char alamat [100][100], char telp [50][50]           // 
//                  char email[80][20], char status[50][20]              // 
//                  time_t ambil_waktu2, time(&ambil_waktu2)             //
// Deskripsi      : Fungsi untuk mendaftarkan member apabila customer    //
//                  sudah pasti ingin menjadi member di Rayuri Spa       //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.2                                    Rev. 1                  //
// Tgl   : 22-12-2020                            Tgl: 29-12-2020         //
// Revisi 1       : Memperbaiki dan merapikan.                           //
//                  Menambahkan kuitansi pendaftaran member dalam file.  //
//                  txt.                                                 //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 2                //
//                                                 Tgl: 30-12-2020       //
// Revisi 2       : Memperbaiki ouput karena masih error di bagian nama  //
//                  dan perulangan.                                      //
 //                 Merapikan program dan output dalam file.txt.         //
// Direvisi Oleh  : Ayulia - 2005551059                                  //
//=======================================================================//
//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk masuk ke menu pegawai
void menuPegawai(void);

void pendaftaranMember(){
        system ("cls");
        pendaftaranMember :
        header();
        char nama [100][30], alamat [100][100], telp [50][50], email[80][20], status[50][20];
        int member;
        int i;
        char konfirmasiPendaftaran;
        printf ("\n\n");
        printf ("\t\t\t\t************* RAYURI SPA MEMBER ************* \n");
        printf ("\t\t\t\t********************************************* \n");
        printf ("\nBerapa jumlah member yang akan ditambahkan ? ");
        scanf  ("%d", &member);
        printf ("\n");
 
        for (i=1; i<=member; i++){
        	printf ("\nMasukkan data diri pelanggan %d: ", i) ;
        	printf("\n");
        	printf ("Nama          : ");
    		scanf  (" %[^\n]s",&nama[i][i]);
        	printf ("Alamat        : ");
        	scanf  (" %[^\n]s",&alamat[i][i]);
        	printf ("No. Telepon   : ");
        	scanf  (" %[^\n]s",&telp[i][i]);
        	printf ("Email Member  : ");
        	scanf  (" %[^\n]s", &email[i][i]);
        	printf ("Status Member : ");
        	scanf  (" %[^\n]s", &status[i][i]);
        	printf("\n");
        }
        	printf ("\n================================================================================\n");
        	printf ("\n\n\n");
            printf ("\t         SELAMAT ANDA SUDAH MENJADI MEMBER DARI RAYURI SPA ^_^ \n");
             FILE * fPointer2;
        		fPointer2 = fopen ("Data Member Rayuri Spa.txt", "a+");
        		fprintf (fPointer2, "\n");
                fprintf (fPointer2, "=====================================================================================================================================\n");
                fprintf (fPointer2, "                                             A N G G O T A  M E M B E R  R A Y U R I  S P A \n");
                fprintf (fPointer2, "=====================================================================================================================================\n");
                fprintf (fPointer2, "%3s", "No");
                fprintf (fPointer2, "%20s", "Nama Customer");
                fprintf (fPointer2, "%20s", "Alamat Customer");
                fprintf (fPointer2, "%20s", "No. Telp");
                fprintf (fPointer2, "%30s", "Email");
                fprintf (fPointer2, "%20s\n", "Status");
                for(i=1; i<=member; i++){
                	fprintf (fPointer2, "%3i", i);
                	fprintf (fPointer2, "%20s", &nama[i][i]);
                	fprintf (fPointer2, "%20s", &alamat[i][i]);
                	fprintf (fPointer2, "%20s", &telp[i][i]);
                	fprintf (fPointer2, "%30s", &email[i][i]);
                	fprintf (fPointer2, "%20s\n", &status[i][i]);}
        		fprintf (fPointer2, "======================================================================================================================================\n");
        		fclose(fPointer2);
        getch(); 
        menuPegawai();     
}