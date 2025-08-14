//----------------------------------------------------------------------------------------------
//                        Queue Header
//----------------------------------------------------------------------------------------------


#define SIZE 258 // Define the size of the circular queue

typedef struct
{
    int x, y;
} QueueNode;

// Queue implementation
typedef struct
{
    QueueNode data[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int x, int y);
QueueNode dequeue(Queue *q);
QueueNode Front(Queue *q);


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//              Queue.c
//----------------------------------------------------------------------------------------------
void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int x, int y)
{
    if (q->rear == SIZE - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
}

QueueNode dequeue(Queue *q)
{
    QueueNode temp = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return temp;
}

QueueNode Front(Queue *q)
{

    QueueNode temp = q->data[q->front];
    return temp;
}

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------



#define North 1
#define South 2
#define East 3
#define West 4
#define ohhhhhhhhhhhhhhhhhhhh 10

//   _
#define Nourth_East 5      //   T|
                           //   _
#define Nourth_West 6      //  |T
                           //   _
#define Nourth_West_East 7 //  |T|

//   _
#define South_East 8       //   T|
                           //   _
#define South_West 9       //  |T
                           //   _
#define South_West_East 10 //  |T|

#define South_West_Nourth 11 //  |T|

#define South_East_Nourth 12 //  |T|

// typedef char u8;

int Is_visited(int x_pos, int y_pos);
int Make_visited(int x_pos, int y_pos);
int Update_Walls(int x_pos, int y_pos);
int Get_neighbours(int x_pos, int y_pos);
int neighbour_isValid(int neighbour_x, int neighbour_y, int Neighbour_Pos);
int visited[16][16] = {0};
int Walls[16][16] = {0};

int neighbour_1_x, neighbour_1_y, neighbour_2_x, neighbour_2_y, neighbour_3_x, neighbour_3_y, neighbour_4_x, neighbour_4_y;
int Direction = North;


int x_pos = 0, y_pos = 0;
    int Maze[16][16] =
        {
            {14, 13, 12, 11, 10, 9, 8, 7, 7, 8, 9, 10, 11, 12, 13, 14},
            {13, 12, 11, 10, 9, 8, 7, 6, 6, 7, 8, 9, 10, 11, 12, 13},
            {12, 11, 10, 9, 8, 7, 6, 5, 5, 6, 7, 8, 9, 10, 11, 12},
            {11, 10, 9, 8, 7, 6, 5, 4, 4, 5, 6, 7, 8, 9, 10, 11},
            {10, 9, 8, 7, 6, 5, 4, 3, 3, 4, 5, 6, 7, 8, 9, 10},
            {9, 8, 7, 6, 5, 4, 3, 2, 2, 3, 4, 5, 6, 7, 8, 9},
            {8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8},
            {7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7},
            {7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, 7},
            {8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8},
            {9, 8, 7, 6, 5, 4, 3, 2, 2, 3, 4, 5, 6, 7, 8, 9},
            {10, 9, 8, 7, 6, 5, 4, 3, 3, 4, 5, 6, 7, 8, 9, 10},
            {11, 10, 9, 8, 7, 6, 5, 4, 4, 5, 6, 7, 8, 9, 10, 11},
            {12, 11, 10, 9, 8, 7, 6, 5, 5, 6, 7, 8, 9, 10, 11, 12},
            {13, 12, 11, 10, 9, 8, 7, 6, 6, 7, 8, 9, 10, 11, 12, 13},
            {14, 13, 12, 11, 10, 9, 8, 7, 7, 8, 9, 10, 11, 12, 13, 14}

        };    


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//                      functions
//-------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------
int Is_visited(int x_pos, int y_pos)
{
    return (visited[x_pos][y_pos]);
}
//-----------------------------------------------------------------------------------------------

int Make_visited(int x_pos, int y_pos)
{
    visited[x_pos][y_pos] = 1;
}

//-----------------------------------------------------------------------------------------------
int Get_neighbours(int x_pos, int y_pos)
{
    neighbour_1_x = x_pos + 1; // the neighbour on right
    neighbour_1_y = y_pos;

    neighbour_2_x = x_pos - 1; // the neighbour on left
    neighbour_2_y = y_pos;

    neighbour_3_x = x_pos; // the neighbour on top
    neighbour_3_y = y_pos + 1;

    neighbour_4_x = x_pos; // the bottom neighbour
    neighbour_4_y = y_pos - 1;
}

//-----------------------------------------------------------------------------------------------

int neighbour_isValid(int neighbour_x, int neighbour_y, int Neighbour_Pos)
{
    switch (Neighbour_Pos)
    {
    case North:
        if (Walls[neighbour_x][neighbour_y] == South || Walls[neighbour_x][neighbour_y] == South_East || Walls[neighbour_x][neighbour_y] == South_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth)
        {
            return false;
        }
        break;
    case South:
        if (Walls[neighbour_x][neighbour_y] == North || Walls[neighbour_x][neighbour_y] == Nourth_East || Walls[neighbour_x][neighbour_y] == Nourth_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth)
        {
            return false;
        }
        break;

    case East:
        if (Walls[neighbour_x][neighbour_y] == East || Walls[neighbour_x][neighbour_y] == Nourth_East || Walls[neighbour_x][neighbour_y] == South_East || Walls[neighbour_x][neighbour_y] == South_East_Nourth)
        {
            return false;
        }
        break;

    case West:
        if (Walls[neighbour_x][neighbour_y] == West || Walls[neighbour_x][neighbour_y] == Nourth_West || Walls[neighbour_x][neighbour_y] == South_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth)
        {
            return false;
        }
        break;
    }

    if (visited[neighbour_x][neighbour_y] == 0 && neighbour_x >= 0 && neighbour_x < 16 && neighbour_y >= 0 && neighbour_y < 16)
    {
        return true;
    }
    else
        return false;
}

//-----------------------------------------------------------------------------------------------

// update in simulator
int Update_Walls(int x_pos, int y_pos)
{
    switch (Direction)
    {
    case North:
        if (wallFront())
            Walls[x_pos][y_pos] = North;
        if (wallLeft())
            Walls[x_pos][y_pos] = West;
        if (wallRight())
            Walls[x_pos][y_pos] = East;
        if (wallLeft() && wallFront())
            Walls[x_pos][y_pos] = Nourth_West;
        if (wallRight() && wallFront())
            Walls[x_pos][y_pos] = Nourth_East;
        if (wallRight() && wallFront() && wallLeft())
            Walls[x_pos][y_pos] = Nourth_West_East;
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;

    case South:
        if (wallFront())
            Walls[x_pos][y_pos] = South;
        if (wallLeft())
            Walls[x_pos][y_pos] = East;
        if (wallRight())
            Walls[x_pos][y_pos] = West;
        if (wallLeft() && wallFront())
            Walls[x_pos][y_pos] = South_East;
        if (wallRight() && wallFront())
            Walls[x_pos][y_pos] = South_West;
        if (wallRight() && wallFront() && wallLeft())
            Walls[x_pos][y_pos] = South_West_East;
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;

    case East:
        if (wallFront())
            Walls[x_pos][y_pos] = East;
        if (wallLeft())
            Walls[x_pos][y_pos] = North;
        if (wallRight())
            Walls[x_pos][y_pos] = South;
        if (wallLeft() && wallFront())
            Walls[x_pos][y_pos] = Nourth_East;
        if (wallRight() && wallFront())
            Walls[x_pos][y_pos] = South_East;
        if (wallRight() && wallFront() && wallLeft())
            Walls[x_pos][y_pos] = South_East_Nourth;
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;

    case West:
        if (wallFront())
            Walls[x_pos][y_pos] = West;
        if (wallLeft())
            Walls[x_pos][y_pos] = South;
        if (wallRight())
            Walls[x_pos][y_pos] = North;
        if (wallLeft() && wallFront())
            Walls[x_pos][y_pos] = South_West;
        if (wallRight() && wallFront())
            Walls[x_pos][y_pos] = Nourth_West;
        if (wallRight() && wallFront() && wallLeft())
            Walls[x_pos][y_pos] = South_West_Nourth;
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;
    }
}











Queue q;
QueueNode poped;

void setup() {
    Serial.begin(19200);
    log("Running...");
    initQueue(&q);
    QueueNode poped;
    enqueue(&q, 7, 7);
    enqueue(&q, 7, 8);
    enqueue(&q, 8, 7);
    enqueue(&q, 8, 8);
    Make_visited(7, 7);
    Make_visited(7, 8);
    Make_visited(8, 7);
    Make_visited(8, 8);
    log("complete setup");
}

void loop() {

  while(!isEmpty(&q)){
    char i = 0;
        if (i > 0)
        {
            enqueue(&q, 7, 7);
            enqueue(&q, 7, 8);
            enqueue(&q, 8, 7);
            enqueue(&q, 8, 8);
            Make_visited(7, 7);
            Make_visited(7, 8);
            Make_visited(8, 7);
            Make_visited(8, 8);
        }
        i = 1;

        poped = dequeue(&q);
        Update_Walls(poped.x, poped.y);
        Get_neighbours(poped.x, poped.y);
        if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East))
        {
            log("n1 is valid");
            Maze[neighbour_1_x][neighbour_1_y] = Maze[poped.x][poped.y] + 1;
            enqueue(&q, neighbour_1_x, neighbour_1_y);
        }
        if (neighbour_isValid(neighbour_2_x, neighbour_2_y, West))
        {
            log("n2 is valid");
            Maze[neighbour_2_x][neighbour_2_y] = Maze[poped.x][poped.y] + 1;
            enqueue(&q, neighbour_2_x, neighbour_2_y);
        }
        if (neighbour_isValid(neighbour_3_x, neighbour_3_y, North))
        {
            log("n3 is valid");
            Maze[neighbour_3_x][neighbour_3_y] = Maze[poped.x][poped.y] + 1;
            enqueue(&q, neighbour_3_x, neighbour_3_y);
        }
        if (neighbour_isValid(neighbour_4_x, neighbour_4_y, South))
        {
            log("n4 is valid");
            Maze[neighbour_4_x][neighbour_4_y] = Maze[poped.x][poped.y] + 1;
            enqueue(&q, neighbour_4_x, neighbour_4_y);
        }

        Make_visited(neighbour_1_x, neighbour_1_y);
        Make_visited(neighbour_2_x, neighbour_2_y);
        Make_visited(neighbour_3_x, neighbour_3_y);
        Make_visited(neighbour_4_x, neighbour_4_y);
        
         for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                visited[i][j] = 0;
            }
        }
        log("reset visited");
        Get_neighbours(x_pos, y_pos);
        if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East) && Maze[neighbour_1_x][neighbour_1_y] == (Maze[x_pos][y_pos] - 1))
        {
            switch (Direction)
            {
            case North:
                turnRight();
                log("turn Right");
                break;
            case South:
                turnLeft();
                log("turn Left");
                break;
            case West:
                turnLeft();
                log("turn Left");
                turnLeft();
                log("turn Left");
                break;
            }
            moveForward();
            x_pos++;
        }
        else if (neighbour_isValid(neighbour_2_x, neighbour_2_y, West) && Maze[neighbour_2_x][neighbour_2_y] == (Maze[x_pos][y_pos] - 1))
        {
            switch (Direction)
            {
            case North:
                turnLeft();
                log("turn Left");
                break;
            case South:
                turnRight();
                log("turn Right");
                break;
            case East:
                turnLeft();
                log("turn Left");
                turnLeft();
                log("turn Left");
                break;
            }
            moveForward();
            x_pos--;
        }
        else if (neighbour_isValid(neighbour_3_x, neighbour_3_y, North) && Maze[neighbour_2_x][neighbour_2_y] == (Maze[x_pos][y_pos] - 1))
        {
            switch (Direction)
            {
            case East:
                turnLeft();
                break;
            case West:
                turnRight();
                break;
            case South:
                turnLeft();
                turnLeft();
                break;
            }
            moveForward();
            y_pos++;
        }
        else if (neighbour_isValid(neighbour_4_x, neighbour_4_y, South) && Maze[neighbour_2_x][neighbour_2_y] == (Maze[x_pos][y_pos] - 1))
        {
            switch (Direction)
            {
            case East:
                turnRight();
                break;
            case West:
                turnLeft();
                break;
            case North:
                turnLeft();
                turnLeft();
                break;
            }
            moveForward();
            y_pos--;
        }
  }
}