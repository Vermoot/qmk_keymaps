extern MidiDevice midi_device;
#include "timer.h"

uint16_t last_A = 0;
uint16_t last_B = 0;
uint16_t last_C = 0;
uint16_t last_D = 0;

#define WINDOW_SIZE 8
uint16_t moving_average_filter(uint16_t new_value, uint16_t *buffer, uint8_t *index, uint32_t *sum) {
  *sum -= buffer[*index];
  buffer[*index] = new_value;
  *sum += new_value;
  *index = (*index + 1) % WINDOW_SIZE;
  return *sum / WINDOW_SIZE;
}
void matrix_scan_user(void) {
  static uint16_t buffer_A[WINDOW_SIZE] = {0};
  static uint16_t buffer_B[WINDOW_SIZE] = {0};
  static uint16_t buffer_C[WINDOW_SIZE] = {0};
  static uint16_t buffer_D[WINDOW_SIZE] = {0};

  static uint8_t index_A = 0;
  static uint8_t index_B = 0;
  static uint8_t index_C = 0;
  static uint8_t index_D = 0;

  static uint32_t sum_A = 0;
  static uint32_t sum_B = 0;
  static uint32_t sum_C = 0;
  static uint32_t sum_D = 0;

  uint16_t current_readA = analogReadPin(GP26);
  uint16_t current_readB = analogReadPin(GP27);
  uint16_t current_readC = analogReadPin(GP28);
  uint16_t current_readD = analogReadPin(GP29);

  uint16_t filtered_A = moving_average_filter(current_readA, buffer_A, &index_A, &sum_A);
  uint16_t filtered_B = moving_average_filter(current_readB, buffer_B, &index_B, &sum_B);
  uint16_t filtered_C = moving_average_filter(current_readC, buffer_C, &index_C, &sum_C);
  uint16_t filtered_D = moving_average_filter(current_readD, buffer_D, &index_D, &sum_D);

  // static uint32_t last_timer = 0;
  // static uint32_t interval = 100;
  // if (timer_elapsed32(last_timer) > interval) {
  //   last_timer = timer_read32();
  //   printf("%u %u %u %u\n", filtered_A/32, filtered_B/32, filtered_C/32, filtered_D/32);
  // }
  filtered_B = filtered_B;
  filtered_C = filtered_C;
  filtered_D = filtered_D;

  if (abs(filtered_A/32 - last_A) >= 2) {
    midi_send_cc(&midi_device, 0, 0, filtered_A/32);
    last_A = filtered_A/32;
    printf("%u\n", filtered_A/32);
  }

}
