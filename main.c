#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

//include file fungsi
#include "judul.h"
#include "header.h"
#include "login.h"
#include "menuCustomer.h"
#include "menuJasa.h"
#include "tentangKami.h"
#include "menuBantuan.h"
#include "inputSalah.h"
#include "cetakKuitansi.h"
#include "konfirmasiPemesanan.h"
#include "cekPembayaran.h"
#include "tampilkanRincianJasa1.h"
#include "tampilkanRincianJasa2.h"
#include "tampilkanRincianJasa3.h"
#include "tampilkanRincianJasa4.h"
#include "tampilkanRincianJasa5.h"
#include "tampilkanRincianJasa6.h"
#include "tampilkanRincianJasa7.h"
#include "daftarTransaksi.h"
#include "menuPegawai.h"
#include "menurekomen.h"
#include "menuKasir.h"
#include "cetaknota.h"
#include "rulesMember.h"
#include "pendaftaranMember.h"
#include "menuAbsensi.h"
#include "penggajianPegawai.h"
 
//PROTOTIPE PROGRAM
//fungsi untuk menampilkan judul program
void judul (void); 
//fungsi untuk login sebagai pengguna(customer) atau staff
void login(void);

int main() {
	judul();
	login();
return 0;
}
