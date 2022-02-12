#ifndef SIMULATION
#define SIMULATION

// Queue 구조 (선택)
// rear -> o -> o -> front
// front <- o <- o <- rear

typedef struct QueueNodeType
{
	char data;
	struct DequeNodeType* pLLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// 현재 원소의 개수
	QueueNode* pFrontNode;		// Front 노드의 포인터
	QueueNode* pRearNode;		// Rear 노드의 포인터
} LinkedQueue;

typedef enum SimStatusType { arrival, start, end} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime; // 도착 시각.
	int serviceTime; // 서비스 시간.
	int startTime; // 시작 시각.
	int endTime; // 종료 시각 : 시작 시각 + 서비스 시간.
} SimCustomer;

// Queue Functions
LinkedQueue *createLinkedQueue();
QueueNode *createQueueNode();
int pushLQ(LinkedQueue *pQueue, LinkedQueue element);
QueueNode *popLQ(LinkedQueue *pQueue);
QueueNode *peekLQ(LinkedQueue *pQueue);
int isLinkedQueueEmpty(LinkedQueue *pQueue);

// Simulation Functions
void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue);
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif
