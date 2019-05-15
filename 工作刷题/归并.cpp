#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode * next;
}LNode;

void merge(LNode * A, LNode * B, LNode *&C)
{
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *r;
	C = A;
	C->next = NULL;
	free(B);
	r = C;
	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q;
			p = p->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if(p != NULL)
		r->next = p;
	if(q != NULL)
		r->next = q;
}

void mergeSort(int A[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid, high);
	}
}
int main(int argc, char *argv[]) 
{
	
}