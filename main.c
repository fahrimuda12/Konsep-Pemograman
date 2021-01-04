#include <stdio.h>

struct pendapat{
    char pendapat[250],saran[250];
};
struct kuisioner {
    char name[50];
    int age;
    char text[250];
    struct pendapat user;
};

char menu(char);
void inputMatriks(int (*array)[10], int *, int *);
void cetakMatriks(int array[10][10], int baris, int kolom);
void penjumlahanPengurangan(int matrikA[10][10], int matrikB[10][10], int [10][10],int [10][10],int baris, int kolom, int pengkali);
void perkalianSkalar(int array[10][10], int [][10],int skalar, int baris, int kolom);
void perkalian(int matrikA[10][10], int matrikB[10][10], int [][10], int barisA, int kolomA, int kolomB);
void kuisioner(struct kuisioner *, char );
void outputKuisioner(struct kuisioner **);
int main(){
    struct kuisioner kuis;
    char pilih = 'Y';
    while (pilih == 'Y' || pilih == 'y'){
        pilih = menu(pilih);
    }
    kuisioner(&kuis, pilih);
    return 0;
}

char menu(char pilih){
        int i, j, k;
        int matrixA[10][10];
        int matrixB[10][10];
        int hasilMatrik[10][10];
        int matrikInvers[10][10];
        int barisA, kolomA;
        int barisB, kolomB;
        int pengoperasi;
        int skalar = 0;
        int tambah = 1;
        int kurang = -1;

        printf("pengoperasi Menu\n");
        printf("\t1. Penjumlahan\n");
        printf("\t2. Pengurangan\n");
        printf("\t3. Perkalian Skalar\n");
        printf("\t4. Pekalian 2 Matriks\n");
        printf("Silahkan pilih: ");
        scanf(" %d", &pengoperasi);

        switch (pengoperasi){
            case 1:
                printf("\nMasukkan bidang matriks A (baris kolom) = ");
                scanf("%d%d", &barisA, &kolomA);

                printf("Masukkan bidang matriks B (baris kolom) = ");
                scanf("%d%d", &barisB, &kolomB);

                while ((barisA != barisB) && (kolomA != kolomB)){
                    printf("\nMatrik harus berbidang sama\n");
                    printf("\nMasukkan bidang matriks A (baris kolom) = ");
                    scanf("%d%d", &barisA, &kolomA);

                    printf("Masukkan bidang matriks B (baris kolom) = ");
                    scanf("%d%d", &barisB, &kolomB);
                }


                printf("\n\tMasukkan elemen dari Matrik A a %d x %d matrik.\n", barisA, kolomA);
                inputMatriks(&matrixA[0][0], &barisA, &kolomA);
                printf("\n\t\tMatrix A\n\n");
                cetakMatriks(matrixA, barisA, kolomA);


                printf("\n\tMasukkan elemen dari Matrix B a %d x %d matrik.\n", barisB, kolomB);
                inputMatriks(matrixB, &barisB, &kolomB); //matrixB = &matrixB[0][0]
                printf("\n\t\tMatrix B\n\n");
                cetakMatriks(matrixB, barisB, kolomB);

                printf("\nPenjumlahan dari matrik A + matrik B = \n");
                penjumlahanPengurangan(matrixA, matrixB,hasilMatrik,matrikInvers, barisA, kolomA, tambah);

                break;

            case 2:

                printf("\nMasukkan bidang matriks A (baris kolom) = ");
                scanf("%d%d", &barisA, &kolomA);

                printf("Masukkan bidang matriks B (baris kolom) = ");
                scanf("%d%d", &barisB, &kolomB);

                while ((barisA != barisB) && (kolomA != kolomB)){
                    printf("\nMatrik harus berbidang sama\n");
                    printf("\nMasukkan bidang matriks A (baris kolom) = ");
                    scanf("%d%d", &barisA, &kolomA);

                    printf("Masukkan bidang matriks B (baris kolom) = ");
                    scanf("%d%d", &barisB, &kolomB);
                }

                printf("\n\tMasukkan elemen dari Matrik A a %d x %d matrik.\n", barisA, kolomA);
                inputMatriks(matrixA, &barisA, &kolomA);
                printf("\n\t\tMatrik A\n\n");
                cetakMatriks(matrixA, barisA, kolomA);

                printf("\n\tMasukkan elemen dari Matrik B a %d x %d matrik.\n", barisB, kolomB);
                inputMatriks(matrixB, &barisB, &kolomB);
                printf("\n\t\tMatrik B\n\n");
                cetakMatriks(matrixB, barisB, kolomB);

                printf("\nPengurangan dari matrik A - B adalah : \n");
                penjumlahanPengurangan(matrixA, matrixB,hasilMatrik,matrikInvers, barisA, kolomA, kurang);
                break;

            case 3:

                printf("\nMasukkan nilai skalar: ");
                scanf("%d", &skalar);
                printf("\nNilai skalar adalah: %d ", skalar);


                printf("\nMasukkan bidang matriks B (baris kolom) = ");
                scanf("%d%d", &barisA, &kolomA);

                printf("\n\tMasukkan elemen dari Matrik A a %d x %d matrik.\n", barisA, kolomA);
                inputMatriks(matrixA,&barisA, &kolomA);
                printf("\n\t\tMatrix A\n\n");
                cetakMatriks(matrixA, barisA, kolomA);

                printf("\nPerkalian sklar matrik A * %d adalah: \n", skalar);
                perkalianSkalar(matrixA, matrikInvers, skalar, barisA, kolomA);

                break;

            case 4:
                printf("\n!! Kolom matrik A harus sama dengan baris Matrik B.");
                printf("\nMasukkan bidang matriks A (baris kolom) = ");
                scanf("%d%d", &barisA, &kolomA);

                printf("Masukkan bidang matriks B (baris kolom) = ");
                scanf("%d%d", &barisB, &kolomB);

                while (kolomA != barisB)
                {
                    printf("\n\nKesalahan! kolom matrik A tidak sama dengan baris Matrik B.\n\n");
                    printf("\nMasukkan bidang matriks A (baris kolom) = ");
                    scanf("%d%d", &barisA, &kolomA);

                    printf("Masukkan bidang matriks B (baris kolom) = ");
                    scanf("%d%d", &barisB, &kolomB);
                }

                printf("\n\tMasukkan elemen dari Matrik A a %d x %d matrik.\n", barisA, kolomA);
                inputMatriks(matrixA, &barisA, &kolomA);
                printf("\n\t\tMatrik A\n\n");
                cetakMatriks(matrixA, barisA, kolomA);

                printf("\n\tMasukkan elemen dari Matrik B a %d x %d matrik.\n", barisB, kolomB);
                inputMatriks(matrixB, &barisB, &kolomB);
                printf("\n\t\tMatrik B\n\n");
                cetakMatriks(matrixB, barisB, kolomB);

                perkalian(matrixA, matrixB, hasilMatrik ,barisA, kolomA, kolomB);

                break;

            default:
                printf("\nMaaf menu tidak tersedia");
                break;
        }

        printf("\n\nApakah anda ingin melanjutkan lagi? Y/N\n");
        fflush(stdin);
        scanf("%c", &pilih);
        return pilih;
} //*array
void inputMatriks(int (*array)[10], int *baris, int *kolom){
    int i, j;
    for (i = 0; i < *baris; i++){
        printf("\t%d data untuk baris ke-%d (data1 data2 ...): ", *kolom, i + 1);
        for (j = 0; j < *kolom; j++){
            scanf("%d",(*(array+i)+j));//&array[i][j]
        }
    }
}

void penjumlahanPengurangan(int matrikA[10][10], int matrikB[10][10],int hasilMatrik[10][10], int matrikInvers[10][10],  int baris, int kolom, int pengkali){
    int i, j;

    for (i = 0; i < baris; i++){
        for (j = 0; j < kolom; j++){
            matrikInvers[i][j] = pengkali * matrikB[i][j];
        }
    }

    for (i = 0; i < baris; i++){
        for (j = 0; j < kolom; j++){
            hasilMatrik[i][j] = matrikA[i][j] + matrikInvers[i][j];
            printf("\t%d", hasilMatrik[i][j]);

        }
        printf("\n");
    }
}

void cetakMatriks(int array[10][10], int baris, int kolom){
    int i, j;

    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++){
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }
}

void perkalianSkalar(int array[10][10], int matrikInvers[10][10],int skalar, int baris, int kolom){
    int i, j;

    for (i = 0; i < baris; i++){
        for (j = 0; j < kolom; j++){
            matrikInvers[i][j] = skalar * array[i][j]; // 2 3
            printf("\t%d", matrikInvers[i][j]);
        }
        printf("\n");
    }

}

void perkalian(int matrikA[10][10], int matrikB[10][10], int hasilMatrik[][10],int barisA, int kolomA,int kolomB){
    int i, j, k;


    for (i = 0; i<barisA; ++i){
        for (j = 0; j<kolomB; ++j)
        {
            hasilMatrik[i][j] = 0;
            // 0 0
            // 0 0
            /* matriks a 2*3 =  2 3 4    11+8 = 19
                                3 4 1
               matriks b 3*2 =  1 2
                                3 4
                                2 4
                hasil matriks 2*2 = 19 0
                                    0 0*/
        }
    }

    for (i = 0; i<barisA; ++i){
        for (j = 0; j<kolomB; ++j){
            for (k = 0; k<kolomA; ++k)
            {
                hasilMatrik[i][j] += matrikA[i][k] * matrikB[k][j];
            }
        }
    }

    printf("\nOutput Matrix:\n\n");
    for (i = 0; i<barisA; ++i){
        for (j = 0; j<kolomB; ++j)
        {
            printf("\t%d ", hasilMatrik[i][j]);
        }
        printf("\n\n");
    }
}

void kuisioner(struct kuisioner *inputp,char pilih){
    printf("\n\nApakah anda bersedia mengisi kuisioner ? Y/N\n");
    fflush(stdin);
    scanf(" %c", &pilih);
    if(pilih  == 'Y' || pilih == 'y'){
        printf("Mohon isi nama anda : ");\
        fflush(stdin);
        fgets(inputp->name,sizeof(inputp->name), stdin); //(*input).name
        printf("Apakah ada kendala dalam pemakaian ? : ");
        fflush(stdin);
        fgets(inputp->text,sizeof(inputp->text), stdin);
        printf("Mohon isi pendapat anda : ");
        fflush(stdin);
        fgets(inputp->user.pendapat,sizeof(inputp->user.pendapat), stdin);
        printf("Mohon isi saran anda : ");
        fflush(stdin);
        fgets(inputp->user.saran,sizeof(inputp->user.saran), stdin);
        outputKuisioner(&inputp);
    }
    else{
        printf("\n\nGoodbye!\n\n");
        exit(0);
    }
}
void outputKuisioner(struct kuisioner **input){
    printf("\n\nTerima Kasih telah membantu"); // **input -> *inputp -> kuis.name
    printf("\nForm yang anda isi telah terkirim\n\n");
    printf("-------------------------------\n");
    printf("| Nama\t\t: %s",(*input)->name);//(*(*input)).name
    printf("| Komentar\t: %s",(*input)->text);
    printf("| Pendapat\t: %s",(*input)->user.pendapat);
    printf("| Saran\t\t: %s",(*input)->user.saran);
    printf("-------------------------------\n");
}
