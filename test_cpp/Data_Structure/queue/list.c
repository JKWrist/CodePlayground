#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct LIST_ITEM {
	int value;
	LIST_ENTRY(LIST_ITEM) entry;
};

static LIST_HEAD(,LIST_ITEM) slist_head;

int main(int argc, char *argv[])
{
	int i = 0;
	struct LIST_ITEM *item;
	struct LIST_ITEM *tmp_item;

	LIST_INIT(&slist_head);

	if (LIST_EMPTY(&slist_head))
		printf("List is empty\n");

	printf("after do LIST_INSERT_HEAD:\n");
	for( i = 0; i < 10; i ++) {
		item = (struct LIST_ITEM *)malloc(sizeof(struct LIST_ITEM));
		item->value = i;
		LIST_INSERT_HEAD(&slist_head, item, entry);
	}

	LIST_FOREACH(tmp_item, &slist_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	printf("after do LIST_INSERT_AFTER:\n");
	for( i = 0; i < 10; i ++) {
		tmp_item = (struct LIST_ITEM *)malloc(sizeof(struct LIST_ITEM));
		tmp_item->value = i + 10;
		// LIST_INSERT_AFTER(item, tmp_item, entry);
		LIST_INSERT_BEFORE(item, tmp_item, entry);
		item = tmp_item;
	}

	LIST_FOREACH(tmp_item, &slist_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	printf("after do LIST_REMOVE:\n");
	LIST_FOREACH(tmp_item, &slist_head, entry) {
		LIST_REMOVE(tmp_item, entry);
		free(tmp_item);
	}

	LIST_FOREACH(tmp_item, &slist_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);

	if (LIST_EMPTY(&slist_head))
		printf("List is empty\n");

    exit(EXIT_SUCCESS);

	return 0;
}
