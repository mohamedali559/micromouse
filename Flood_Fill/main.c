#include <stdio.h>
#include "API.h"
#include "include.h"
#include "Queue.h"

int visited[16][16] = {0};
int Walls[16][16] = {0};

int neighbour_1_x, neighbour_1_y, neighbour_2_x, neighbour_2_y, neighbour_3_x, neighbour_3_y, neighbour_4_x, neighbour_4_y;
int Direction = North;

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

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

int Wall_idx = 0;
int curr_x_pos = 0, curr_y_pos = 15;
char buffer_x[50];
char buffer_y[50];

//----------------------------------------------------------------
//----------------------------------------------------------------
//                  MAIN
//----------------------------------------------------------------
//----------------------------------------------------------------

int main(int argc, char *argv[])
{

    // Queue q;
    // initQueue(&q);
    // QueueNode poped;

    // enqueue(&q, 7, 7);
    // enqueue(&q, 7, 8);
    // enqueue(&q, 8, 7);
    // enqueue(&q, 8, 8);
    // Make_visited(7, 7);
    // Make_visited(7, 8);
    // Make_visited(8, 7);
    // Make_visited(8, 8);

    while (1)
    {

        //----------------------------------------
        //  update walls & print direction
        //----------------------------------------
        Update_Walls(curr_x_pos, curr_y_pos);
        Wall_printer();
        //----------------------------------------

        //----------------------------------------------
        //----------------------------------------------
        // get neighbours:)
        Get_neighbours(curr_x_pos, curr_y_pos);
        printt("neighbour 1 ");
        sprintf(buffer_x, "%d", neighbour_1_x);
        sprintf(buffer_y, "%d", neighbour_1_y);
        printtt(buffer_x, buffer_y);
        printt("neighbour 2 ");
        sprintf(buffer_x, "%d", neighbour_2_x);
        sprintf(buffer_y, "%d", neighbour_2_y);
        printtt(buffer_x, buffer_y);
        printt("neighbour 3 ");
        sprintf(buffer_x, "%d", neighbour_3_x);
        sprintf(buffer_y, "%d", neighbour_3_y);
        printtt(buffer_x, buffer_y);
        printt("neighbour 4 ");
        sprintf(buffer_x, "%d", neighbour_4_x);
        sprintf(buffer_y, "%d", neighbour_4_y);
        printtt(buffer_x, buffer_y);
        //----------------------------------------------
        //----------------------------------------------
        if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East))
        {
            printt("neighbour 1 ");
            sprintf(buffer_x, "%d", neighbour_1_x);
            sprintf(buffer_y, "%d", neighbour_1_y);
            printtt(buffer_x, buffer_y);
            printt("Is Valid ");
        }
        else
        {
            printt("neighbour 1 ");
            sprintf(buffer_x, "%d", neighbour_1_x);
            sprintf(buffer_y, "%d", neighbour_1_y);
            printtt(buffer_x, buffer_y);
            printt("Is not Valid ");
        }
        if (neighbour_isValid(neighbour_2_x, neighbour_2_y, West))
        {
            printt("neighbour 2 ");
            sprintf(buffer_x, "%d", neighbour_2_x);
            sprintf(buffer_y, "%d", neighbour_2_y);
            printtt(buffer_x, buffer_y);
            printt("Is Valid ");
        }
        else
        {
            printt("neighbour 2 ");
            sprintf(buffer_x, "%d", neighbour_2_x);
            sprintf(buffer_y, "%d", neighbour_2_y);
            printtt(buffer_x, buffer_y);
            printt("Is not Valid ");
        }
        if (neighbour_isValid(neighbour_3_x, neighbour_3_y, North))
        {
            printt("neighbour 3 ");
            sprintf(buffer_x, "%d", neighbour_3_x);
            sprintf(buffer_y, "%d", neighbour_3_y);
            printtt(buffer_x, buffer_y);
            printt("Is Valid ");
        }
        else
        {
            printt("neighbour 3 ");
            sprintf(buffer_x, "%d", neighbour_3_x);
            sprintf(buffer_y, "%d", neighbour_3_y);
            printtt(buffer_x, buffer_y);
            printt("Is not Valid ");
        }
        if (neighbour_isValid(neighbour_4_x, neighbour_4_y, South))
        {
            printt("neighbour 4 ");
            sprintf(buffer_x, "%d", neighbour_4_x);
            sprintf(buffer_y, "%d", neighbour_4_y);
            printtt(buffer_x, buffer_y);
            printt("Is Valid ");
        }
        else
        {
            printt("neighbour 4 ");
            sprintf(buffer_x, "%d", neighbour_4_x);
            sprintf(buffer_y, "%d", neighbour_4_y);
            printtt(buffer_x, buffer_y);
            printt("Is not Valid ");
        }

        // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
        // just  wall following algo
        //----------------------------------------
        //----------------------------------------
        if (!API_wallLeft())
        {
            API_turnLeft();
            switch (Direction)
            {
            case North:
                Direction = West;
                break;
            case South:
                Direction = East;
                break;
            case East:
                Direction = North;
                break;
            case West:
                Direction = South;
                break;
            }
        }
        while (API_wallFront())
        {
            API_turnRight();

            switch (Direction)
            {
            case North:
                Direction = East;
                break;
            case South:
                Direction = West;
                break;
            case East:
                Direction = South;
                break;
            case West:
                Direction = North;
                break;
            }
        }
        API_moveForward();
        switch (Direction)
        {
        case North:
            curr_y_pos--;
            break;
        case South:
            curr_y_pos++;
            break;
        case East:
            curr_x_pos++;
            break;
        case West:
            curr_x_pos--;
            break;
        }
        sprintf(buffer_x, "%d", curr_x_pos);
        sprintf(buffer_y, "%d", curr_y_pos);
        printtt(buffer_x, buffer_y);
    }

    //--------------------------------------
    //--------------------------------------
    //--------------------------------------

    // the code where here!!!!!!!!

    //--------------------------------------
    //--------------------------------------
    //--------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

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
        if (Walls[neighbour_x][neighbour_y] == South || Walls[neighbour_x][neighbour_y] == South_East || Walls[neighbour_x][neighbour_y] == South_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East)
        {
            return false;
        }
        break;
    case South:
        if (Walls[neighbour_x][neighbour_y] == North || Walls[neighbour_x][neighbour_y] == Nourth_East || Walls[neighbour_x][neighbour_y] == Nourth_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East)
        {
            return false;
        }
        break;

    case East:
        if (Walls[neighbour_x][neighbour_y] == West || Walls[neighbour_x][neighbour_y] == Nourth_West || Walls[neighbour_x][neighbour_y] == South_West || Walls[neighbour_x][neighbour_y] == South_West_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East)
        {
            return false;
        }
        break;

    case West:
        if (Walls[neighbour_x][neighbour_y] == East || Walls[neighbour_x][neighbour_y] == Nourth_East || Walls[neighbour_x][neighbour_y] == South_East || Walls[neighbour_x][neighbour_y] == South_East_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East)
        {
            return false;
        }
        break;
    }

    if (visited[neighbour_x][neighbour_y] == 0 && neighbour_x >= 0 && neighbour_x < 15 && neighbour_y >= 0 && neighbour_y < 15)
    {
        return true;
    }
    else
        return false;
}

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

// update in simulator
int Update_Walls(int x_pos, int y_pos)
{
    switch (Direction)
    {
    case North:
        // i update just the 3 main directions.
        if (API_wallFront())
        {
            Wall_idx = 1;
            Walls[x_pos][y_pos] = North;

            if (y_pos - 1 >= 0) // update the next cell not just mine!
            {
                Walls[x_pos][y_pos - 1] = South;
                printt("update next!!!!!!! South");
            }
        }
        if (API_wallLeft())
        {
            Wall_idx = 2;
            Walls[x_pos][y_pos] = West;

            if (x_pos - 1 >= 0)
                Walls[x_pos - 1][y_pos] = East;
        }
        if (API_wallRight())
        {
            Wall_idx = 3;
            Walls[x_pos][y_pos] = East;

            if (x_pos + 1 < 15)
            {
                Walls[x_pos + 1][y_pos] = West;
                printt("update next!!!!!!! put West");
            }
        }
        if (API_wallLeft() && API_wallFront())
        {
            Wall_idx = 4;
            Walls[x_pos][y_pos] = Nourth_West;
        }
        if (API_wallRight() && API_wallFront())
        {
            Wall_idx = 5;
            Walls[x_pos][y_pos] = Nourth_East;
        }
        if (API_wallRight() && API_wallLeft())
        {
            Wall_idx = 6;
            Walls[x_pos][y_pos] = East_West;
        }
        if (API_wallRight() && API_wallFront() && API_wallLeft())
        {
            Wall_idx = 7;
            Walls[x_pos][y_pos] = Nourth_West_East;
        }
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;

    case South:
        if (API_wallFront())
        {
            Wall_idx = 8;
            Walls[x_pos][y_pos] = South;

            if (y_pos + 1 < 15)
                Walls[x_pos][y_pos + 1] = North;
        }
        if (API_wallLeft())
        {
            Wall_idx = 9;
            Walls[x_pos][y_pos] = East;

            if (x_pos + 1 < 15)
                Walls[x_pos + 1][y_pos] = West;
        }
        if (API_wallRight())
        {
            Wall_idx = 10;
            Walls[x_pos][y_pos] = West;

            if (x_pos - 1 >= 0)
                Walls[x_pos - 1][y_pos] = East;
        }
        if (API_wallLeft() && API_wallFront())
        {
            Wall_idx = 11;
            Walls[x_pos][y_pos] = South_East;
        }
        if (API_wallRight() && API_wallFront())
        {
            Wall_idx = 12;
            Walls[x_pos][y_pos] = South_West;
        }
        if (API_wallRight() && API_wallLeft())
        {
            Wall_idx = 13;
            Walls[x_pos][y_pos] = East_West;
        }
        if (API_wallRight() && API_wallFront() && API_wallLeft())
        {
            Wall_idx = 14;
            Walls[x_pos][y_pos] = South_West_East;
        }
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;
    case East:
        if (API_wallFront())
        {
            Wall_idx = 15;
            Walls[x_pos][y_pos] = East;

            if (x_pos + 1 < 15)
                Walls[x_pos + 1][y_pos] = West;
        }
        if (API_wallLeft())
        {
            Wall_idx = 16;
            Walls[x_pos][y_pos] = North;

            if (y_pos - 1 >= 0)
                Walls[y_pos - 1][y_pos] = South;
        }
        if (API_wallRight())
        {
            Wall_idx = 17;
            Walls[x_pos][y_pos] = South;

            if (y_pos + 1 < 15)
                Walls[x_pos][y_pos + 1] = North;
        }
        if (API_wallLeft() && API_wallFront())
        {
            Wall_idx = 18;
            Walls[x_pos][y_pos] = Nourth_East;
        }
        if (API_wallRight() && API_wallFront())
        {
            Wall_idx = 19;
            Walls[x_pos][y_pos] = South_East;
        }
        if (API_wallRight() && API_wallLeft())
        {
            Wall_idx = 20;
            Walls[x_pos][y_pos] = North_South;
        }
        if (API_wallRight() && API_wallFront() && API_wallLeft())
        {
            Wall_idx = 21;
            Walls[x_pos][y_pos] = South_East_Nourth;
        }
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;

    case West:
        if (API_wallFront())
        {
            Wall_idx = 22;
            Walls[x_pos][y_pos] = West;

            if (x_pos - 1 >= 0)
                Walls[x_pos - 1][y_pos] = East;
        }
        if (API_wallLeft())
        {
            Wall_idx = 23;
            Walls[x_pos][y_pos] = South;

            if (y_pos + 1 < 15)
                Walls[x_pos][y_pos + 1] = North;
        }
        if (API_wallRight())
        {
            Wall_idx = 24;
            Walls[x_pos][y_pos] = North;

            if (y_pos - 1 >= 0)
                Walls[x_pos][y_pos - 1] = South;
        }
        if (API_wallLeft() && API_wallFront())
        {
            Wall_idx = 25;
            Walls[x_pos][y_pos] = South_West;
        }
        if (API_wallRight() && API_wallFront())
        {
            Wall_idx = 26;
            Walls[x_pos][y_pos] = Nourth_West;
        }
        if (API_wallRight() && API_wallLeft())
        {
            Wall_idx = 27;
            Walls[x_pos][y_pos] = North_South;
        }
        if (API_wallRight() && API_wallFront() && API_wallLeft())
        {
            Wall_idx = 28;
            Walls[x_pos][y_pos] = South_West_Nourth;
        }
        else
            return ohhhhhhhhhhhhhhhhhhhh;
        break;
    }
}

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

void printt(char *text)
{
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

void printtt(char *text, char *text2)
{
    fprintf(stderr, "{%s , %s}\n", text, text2);
    fflush(stderr);
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

void Wall_printer(void)
{
    switch (Wall_idx)
    {
    case 1:
        printt("Direction is nourth , wall is Ahead");
        break;
    case 2:
        printt("Direction is nourth , wall is left");
        break;
    case 3:
        printt("Direction is nourth , wall is Right");
        break;
    case 4:
        printt("Direction is nourth , wall is ahed & left");
        break;
    case 5:
        printt("Direction is nourth , wall is ahed & right");
        break;
    case 6:
        printt("Direction is nourth , wall is left & right");
        break;
    case 7:
        printt("Direction is nourth , wall is ahed & left & right");
        break;
    case 8:
        printt("Direction is South , wall is Ahead");
        break;
    case 9:
        printt("Direction is South , wall is left");
        break;
    case 10:
        printt("Direction is South , wall is Right");
        break;
    case 11:
        printt("Direction is South , wall is ahed & left");
        break;
    case 12:
        printt("Direction is South , wall is ahed & right");
        break;
    case 13:
        printt("Direction is South , wall is left & right");
        break;
    case 14:
        printt("Direction is South , wall is ahed & left & right");
        break;
    case 15:
        printt("Direction is East , wall is Ahead");
        break;
    case 16:
        printt("Direction is East , wall is left");
        break;
    case 17:
        printt("Direction is East , wall is Right");
        break;
    case 18:
        printt("Direction is East , wall is ahed & left");
        break;
    case 19:
        printt("Direction is East , wall is ahed & right");
        break;
    case 20:
        printt("Direction is East , wall is left & right");
        break;
    case 21:
        printt("Direction is East , wall is ahed & left & right");
        break;
    case 22:
        printt("Direction is West , wall is Ahead");
        break;
    case 23:
        printt("Direction is West , wall is left");
        break;
    case 24:
        printt("Direction is West , wall is Right");
        break;
    case 25:
        printt("Direction is West , wall is ahed & left");
        break;
    case 26:
        printt("Direction is West , wall is ahed & right");
        break;
    case 27:
        printt("Direction is West , wall is left & right");
        break;
    case 28:
        printt("Direction is West , wall is ahed & left & right");
        break;
    }
}

// while (!isEmpty(&q))
// {

//     poped = dequeue(&q);
//     Get_neighbours(poped.x, poped.y);
//     if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East))
//     {
//         Maze[neighbour_1_x][neighbour_1_y] = Maze[poped.x][poped.y] + 1;
//         enqueue(&q, neighbour_1_x, neighbour_1_y);
//     }
//     if (neighbour_isValid(neighbour_2_x, neighbour_2_y, West))
//     {
//         Maze[neighbour_2_x][neighbour_2_y] = Maze[poped.x][poped.y] + 1;
//         enqueue(&q, neighbour_2_x, neighbour_2_y);
//     }
//     if (neighbour_isValid(neighbour_3_x, neighbour_3_y, North))
//     {
//         Maze[neighbour_3_x][neighbour_3_y] = Maze[poped.x][poped.y] + 1;
//         enqueue(&q, neighbour_3_x, neighbour_3_y);
//     }
//     if (neighbour_isValid(neighbour_4_x, neighbour_4_y, South))
//     {
//         Maze[neighbour_4_x][neighbour_4_y] = Maze[poped.x][poped.y] + 1;
//         enqueue(&q, neighbour_4_x, neighbour_4_y);
//     }

//     Make_visited(neighbour_1_x, neighbour_1_y);
//     Make_visited(neighbour_2_x, neighbour_2_y);
//     Make_visited(neighbour_3_x, neighbour_3_y);
//     Make_visited(neighbour_4_x, neighbour_4_y);
//     /////////////////////////////////////////////////////////////////////////////////////////////////////
//     QueueNode top = Front(&q);
//     // printf("x=%d  y=%d\n", top.x, top.y);

//     //-------------------------------------------------------------------------

//     for (int i = 0; i < 16; i++)
//     {
//         for (int j = 0; j < 16; j++)
//         {
//             visited[i][j] = 0;
//         }
//     }

//     //-------------------------------------------------------------------------
//     //-------------------------------------------------------------------------

//     ////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     Get_neighbours(curr_x_pos, curr_y_pos);
//     if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East) && Maze[neighbour_1_x][neighbour_1_y] == (Maze[curr_x_pos][curr_y_pos] - 1))
//     {
//         switch (Direction)
//         {
//         case North:
//             API_turnRight();
//             break;
//         case South:
//             API_turnLeft();
//             break;
//         case West:
//             API_turnLeft();
//             API_turnLeft();
//             break;
//         }
//         API_moveForward();
//         curr_x_pos++;
//     }
//     else if (neighbour_isValid(neighbour_2_x, neighbour_2_y, West) && Maze[neighbour_2_x][neighbour_2_y] == (Maze[curr_x_pos][curr_y_pos] - 1))
//     {
//         switch (Direction)
//         {
//         case North:
//             API_turnLeft();
//             break;
//         case South:
//             API_turnRight();
//             break;
//         case East:
//             API_turnLeft();
//             API_turnLeft();
//             break;
//         }
//         API_moveForward();
//         curr_x_pos--;
//     }
//     else if (neighbour_isValid(neighbour_3_x, neighbour_3_y, North) && Maze[neighbour_3_x][neighbour_3_y] == (Maze[curr_x_pos][curr_y_pos] - 1))
//     {
//         switch (Direction)
//         {
//         case East:
//             API_turnLeft();
//             break;
//         case West:
//             API_turnRight();
//             break;
//         case South:
//             API_turnLeft();
//             API_turnLeft();
//             break;
//         }
//         API_moveForward();
//         curr_y_pos++;
//         Direction = North; // Update direction after moving
//     }
//     else if (neighbour_isValid(neighbour_4_x, neighbour_4_y, South) && Maze[neighbour_4_x][neighbour_4_y] == (Maze[curr_x_pos][curr_y_pos] - 1))
//     {
//         switch (Direction)
//         {
//         case East:
//             API_turnRight();
//             break;
//         case West:
//             API_turnLeft();
//             break;
//         case North:
//             API_turnLeft();
//             API_turnLeft();
//             break;
//         }
//         API_moveForward();
//         curr_y_pos--;
//         Direction = South; // Update direction after moving
//     }
// }