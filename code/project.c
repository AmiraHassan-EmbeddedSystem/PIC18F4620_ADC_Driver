/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
//#include <builtins.h>
#include "project.h"
#define _XTAL_FREQ 80000000UL
#pragma config PBADEN = OFF 




void initialization(void);
void app_adc(void);

volatile uint8 flag_adc = 0;
uint16 adc_res1, adc_res2, adc_res3, adc_res4;



Adc_t adc_1= {
    .ADC_InterruptHandler = app_adc,
    .TAD_Time = ADC_AQUISION_TAD12,
    .FOSC_Clock = ADC_RC_FOSC_DIV_16,
    .channel = ADC_CHANNEL_AN0,
    .adc_result_format = ADC_RESULT_RIGH_FORMAT,
    .adc_voltage_reference = ADC_INPUT_VOLTAGE_FORMAT,
};



void main(void) {
    initialization();
    ADC_StartConversionInterrupt(&adc_1, ADC_CHANNEL_AN0);      
    ADC_StartConversionInterrupt(&adc_1, ADC_CHANNEL_AN1);
    ADC_StartConversionInterrupt(&adc_1, ADC_CHANNEL_AN2);
    ADC_StartConversionInterrupt(&adc_1, ADC_CHANNEL_AN3);


    while(1){

    }
    
    return;
}

void initialization(void){
    ADC_Init(&adc_1);
}

void app_adc(void){
    flag_adc++;
    ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN0, &adc_res1);
    ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN1, &adc_res2);
    ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN2, &adc_res3);
    ADC_GetConversion_Blocking(&adc_1, ADC_CHANNEL_AN3, &adc_res4);
}