# Arduino ADC-to-PWM LED Brightness Controller

A simple Arduino project demonstrating how an **analog input (ADC)** can be converted into a **PWM output** to control LED brightness.

The project uses a potentiometer as the analog input. The Arduino reads the potentiometer voltage using its ADC, scales the resulting value from **0–1023 to 0–255**, and uses the scaled value to control LED brightness through PWM.

## Project Overview

```text
Potentiometer
      │
      ▼
Analog Input (A0)
      │
      ▼
ADC: 0–1023
      │
      ▼
Scale to 0–255
      │
      ▼
PWM Output (Pin 9)
      │
      ▼
LED Brightness
```

## Hardware

* Arduino Uno
* Potentiometer
* LED
* 220Ω resistor
* Jumper wires

## Pin Connections

| Component            | Arduino Pin |
| -------------------- | ----------- |
| Potentiometer output | A0          |
| LED                  | D9          |
| Potentiometer VCC    | 5V          |
| Potentiometer GND    | GND         |

Pin 9 is used because it supports PWM on the Arduino Uno.

## How It Works

The Arduino Uno has a **10-bit ADC**, which converts the analog voltage into a value between:

```text
0 → 1023
```

The PWM output uses an 8-bit value:

```text
0 → 255
```

Therefore, the ADC reading is scaled using:

```cpp
int brightness = (reading * 255) / 1023;
```

The resulting value is sent to the PWM output:

```cpp
analogWrite(9, brightness);
```

For example:

| ADC Reading | PWM Value | Approx. Brightness |
| ----------: | --------: | -----------------: |
|           0 |         0 |                 0% |
|         256 |        64 |                25% |
|         512 |       127 |                50% |
|         768 |       191 |                75% |
|        1023 |       255 |               100% |

## Code

```cpp
void setup() {
    Serial.begin(9600);
    pinMode(9, OUTPUT);
}

void loop() {
    int reading = analogRead(A0);

    Serial.println(reading);

    int brightness = (reading * 255) / 1023;

    analogWrite(9, brightness);
}
```

## Key Concepts Learned

* Analog-to-Digital Conversion (ADC)
* `analogRead()`
* Serial communication and `Serial.begin()`
* PWM output
* `analogWrite()`
* ADC-to-PWM scaling
* Arduino GPIO configuration
* Mapping a sensor/input range to an output range

## Important Note

`analogWrite()` on an Arduino Uno does **not** produce a true analog voltage. It generates a **PWM signal** whose duty cycle controls the average power delivered to the LED.

For example:

```cpp
analogWrite(9, 64);
```

produces approximately a **25% PWM duty cycle**.

## Learning Objective

This project was built to understand the fundamental embedded-systems signal flow:

**Analog Input → ADC → Digital Processing → PWM Output**

This concept is commonly used in embedded systems for applications such as sensor-based control, LED dimming, motor control, and actuator control.

## Platform

* **Board:** Arduino Uno
* **Development Environment:** Arduino IDE / Wokwi
* **Language:** C/C++
* **Programming Style:** Arduino API
