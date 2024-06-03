#include "main.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
 
UART_HandleTypeDef huart1;
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
 
char Rx_Byte[1];        // Creating a single byte buffer
uint8_t Rx_Buffer[256]; // Full buffer
uint8_t Rx_Buffer_Index = 0;
 
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
 
    HAL_UART_Receive_IT(&huart1, (uint8_t *)Rx_Byte, 1);
    memcpy(Rx_Buffer + Rx_Buffer_Index, Rx_Byte, 1);
    Rx_Buffer_Index++;
    if (*Rx_Byte == '\r' || *Rx_Byte == '\n') {
// I could send data via putty and FTDI, and when enter was pressed it printed the data in the buffer back to you via uart
//        HAL_UART_Transmit(&huart1, (uint8_t *) Rx_Buffer, Rx_Buffer_Index, 1000);  
        memset(Rx_Buffer, 0, sizeof(Rx_Buffer)); // Clear buffer
        Rx_Buffer_Index = 0;
    }
}
 
int main(void)
{
 
  HAL_Init();
 
  SystemClock_Config();
 
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USB_DEVICE_Init();
 
  char echo_off[] = "ATE0\r\n";
  char data[] = "AT\r\n";
  HAL_Delay(1000);
  HAL_UART_Transmit(&huart1, (uint8_t*)echo_off, sizeof(echo_off), 10);
 
  while (1)
  {
      HAL_GPIO_TogglePin(GPIOA, LED_1_Pin);
      HAL_UART_Transmit(&huart1, (uint8_t*)data, sizeof(data), 1000);
      HAL_Delay(500);
  }
}
