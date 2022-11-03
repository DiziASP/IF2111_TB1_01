#include "dinnerdash.h"
/* File : q_dinerdash.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/*void hitungMasakan(Queue q, int *ctr){
    int i;
    *ctr = 0;
    for(i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
        if(q.buffer[i].durasi != 0){
            *ctr += 1;
        }
    }
}
*/

void faseAwal(int saldo, Queue Order, Queue Cook, Queue Rserve)
{
    printf("SALDO: %d\n\n", saldo);
    displayQueueOrder(Order);
    displayQueueCook(Cook);
    displayQueueServe(Rserve);
}

void queueOrder(Queue *qOrder)
{
    Food order;
    order.OrderId = length(*qOrder);
    order.durasi = rand() % 5 + 1;
    order.ketahanan = rand() % 5 + 1;
    order.harga = rand() % 41 * 1000 + 10000;
    enqueue(qOrder, order);
}

// kalau mau nge print yg penting masukkin dulu aja ke queuenya , ntar cobain satu2 aja
void waktu(Queue *Order, Queue *Cook, Queue *RServe, char command[5])
{
    int i, j;
    if (command == "SERVE" || command == "COOK")
    {
        for (i = 0; i < length(*Cook); i++)
        {
            if ((*Cook).buffer[i].durasi != 0)
            {
                (*Cook).buffer[i].durasi--;
            }
            else
            {
                enqueue(RServe, (*Cook).buffer[i]);
                printf("Makanan M%d telah selesai dimasak\n", (*Cook).buffer[i].OrderId);
                dequeue(Cook);
            }
        }
        for (j = 0; j < length(*RServe); j++)
        {
            if ((*RServe).buffer[j].ketahanan != 0)
            {
                (*RServe).buffer[j].ketahanan--;
            }
            else
            {
                printf("Ketahanan Makanan M%d telah habis\n", (*RServe).buffer[j].OrderId);
                dequeue(RServe);
                dequeue(Order);
            }
        }
    }
}
/* ********* Prototype ********* */
int dinnerDash()
{
    int saldo = 0;
    int ctr_layani = 0;
    int i, j;
    srand(time(NULL));
    printf("Selamat Datang di Diner Dash!\n\n");
    Queue Order, Cook, RServe;
    CreateQueue(&Order);
    CreateQueue(&Cook);
    CreateQueue(&RServe);
    for (i = 0; i < 3; i++)
    {
        queueOrder(&Order);
    }
    // buat q dulu, ntar jadi masukkan juga ke void awal
    char command[5];
    int id_pesanan;
    while (!isFull(Order) && ctr_layani < 15)
    {
        faseAwal(saldo, Order, Cook, RServe);
        waktu(&Order, &Cook, &RServe, command);
        printf("MASUKKAN COMMAND: ");
        scanf("%s M%d", command, &id_pesanan);
        printf("\n\n");
        if (command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K')
        {
            if (length(Cook) <= 5)
            {
                enqueue(&Cook, Order.buffer[id_pesanan]);
                printf("Berhasil memasak M%d\n", id_pesanan);
                queueOrder(&Order);
            }
            else
            {
                printf("Antrian memasak penuh\n");
            }
        }
        else if (command[0] == 'S' && command[1] == 'E' && command[2] == 'R' && command[3] == 'V' && command[4] == 'E')
        {
            if (Order.buffer[IDX_HEAD(Order)].OrderId == id_pesanan)
            {
                // if(Cook.buffer[IDX_HEAD(Cook)].durasi == 0){
                printf("Berhasil Mengantarkan M%d\n", id_pesanan);
                saldo = saldo + Cook.buffer[id_pesanan].harga;
                dequeue(&RServe);
                dequeue(&Order);
                queueOrder(&Order);
            }
            else
            {
                printf("M%d belum bisa disajikan karena M%d belum selesai\n", id_pesanan, HEAD(Order));
            }
        }
        else
        {
            printf("Command tidak valid\n");
        }
        printf("==========================================================\n\n");
    }
    printf("SALDO: %d\n", saldo);
    if (ctr_layani == 15)
    {
        printf("\nSelamat! Anda berhasil menyelesaikan level ini!\n");
    }
    else
    {
        printf("\nMaaf, Anda gagal menyelesaikan level ini!\n");
    }
    return 0;
}

int main()
{
    dinnerDash();
    return 0;
}
