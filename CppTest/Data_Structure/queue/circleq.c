#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct QUEUE_ITEM {
	int value;
	CIRCLEQ_ENTRY(QUEUE_ITEM) entry;
};

static CIRCLEQ_HEAD(,QUEUE_ITEM) queue_head;

int main(int argc, char *argv[])
{
	int i = 0;
	struct QUEUE_ITEM *item;
	struct QUEUE_ITEM *tmp_item;

	CIRCLEQ_INIT(&queue_head);

	if (CIRCLEQ_EMPTY(&queue_head))
		printf("queue is empty\n");

	printf("after do CIRCLEQ_INSERT_HEAD:\n");
	for( i = 0; i < 10; i ++) {
		item = (struct QUEUE_ITEM *)malloc(sizeof(struct QUEUE_ITEM));
		item->value = i;
		CIRCLEQ_INSERT_HEAD(&queue_head, item, entry);
	}

	CIRCLEQ_FOREACH(tmp_item, &queue_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);


	printf("after do CIRCLEQ_INSERT_BEFORE:\n");
	for( i = 0; i < 10; i ++) {
		tmp_item = (struct QUEUE_ITEM *)malloc(sizeof(struct QUEUE_ITEM));
		tmp_item->value = i + 10;
		CIRCLEQ_INSERT_BEFORE(&queue_head, item, tmp_item, entry);
		item = tmp_item;
	}

	CIRCLEQ_FOREACH(tmp_item, &queue_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	CIRCLEQ_FOREACH(tmp_item, &queue_head, entry) {
		CIRCLEQ_REMOVE(&queue_head, tmp_item, entry);
	}

	CIRCLEQ_FOREACH(tmp_item, &queue_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	if (CIRCLEQ_EMPTY(&queue_head))
		printf("queue is empty\n");

	exit(EXIT_SUCCESS);

	return 0;
}