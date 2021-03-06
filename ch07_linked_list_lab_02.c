#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element				data;
	struct ListNode*	link;
} ListNode;

typedef struct ListNodeHead { 	// 헤드노드 타입
	double				sum;	// 합계
	double				avg;	// 평균
	double				var;	// 분산
	ListNode*			head;
} ListHeadNode;

//
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->link = NULL;
	if (head == NULL) {
		head = node;
	}
	else {
		node->link	= head;
		head		= node;
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

//
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* temp = head;
	node->data = data;
	node->link = NULL;
	if (head == NULL) {
		head = node;
	}
	else {
		// 마지막 노드까지 traverse...
		while (temp->link != NULL) {
			temp = temp->link;
		}
		// 마지막 노드 뒤에 생성 노드 추가...
		temp->link = node;
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

//
void InitHeadNode( ListHeadNode* headNode )
{
	headNode->head = NULL;
	headNode->sum = 0.0;
	headNode->avg = 0.0;
	headNode->var = 0.0;
}

// 합계 구하기 함수를 완성하시오.
double get_sum_of_linked_list( ListHeadNode* headNode )
{
	//
	return headNode->sum;
}

// 평균 구하기 함수를 완성하시오.
double get_avg_of_linked_list( ListHeadNode* headNode )
{
	//
	return headNode->avg;
}

// 분산 구하기 함수를 완성하시오.
double get_var_of_linked_list(ListHeadNode* headNode)
{
	//
	return headNode->var;
}

// 리스트의 항목 출력
void print_list( ListNode* head )
{
	ListNode* p = head;

	if (head == NULL) return;
	do {
		printf("->%d ", p->data);
		p = p->link;
	} while (p != NULL);
	printf("\n");
}

//
int main(void)
{
	ListHeadNode	HeadNode;
	

	InitHeadNode(&HeadNode);

	// list = 10->20->30->40-> ... ->90->100
	for (int i = 10; i <= 100; i += 10) {
		HeadNode.head = insert_last(HeadNode.head, i);
	}

	//
	print_list( HeadNode.head );

	// 
	printf("- sum : %lf\n", get_sum_of_linked_list( &HeadNode ));
	printf("- avg : %lf\n", get_avg_of_linked_list( &HeadNode ));
	printf("- var : %lf\n", get_var_of_linked_list( &HeadNode ));

	return 0;
}


