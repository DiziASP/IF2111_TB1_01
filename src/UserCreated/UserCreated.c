#include "UserCreated.h"

ArrayDin Encourage;
ArrayDin Booster;
ArrayDin Sad;
int YourMood;

void Quotinator()
{
    YourMood = rand() % 100 + 1;
    printf("Your mood rate today is %d\n");

    /* Initial Quote */
    /* Sad */
    char sad1[500] = "Aku tahun kau sedang mencari. Tapi mencari kan, tak harus jauh-jauh. Dari aku yang dekat tapi tak pernah kau lihat.";
    char sad2[500] = "Beberapa jarak diciptakan bukan untuk ditempuh, tapi untuk dibiarkan.";
    char sad3[500] = "Kalau dunia engga baik ke kamu, kamu tetap harus baik ke dirimu sendiri.";
    InsertLast(&Sad, sad1);
    InsertLast(&Sad, sad2);
    InsertLast(&Sad, sad3);
    /* Encourage */
    char encourage1[500] = "Namun bila hari ini adalah yang terakhir, namun ku tetap bahagia. Selalu kusyukuri, begitulah adanya.";
    char encourage2[500] = "Ulat terbang tak akan cantik. Biji bunga yang belum terbelah. Waktu adalah perias rupa. Berjalanlah berdampingan.";
    char encourage3[500] = "Mengapa takut pada lara, sementara semua rasa bisa kita cipta.";
    InsertLast(&Encourage, encourage1);
    InsertLast(&Encourage, encourage2);
    InsertLast(&Encourage, encourage3);
    /* Booster */
    char booster1[500] = "Kalau ada yang nyakitin kamu, aku bakal bilang 'Kamu nanyaea?'";
    char booster2[500] = "Jangan kebanyakan kasih kode. Salah tiga kali, hatinya bisa keblokir.";
    char booster3[500] = "Jika terlalu menjaga image, hidupmu hanyalah sebatas jpeg.";
    InsertLast(&Booster, booster1);
    InsertLast(&Booster, booster2);
    InsertLast(&Booster, booster3);

    /* Quotinator */
    if (YourMood <= 25)
    {
        printf("Kamu terindikasi Sadboi/Sadgirl, nih quote yang pas buat kamu!\n\n");
        printf("%s\n\n", Get(Sad, rand() % Length(Sad)));
    }
    else if (YourMood > 25 && YourMood <= 50)
    {
        printf("Lagi biasa aja ya? Ini juga ada quote buat kamu ihiy!\n\n");
        printf("%s\n\n", Get(Encourage, rand() % Length(Encourage)));
    }
    else
    {
        printf("Idieh lagi seneng kenapa sihh? Kasmaran ya? Nih quote buat kamu\n\n");
        printf("%s\n\n", Get(Booster, rand() % Length(Booster)));
    }
}
int UserCreated()
{
    srand(time(NULL));
    Encourage = MakeArrayDin();
    Booster = MakeArrayDin();
    Sad = MakeArrayDin();
    printf("Selamat datang di QUOTINATOR!\n");
    Quotinator();

    return YourMood;
}