int DS   = 10;
int SHCP = 8;
int STCP = 9;

// COMMON-ANODE segment data
byte seg[10] = {
  0b11000000, //0
  0b11111001, //1
  0b10100100, //2
  0b10110000, //3
  0b10011001, //4
  0b10010010, //5
  0b10000010, //6
  0b11111000, //7
  0b10000000, //8
  0b10010000  //9
};

void showNumber(int num)
{
  int d1 = (num / 1000) % 10;   // thousands
  int d2 = (num / 100)  % 10;   // hundreds
  int d3 = (num / 10)   % 10;   // tens
  int d4 = num % 10;            // ones

  digitalWrite(STCP, LOW);

  // **ORDER IMPORTANT: send left-most digit FIRST**
  shiftOut(DS, SHCP, MSBFIRST, seg[d1]);  
  shiftOut(DS, SHCP, MSBFIRST, seg[d2]);  
  shiftOut(DS, SHCP, MSBFIRST, seg[d3]);  
  shiftOut(DS, SHCP, MSBFIRST, seg[d4]);  

  digitalWrite(STCP, HIGH);
}

void setup() {
  pinMode(DS, OUTPUT);
  pinMode(SHCP, OUTPUT);
  pinMode(STCP, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 9999; i++) {
    showNumber(i);
    delay(100);   // 1 second per number
  }
}
