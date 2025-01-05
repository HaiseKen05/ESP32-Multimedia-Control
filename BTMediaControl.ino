#include <BleKeyboard.h>

// Create a BLE Keyboard object
BleKeyboard bleKeyboard;

// Define GPIO pins for buttons
#define MUTE_BUTTON_PIN 15
#define PREV_TRACK_BUTTON_PIN 4
#define NEXT_TRACK_BUTTON_PIN 5
#define PAUSE_PLAY_BUTTON_PIN 18
#define VOLUME_UP_BUTTON_PIN 19
#define VOLUME_DOWN_BUTTON_PIN 21

void setup() {
  // Configure button pins with internal pull-up resistors
  pinMode(MUTE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PREV_TRACK_BUTTON_PIN, INPUT_PULLUP);
  pinMode(NEXT_TRACK_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PAUSE_PLAY_BUTTON_PIN, INPUT_PULLUP);
  pinMode(VOLUME_UP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(VOLUME_DOWN_BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(115200);

  // Initialize BLE Keyboard
  Serial.println("Starting BLE Keyboard...");
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) { // Check if Bluetooth is connected

    // Check if Mute button is pressed
    if (digitalRead(MUTE_BUTTON_PIN) == LOW) {
      Serial.println("Mute button pressed!");
      bleKeyboard.write(KEY_MEDIA_MUTE);
      delay(300); // Debounce
    }

    // Check if Previous Track button is pressed
    if (digitalRead(PREV_TRACK_BUTTON_PIN) == LOW) {
      Serial.println("Previous Track button pressed!");
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      delay(300); // Debounce
    }

    // Check if Next Track button is pressed
    if (digitalRead(NEXT_TRACK_BUTTON_PIN) == LOW) {
      Serial.println("Next Track button pressed!");
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      delay(300); // Debounce
    }

    // Check if Pause/Play button is pressed
    if (digitalRead(PAUSE_PLAY_BUTTON_PIN) == LOW) {
      Serial.println("Pause/Play button pressed!");
      bleKeyboard.write(' '); // Spacebar key for YouTube compatibility
      delay(300); // Debounce
    }

    // Check if Volume Up button is pressed
    if (digitalRead(VOLUME_UP_BUTTON_PIN) == LOW) {
      Serial.println("Volume Up button pressed!");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      delay(300); // Debounce
    }

    // Check if Volume Down button is pressed
    if (digitalRead(VOLUME_DOWN_BUTTON_PIN) == LOW) {
      Serial.println("Volume Down button pressed!");
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      delay(300); // Debounce
    }
  }

  delay(10); // Small delay for stability
}
