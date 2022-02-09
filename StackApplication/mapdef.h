#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8
#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 위쪽으로 이동.
	{1, 0},			// 오른쪽으로 이동.
	{0, 1},			// 아래쪽으로 이동.
	{-1, 0}			// 왼쪽으로 이동.
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

enum Direction {RIGHT = 3, DOWN = 4, LEFT = 5, UP = 6};
typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표.
	int y;				// 현재 위치 y좌표.
	int direction;		// 다음 위치로 이동 방향.
} MapPosition;

typedef struct StackNodeType
{
	MapPosition data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top Node의 포인터
} LinkedStack;
#endif
