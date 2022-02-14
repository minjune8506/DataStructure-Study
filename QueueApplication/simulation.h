#ifndef SIMULATION
#define SIMULATION

#define MAX_TIME 20
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define RESET "\033[0;0m"

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime; // 도착 시각.
	int serviceTime; // 서비스 시간.
	int startTime; // 시작 시각.
	int endTime; // 종료 시각 : 시작 시각 + 서비스 시간.
} SimCustomer;

typedef struct QueueNodeType
{
	SimCustomer data;
	struct QueueNodeType* pLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentCustomerCount;	// 현재 고객의 수
	QueueNode* pFrontNode;		// Front 노드의 포인터 (나가는 곳)
	QueueNode* pRearNode;		// Rear 노드의 포인터 (들어오는 곳)
} LinkedQueue;

// Queue Functions
LinkedQueue *createLinkedQueue();
QueueNode *createQueueNode(QueueNode customer);
int pushLQ(LinkedQueue *pQueue, QueueNode element);
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
