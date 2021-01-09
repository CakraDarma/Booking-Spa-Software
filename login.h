//=======================================================================//
//***********       Fungsi Untuk Menampilkan login       ****************//
//=======================================================================//
// Nama Fungsi    : login                                                //
// Input Argumen  : int pilihPengguna                                    //
// Output Argumen : void                                                 //
// Deskripsi      : Fungsi ini untuk menampilkan pilihan login sebagai   //
//                  customer atau staff. Jika input 1 akan diarahkan ke  //
//                  customer dan jika input 2 akan diarahkan ke staff    //
// Dibuat Oleh    : Sri - 2005551121                                     //
//                                                                       //
// Versi : 1.3                                     Rev. 1                //
// Tgl   : 9-12-2020                               Tgl: 10-12-2020       //
// Revisi 1       : Menambahkan agar customer dapat melakukan login dan  //
//                  sign up.                                             //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//                                                 Rev. 2                //
//                                                 Tgl: 22-12-2020       //
// Revisi 2       : Merapikan isi fungsi agar terlihat rapi              //
// Direvisi Oleh  : Sri - 2005551121                                     //
//                                                 Rev. 3                //
//                                                 Tgl: 27-12-2020       //
// Revisi 3       : Membenahi fungsi login sehingga akses data bisa      //
//                  berdasarkan tiap akun pengguna                       //
// Direvisi Oleh  : Cakra - 2005551075                                   //
//=======================================================================//

//fungsi untuk menampilkan header program
void header(void);
//fungsi untuk masuk ke menu utama apabila sebelumnya di login memilih customer
void menuCostumer(void);
//fungsi untuk menampilkan menu apabila login sebagai pegawai/staff
void menuPegawai(void);

char username[20];
char password [20];
struct Data{
    char nama[100];
    char password[100];
};
struct Data pengguna;
FILE*out;

void login(void){
	login:
	system("cls");
 
	int pilihPengguna;
 
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t*** RAYURI SPA ***\n\n");
	printf("\t\t\t\t\tLogin For : \n");
	printf("\t\t\t\t\t[1] Customer\n");
	printf("\t\t\t\t\t[2] Staff\n");
	printf("\n\n\t\t\tMasukkan pilihan anda :");
	scanf("%d",&pilihPengguna);
 
	if(pilihPengguna == 1){ //jika milih ini maka akan masuk ke login costumer
		loginCostumer:
		system("cls");
		bool masuk;
		int opsi;
 		printf ("\n\n\n\n\n");
 		header();
		printf("\n\n\t\t   1. Register\n");
		printf("\t\t   2. Login\n\n");
		printf("\tOpsi Anda: ");
		scanf("%d", &opsi);
 
		switch(opsi){
			case 1: //buat pengguna
				system("cls");
				out=fopen("pengguna","a+");
				header();
				printf("\nUsername  : ");
				scanf("%s", &pengguna.nama);
				printf("\nPassword  : ");
				scanf("%s", &pengguna.password);
				printf("\n\n\t\t ********************");
				printf("\n\n\t\t *REGISTER BERHASIL!*");
				printf("\n\n\t\t ********************");
				fprintf(out,"%s\n",pengguna.nama);
	            fprintf(out,"%s\n",pengguna.password);
	            fclose(out);
				getch();
				system("cls");			
				goto loginCostumer; 
			case 2: //masuk setelah buat akun
				cobaMasuk:
				system("cls");
				out = fopen("pengguna","r+");
				masuk = false;
				header();
				printf("\nUsername : ");
				scanf("%s", &username);
				printf("\nPassword : ");
				scanf("%s", &password);
				while(fscanf(out,"\n%s\n%s",pengguna.nama,pengguna.password)!=EOF){
		            if((strcmp(pengguna.nama,username) == 00) && (strcmp(pengguna.password,password)==00)){
		                masuk = true;
		                break;
	           		}
	       		}
	        	if(!masuk){ //kalau salah
		            system("cls");
		            int loginFailed;
		            printf("\n\n\t\t   LOGIN FAILED!!!\n\n\n");
		            printf("Pilih langkah yang akan dilakukan : \n");
		            printf("\n> Pilih 1 untuk keluar\n");
		            printf("> Pilih sembarang untuk coba lagi\n\n");
		            //pilih sembarang artinya pilih nomor berapa saja untuk coba lagi memasukkan username dan password
		            printf("Pilih : ");
		            scanf("%d",&loginFailed);
		            if(loginFailed==1){
		            	goto loginCostumer;
		            }
		            else{
						goto cobaMasuk;
		            }
		    	}
		    	else { //kalau benar
	            printf("\n\n\t    Selamat anda berhasil masuk!");
	            getch();
				menuCostumer();
	            system("cls");
	        	}
	    }
	}
	else if(pilihPengguna == 2){ //jika memilih ini maka akan masuk ke login costumer
		loginPegawai:
		system("cls");
		char usernamePegawai [50];
		char passwordPegawai [50];
		printf("\n\n\n\t\t    RAYURI SPA                            \n");
		printf("\t\t Jl. Kenangan No.666                            \n");
		printf("\t\tNo. Telp 08123456789                            \n");
		printf("****************************************************\n");
		printf("\nUsername : ");
        scanf("%s",&usernamePegawai);
        printf("\nPassword : ");
        scanf("%s",&passwordPegawai);
 		//username disini masukkan admin dan untuk password masukkan 123
 
        if(strcmp(usernamePegawai,"admin")==0 && strcmp(passwordPegawai,"123")==0){
			menuPegawai();
		}
		else{
			int gagal;
            printf("\n\nLogin Failed\n\n\n");
            printf("Pilih 1 untuk keluar\n");
            printf("Pilih sembarang untuk coba lagi\n\n");
            printf("Pilih : ");
            scanf("%d",&gagal);
            if(gagal == 1){
                goto login;
            }
            else{
                goto loginPegawai;
			}
		}
	}
}