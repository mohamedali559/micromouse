#include <stdio.h>
#include "../include/API.h"
#include "../include/include.h"
#include "../include/Queue.h"

// visited => To make indication if i have visited this cell before or not if yes then i can't make operations on it again
// Walls => make some thing like the maze walls but using directions (Check Directions Section in include header file)
// neighbour (1->4(x,y)) => this 8 variables stores the locations of the four cells neighbouring the current one
// curr_x_pos , curr_y_pos => stores the current cell
// buffers => used to convert from intger to string so i can print them in the simulator using APIs

int visited[16][16] = {0}, Walls[16][16] = {0};
int neighbour_1_x, neighbour_1_y, neighbour_2_x, neighbour_2_y, neighbour_3_x, neighbour_3_y, neighbour_4_x, neighbour_4_y;
int Wall_idx = 0, Direction = North;
int curr_x_pos = 0, curr_y_pos = 15;
char buffer_x[50], buffer_y[50], buffer_Text[50];

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

// The Maze which stores the manhaten distances

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

//----------------------------------------------------------------
//----------------------------------------------------------------
//                            MAIN
//----------------------------------------------------------------
//----------------------------------------------------------------

Queue q;
// poped => to store the dequeued cell form the queue to get its neighbours
QueueNode poped;

int main(int argc, char *argv[])
{
    initQueue(&q);
    while (1)
    {
        //--------------------------------------------------
        //  update walls & print The Positions of this Walls
        //--------------------------------------------------
        Update_Walls(curr_x_pos, curr_y_pos);
        Wall_printer();
        //--------------------------------------------------

        //--------------------------------------------------
        //--------------------------------------------------
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
        //              VALIDATE NEIGHBOURS (the neighbours for only the current cell not all cell)
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
        if (neighbour_isValid(neighbour_3_x, neighbour_3_y, South))
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
        if (neighbour_isValid(neighbour_4_x, neighbour_4_y, North))
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

        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------
        //                               Manhaten
        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------

        // enqueue The goal cell to start with them to make manhaten
        enqueue(&q, 7, 7);
        enqueue(&q, 7, 8);
        enqueue(&q, 8, 7);
        enqueue(&q, 8, 8);
        // make them as visited to prevent adding them again into the queue
        Make_visited(7, 7);
        Make_visited(7, 8);
        Make_visited(8, 7);
        Make_visited(8, 8);
        // print the manhaten values on the simulator maze
        API_setText(7, 7, "0");
        API_setText(7, 8, "0");
        API_setText(8, 7, "0");
        API_setText(8, 8, "0");

        while (!isEmpty(&q))
        {
            printt("in queue");
            poped = dequeue(&q);
            Get_neighbours(poped.x, poped.y);
            if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East))
            {
                Maze[neighbour_1_x][neighbour_1_y] = Maze[poped.x][poped.y] + 1;
                sprintf(buffer_Text, "%d", Maze[poped.x][poped.y] + 1);
                API_setText(neighbour_1_x, neighbour_1_y, buffer_Text); // print Manhaten on  The maze
                enqueue(&q, neighbour_1_x, neighbour_1_y);
                Make_visited(neighbour_1_x, neighbour_1_y);
            }
            if (neighbour_isValid(neighbour_2_x, neighbour_2_y, West))
            {
                Maze[neighbour_2_x][neighbour_2_y] = Maze[poped.x][poped.y] + 1;
                sprintf(buffer_Text, "%d", Maze[poped.x][poped.y] + 1);
                API_setText(neighbour_2_x, neighbour_2_y, buffer_Text); // print Manhaten on  The maze
                enqueue(&q, neighbour_2_x, neighbour_2_y);
                Make_visited(neighbour_2_x, neighbour_2_y);
            }
            if (neighbour_isValid(neighbour_3_x, neighbour_3_y, South))
            {
                Maze[neighbour_3_x][neighbour_3_y] = Maze[poped.x][poped.y] + 1;
                sprintf(buffer_Text, "%d", Maze[poped.x][poped.y] + 1);
                API_setText(neighbour_3_x, neighbour_3_y, buffer_Text); // print Manhaten on  The maze
                enqueue(&q, neighbour_3_x, neighbour_3_y);
                Make_visited(neighbour_3_x, neighbour_3_y);
            }
            if (neighbour_isValid(neighbour_4_x, neighbour_4_y, North))
            {
                Maze[neighbour_4_x][neighbour_4_y] = Maze[poped.x][poped.y] + 1;
                sprintf(buffer_Text, "%d", Maze[poped.x][poped.y] + 1);
                API_setText(neighbour_4_x, neighbour_4_y, buffer_Text); // print Manhaten on  The maze
                enqueue(&q, neighbour_4_x, neighbour_4_y);
                Make_visited(neighbour_4_x, neighbour_4_y);
            }
        }

        // Make all cells as not visited to update manhaten in the next Move
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                visited[i][j] = 0;
            }
        }
        //---------------------------------------------------------------------------
        //---------------------------------------------------------------------------

        // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
        // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
        //                      FLOOD_FILL
        // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
        // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

        if (neighbour_isValid(neighbour_1_x, neighbour_1_y, East) && (Maze[neighbour_1_x][neighbour_1_y] == Maze[curr_x_pos][curr_y_pos] - 1))
        {
            printt("neighbour 1 ");
            sprintf(buffer_x, "%d", neighbour_1_x);
            sprintf(buffer_y, "%d", neighbour_1_y);
            printtt(buffer_x, buffer_y);
            printt("Is Valid ");

            // check the direc & the pos of the neighbour :(
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
        if (neighbour_isValid(neighbour_3_x, neighbour_3_y, South))
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
        if (neighbour_isValid(neighbour_4_x, neighbour_4_y, North))
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
        // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
        // just  wall following algo
        //------------------------------------------------------------
        //------------------------------------------------------------
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
        if (Walls[neighbour_x][neighbour_y] == South || Walls[neighbour_x][neighbour_y] == South_East || Walls[neighbour_x][neighbour_y] == South_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East || Walls[neighbour_x][neighbour_y] == South_West_Nourth)
        {
            return false;
        }
        break;
    case South:
        if (Walls[neighbour_x][neighbour_y] == North || Walls[neighbour_x][neighbour_y] == Nourth_East || Walls[neighbour_x][neighbour_y] == Nourth_West || Walls[neighbour_x][neighbour_y] == South_East_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East || Walls[neighbour_x][neighbour_y] == Nourth_West_East)
        {
            return false;
        }
        break;

    case East:
        if (Walls[neighbour_x][neighbour_y] == West || Walls[neighbour_x][neighbour_y] == Nourth_West || Walls[neighbour_x][neighbour_y] == South_West || Walls[neighbour_x][neighbour_y] == South_West_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East || Walls[neighbour_x][neighbour_y] == Nourth_West_East)
        {
            return false;
        }
        break;

    case West:
        if (Walls[neighbour_x][neighbour_y] == East || Walls[neighbour_x][neighbour_y] == Nourth_East || Walls[neighbour_x][neighbour_y] == South_East || Walls[neighbour_x][neighbour_y] == South_East_Nourth || Walls[neighbour_x][neighbour_y] == South_West_East || Walls[neighbour_x][neighbour_y] == Nourth_West_East)
        {
            return false;
        }
        break;
    }

    if (visited[neighbour_x][neighbour_y] == 0 && neighbour_x >= 0 && neighbour_x < Maze_Limit && neighbour_y >= 0 && neighbour_y < Maze_Limit)
    {
        return true;
    }
    else
        return false;
}

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
                Walls[x_pos][y_pos - 1] = South;
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

            if (x_pos + 1 < Maze_Limit)
                Walls[x_pos + 1][y_pos] = West;
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

            if (y_pos + 1 < Maze_Limit)
                Walls[x_pos][y_pos + 1] = North;
        }
        if (API_wallLeft())
        {
            Wall_idx = 9;
            Walls[x_pos][y_pos] = East;

            if (x_pos + 1 < Maze_Limit)
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
            Wall_idx = Maze_Limit;
            Walls[x_pos][y_pos] = East;

            if (x_pos + 1 < Maze_Limit)
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

            if (y_pos + 1 < Maze_Limit)
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

            if (y_pos + 1 < Maze_Limit)
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