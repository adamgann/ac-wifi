/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 */


#include <IRremote.h>
IRsend irsend;

void setup()
{
  Serial.begin(115200);
}

void loop() {
  if (Serial.read() != -1) {
    Serial.println("sending");
    int khz = 38; // 38kHz carrier frequency for the NEC protocol
    unsigned int irSignal[] = {9012, 4480, 600, 548, 576, 544, 576, 544, 576, 1648, 592, 556, 568, 552, 568, 552, 568, 552, 568, 1656, 596, 552, 568, 1652, 600, 548, 576, 1648, 592, 1656, 596, 1652, 600, 1648, 596, 1652, 600, 548, 572, 548, 572, 548, 572, 1652, 600, 548, 572, 548, 576, 544, 576, 548, 572, 1648, 596, 1652, 600, 1648, 604, 544, 576, 1648, 592, 1656, 596, 1644, 600, 40924, 8988, 2260, 600};
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
    delay(1000);
  }


}
