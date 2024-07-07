# AVR C Code for Common Anode 7-Segment Display

This repository contains AVR C code to drive a common anode 7-segment display using direct port manipulation. It sequentially displays digits 0-9 with a 1-second delay between each digit.

## Hardware Requirements

- AVR microcontroller (e.g., ATmega328P)
- Common anode 7-segment display
- Breadboard and jumper wires


## Circuit Diagram

Include a simple diagram or schematic of how the 7-segment display is connected to the AVR microcontroller.

## Installation and Setup

1. **Clone the Repository:**

## Proteus Simulation

You can simulate the circuit in Proteus to verify functionality before hardware implementation:

1. **Open Proteus:** Open simulation folder, then open file 

2. **Import Circuit:** Double click on controller and add path of hex file

3. **Simulate:** Run the simulation to observe the 7-segment display operation.

2. **Open Project:**
Open the project in your preferred AVR C development environment (e.g., Atmel Studio, AVR-GCC).

3. **Compile and Upload:**
Compile the `main.c` file and upload the generated `.hex` file to your AVR microcontroller using AVR programmer tools.

## Usage

1. **Configure Pins:**
Adjust `SEG_A_MASK`, `SEG_B_MASK`, ..., `SEG_G_MASK` in `main.c` to match your specific wiring configuration.

2. **Compile and Upload:**
Compile the code and upload it to your AVR microcontroller.

3. **Run Program:**
Upon successful upload, the program will display digits 0-9 sequentially on the 7-segment display.

## Notes

- Ensure correct wiring and pin configurations for your specific 7-segment display.
- Modify `digitPatterns` in `main.c` if your display has a different pinout or segment mapping.