#include <elapsedMillis.h>
#include<DotMatrix.h>

const int CONTRAST = 4;
const int DELAY_TIME = 500;

ElemType DefaultArray[nROWS][nCOLS] = {             //short int
  {-1, 0, 0, 0, 0, 0, 0,-1},
  {-1, 0, 1, 1, 1, 0, 0,-1},
  {-1, 0, 1, 0, 0, 1, 0,-1},
  {-1, 0, 1, 0, 0, 1, 0,-1},
  {-1, 0, 1, 1, 1, 0, 0,-1},
  {-1, 0, 1, 0, 0, 1, 0,-1},
  {-1, 0, 1, 0, 0, 1, 0,-1},
  {-1, 0, 0, 0, 0, 0, 0,-1}};

DotMatrix dm(DefaultArray);

int count = 0;

void setup()
{
  //Serial.begin(9600);

  int i;
  for (i=2; i<=17; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

    dm.setTo(DefaultArray);
    dm.show(DELAY_TIME, CONTRAST);
    dm.clear();
    dm.show(DELAY_TIME, CONTRAST);
    
    dm.setTo(DefaultArray);
    dm.showAll(DELAY_TIME);
    
    dm.rotate270();
    dm.show(DELAY_TIME);
    
    dm(1,6) = -1;
    dm(5,9) = 4;
    dm.show(DELAY_TIME);
    
    dm.transpose();
    dm.showAll(DELAY_TIME);
    
    dm.flipVert();
    dm.show(DELAY_TIME);

    for(i=0; i<nROWS; i++)
    {
        dm.wrap(-1, 2);
        dm.show(DELAY_TIME);
    }
    
    dm.clear();
    dm.show(DELAY_TIME);

    for(i=0; i<8; i++)
    {
        dm.setTo(DefaultArray);
        dm.reorient(i);
        dm.show(DELAY_TIME);
    }
    
    dm.clear();
    dm.show(DELAY_TIME);
    
    dm.setTo(DefaultArray);
    /*dm(0,0) = 1;
    dm(7,0) = 1;
    dm(0,7) = 1;
    dm(7,7) = 1;*/

    dm.show(DELAY_TIME);
}

void loop()
{
    int i;
    for(i=0; i<nROWS; i++)
    {
        dm.swapCols((i+1)%nCOLS, i);
        //dm.show(DELAY_TIME/4);
        dm.swapRows((i+1)%nROWS, i);
        dm.show(DELAY_TIME/4);
    }
}

