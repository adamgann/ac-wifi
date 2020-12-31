/*  Control air conditioner using Adafruit IO and IR LED. 
 *  Adam Gannon - 9/2020. 
  */

// Stores IO key and WiFi setup info 
#include "config.h"

// IR remote info 
#define IR_BIT_BANG_OVERHEAD 10
int ir_freq_khz = 38;

// Set up the Air Conditioner feed 
AdafruitIO_Feed *acFeed = io.feed("Air Conditioner");

void setup() {

  // Start serial and connect to io.adafruit.com 
  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // Hanlder function for the "Air Conditioner" feed from Adafruit IO. 
  acFeed->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  acFeed->get();

}

void loop() {

  // Run IO in loop with timeout 
  io.run(10,true);

}

// Message handler routine whenever ac_feed is updated 
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  sendIr();
  Serial.println("sent.");
}

//
//void sendIr()
//{
//  // arcfn.com
//    Serial.println("sending");
//    int khz = 38; // 38kHz carrier frequency for the NEC protocol
//    unsigned int irSignal[] = {9012, 4480, 600, 548, 576, 544, 576, 544, 576, 1648, 592, 556, 568, 552, 568, 552, 568, 552, 568, 1656, 596, 552, 568, 1652, 600, 548, 576, 1648, 592, 1656, 596, 1652, 600, 1648, 596, 1652, 600, 548, 572, 548, 572, 548, 572, 1652, 600, 548, 572, 548, 576, 544, 576, 548, 572, 1648, 596, 1652, 600, 1648, 604, 544, 576, 1648, 592, 1656, 596, 1644, 600, 40924, 8988, 2260, 600};
//    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
//}


// After a frankly painful amount of debugging the above routine, that uses 
// the sendRaw function from IRLib, I brute-force
// duplicated the IRLib functions below and am calling marks/spaces one-by-one. 
// For some reason a for loop crashes the whole thing, I suspect a timer conflict
// with Adafruit IO and/or the ESP32 WiFi module? This ain't pretty, but it works. 
// FIXME: Get rid of this whole mess 
void sendIr()
{
  // Recorded using read_ir_remote.io 
  uint16_t irSignal[] = {9012, 4480, 600, 548, 576, 544, 576, 544, 576, 1648, 592, 556, 568, 552, 568, 552, 568, 552, 568, 1656, 596, 552, 568, 1652, 600, 548, 576, 1648, 592, 1656, 596, 1652, 600, 1648, 596, 1652, 600, 548, 572, 548, 572, 548, 572, 1652, 600, 548, 572, 548, 576, 544, 576, 548, 572, 1648, 596, 1652, 600, 1648, 604, 544, 576, 1648, 592, 1656, 596, 1644, 600, 40924, 8988, 2260, 600};

  // Set IR pin as output 
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

      mark(irSignal[0]); 
      space(irSignal[1]); 
      mark(irSignal[2]); 
      space(irSignal[3]); 
      mark(irSignal[4]); 
      space(irSignal[5]); 
      mark(irSignal[6]); 
      space(irSignal[7]); 
      mark(irSignal[8]); 
      space(irSignal[9]); 
      mark(irSignal[10]); 
      space(irSignal[11]); 
      mark(irSignal[12]); 
      space(irSignal[13]); 
      mark(irSignal[14]); 
      space(irSignal[15]); 
      mark(irSignal[16]); 
      space(irSignal[17]); 
      mark(irSignal[18]); 
      space(irSignal[19]); 
      mark(irSignal[20]); 
      space(irSignal[21]); 
      mark(irSignal[22]); 
      space(irSignal[23]); 
      mark(irSignal[24]); 
      space(irSignal[25]); 
      mark(irSignal[26]); 
      space(irSignal[27]); 
      mark(irSignal[28]); 
      space(irSignal[29]); 
      mark(irSignal[30]); 
      space(irSignal[31]); 
      mark(irSignal[32]); 
      space(irSignal[33]); 
      mark(irSignal[34]); 
      space(irSignal[35]); 
      mark(irSignal[36]); 
      space(irSignal[37]); 
      mark(irSignal[38]); 
      space(irSignal[39]); 
      mark(irSignal[40]);
      space(irSignal[41]); 
      mark(irSignal[42]); 
      space(irSignal[43]); 
      mark(irSignal[44]); 
      space(irSignal[45]); 
      mark(irSignal[46]); 
      space(irSignal[47]); 
      mark(irSignal[48]); 
      space(irSignal[49]); 
      mark(irSignal[50]); 
      space(irSignal[51]); 
      mark(irSignal[52]); 
      space(irSignal[53]); 
      mark(irSignal[54]); 
      space(irSignal[55]); 
      mark(irSignal[56]); 
      space(irSignal[57]); 
      mark(irSignal[58]); 
      space(irSignal[59]); 
      mark(irSignal[60]); 
      space(irSignal[61]); 
      mark(irSignal[62]); 
      space(irSignal[63]); 
      mark(irSignal[64]); 
      space(irSignal[65]); 
      mark(irSignal[66]); 
      space(irSignal[67]); 
      mark(irSignal[68]); 
      space(irSignal[69]); 
      mark(irSignal[70]); 
      space(0);
}

// These come directly from IRLib (https://github.com/cyborg5/IRLib2)
void space(uint16_t time)
{
  IRLibDelayUSecs(time);
}

void mark(uint16_t time)
{
  float Length=1000.0/(float)ir_freq_khz;
  int iLength=int(Length+0.5); 
  int onTime=int(Length/3.0);
  int offTime=iLength-onTime-IR_BIT_BANG_OVERHEAD-(ir_freq_khz<40);
  unsigned int jmax=time/iLength;
  for(unsigned int j=0;j<jmax;j++) 
  {
      digitalWrite(3, HIGH);  delayMicroseconds(onTime);
      digitalWrite(3, LOW);   delayMicroseconds(offTime);
  }
}


void  IRLibDelayUSecs(uint16_t time) {
  if(time){if(time>16000) {delayMicroseconds(time % 1000); delay(time/1000); } else delayMicroseconds(time);};
}
