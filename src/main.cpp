/***********************************************************************
 * Project      :     tiny32_v3_template
 * Description  :     Template coding for tiny32_v3 on vscode with platformIO
 * Hardware     :     tiny32_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     04/07/2022
 * Revision     :     1.0
 * Rev1.0       :     Origital
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@tenergyinnovation.co.th
 * TEL          :     +66 89-140-7205
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>
#include <esp_task_wdt.h>

/**************************************/
/*          Firmware Version          */
/**************************************/
String version = "0.1";

/**************************************/
/*          Header project            */
/**************************************/
void header_print(void)
{
Serial.printf("\r\n***********************************************************************\r\n");
Serial.printf("* Project      :     tiny32_v3_template\r\n");
Serial.printf("* Description  :     Template coding for tiny32_v3 on vscode with platformIO\r\n");
Serial.printf("* Hardware     :     tiny32_v3\r\n");
Serial.printf("* Author       :     Tenergy Innovation Co., Ltd.\r\n");
Serial.printf("* Date         :     04/07/2022\r\n");
Serial.printf("* Revision     :     %s\r\n",version);
Serial.printf("* Rev1.0       :     Origital\r\n");
Serial.printf("* website      :     http://www.tenergyinnovation.co.th\r\n");
Serial.printf("* Email        :     uten.boonliam@tenergyinnovation.co.th\r\n");
Serial.printf("* TEL          :     +66 89-140-7205\r\n");
Serial.printf("***********************************************************************/\r\n");
}

/**************************************/
/*        define object variable      */
/**************************************/
tiny32_v3 mcu;

/**************************************/
/*            GPIO define             */
/**************************************/


/**************************************/
/*       Constand define value        */
/**************************************/
// 10 seconds WDT
#define WDT_TIMEOUT 10

/**************************************/
/*       eeprom address define        */
/**************************************/

/**************************************/
/*        define global variable      */
/**************************************/

/**************************************/
/*           define function          */
/**************************************/


/***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup()
{
    Serial.begin(115200);
    header_print();

    Serial.println("Configuring WDT...");
    esp_task_wdt_init(WDT_TIMEOUT, true); // enable panic so ESP32 restarts
    esp_task_wdt_add(NULL);               // add current thread to WDT watch
    mcu.buzzer_beep(2);
}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop()
{
    esp_task_wdt_reset();
    vTaskDelay(100);
}
