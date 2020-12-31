## WiFi-Controlled Air Conditioner
Controlling my Kenmore air conditioner using Alexa, Arduino, and Adafruit IO. See [example video](https://www.youtube.com/watch?v=YW_7fpdhlW8) and [blog post](https://adamgannon.com/2020/12/31/air-conditioner-wifi/) for more details.

### Project Files
Main project code is located in `arduino/ac_io`. Uses Adafruit IO and the IRremote library.

A sketch from AnalysisIR, [available here](https://www.analysir.com/blog/2014/03/19/air-conditioners-problems-recording-long-infrared-remote-control-signals-arduino/), was used to clone the power on/off button sequence from the AC unit's original IR remote. That sequence is located in `data`.

A rough wiring diagram drawing is included in the top-level directory. This will eventually be replaced with schematic/board files when I spin a PCB for this.

### Arduino Error
I ended up having a very weird error when using IRremote together with the Adafruit IO library (probably the ESP32 timer library, specifically). I can't use a long for loop to send IR sequences without the connection to Adafruit IO crashing. The sketch `arduino/timer_mwe` illustrates the issue. Any suggestions are more than welcome!
