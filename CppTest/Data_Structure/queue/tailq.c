#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct QUEUE_ITEM {
	int value;
	TAILQ_ENTRY(QUEUE_ITEM) entry;
};

static TAILQ_HEAD(,QUEUE_ITEM) queue_head;

int main(int argc, char *argv[])
{
	int i = 0;
	struct QUEUE_ITEM *item;
	struct QUEUE_ITEM *tmp_item;

	TAILQ_INIT(&queue_head);

	if (TAILQ_EMPTY(&queue_head))
		printf("queue is empty\n");

	printf("after do TAILQ_INSERT_HEAD\n");
	for( i = 0; i < 10; i ++) {
		item = (struct QUEUE_ITEM *)malloc(sizeof(struct QUEUE_ITEM));
		item->value = i;
		TAILQ_INSERT_HEAD(&queue_head, item, entry);
	}
	TAILQ_FOREACH(tmp_item, &queue_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	printf("after do TAILQ_INSERT_TAIL\n");
	for( i = 0; i < 10; i ++) {
		item = (struct QUEUE_ITEM *)malloc(sizeof(struct QUEUE_ITEM));
		item->value = i + 10;
		TAILQ_INSERT_TAIL(&queue_head, item, entry);
	}
	TAILQ_FOREACH(tmp_item, &queue_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	printf("after do TAILQ_REMOVE\n");
	TAILQ_FOREACH(tmp_item, &queue_head, entry) {
		TAILQ_REMOVE(&queue_head, tmp_item, entry);
		free(tmp_item);
	}

	if (TAILQ_EMPTY(&queue_head))
		printf("queue is empty\n");

    exit(EXIT_SUCCESS);

	return 0;
}