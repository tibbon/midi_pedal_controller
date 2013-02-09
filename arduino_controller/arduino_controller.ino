#include <LiquidCrystal.h>
#include <MIDI.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char* presetNames[] = {"Test", 
                       "Foo", 
                       "Bar"};
const int upButtonPin = 8;
const int downButtonPin = 9;
const int actButtonPin = 10;
int upButtonState = 0; 
int downButtonState = 0;
int actButtonState = 0;
                       
// Midi channel 4
int spacePresets[] = {1, 2, 3, 4};

// Midi channel 3
int timelinePresets[] = {4, 3, 2, 1};

// Midi channel 2
int mobiusPresets[] = {8, 8, 9, 1};

// Midi channel 1
int pitchfactorPresets[] = {1, 10, 20, 30};

int currentPreset = 0;
const int maxPreset = 3;

void setup()
{
  MIDI.begin(4);
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Hello, David!");
}

void loop()
{ 
  // On buttonup
  // I could trigger these with interrupts, or just with button presses. 
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    incrementPreset();
    scrollDisplay();
  } 
  
  
  // On buttonDown
  //decrementPreset();
  
  // On Activate button
  //activatePreset();
}

void incrementPreset()
{
  currentPreset++;
//  if (currentPreset < (maxPreset)) {
//    currentPreset++;
//  }
//  else
//  {
//    currentPreset = 0;
//  }
}

void decrementPreset()
{
  if (currentPreset > 0) {
    currentPreset--;
  }
  else
  {
    currentPreset = 128;
  }
}

void scrollDisplay(){
  lcd.setCursor(0, 1);
  //lcd.print(presetNames[currentPreset]);
  lcd.print(currentPreset);
}

void activatePreset(){
  // Might update the screen too saying its done
  sendMidiControlChanges();
}

void sendMidiControlChanges()
{
  //MIDI.sendProgramChange(pitchfactorPresets[currentPreset],1);
  //MIDI.sendProgramChange(mobiusPresets[currentPreset],2);
  //MIDI.sendProgramChange(timelinePresets[currentPreset],3);
  //MIDI.sendProgramChange(spacePresets[currentPreset],4);
  lcd.setCursor(0, 1);
  lcd.print(presetNames[currentPreset]);
}
