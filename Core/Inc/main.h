/* USER CODE BEGIN Header */
/**
  * @file           : main.h
  * @brief          : Header for main.c file.
  */
/* USER CODE END Header */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/* --- KULLANILAN DONANIM PINLERI --- */

/* Mavi Kullanici Butonu */
#define BUTTON_USER_PIN     GPIO_PIN_13
#define BUTTON_USER_PORT    GPIOC

/* Kart Uzerindeki LED'ler */
#define LED_GREEN_PIN       GPIO_PIN_0
#define LED_GREEN_PORT      GPIOB
#define LED_RED_PIN         GPIO_PIN_14
#define LED_RED_PORT        GPIOB
#define LED_BLUE_PIN        GPIO_PIN_7
#define LED_BLUE_PORT       GPIOB

/* Servo Motor Pini (PWM) */
#define ACTUATOR_PIN        GPIO_PIN_9
#define ACTUATOR_PORT       GPIOE

/* Isik Sensorleri (LDR) */
#define SENSOR_RIGHT_PIN    GPIO_PIN_3
#define SENSOR_RIGHT_PORT   GPIOA
#define SENSOR_LEFT_PIN     GPIO_PIN_3
#define SENSOR_LEFT_PORT    GPIOF

/* Serial Konsol (USB Baglantisi) */
#define SERIAL_TX_PIN       GPIO_PIN_8
#define SERIAL_TX_PORT      GPIOD
#define SERIAL_RX_PIN       GPIO_PIN_9
#define SERIAL_RX_PORT      GPIOD

/* --- SABITLER --- */
#define PULSE_MIN_US        800
#define PULSE_MAX_US        2200
#define MOVEMENT_THRESHOLD  0.05
#define STEP_SIZE           0.02

/* --- YAPILAR --- */
typedef struct {
    TIM_HandleTypeDef *tim_handle;
    uint32_t channel;
    double current_position;
} ServoMechanism;

typedef struct {
    ADC_HandleTypeDef *adc_handle;
    uint32_t channel_rank;
} LightSensor;

/* --- FONKSIYON PROTOTIPLERI --- */
void Error_Handler(void);
/* Bu satir cok onemli, silmeyin: */
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
