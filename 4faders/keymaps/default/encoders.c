extern MidiDevice midi_device;

#include "timer.h"

#define BASE_CC_VALUE 64
#define MAX_DEVIATION 8  // Maximum deviation from 64
#define MIN_INTERVAL 10   // Minimum interval for maximum speed (in ms)
#define MAX_INTERVAL 100  // Maximum interval for minimum speed (in ms)

// static uint16_t last_rotation_time = 0;  // Timestamp of the last rotation

bool encoder_update_user(uint8_t index, bool CW) {
  // uint16_t current_time = timer_read();  // Get the current time
  // uint16_t interval = current_time - last_rotation_time;  // Calculate the interval
  // last_rotation_time = current_time;  // Update the last rotation time
  //
  // // Calculate deviation based on interval
  // int deviation;
  // if (interval < MIN_INTERVAL) {
  //   deviation = MAX_DEVIATION;
  // } else if (interval > MAX_INTERVAL) {
  //   deviation = 1;
  // } else {
  //   deviation = MAX_DEVIATION - ((interval - MIN_INTERVAL) * (MAX_DEVIATION - 1)) / (MAX_INTERVAL - MIN_INTERVAL);
  // }

  // uint8_t cc_value = BASE_CC_VALUE;
  switch (index) {
    // case 0:
    //   deviation = KNOB1_pressed ? 4 : 1;
    //   if (CW) {
    //     cc_value += deviation;
    //   } else {
    //     cc_value -= deviation;
    //   }
    //   midi_send_cc(&midi_device, 0, 1 + index, cc_value);
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      midi_send_cc(&midi_device, 0, 1 + index, CW ? 65 : 63);
      break;
    default:
      break;
  }


  return false;  // Always return false
}
