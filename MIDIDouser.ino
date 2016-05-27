#include <MIDI.h>

#define D1EN 3
#define D1OUT1 4
#define D1OUT2 2

#define D1OPEN 10
#define D1CLOSE 11

#define D2EN 9
#define D2OUT1 7
#define D2OUT2 8

#define D2OPEN 20
#define D2CLOSE 21

#define D3EN 10
#define D3OUT1 5
#define D3OUT2 12

#define D3OPEN 30
#define D3CLOSE 31

#define LED 13

boolean D1Status = false; //Is douser 1 moving?

MIDI_CREATE_DEFAULT_INSTANCE();

void BlinkLed(byte num)         // Basic blink function
{
    for (byte i=0;i<num;i++)
    {
        digitalWrite(LED,HIGH);
        delay(50);
        digitalWrite(LED,LOW);
        delay(50);
    }
}

void handleNoteOn(byte channel, byte note, byte velocity)
{   //BlinkLed(1);
    int n = note;
    int v = velocity;
    switch(note)
    {
        case D1OPEN:
        digitalWrite(D1OUT1, HIGH);
        digitalWrite(D1OUT2, LOW);
        analogWrite(D1EN,v*2);
        break;
        
        case D1CLOSE:
        digitalWrite(D1OUT2, HIGH);
        digitalWrite(D1OUT1, LOW);
        analogWrite(D1EN,v*2);
        break;
        
        case D2OPEN:
        digitalWrite(D2OUT1, HIGH);
        digitalWrite(D2OUT2, LOW);
        analogWrite(D2EN,v*2);
        break;
        
        case D2CLOSE:
        digitalWrite(D2OUT2, HIGH);
        digitalWrite(D2OUT1, LOW);
        analogWrite(D2EN,v*2);
        break;
        
        case D3OPEN:
        digitalWrite(D3OUT1, HIGH);
        digitalWrite(D3OUT2, LOW);
        analogWrite(D3EN,v*2);
        break;
     
        case D3CLOSE:
        digitalWrite(D3OUT2, HIGH);
        digitalWrite(D3OUT1, LOW);
        analogWrite(D3EN,v*2);
        break;
        
        default:
        break;
    }
}

void handleNoteOff(byte channel, byte note, byte velocity)
{   //BlinkLed(1);
    int n = note;
    int v = velocity;
    switch(note)
    {
        case D1OPEN:
        digitalWrite(D1EN, LOW);
        break;
        case D1CLOSE:
        digitalWrite(D1EN, LOW);
        break;
        
        case D2OPEN:
        digitalWrite(D2EN, LOW);
        break;
        case D2CLOSE:
        digitalWrite(D2EN, LOW);
        break;
        
        case D3OPEN:
        digitalWrite(D3EN, LOW);
        break;
        case D3CLOSE:
        digitalWrite(D3EN, LOW);
        break;
        default:
        break;
    }
}


void setup() {
  pinMode(LED, OUTPUT);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.begin(8);           // Launch MIDI, on channel 8
  Serial.begin(115200);
  MIDI.turnThruOff();
 
  pinMode(D1OUT1, OUTPUT);
  pinMode(D1OUT2, OUTPUT);
  pinMode(D1EN, OUTPUT);
  
  digitalWrite(D1EN, LOW);
  digitalWrite(D1OUT1, LOW);
  digitalWrite(D1OUT2, LOW);
  
  pinMode(D2OUT1, OUTPUT);
  pinMode(D2OUT2, OUTPUT);
  pinMode(D2EN, OUTPUT);
  
  digitalWrite(D2EN, LOW);
  digitalWrite(D2OUT1, LOW);
  digitalWrite(D2OUT2, LOW);
  
  pinMode(D3OUT1, OUTPUT);
  pinMode(D3OUT2, OUTPUT);
  pinMode(D3EN, OUTPUT);
  
  digitalWrite(D3EN, LOW);
  digitalWrite(D3OUT1, LOW);
  digitalWrite(D3OUT2, LOW);
  
}
 
void loop() {
       MIDI.read();
 }
  

