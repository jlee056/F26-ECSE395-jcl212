#include <Arduino.h>
// This is required in PlatformIO but hidden in the standard Arduino IDE.

#define LED_PIN 13

// jcl212 - Baud rate for the serial connection. Must match monitor_speed in platformio.ini.
#define BAUD_RATE 115200

// jcl212 - Timing constants for my light show, all in milliseconds.
// jcl212 - Named constants instead of magic numbers so the pattern is easy to retune.
#define HEARTBEAT_ON      90    // jcl212 - short "thump" of the heartbeat
#define HEARTBEAT_GAP     120   // jcl212 - pause between the two thumps of one beat
#define HEARTBEAT_REST    650   // jcl212 - long rest between heartbeats

#define MORSE_DOT         150   // jcl212 - length of a dot in my SOS
#define MORSE_DASH        450   // jcl212 - a dash is 3x a dot, standard Morse timing
#define MORSE_GAP         150   // jcl212 - gap between symbols inside one letter
#define MORSE_LETTER_GAP  450   // jcl212 - gap between letters

#define STROBE_START      200   // jcl212 - strobe begins slow at 200 ms
#define STROBE_MIN        20    // jcl212 - strobe speeds up until it hits 20 ms
#define STROBE_STEP       15    // jcl212 - amount the strobe speeds up each cycle

#define PATTERN_PAUSE     1000  // jcl212 - dark pause between patterns so they read clearly

// jcl212 - Helper: turn the LED on for onTime, then off for offTime.
// jcl212 - Every pattern below is built out of this one function.
void flash(int onTime, int offTime) {
  digitalWrite(LED_PIN, HIGH); // LED On
  delay(onTime);               // jcl212 - how long the LED stays lit
  digitalWrite(LED_PIN, LOW);  // LED Off
  delay(offTime);              // jcl212 - how long the LED stays dark
}

// jcl212 - Pattern 1: a double-thump heartbeat, like a pulse monitor.
void heartbeat(int beats) {
  for (int i = 0; i < beats; i++) {
    flash(HEARTBEAT_ON, HEARTBEAT_GAP);   // jcl212 - first thump
    flash(HEARTBEAT_ON, HEARTBEAT_REST);  // jcl212 - second thump, then the long rest
  }
}

// jcl212 - Pattern 2: SOS in real Morse code (dot dot dot / dash dash dash / dot dot dot).
void sos() {
  for (int i = 0; i < 3; i++) flash(MORSE_DOT, MORSE_GAP);   // jcl212 - S
  delay(MORSE_LETTER_GAP);                                   // jcl212 - gap before O
  for (int i = 0; i < 3; i++) flash(MORSE_DASH, MORSE_GAP);  // jcl212 - O
  delay(MORSE_LETTER_GAP);                                   // jcl212 - gap before S
  for (int i = 0; i < 3; i++) flash(MORSE_DOT, MORSE_GAP);   // jcl212 - S
}

// jcl212 - Pattern 3: a strobe that accelerates, then decelerates back to slow.
void rampStrobe() {
  // jcl212 - speed up: delay shrinks from STROBE_START down to STROBE_MIN
  for (int d = STROBE_START; d >= STROBE_MIN; d -= STROBE_STEP) {
    flash(d, d);
  }
  // jcl212 - slow back down: delay grows from STROBE_MIN back up to STROBE_START
  for (int d = STROBE_MIN; d <= STROBE_START; d += STROBE_STEP) {
    flash(d, d);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);  // jcl212 - Start the Serial connection at 115200 baud
  delay(500);               // jcl212 - brief wait so the serial monitor catches the first message
  Serial.println("jcl212 - ESP32 online. Booting the light show..."); // jcl212 - custom startup message
}

void loop() {
  // jcl212 - Each pattern announces itself in the Serial Monitor before it runs,
  // jcl212 - so the grader can match what they read to what the LED is doing.

  Serial.println("Lub-dub, lub-dub... this ESP32 has a pulse."); // jcl212 - custom serial message
  heartbeat(3);           // jcl212 - three heartbeats
  delay(PATTERN_PAUSE);   // jcl212 - dark pause between patterns

  Serial.println("SOS! Send help, my toilet lid is still open."); // jcl212 - custom serial message, nods to our semester project
  sos();
  delay(PATTERN_PAUSE);

  Serial.println("Warp speed engaged. Hold on to something."); // jcl212 - custom serial message
  rampStrobe();
  delay(PATTERN_PAUSE);
}
