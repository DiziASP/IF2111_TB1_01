#include "../ADT/Queue/queue.h"

int main()
{
    Queue Q;
    CreateQueue(&Q);

    enqueue(&Q, "A. Test1");
    enqueue(&Q, "B. Test2");
    enqueue(&Q, "C. Test3");
    enqueue(&Q, "D. Test4");
    enqueue(&Q, "E. Test5");
    printf("Is Empty? %d\n", isEmpty(Q));

    // Print Queue
    displayQueue(Q);

    printf("\n");

    printf("Length: %d\n", length(Q));
    ElType temp;
    dequeue(&Q, &temp);
    dequeue(&Q, &temp);

    // Print Queue
    displayQueue(Q);

    dequeue(&Q, &temp);
    printf("Dequeue: '%s'\n", temp);
    dequeue(&Q, &temp);
    printf("Dequeue: '%s'\n", temp);
    dequeue(&Q, &temp);
    printf("Dequeue: '%s'\n", temp);
    printf("Is Empty? %d\n", isEmpty(Q));

    return 0;
}