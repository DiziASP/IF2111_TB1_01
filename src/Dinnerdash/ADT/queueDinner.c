/*
NIM : 18221077
Nama : Riandra Diva Auzan
Tanggal Pratikum: 17/10/2022
Deskripsi : Program ini berisi implementasi queque.h
*/

#include "../../ADT/Boolean/boolean.h"
#include "queueDinner.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
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
boolean isEmpty(Queue q)
{
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q)
{
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q);
}

int length(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

/* *** Primitif Add/Delete *** */

void enqueue(Queue *q, Food Order)
{
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    (*q).buffer[(*q).idxTail].OrderId = Order.OrderId;
    (*q).buffer[(*q).idxTail].durasi = Order.durasi;
    (*q).buffer[(*q).idxTail].ketahanan = Order.ketahanan;
    (*q).buffer[(*q).idxTail].harga = Order.harga;

    // if (IDX_TAIL(*q) == CAPACITY-1) {
    //     for(int i= IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
    //         (*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
    //     }
    //     IDX_TAIL(*q) -= IDX_HEAD(*q);
    //     IDX_HEAD(*q) = 0;
    // }
}

void dequeue(Queue *q)
{
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
            q mungkin kosong */
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q) = IDX_HEAD(*q) + 1;
    }
}

/* *** Display Queue *** */
void displayQueueOrder(Queue q)
{
    int i;
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
    if (!isEmpty(q))
    {
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            printf("M%d      | %d              | %d         | %d\n", (q).buffer[i].OrderId, (q).buffer[i].durasi, (q).buffer[i].ketahanan, (q).buffer[i].harga);
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

void displayQueueCook(Queue q)
{
    int i = IDX_HEAD(q);
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("---------------------------------------------\n");
    if (!isEmpty(q))
    {
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            if (q.buffer[i].durasi != 0)
            {
                printf("M%d      | %d\n", (q).buffer[i].OrderId, (q).buffer[i].durasi);
            }
        }
    }
    else
    {
        printf("         |   \n");
    }
}

void displayQueueServe(Queue q)
{
    int i;
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("---------------------------------------------\n");
    if (!isEmpty(q))
    {
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            // if (q.buffer[i].durasi == 0)
            //{
            printf("M%d      | %d\n\n\n", (q).buffer[i].OrderId, (q).buffer[i].ketahanan);
            //}
        }
    }
    else
    {
        printf("        |   \n\n\n");
    }
}
