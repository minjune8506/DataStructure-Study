#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * createLinkedQueue() - Linked Queue 생성
 * 
 * return : Linked Queue의 포인터
 */
LinkedQueue *createLinkedQueue()
{
    LinkedQueue* queue;
	
	queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (!queue)
        return (NULL);
    queue->currentCustomerCount = 0;
    queue->pFrontNode = NULL;
    queue->pRearNode = NULL;
    return (queue);
}

/**
 * createQueueNode() - Queue Node 생성
 * 
 * return : Queue Node의 포인터
 * element : 추가할 QueueNode
 */
QueueNode *createQueueNode(QueueNode element)
{
	QueueNode* node;
	
	node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!node)
        return (NULL);
    node->data = element.data;
    node->pLink = NULL;
    return (node);
}

/**
 * pushLQ() - Linked Queue의 rear에 Node 추가
 * 
 * return : 1 (EXIT_FAILURE) / 0 (EXIT_SUCCESS)
 * pQueue : Linked Queue의 포인터
 * element : 추가할 Queue Node
 */
int pushLQ(LinkedQueue *pQueue, QueueNode element)
{
	QueueNode *node;

	if (!pQueue)
		return (EXIT_FAILURE);
	node = createQueueNode(element);
	if (!node)
		return (EXIT_FAILURE);
	if (pQueue->currentCustomerCount == 0)
	{
		pQueue->pFrontNode = node;
		pQueue->pRearNode = node;
	}
	else
	{
		pQueue->pRearNode->pLink = node;
		pQueue->pRearNode = node;
	}
	pQueue->currentCustomerCount++;
	return (EXIT_SUCCESS);

}

/**
 * popLQ() - Linked Queue의 Front Node 제거
 * 
 * return : 제거한 Node의 포인터 / Linked Queue가 비어있으면 NULL 반환
 * pQueue : Linked Queue의 포인터
 */
QueueNode *popLQ(LinkedQueue *pQueue)
{
	QueueNode *node;

	if (!pQueue || isLinkedQueueEmpty(pQueue))
		return (NULL);
	node = pQueue->pFrontNode;
	if (pQueue->currentCustomerCount == 1)
	{
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else
		pQueue->pFrontNode = node->pLink;
	pQueue->currentCustomerCount--;
	return (node);
}

/**
 * peekLQ() - Linked Queue의 Front Node 반환
 * 
 * return : Linked Queue의 Front Node의 포인터 / 비어있다면 NULL 반환
 * pQueue : Linked QUeue의 포인터 
 */
QueueNode *peekLQ(LinkedQueue *pQueue)
{
	QueueNode *node;

	if (!pQueue || isLinkedQueueEmpty(pQueue))
		return (NULL);
	node = pQueue->pFrontNode;
	return (node);
}

/**
 * isLinkedQueueEmpty() - Linked Queue가 비어있는지 확인
 * 
 * return : True / False
 * pQueue : Linked Queue의 포인터
 */
int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	if (!pQueue)
		return (-1);
	return (pQueue->currentCustomerCount == 0);
}

/**
 * insertCustomer() - Linked Queue에 고객 추가
 * 
 * return : None
 * arrivalTime : 고객의 도착 시간
 * processTime : 고객이 서비스를 받는 시간
 * pQueue : Linked Queue의 포인터
 */
void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	QueueNode customer;

	customer.data.status = 0;
	customer.data.arrivalTime = arrivalTime;
	customer.data.serviceTime = processTime;
	customer.data.startTime = 0;
	customer.data.endTime = 0;
	pushLQ(pQueue, customer);
}

/**
 * processArrival() - Arrival Queue에서 Wait Queue로 고객 이동
 * 
 * Arrival Queue의 Front에 위치한 Node의 도착 시간이 현재 시간과 같을 경우
 * Wait Queue로 이동하여 서비스를 받을 준비가 됐음을 알림
 * 
 * return : None
 * currentTime : 현재 시각
 * pArrivalQueue : Arrival Queue의 포인터
 * pWaitQueue : Wait Queue의 포인터
 */
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	QueueNode *node;

	node = peekLQ(pArrivalQueue);
	if (!node)
		return ;
	if (currentTime == node->data.arrivalTime)
	{
		node = popLQ(pArrivalQueue);
		node->data.status = arrival;
		pushLQ(pWaitQueue, *node);
		free(node);
	}
}

/**
 * processServiceNodeStart() - Service를 받을 Node를 wait queue에서 가져와 시작 상태로 만듬
 * 
 * return : Service를 받는 Node의 포인터 / Service를 받을 노드가 없다면 NULL
 * currentTime : 현재 시각
 * pWaitQueue : Wait Queue의 포인터
 */
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode *node;

	node = popLQ(pWaitQueue);
	if (!node)
		return (NULL);
	node->data.status = start;
	node->data.startTime = currentTime;
	return (node);
}

/**
 * processServiceNodeEnd() - Service를 받는 Node가 서비스를 다 받았을 경우 종료 상태로 만듬
 * 
 * return : pServiceNode / 아직 종료할 시간이 되지 않았다면 NULL
 * currentTime : 현재 시간
 * pServiceNode : Service를 받는 Node의 주소
 * pServiceUserCount : Service를 받은 User의 수
 * pTotalWaitTime : Service를 받은 User들의 총대기시간
 */
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (currentTime != pServiceNode->data.startTime + pServiceNode->data.serviceTime)
		return (NULL);
	pServiceNode->data.endTime = currentTime;
	pServiceNode->data.status = end;
	*pServiceUserCount += 1;
	*pTotalWaitTime += (pServiceNode->data.startTime - pServiceNode->data.arrivalTime);
	return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	// printf(RED"\nCurrentTime: %d\n"RESET, currentTime);
	if (customer.status == arrival)
		printf("status : "BLUE"arrival "RESET);
	else if (customer.status == start)
		printf("status : "BLUE"start "RESET);
	else
		printf("status : "BLUE"end "RESET);
	
	printf("arrivalTime : %d serviceTime : %d startTime : %d ", customer.arrivalTime, customer.serviceTime, customer.startTime);
	if (customer.endTime)
		printf("endTime : %d", customer.endTime);
	printf("\n");
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    if (isLinkedQueueEmpty(pWaitQueue))
	{
        printf("Wait Queue is Empty.\n");
		return ;
	}
    printf("%d Customers in the Wait Queue\n", pWaitQueue->currentCustomerCount);
}

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf(BLUE"---------------------REPORT---------------------\n"RESET);
	printf("MAX_TIME : %d\n", MAX_TIME);
	if (!isLinkedQueueEmpty(pWaitQueue))
		printf("Remaining Customer : %d\n", pWaitQueue->currentCustomerCount);
	printf("Service User Count : %d\n", serviceUserCount);
	printf("Total Wait Time : %d\n", totalWaitTime);
	printf("Average Wait Time : %.1f\n", totalWaitTime / (float)serviceUserCount);
}

void inputCustomer(LinkedQueue *pArrivalQueue)
{
	// insertCutomer(0, 2, pArrivalQueue); // 0도착 2종료
	// insertCutomer(1, 3, pArrivalQueue); // 1도착 2시작 5종료 
	// insertCutomer(2, 4, pArrivalQueue); // 2도착 5시작 9종료 
	// insertCutomer(6, 2, pArrivalQueue); // 6도착 9시작 11종료
	int menu;
	int arrivalTime;
	int serviceTime;

	printf("---------------------Customer Input---------------------\n");
	while (1)
	{
		printf("메뉴\n");
		printf("1. 고객 추가\n");
		printf("2. 고객 입력 종료\n");
		printf("입력 : ");
		scanf("%d", &menu);
		if (menu == 1)
		{
			printf("고객 도착 시간 : ");
			scanf("%d", &arrivalTime);
			printf("고객 서비스 시간 : ");
			scanf("%d", &serviceTime);
			insertCutomer(arrivalTime, serviceTime, pArrivalQueue);
		}
		else if (menu == 2)
			break ;
		else
			printf("RTFM\n");
	}
	printf("---------------------Input END---------------------\n");
}

int main(void)
{
	LinkedQueue *pArrivalQueue = NULL;
	LinkedQueue *pWaitQueue = NULL;
	QueueNode *pServiceNode = NULL;
	QueueNode *temp = NULL;
	int ServiceUserCount = 0;
	int TotalWaitTime = 0;

	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();	
	inputCustomer(pArrivalQueue);

	for (int t = 0 ; t < MAX_TIME ; t++)
	{
		printf(RED"\nCurrentTime: %d\n"RESET, t);
		processArrival(t, pArrivalQueue, pWaitQueue);
		printWaitQueueStatus(t, pWaitQueue);
		if (!pServiceNode) // pServiceNode 가 NULL 인경우 service node를 받아온다.
		{
			pServiceNode = processServiceNodeStart(t, pWaitQueue);
			if (pServiceNode)
				printSimCustomer(t, pServiceNode->data);
			else // wait queue에 고객이 없는경우 반복문 넘어가기
				continue ;
		}
		temp = processServiceNodeEnd(t, pServiceNode, &ServiceUserCount, &TotalWaitTime);
		if (temp) // 끝날 시간이 돼서 주소가 반환된 경우
		{
			printSimCustomer(t, pServiceNode->data);
			free(pServiceNode);
			pServiceNode = NULL;
			pServiceNode = processServiceNodeStart(t, pWaitQueue);
			if (pServiceNode)
				printSimCustomer(t, pServiceNode->data);
		}
	}
	printReport(pWaitQueue, ServiceUserCount, TotalWaitTime);

	assert(isLinkedQueueEmpty(pArrivalQueue));
	assert(isLinkedQueueEmpty(pWaitQueue));
	
	free(pWaitQueue);
	free(pArrivalQueue);
	// system("leaks a.out");
}
