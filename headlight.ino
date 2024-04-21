#include <LedControl.h>

// Pin connections for MAX7219
const int MAX7219_DATA_PIN = 12;  // Data IN Pin
const int MAX7219_CLK_PIN = 11;   // Clock Pin
const int MAX7219_CS_PIN = 10;    // Chip Select Pin

// Number of MAX7219 ICs (four 8x8 LED modules)
const int NUM_MAX7219 = 4;

// Create an instance of the LedControl library
LedControl lc = LedControl(MAX7219_DATA_PIN, MAX7219_CLK_PIN, MAX7219_CS_PIN, NUM_MAX7219);

void setup() {
  Serial.begin(9600);  //Start serial connection
  // Initialize the MAX7219

  lc.shutdown(0, false);  // Wake up MAX7219 (0 = first IC)
  lc.shutdown(1, false);  // Wake up MAX7219 (1 = second IC)
  lc.shutdown(2, false);  // Wake up MAX7219 (2 = third IC)
  lc.shutdown(3, false);  // Wake up MAX7219 (3 = fourth IC)

  lc.setIntensity(0, 15);  // Set the brightness (0-15)
  lc.setIntensity(1, 15);  // Set the brightness (0-15)
  lc.setIntensity(2, 15);  // Set the brightness (0-15)
  lc.setIntensity(3, 15);  // Set the brightness (0-15)

  lc.clearDisplay(0);  // Clear the display (0 = first IC)
  lc.clearDisplay(1);  // Clear the display (1 = second IC)
  lc.clearDisplay(2);  // Clear the display (2 = third IC)
  lc.clearDisplay(3);  // Clear the display (3 = fourth IC)
}

void turnOnAllModules() {
  // Turn on all LEDs in the four LED modules
  for (int module = 0; module < NUM_MAX7219; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
    }
  }
}

void pattern2() {
  // Turn on all LEDs in the first LED module
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, HIGH);
    }
  }
}

void turnOffModule1() {
  // Turn off in module 1 and on all LEDs in the other three LED modules
  for (int module = 1; module < NUM_MAX7219; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
      lc.setRow(0, row, B00000000);
    }
  }
  lc.setRow(0, 0, B11111111);
}

void turnOffModule2() {
  // Turn off in module 2 and on all LEDs in the other three LED modules
  for (int module = 2; module < NUM_MAX7219; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
      lc.setRow(1, row, B00000000);
    }
  }
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, B11111111);
  }
  lc.setRow(1, 0, B11111111);
}

void turnOffModule3() {
  // Turn off in module 3 and on all LEDs in the other three LED modules
  for (int module = 0; module < NUM_MAX7219 - 2; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
      lc.setRow(2, row, B00000000);
    }
  }
  for (int row = 0; row < 8; row++) {
    lc.setRow(3, row, B11111111);
  }
  lc.setRow(2, 0, B11111111);
}

void turnOffModule4() {
  // Turn off in module 4 and on all LEDs in the other three LED modules
  for (int module = 0; module < NUM_MAX7219 - 1; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
      lc.setRow(3, row, B00000000);
    }
  }
  lc.setRow(3, 0, B11111111);
}

void turnOffModule1and2() {
  // Turn off in module 1 and 2 and on in 3 and 4
  for (int module = 2; module < NUM_MAX7219; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
      lc.setRow(0, row, B00000000);
      lc.setRow(1, row, B00000000);
    }
  }
  lc.setRow(0, 0, B11111111);
  lc.setRow(1, 0, B11111111);
}

void turnOffModule3and4() {
  // Turn off in module 3 and 4 and on in 1 and 2
  for (int module = 0; module < NUM_MAX7219 - 2; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B11111111);
      lc.setRow(2, row, B00000000);
      lc.setRow(3, row, B00000000);
    }
  }
  lc.setRow(2, 0, B11111111);
  lc.setRow(3, 0, B11111111);
}

void turnOffModule1and4() {
  // Turn off in module 1 and 4 and on in 2 and 3
  for (int row = 0; row < 8; row++) {
    lc.setRow(1, row, B11111111);
    lc.setRow(2, row, B11111111);
    lc.setRow(0, row, B00000000);
    lc.setRow(3, row, B00000000);
  }
  lc.setRow(0, 0, B11111111);
  lc.setRow(3, 0, B11111111);
}

void turnOffModule2and3() {
  // Turn off in module 1 and 4 and on in 2 and 3
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, B11111111);
    lc.setRow(3, row, B11111111);
    lc.setRow(1, row, B00000000);
    lc.setRow(2, row, B00000000);
  }
  lc.setRow(1, 0, B11111111);
  lc.setRow(2, 0, B11111111);
}

void turnOffModule1and2and3() {
  // Turn off in module 1 and 2 and 3
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, B00000000);
    lc.setRow(1, row, B00000000);
    lc.setRow(2, row, B00000000);
    lc.setRow(3, row, B11111111);
  }
  lc.setRow(0, 0, B11111111);
  lc.setRow(1, 0, B11111111);
  lc.setRow(2, 0, B11111111);
}

void turnOffModule1and3and4() {
  // Turn off in module 1 and 3 and 4
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, B00000000);
    lc.setRow(3, row, B00000000);
    lc.setRow(2, row, B00000000);
    lc.setRow(1, row, B11111111);
  }
  lc.setRow(0, 0, B11111111);
  lc.setRow(3, 0, B11111111);
  lc.setRow(2, 0, B11111111);
}

void turnOffModule1and2and4() {
  // Turn off in module 1 and 2 and 4
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, B00000000);
    lc.setRow(1, row, B00000000);
    lc.setRow(3, row, B00000000);
    lc.setRow(2, row, B11111111);
  }
  lc.setRow(0, 0, B11111111);
  lc.setRow(3, 0, B11111111);
  lc.setRow(1, 0, B11111111);
}

void turnOffModule2and3and4() {
  // Turn off in module 1 and 4 and on in 2 and 3
  for (int row = 0; row < 8; row++) {
    lc.setRow(1, row, B00000000);
    lc.setRow(2, row, B00000000);
    lc.setRow(3, row, B00000000);
    lc.setRow(0, row, B11111111);
  }
  lc.setRow(1, 0, B11111111);
  lc.setRow(2, 0, B11111111);
  lc.setRow(3, 0, B11111111);
}

// To be rechecked
void turnOffAllRowsExceptBottom2() {
  // Turn off all columns in the LED matrix
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, B00000000);
    lc.setRow(1, row, B00000000);
    lc.setRow(2, row, B00000000);
    lc.setRow(3, row, B00000000);
  }
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setRow(module, 0, B11111111);
    lc.setRow(module, 1, B11111111);
  }
}

void turnOff() {
  for (int module = 0; module < NUM_MAX7219; module++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(module, row, B00000000);
    }
  }
}


void pattern9() {
  // Turn off the first and last columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 0, B00000000);  // Turn off the first column
    lc.setColumn(module, 7, B00000000);  // Turn off the last column
    lc.setRow(module, 6, B11111111);
    lc.setRow(module, 7, B11111111);
  }
  turnOnOtherColumns9();
}

void turnOnOtherColumns9() {
  // Turn on the other two columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 1, B11111111);  // Turn on the second column
    lc.setColumn(module, 6, B11111111);  // Turn on the second to last column
  }
}

void pattern10() {
  // Turn off the second and third columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 1, B00000000);  // Turn off the second column
    lc.setColumn(module, 2, B00000000);  // Turn off the third column
    lc.setRow(module, 6, B11111111);
    lc.setRow(module, 7, B11111111);
  }
  turnOnOtherColumns10();
}

void turnOnOtherColumns10() {
  // Turn on the other two columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 0, B11111111);  // Turn on the first column
    lc.setColumn(module, 3, B11111111);  // Turn on the fourth column
  }
}

void pattern11() {
  // Turn on the second and fourth columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 1, B11111111);  // Turn on the second column
    lc.setColumn(module, 3, B11111111);  // Turn on the fourth column
  }
  turnOffOtherColumns11();
}

void turnOffOtherColumns11() {
  // Turn off all the other columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 0, B00000000);  // Turn off the first column
    lc.setColumn(module, 2, B00000000);  // Turn off the third column
    lc.setRow(module, 6, B11111111);
    lc.setRow(module, 7, B11111111);
  }
}

void pattern12() {
  // Turn on the first and third columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 0, B11111111);  // Turn on the first column
    lc.setColumn(module, 2, B11111111);  // Turn on the third column
  }
  turnOffOtherColumns12();
}

void turnOffOtherColumns12() {
  // Turn off all the other columns in the LED matrix
  for (int module = 0; module < NUM_MAX7219; module++) {
    lc.setColumn(module, 1, B00000000);  // Turn off the second column
    lc.setColumn(module, 3, B00000000);  // Turn off the fourth column
    lc.setRow(module, 6, B11111111);
    lc.setRow(module, 7, B11111111);
  }
}

char ch[3] = "";
int sensorValue = 0;  // value read from the LDR
int outputValue = 0;  // value output to the LDR (analog out)

void loop() {
  // turnOff();
  // turnOnAllModules();
  // delay(1000);
  // turnOffModule1();
  // delay(1000);
  // turnOffModule2();
  // delay(1000);
  // turnOffModule3();
  // delay(1000);
  // turnOffModule4();
  // delay(1000);
  // turnOffModule1and2();
  // delay(1000);
  // turnOffModule3and4();
  // delay(1000);
  // turnOffModule1and4();
  // delay(1000);
  // turnOffAllRowsExceptBottom2();
  // delay(1000);

  sensorValue = analogRead(A0);
  sensorValue = 1023 - sensorValue;
  if (sensorValue < 550) {
    if (Serial.available() > 0) {
    
      ch[0] = Serial.read();  //Start reading characters from the received data

      ////START - If checks for single vehicle detected
      if (ch[0] == '1')
        turnOnAllModules();

      if (ch[0] == 'a')
        turnOffModule4();

      // if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '2')
      //   turnOffModule3();

      // if (ch[0] == 'x' && ch[1] == 'y' && ch[2] == '3')
      //   turnOffModule2();

      if (ch[0] == 'd')
        turnOffModule1();

      if (ch[0] == 'e')
        turnOffModule3and4();

      if (ch[0] == 'f')
        turnOffModule1and2();

      if (ch[0] == 'g')
        turnOffModule1and2and3();

      if (ch[0] == 'h')
        turnOffModule2and3and4();

      if (ch[0] == '0')
        turnOffAllRowsExceptBottom2();
      ////END - If checks for single vehicle detected

      ////START - If checks for double vehicle detected

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '1')
      //   turnOffModule4();

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '2')
      //   turnOffModule3and4();

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '3')
      //   turnOffModule1and2();

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '4')
      //   turnOffModule1();

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '5')
      //   turnOffModule2and3and4();

      if (ch[0] == 'b')
        turnOffModule1and2and4();

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '7')
      //   turnOffModule1and2and3();

      if (ch[0] == 'c')
        turnOffModule1and3and4();

      // if (ch[0] == 'x' && ch[1] == 'z' && ch[2] == '9')
      //   turnOffAllRowsExceptBottom2();

      ////END - If checks for double vehicle detected

      if (ch[0] == 'z')
        turnOff();


      //To make sure what is being received from the serial port
      //Wirte on the serial to double check the characters on the Pyhton side
      Serial.print(ch[0]);
      //Flush to clear the received data
      Serial.flush();
    }
    ////END - Handle detected vehicles
  } else {
    turnOff();
  }
  // }
  ////END - Check serial connection status
}
