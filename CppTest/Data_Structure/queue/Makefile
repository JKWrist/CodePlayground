.PHONY : single_list single_list_test clean
single_list:
	gcc single_list.c -D QUEUE -o single_list.out

single_list_test:
	gcc single_list_test.c -o single_list_test.out

stailq:
	gcc stailq.c -D QUEUE -o stailq.out

list:
	gcc list.c -D QUEUE -o list.out

tailq:
	gcc tailq.c -D QUEUE -o tailq.out

circleq:
	gcc circleq.c -D QUEUE -o circleq.out

clean:
	rm *.out