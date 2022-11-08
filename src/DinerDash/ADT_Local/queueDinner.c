/*
NIM : 18221077
Nama : Riandra Diva Auzan
Tanggal Praktikum: 17/10/2022
Deskripsi : Program ini berisi implementasi queue.h
*/

#include "../../ADT/Boolean/boolean.h"
#include "queueDinner.h"

/* *** Kreator *** */
void CreateQueueF(QueueF *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyF(QueueF q)
{
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFullF(QueueF q)
{
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITYF - 1));
}

int lengthF(QueueF q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* ALGORITMA */
    if (isEmptyF(q))
    {
        return 0;
    }
    else
    {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */

void enqueueF(QueueF *q, Food Order)
{
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam representasi rata kiri. */

    int i;

    /* ALGORITMA */
    if (isEmptyF(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        if ((IDX_TAIL(*q) == CAPACITYF - 1))
        {
            for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++)
            {
                q->buffer[i - IDX_HEAD(*q)] = q->buffer[i];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)
        ++;
    }
    TAIL(*q).OrderId = Order.OrderId;
    TAIL(*q).durasi = Order.durasi;
    TAIL(*q).ketahanan = Order.ketahanan;
    TAIL(*q).harga = Order.harga;
}

void dequeueF(QueueF *q, Food *Order)
{
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val yang dihapus = nilai elemen HEAD pd I.S., */
    /*      IDX_HEAD "maju" dalam buffer melingkar. */
    /*      Jika q menjadi kosong, IDX_HEAD = IDX_TAIL = IDX_UNDEF */
    *Order = HEAD(*q);

    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q)
        ++;
    }
}

boolean compare(char *query, char *command)
{
    int i = 0;
    while (query[i] != '\0' && command[i] != '\0')
    {
        if (query[i] != command[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

int searchIdx(QueueF *q, char *id)
{
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q))
    {
        if (compare(q->buffer[i].OrderId, id))
        {
            return i;
        }
        i++;
    }
    return IDX_UNDEF;
}
/* *** Display Queue *** */
void displayQueueOrder(QueueF q)
{
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
    if (!isEmptyF(q))
    {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            printf("%s      | %d              | %d         | %d\n", (q).buffer[i].OrderId, (q).buffer[i].durasi, (q).buffer[i].ketahanan, (q).buffer[i].harga);
        }
    }
    else
    {
        printf("         |                 |            |   \n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void displayQueueCook(QueueF q)
{
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("---------------------------------------------\n");
    if (!isEmptyF(q))
    {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            printf("%s      | %d\n", (q).buffer[i].OrderId, (q).buffer[i].durasi);
        }
    }

    else
    {
        printf("         |   \n");
    }
}

void displayQueueServe(QueueF q)
{
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("---------------------------------------------\n");
    if (!isEmptyF(q))
    {

        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            printf("%s      | %d\n\n\n", (q).buffer[i].OrderId, (q).buffer[i].ketahanan);
        }
    }
    else
    {
        printf("        |   \n\n\n");
    }
}
