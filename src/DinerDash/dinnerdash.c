/* File : dinnerdash.c */
/* implementasi game dinnerdash */
#include "dinnerdash.h"
char *query1;
char *query2;
int ordNum;
/* Fungsi bantuan */
<<<<<<< HEAD
void rQuery(char **arg1, char **arg2)
=======
void readQuery(char **arg1, char **arg2)
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
{
    STARTWORD();
    *arg1 = KataToString(currentKata);
    ADVWORDSTD();
    *arg2 = KataToString(currentKata);
}

<<<<<<< HEAD
char *conStr(char *str1, char *str2)
=======
char *concatStr(char *str1, char *str2)
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
{
    int i = 0;
    int j = 0;
    char *str3 = (char *)malloc(100 * sizeof(char));
    while (str1[i] != '\0')
    {
        str3[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
    {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';
    return str3;
}

int charLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

<<<<<<< HEAD
boolean cQuery(char *query, char *command)
=======
boolean compQuery(char *query, char *command)
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
{
    int i = 0;
    if (charLength(query) == charLength(command))
    {
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
    return false;
}

boolean ValidInput(char *query1, char *query2)
{
<<<<<<< HEAD
    if (cQuery(query1, "COOK") || cQuery(query1, "SERVE") || query2 != NULL)
    {
        if (query2[0] == 'M' && !cQuery(query2, "M"))
=======
    if (compQuery(query1, "COOK") || compQuery(query1, "SERVE") || query2 != NULL)
    {
        if (query2[0] == 'M' && !compQuery(query2, "M"))
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
        {
            int i = 1;
            while (query2[i] != '\0')
            {
                if (query2[i] < '0' || query2[i] > '9')

                {
                    return false;
                }
                i++;
            }
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

char *IntToString(int x)
{

    char *res = (char *)malloc(sizeof(char) * 100);

    itoa(x, res, 10);

    return res;
}
/* End of fungsi bantuan */

<<<<<<< HEAD
void PrintInitialState(int saldo, int ctr_layani, QueueF Order, QueueF Cook, QueueF RServe)
=======
void PrintInitialState(int saldo, int ctr_layani, Queue Order, Queue Cook, Queue RServe)
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
{
    printf("Saldo: %d\n", saldo);
    printf("Customer yang telah dilayani: %d\n", ctr_layani);
    displayQueueOrder(Order);
    displayQueueCook(Cook);
    displayQueueServe(RServe);
}

<<<<<<< HEAD
void QueueOrder(QueueF *Order)
{
    Food order;
    char *ordnum = IntToString(ordNum);
    order.OrderId = conStr("M", ordnum);
=======
void QueueOrder(Queue *Order)
{
    Food order;
    char *ordnum = IntToString(ordNum);
    order.OrderId = concatStr("M", ordnum);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
    order.durasi = rand() % 5 + 1;
    order.ketahanan = rand() % 5 + 1;
    order.harga = rand() % 41 * 1000 + 10000;
    enqueueF(Order, order);
    ordNum++;
}

<<<<<<< HEAD
void CookCycle(QueueF *Cook, QueueF *RServe, QueueF *Order)
=======
void CookCycle(Queue *Cook, Queue *RServe, Queue *Order)
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
{

    Food val;
    for (int i = IDX_HEAD(*Cook); i <= IDX_TAIL(*Cook); i++)
    {
        Cook->buffer[i].durasi--;
    }
    int i = IDX_HEAD(*Cook);
    int j = IDX_TAIL(*Cook);
    while (i <= j)
    {
        if (Cook->buffer[i].durasi == 0)
        {
            val = Cook->buffer[i];
            for (int k = i; k < IDX_TAIL(*Cook); k++)
            {
                Cook->buffer[k] = Cook->buffer[k + 1];
            }
            IDX_TAIL(*Cook) -= 1;
            j--;
            int idx = searchIdx(Order, val.OrderId);
            enqueueF(RServe, Order->buffer[idx]);
            printf("Makanan %s telah dimasak\n", val.OrderId);
        }
        i++;
    }
}

<<<<<<< HEAD
void RServeCycle(QueueF *RServe, QueueF *Cook, QueueF *Order)
=======
void RServeCycle(Queue *RServe, Queue *Cook, Queue *Order)
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
{
    Food val;
    for (int i = IDX_HEAD(*RServe); i <= IDX_TAIL(*RServe); i++)
    {
        RServe->buffer[i].ketahanan--;
    }
    int i = IDX_HEAD(*RServe);
    int j = IDX_TAIL(*RServe);
    while (i <= j)
    {
        if (RServe->buffer[i].durasi == 0)
        {
            val = RServe->buffer[i];
            for (int k = i; k < IDX_TAIL(*RServe); k++)
            {
                RServe->buffer[k] = RServe->buffer[k + 1];
            }
            IDX_TAIL(*RServe) -= 1;
            j--;
            int idx = searchIdx(Order, val.OrderId);
            enqueueF(Cook, Order->buffer[idx]);
            printf("Ketahanan makanan %s telah habis\n", val.OrderId);
        }
        i++;
    }
}

void dinnerdash()
{
    ordNum = 0;
<<<<<<< HEAD
    QueueF Order, Cook, RServe;
=======
    Queue Order, Cook, RServe;
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
    CreateQueueF(&Order);
    CreateQueueF(&Cook);
    CreateQueueF(&RServe);
    int saldo = 0, ctr_layani = 0;
    int i, j;

    srand(time(NULL));
    printf("Selamat Datang di Diner Dash!\n\n");
    for (i = 0; i < 3; i++) // First 3 orders
    {
        QueueOrder(&Order);
    }
    printf("Banyak order: %d\n", lengthF(Order));
    PrintInitialState(saldo, ctr_layani, Order, Cook, RServe);
    while (ctr_layani < 15 && lengthF(Order) <= 7 && !isFullF(Order))
    {

        printf("Masukkan perintah: ");
<<<<<<< HEAD
        rQuery(&query1, &query2);
=======
        readQuery(&query1, &query2);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c

        while (!ValidInput(query1, query2))
        {
            printf("Masukkan perintah yang valid: ");
<<<<<<< HEAD
            rQuery(&query1, &query2);
        }

        if (cQuery(query1, "COOK"))
=======
            readQuery(&query1, &query2);
        }

        if (compQuery(query1, "COOK"))
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
        {
            if (searchIdx(&Order, query2) != -1)
            {
                if (!isEmptyF(Cook) && searchIdx(&Cook, query2) != -1 && !isEmptyF(RServe) && searchIdx(&RServe, query2) != -1)
                {
                    printf("Makanan %s sedang dimasak\n", query2);
                }
                else
                {
                    Food val = Order.buffer[searchIdx(&Order, query2)];
                    printf("Berhasil memasak %s\n", query2);
                    RServeCycle(&RServe, &Cook, &Order);
                    CookCycle(&Cook, &RServe, &Order);
                    enqueueF(&Cook, val);
                    QueueOrder(&Order);
                }
            }
            else
            {
                printf("Pesanan tidak ditemukan\n");
            }
        }
<<<<<<< HEAD
        else if (cQuery(query1, "SERVE"))
=======
        else if (compQuery(query1, "SERVE"))
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
        {
            if (!isEmptyF(RServe))
            {
                if (searchIdx(&RServe, query2) != -1)
                {
<<<<<<< HEAD
                    if (cQuery(HEAD(Order).OrderId, query2))
=======
                    if (compQuery(HEAD(Order).OrderId, query2))
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
                    {
                        Food temp;
                        dequeueF(&Order, &temp);
                        dequeueF(&RServe, &temp);
                        saldo += temp.harga;
                        ctr_layani++;
                        printf("Berhasil mengantar %s\n", temp.OrderId);
<<<<<<< HEAD
                        RServeCycle(&RServe, &Cook, &Order);
                        CookCycle(&Cook, &RServe, &Order);
=======
                        // RServeCycle(&RServe, &Cook, &Order);
                        // CookCycle(&Cook, &RServe);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
                        QueueOrder(&Order);
                    }
                    else
                    {
                        printf("%s belum bisa disajikan karena %s belum selesai\n", query2, HEAD(Order).OrderId);
                    }
                }
                else
                {
                    printf("Pesanan tidak ditemukan atau tidak valid\n");
                }
            }
            else
            {
                printf("Tidak ada makanan yang siap disajikan\n");
            }
        }
<<<<<<< HEAD
        else if (cQuery(query1, "SKIP"))
        {
=======
        else if (compQuery(query1, "SKIP")){
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
            RServeCycle(&RServe, &Cook, &Order);
            CookCycle(&Cook, &RServe, &Order);
            QueueOrder(&Order);
        }
        query1 = NULL;
        query2 = NULL;
        printf("==========================================================\n\n");
        printf("Banyak order: %d\n", lengthF(Order));
        PrintInitialState(saldo, ctr_layani, Order, Cook, RServe);
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
<<<<<<< HEAD
=======
}

int main()
{
    dinnerdash();
    return 0;
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
}