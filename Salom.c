#include <stdio.h>
#include "./t.c"


void savdo(int joyi, int soni)
{
    maxsulot_soni[joyi] = soni;
}

void menyuuchun()
{
    for (int i = 0; i < LEN; i++)
    {
        printf("%d. %s\t\t%d so'm\n", i, maxsulotlar[i], maxsulot_narxi[i]);
    }
}

int malumot(char ma[], int dan, int gacha)
{
    int ja;
    int bel = 0;
    
    do
    {
        if (bel > 0)
        {
            printf("\nbunday variant yo'q iltmos (%d-dan %d-gacha) orsida tanlang\n", dan, gacha);
        }
        printf("%s", ma);
        scanf("%d", &ja);
        bel++;  
    } while (ja < dan || ja >= gacha);

    return ja;
}


int malumot2(char ma[], int dan, int gacha)
{
    int ja;
    int bel = 0;
    do
    {
        if (bel > 0)
        {
            printf("\nBuncha miqdor bizda mavjut emas (%d-dan %d-gacha) orsida tanlang\n", dan, gacha);
        }
        printf("%s", ma);
        scanf("%d", &ja);
        bel++;
    } while (ja < dan || ja >= gacha);

    return ja;
}

int hisob()
{

    int sum = 0;
    for (int i = 0; i < LEN; i++)
    {
        sum += maxsulot_soni[i] * maxsulot_narxi[i];
    }

    return sum;
}

void jarayon()
{
    int bel = 1;
    printf("Assalomu alaykum, Oshxonamizga hushkelibsiz\n");
    while (bel > 0)
    {
        menyuuchun();
        int joyi = malumot("nima kerak?\n(iltmos menuda bor maxsulotni birni talang): ", 0, LEN);
        int soni = malumot2("nechta olasiz?\n", 1, 100);
        savdo(joyi, soni);
        printf("yana biror narsa olasizmi? 0-yoq, 1-ha: ");
        scanf("%d", &bel);
    }
    chek(13);
}

void chek(int tekshirish)
{
    printf("\n\n\t\t\tChek\n|------------------------------------------------|");
    for (int i = 0; i < LEN; i++)
    {
    
        if (maxsulot_soni[i] > 0)
            printf("\n| %d %s \t%d * %d = %d so'm |\n", i + 1, maxsulotlar[i], maxsulot_soni[i], maxsulot_narxi[i], maxsulot_soni[i] * maxsulot_narxi[i]);
    }
    printf("|-----------------------------\n");
    int summa = hisob();
    printf("| JAMI %d so'm %d foiz  |\n", summa, tekshirish);
    if (tekshirish > 0)
    {
        printf("| TOLOV: %d so'm        |\n|-----------------------------\nYana keling!!!\n", summa - summa * tekshirish / 100);
    }
    else
    {
        printf("TOLOV: %d so'm\n\n\t| Yana keling!!! |", summa);
    }
}

int main()
{
    jarayon();
    return 0;
}