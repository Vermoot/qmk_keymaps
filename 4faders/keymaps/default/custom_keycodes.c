extern MidiDevice midi_device;

enum custom_keycodes {
  KNOB1 = SAFE_RANGE,
  KNOB2,
  KNOB3,
  KNOB4,
  KNOB5,
  KNOB6,
  KNOB7,
  KNOB8,
  KEY1,
  KEY2,
  KEY3,
  KEY4,
  KEY5,
  KEY6,
  KEY7,
  KEY8
};

#define CYCLE 0x2E
#define STOP 0x2A
#define PLAY 0x29
#define REC 0x2D
#define REW 0x2B
#define FF 0x2C
#define FADER1 0x00
#define FADER4 0x03


bool KNOB1_pressed = false;
bool KNOB2_pressed = false;
bool KNOB3_pressed = false;
bool KNOB4_pressed = false;
bool KNOB5_pressed = false;
bool KNOB6_pressed = false;
bool KNOB7_pressed = false;
bool KNOB8_pressed = false;

void midi_send_note(MidiDevice *device, uint8_t channel, uint8_t note, uint8_t velocity) {
  midi_send_noteon(device, channel, note, velocity);
  midi_send_noteoff(device, channel, note, velocity);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  const bool pressed = record->event.pressed;
  switch (keycode) {

    case KNOB1:
      if (pressed) { KNOB1_pressed = true; } else { KNOB1_pressed = false; }                      
      return false;
    case KNOB2:
      if (pressed) { KNOB1_pressed = true; } else { KNOB2_pressed = false; }                      
      return false;
    case KNOB3:
      if (pressed) { KNOB1_pressed = true; } else { KNOB3_pressed = false; }                      
      return false;
    case KNOB4:
      if (pressed) { KNOB1_pressed = true; } else { KNOB4_pressed = false; }                      
      return false;
    case KNOB5:
      if (pressed) { KNOB1_pressed = true; } else { KNOB5_pressed = false; }                      
      return false;
    case KNOB6:
      if (pressed) { KNOB1_pressed = true; } else { KNOB6_pressed = false; }                      
      return false;
    case KNOB7:
      if (pressed) { KNOB1_pressed = true; } else { KNOB7_pressed = false; }                      
      return false;
    case KNOB8:
      if (pressed) { KNOB1_pressed = true; } else { KNOB8_pressed = false; }                      
      return false;
    case KEY5:
      if (pressed) { midi_send_noteon(&midi_device, 0, CYCLE, 127); }
      return false;
    case KEY6:
      if (pressed) { midi_send_noteon(&midi_device, 0, STOP, 127); }
      return false;
    case KEY7:
      if (pressed) { midi_send_noteon(&midi_device, 0, PLAY, 127); }
      return false;
    case KEY8:
      if (pressed) { midi_send_noteon(&midi_device, 0, REC, 127); }
      return false;

    default:
      return true;
  }

}
