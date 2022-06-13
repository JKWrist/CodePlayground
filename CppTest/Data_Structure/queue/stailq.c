#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct entry {
    int value;
    STAILQ_ENTRY(entry) entries;        /* Singly linked tail queue */
};

static STAILQ_HEAD(stailhead, entry) stailq_head;

int
main(void)
{
    struct entry *item1, *item2, *item3, *item_temp;

    STAILQ_INIT(&stailq_head);                                  /* Initialize the queue */

    if(STAILQ_EMPTY(&stailq_head)) {
        printf("stailq_head is NULL\n");
    }

    item1 = malloc(sizeof(struct entry));
    item1->value = 1;
    STAILQ_INSERT_HEAD(&stailq_head, item1, entries);           /* Insert at the stailq_head */

    item1 = malloc(sizeof(struct entry));
    item1->value = 2;
    STAILQ_INSERT_TAIL(&stailq_head, item1, entries);           /* Insert at the tail */

    item2 = malloc(sizeof(struct entry));
    item2->value = 3;
    STAILQ_INSERT_AFTER(&stailq_head, item1, item2, entries);   /* Insert after */

    STAILQ_FOREACH(item_temp, &stailq_head, entries)
        printf("Has Item pointer = %p, item value = %d\n", item_temp, item_temp->value);

    STAILQ_REMOVE(&stailq_head, item2, entry, entries);         /* Deletion */
    free(item2);

    item3 = STAILQ_FIRST(&stailq_head);
    STAILQ_REMOVE_HEAD(&stailq_head, entries);                  /* Deletion from the stailq_head */
    free(item3);

    printf("After do STAILQ_INSERT_HEAD\n");

    item1 = STAILQ_FIRST(&stailq_head);
    item1->value = 0;

    for (int i = 1; i < 10; i++) {
        item1 = malloc(sizeof(struct entry));
        item1->value = i;

        // 头插：9，8， ... 4， 3， 2， 1， 0
        STAILQ_INSERT_HEAD(&stailq_head, item1, entries);
    }

    STAILQ_FOREACH(item_temp, &stailq_head, entries)
        printf("Has Item pointer = %p, item value = %d\n", item_temp, item_temp->value);

    printf("After do STAILQ_INSERT_TAIL\n");

    for (int i = 1; i < 10; i++) {
        item1 = malloc(sizeof(struct entry));
        item1->value = i + 10;

        // 头插：9，8， ... 4， 3， 2， 1， 0
        STAILQ_INSERT_TAIL(&stailq_head, item1, entries);
    }
    STAILQ_FOREACH(item_temp, &stailq_head, entries)
        printf("Has Item pointer = %p, item value = %d\n", item_temp, item_temp->value);

    printf("After do STAILQ_INSERT_AFTER\n");

    item_temp = item1;
    for (int i = 1; i < 10; i++) {
        item1 = malloc(sizeof(struct entry));
        item1->value = i + 20;

        // 头插：9，8， ... 4， 3， 2， 1， 0
        STAILQ_INSERT_AFTER(&stailq_head, item_temp, item1, entries);
        item_temp = item1;
    }
    STAILQ_FOREACH(item_temp, &stailq_head, entries)
        printf("Has Item pointer = %p, item value = %d\n", item_temp, item_temp->value);

    // printf("After do STAILQ_REMOVE_HEAD_UNTIL\n");

    // item_temp = STAILQ_FIRST(&stailq_head);
    // while (item_temp != NULL) {
    //     if(item_temp->value == 6) {
    //         // STAILQ_REMOVE_AFTER(&stailq_head, item_temp, entries);
    //         // STAILQ_REMOVE_HEAD(&stailq_head, entries); 
    //         // if ((STAILQ_FIRST((&stailq_head)) = STAILQ_NEXT((item_temp), entries)) == NULL)	
	// 	    //     (&stailq_head)->stqh_last = &STAILQ_FIRST((&stailq_head));
    //     }
    //     item_temp = STAILQ_NEXT(item_temp, entries);
    // }
    // STAILQ_FOREACH(item_temp, &stailq_head, entries)
    //     printf("Has Item pointer = %p, item value = %d\n", item_temp, item_temp->value);

    printf("After do DELETE ALL ELEMENTS\n");
    // 删除所有元素
    item1 = STAILQ_FIRST(&stailq_head);
    while (item1 != NULL) {
        item2 = STAILQ_NEXT(item1, entries);
        free(item1);
        item1 = item2;
    }
    STAILQ_INIT(&stailq_head);

    if(STAILQ_EMPTY(&stailq_head)) {
        printf("stailq_head is NULL\n");
    }

    exit(EXIT_SUCCESS);
}
