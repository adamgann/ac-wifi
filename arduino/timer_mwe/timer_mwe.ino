/* This example illustrates the problem I'm having with IRLib and Adafruit IO. 
 * See sendStuff() for explaination. 
 * 
  */

#include "config.h"

// Set up the Air Conditioner feed 
AdafruitIO_Feed *acFeed = io.feed("Air Conditioner");

void setup() {


  // start the serial connection
  Serial.begin(115200);
  while(! Serial);


  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'ac_feed' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  acFeed->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  acFeed->get();

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run(10,true);

}

// Message handler routine whenever ac_feed is updated 
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->toPinLevel());
  sendStuff();
  // When sendStuff() hangs, this statement is never printed, the 
  // handler function is never run again 
  Serial.println("sent.");
}


void sendStuff()
{
  uint16_t irSignal[] = {9012, 4480, 600, 548, 576, 544, 576, 544, 576, 1648, 592, 556, 568, 552, 568, 552, 568, 552, 568, 1656, 596, 552, 568, 1652, 600, 548, 576, 1648, 592, 1656, 596, 1652, 600, 1648, 596, 1652, 600, 548, 572, 548, 572, 548, 572, 1652, 600, 548, 572, 548, 576, 544, 576, 548, 572, 1648, 596, 1652, 600, 1648, 604, 544, 576, 1648, 592, 1656, 596, 1644, 600, 40924, 8988, 2260, 600};
  
//  This does NOT work
    for (int ii=0; ii<4; ii++)
    {
      space(irSignal[ii]); 
    }


//    This DOES WORK
//      space(irSignal[0]); 
//      space(irSignal[1]); 
//      space(irSignal[2]); 
//      space(irSignal[3]); 
      
  
}

void space(uint16_t time)
{
  delayMicroseconds(time);
}
