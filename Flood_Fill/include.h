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

#define East_West 13
#define North_South 14

// typedef char u8;

int Is_visited(int x_pos, int y_pos);
int Make_visited(int x_pos, int y_pos);
int Update_Walls(int x_pos, int y_pos);
int Get_neighbours(int x_pos, int y_pos);
int neighbour_isValid(int neighbour_x, int neighbour_y, int Neighbour_Pos);
void printt(char *text);
void printtt(char *text, char *text2);
void Wall_printer(void);