#include <avr/io.h>
#include <util/delay.h>

// ARUDINO PIN used 2 to 8
// ATMEGE328p PIN used from PD2 TO PD7 and B0

// Define port addresses for direct port manipulation
#define SEG_A_MASK (1 << PD2)
#define SEG_B_MASK (1 << PD3)
#define SEG_C_MASK (1 << PD4)
#define SEG_D_MASK (1 << PD5)
#define SEG_E_MASK (1 << PD6)
#define SEG_F_MASK (1 << PD7)
#define SEG_G_MASK (1 << PB0) // B0

// Array to store the segment masks for each segment pin
uint8_t segmentMasks[] = {SEG_A_MASK, SEG_B_MASK, SEG_C_MASK, SEG_D_MASK, SEG_E_MASK, SEG_F_MASK, SEG_G_MASK};

// Segment patterns for digits 0-9 (common anode)
const uint8_t digitPatterns[][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 1, 0, 0}  // 9
};

void setup_pins()
{
  // Set segment pins as output using DDRD and DDRB
  DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);
  DDRB |= (1 << PB0);
}

void displayDigit(uint8_t digit)
{
  // Check if the digit is within valid range (0-9)
  if (digit >= 0 && digit <= 9)
  {
    // Loop through each segment mask and set its state
    for (int i = 0; i < 7; i++)
    {
      if (digitPatterns[digit][i])
      {
        // Segment is active (HIGH)
        if (i < 6)
        {
          PORTD |= segmentMasks[i]; // Set segment A to F
        }
        else
        {
          PORTB |= segmentMasks[i]; // Set segment G (on PB0)
        }
      }
      else
      {
        // Segment is inactive (LOW)
        if (i < 6)
        {
          PORTD &= ~segmentMasks[i]; // Clear segment A to F
        }
        else
        {
          PORTB &= ~segmentMasks[i]; // Clear segment G (on PB0)
        }
      }
    }
  }
}

int main()
{
  // Initialize ports and pins
  setup_pins();

  // Main loop
  while (1)
  {
    // Display digits 0-9 sequentially with a delay between each
    for (int digit = 0; digit <= 9; digit++)
    {
      displayDigit(digit);
      _delay_ms(1000); // Delay for 1 second using _delay_ms function
    }
  }

  return 0;
}
