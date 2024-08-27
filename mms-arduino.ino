#define North 1
#define South 2
#define East 3
#define West 4
int dirc = North;
int x = 0 , y =0;
void setup() {
    Serial.begin(19200);
    log("Running...");
}

void loop() {
    setColor(0, 0, 'G');
    setText(0, 0, "abc");
    while (true) {
      //----------------
      if(x==9 && y == 8)
        moveForward();
      //-------------------
        if (!wallRight()) {
            turnRight();
            if(dirc == North)
              dirc = East;
            else if(dirc == East)
              dirc = South;
            else if(dirc == South)
              dirc = West;
            else if(dirc == West)
              dirc = North;
            log("Right");
        }
        while (wallFront()) {
            turnLeft();
            if(dirc == North)
              dirc = West;
            else if(dirc == East)
              dirc = North;
            else if(dirc == South)
              dirc = East;
            else if(dirc == West)
              dirc = South;
            log("Left");
        }
        moveForward();
        switch (dirc) {
        case North:
          y++;
        break;
        case South:
          y--;
        break;
        case East:
          x++;
        break;
        case West:
          x--;
        break;
        }
        String X = "{";
        X += (String)(x);
        String Y = (String)(y);
        X += " ,";
        X += Y;
        X += "}";
        log(X);
    }
}