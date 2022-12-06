#include<stdio.h>
#include<stdlib.h>

#define BPM_RT 10 //Biaya Pemliharaan Meter Rumah Tangga
#define BPM_U 20 //Biaya Pemeliharaan Meter Usaha
#define BIAYA_ADM 50 //Biaya Administrasi
#define BIAYA_METER_1 50 //Biaya 10 meter kubik pertama adalah Rp 50,-
#define BIAYA_N 10 //Biaya 10+n meter kubik adalah Rp 10,-
#define DENDA_100_KEATAS 20 //Denda pemakaian lebih dari 100 meter kubik adalah 20,-
#define DENDA_LBH10_KRG100 10 //Denda pemakaian lebih dari 10 meter kubik dan tidak lebih dari 100 m

//Gusti Agung Ayu Kade Tami Suastuti (2205551055)

int validasi_angka() {
	int angka;
	char huruf;

	scanf("%d%c",&angka,&huruf);
	if(huruf != '\n') {
		printf("||Input hanya berupa angka, mohon inputkan ulang : ");
		fflush(stdin);
		validasi_angka();
	} else if(angka<=0) {
		printf("||Angka tidak boleh dibawah atau sama dengan 0! Mohon inputkan ulang : ");
		fflush(stdin);
		validasi_angka();
	} else {
		return angka;
	}
}

void range_int(int *var, int range1, int range2, char *intruksi, char *salah)
{
    while (1)
    {
        input_int(var, intruksi);
        fflush(stdin);
        if (*var >= range1 && *var <= range2)
            break;
        printf("%s", salah);
    }
}

void input_int(int *var, char *intruksi)
{
    char buff[1024];
    char cek;

    while (1)
    {
        printf("%s", intruksi);
        fflush(stdin);
        if (fgets(buff, sizeof(buff), stdin) != NULL)
        {
            if (sscanf(buff, "%d %c", var, &cek) == 1)
            {
                break;
            }
        }
        printf("\t\t\t Input salah! Silahkan coba lagi\n");
    }
}

void pembuka(){
    printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                                                 |\n");
    printf("|                                  ||===================================================||                                        |\n");
    printf("|                                  ||             Selamat Datang Kembali di             ||                                        |\n");
    printf("|                                  ||       PDAM Tirta Sewakadarma Kota Denpasar        ||                                        |\n");
    printf("|                                  ||===================================================||                                        |\n");
    printf("|                                       	Klik apapun untuk melanjutkan                                                     |\n");
    printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
	getch();
	system("cls");
}

void pilihan(){
	printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                    ||===================================================||                                      |\n");
    printf("|                                    ||                   Tarif Air Minum                 ||                                      |\n");
    printf("|                                    ||                  Tirta Sewakadarma                ||                                      |\n");
    printf("|                                    ||                    Kota Denpasar                  ||                                      |\n");
    printf("|                                    ||===================================================||                                      |\n");
    printf("|                                                                                                                                 |\n");
    printf("|                       Jl. Ahmad Yani No.98, Dauh Puri Kaja, Kec. Denpasar Utara, Kota Denpasar, Bali 80231                      |\n");
    printf("|                        Facebook : Perumda Tirta Sewakadarma Kota Denpasar|| Instagram : Tirta Sewakadarma                       |\n");
    printf("|                                                    Call center : (0361) 231314                                                  |\n");
    printf("|                                                                                                                                 |\n");
    printf("+-----------------------------------------------------------------------+---------------------------------------------------------|\n");
    printf("|                                                                       |     Catatan :                                           |\n");
    printf("|             -----Biaya Pemeliharaan Meter (BPM) Air-----              |        1. Denda Rp.20 apabila pemakaian diatas 100      |\n");
    printf("+----+-------------------------+---------------------+------------------+          											      |\n");
    printf("| No |          Golongan Pengguna           |        kode BPM           |        2. Denda Rp.10 apabila pemakaian dari 10 - 100	  |\n");
    printf("+----+-------------------------+---------------------+------------------+          											      |\n");
    printf("|  1 |            Rumah Tangga              |        Rp. 10             |        3. Biaya Administrasi dikenakan sebesar Rp.50    |\n");
    printf("|  2 |             Usaha                    |        Rp. 20             |           setiap melakukan pembayaran tagihan air       |\n");
    printf("+----+-------------------------+---------------------+------------------+---------------------------------------------------------+\n");

}
                                                                //bpm = biaya peralihan meter
int main(){                                                     //bp = biaya pemakaian
	int golongan, pbi, pbl, bpm, bp, denda, tarif, total, date; //pbi = pemakaian bulan ini
                                                                //pbl = pemakaian bulan lalu
	FILE *fPointer = fopen("Struk_tagihan_air.txt", "w");
	char nama[100];
	int rekening[100];
	char no_telp[100];

    pembuka();
    pilihan();
    range_int(&golongan, 1, 2, "\tINPUT GOLONGAN PENGGUNA [1/2] : ", "\n\t\t\tInput salah!\n\t\t\tGolongan yang tersedia hanya 1 dan 2\n\n");
            system("cls");


 	printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                    ||===================================================||                                      |\n");
    printf("|                                    ||                   Tarif Air Minum                 ||                                      |\n");
    printf("|                                    ||                  Tirta Sewakadarma                ||                                      |\n");
    printf("|                                    ||                    Kota Denpasar                  ||                                      |\n");
    printf("|                                    ||===================================================||                                      |\n");
    printf("|                                                                                                                                 |\n");
    printf("|                       Jl. Ahmad Yani No.98, Dauh Puri Kaja, Kec. Denpasar Utara, Kota Denpasar, Bali 80231                      |\n");
    printf("|                        Facebook : Perumda Tirta Sewakadarma Kota Denpasar|| Instagram : Tirta Sewakadarma                       |\n");
    printf("|                                                    Call center : (0361) 231314                                                  |\n");
    printf("|                                                                                                                                 |\n");
    printf("+-----------------------------------------------------------------------+---------------------------------------------------------|\n");

    while(1){
    	printf("\t||Input Nama pengguna:   ");fflush(stdin);
		gets(nama);
		printf("\t||Input Rekening Tagihan: ");fflush(stdin);
		scanf("%d", &rekening);
		printf("\t||Input No Telp Pengguna: ");fflush(stdin);
		scanf("%s", &no_telp);

	    printf("\t||Besar pemakaian bulan ini dalam m3 :  ");
	    fflush(stdin);
        pbi = validasi_angka();

	    printf("\t||Besar pemakaian bulan lalu dalam m3 :  ");
	    fflush(stdin);
	    pbl = validasi_angka();

	    if(pbi<pbl){
	    	printf("\nMaaf data anda salah!! \n");
		}else{
			break; //Break merupakan perintah yang digunakan untuk memaksa sebuah perulangan berhenti sebelum waktunya
		}
	}
    printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");

   	if(golongan == 1){
   		bpm = BPM_RT;
	}else{
	   	bpm = BPM_U;
	}

	bp = pbi - pbl;

	if(bp<=10){
		tarif = BIAYA_METER_1;
	}else{
		tarif = BIAYA_METER_1 + (BIAYA_N * (bp- 10));
	}

		range_int(&date, 1, 31, "\tMASUKKAN TANGGAL [1-31] : ", "\n\t\t\tInput salah!\n\t\t\tTanggal tersedia hanya 1-31\n\n");

    system("cls");

    denda = 0;
    if(date>15){
    	if(bp>100 ){
			denda = DENDA_100_KEATAS;
		}else if(bp>10 && bp<=100){
			denda = DENDA_LBH10_KRG100;
		}
	}

	total = BIAYA_ADM + bpm + tarif + denda;

	printf("\n\n+---------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                               -----Rincian pembayaran-----                                                      |\n");
    printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("					Nama Pelanggan	: %s\n", nama);
	printf("					Rekening Tagihan: %d\n", rekening);
    printf("					No Telepon	: %s\n\n", no_telp);
	printf("+---------------------+---------------------------+---------------------------+-------------------------+-------------------------+\n");
    printf("|         BPM         |      Biaya Adminitrasi    |    Tarif Penggunaan Air   |     	Denda 	        |   Total           	  |\n");
    printf("+---------------------+---------------------------+---------------------------+-------------------------+-------------------------+\n");
    printf("| Rp. %d                  Rp. %d                      Rp. %d             	   Rp. %d                  Rp. %d\n\n\n", bpm, BIAYA_ADM, tarif, denda, total);
    //printf("|Rp. %-17d| Rp. %-13d| Rp. %-17d| Rp. %-28d| Rp. %-21d\n\n\n", bpm, BIAYA_ADM, tarif, denda, total);
    printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                                                 |\n");
    printf("|                                  ||===================================================||                                        |\n");
    printf("|                                  ||Terima kasih telah melakukan pembayaran tagihan air||                                        |\n");
    printf("|                                  ||       PDAM Tirta Sewakadarma Kota Denpasar        ||                                        |\n");
    printf("|                                  ||         Semoga hari-hari anda menyenangkan        ||                                        |\n");
    printf("|                                  ||===================================================||                                        |\n");
    printf("|                                                                                                                                 |\n");
    printf("|                                                                                                                                 |\n");
    printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");

    fprintf(fPointer, "\n\n+------------------------------------------------------------------------------------------------------------------+\n");
    fprintf(fPointer, "|                                               -----Rincian pembayaran-----                                           |\n");
    fprintf(fPointer, "|----------------------------------------------------------------------------------------------------------------------|\n");
	fprintf(fPointer, "					Nama Pelanggan	: %s\n", nama);
	fprintf(fPointer, "					Rekening Tagihan: %d\n", rekening);
    fprintf(fPointer, "					No Telepon	: %s\n\n", no_telp);
	fprintf(fPointer, "+---------------------+----------------------+-------------------------+-------------------------+-----------------------+\n");
    fprintf(fPointer, "|         BPM         |   Biaya Adminitrasi  |   Biaya Penggunaan Air  |    	Denda 	            |   Total         	  |\n");
    fprintf(fPointer, "+---------------------+----------------------+-------------------------+-------------------------+---------------------+\n");
    fprintf(fPointer, "| Rp. %d                  Rp. %d               Rp. %d                    Rp. %d                   Rp. %d\n\n\n", bpm, BIAYA_ADM, tarif, denda, total);

    fprintf(fPointer, "+----------------------------------------------------------------------------------------------------------------------+\n");
    fprintf(fPointer, "|                                                                                                                      |\n");
    fprintf(fPointer, "|                                  ||===================================================||                             |\n");
    fprintf(fPointer, "|                                  ||Terima kasih telah melakukan pembayaran tagihan air||                             |\n");
    fprintf(fPointer, "|                                  ||       PDAM Tirta Sewakadarma Kota Denpasar        ||                             |\n");
    fprintf(fPointer, "|                                  ||         Semoga hari-hari anda menyenangkan        ||                             |\n");
    fprintf(fPointer, "|                                  ||===================================================||                             |\n");
    fprintf(fPointer, "|                                                                                                                      |\n");
    fprintf(fPointer, "|                                                                                                                      |\n");
    fprintf(fPointer, "+----------------------------------------------------------------------------------------------------------------------+\n");


return 0;
}
