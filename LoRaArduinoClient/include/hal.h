/*
 * Header for the Hardware Abstraction Layer (HAL)
 * CTIC - LoRa Test
 * Components ports
 */

#ifndef HAL_H 
#define HAL_H

/* - - Includes - - */
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

/* - - Defines - - */
#define MONITOR_SPEED 115200

#define ONE_WIRE_SENSORS_BUS 3

#define LORAWAN_FRECUENCY 868E6
#define LORA_SYNC_WORD 0xF3
//Lora PINs (See Pinout diagrams)
#define LORA_CS 18
#define LORA_RST 14
#define LORA_NSS 18 //V_SPI_CLK, Warning: Same as CS
#define LORA_DIO0 26
#define LORA_DIO1 33
#define LORA_DIO2 32

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_WIDTH 128 // OLED display width, in pixels //(128)x64
#define SCREEN_HEIGHT 64 // OLED display height, in pixels //128x(64)

/* - - Functions - - */
void initLoraTransceiver();
void initLoraCommunication();
void initSerialMonitor();
void initTempSensor();
void do_send(osjob_t *);

#endif