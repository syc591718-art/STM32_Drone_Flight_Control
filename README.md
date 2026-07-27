# STM32_Drone_Flight_Control
STM32F103C8T6 四轴无人机飞控系统 - 软硬件协同设计

## 项目概述
本项目是一个基于两块STM32F103C8T6主控芯片的四轴无人机飞控系统，使用C语言编写，基于FreeRTOS实时操作系统，集成有MPU6050、SI24R1等模块，实现完整的无人机姿态控制与遥控飞行功能

## 引脚分配表
### 飞控板
|引脚|功能|连接方式|
|----|----|----|
|VBAT|备用电池供电(不使用)|直连VDD引脚|
|PD0-OSC_IN|外部晶振输入|接8MHz外部晶振(HSE)，OSC_IN|
|PD1-OSC_OUT|外部晶振输出|接8MHz外部晶振(HSE)，OSC_OUT|
|NRST|低电平复位引脚|接10kΩ上拉电阻至VCC，并联0.1uF电容到GND；复位按键一端接NRST，另一端接GND|
|PA0|电机驱动(前左)输出PWM波形|TIM2_CH1_ETR|
|PA1|电机驱动(前右)输出PWM波形|TIM2_CH2|
|PA2|电机驱动(后左)输出PWM波形|TIM2_CH3|
|PA3|电机驱动(后右)输出PWM波形|TIM2_CH4|
|PA4|SI24R1-SPI片选|SPI1_NSS|
|PA5|SI24R1-SPI时钟|SPI1_SCK|
|PA6|SI24R1-SPI数据输入|SPI1_MISO|
|PA7|SI24R1-SPI数据输出|SPI1_MOSI|
|PB0|ADC电池电压检测|BAT_DET|
|PB1|使能SI24R1|SI_CE|
|PB2|SI24R1中断请求|SI_IRQ|
|PB10|MPU6050-IIC时钟线|IIC2_SCL|
|PB11|MPU6050-IIC数据线|IIC2_SDA|
|PB12|LED|LED1|
|PB13|LED|LED2|
|PB14|LED|LED3|
|PB15|LED|LED4|
|PA8|MPU6050中断请求|MPU_INT|
|PA9|接口插座串口输出|UART1_TX|
|PA10|接口插座串口输入|UART1_RX|
|PA11|VL53L4中断请求|VL_GPIO1|
|PA12|VL53L4关断|VL_XSHUT|
|PA13|SWDIO(调试接口)|接ST-Link的SWDIO|
|PA14|SWCLK(调试接口)|接ST-Link的SWCLK|
|PB6|VL53L4-IIC时钟线|IIC1_SCL|
|PB7|VL53L4-IIC数据线|IIC1_SDA|
|PB8|电源按键|POWER_KEY|
|PB9|电池电压检测使能|BAT_DET_EN|
|VSS|数字地|接GND|
|VDD|数字电源|接3V3|
|BOOT0|启动模式选择|接10kΩ下拉电阻至GND（默认低电平，从 Flash 启动）；通过 NC电阻预留上拉至 VDD ，需串口下载时焊上该电阻将 BOOT0 拉高|

### 遥控器
|引脚|功能|连接方式|
|----|----|----|
|VBAT|备用电池供电(不使用)|直连VDD引脚|
|PD0-OSC_IN|外部晶振输入|接8MHz外部晶振(HSE)，OSC_IN|
|PD1-OSC_OUT|外部晶振输出|接8MHz外部晶振(HSE)，OSC_OUT|
|NRST|低电平复位引脚|接10kΩ上拉电阻至VCC，并联0.1uF电容到GND；复位按键一端接NRST，另一端接GND|
|PA0|摇杆|ADC_IN0|
|PA1|摇杆|ADC_IN1|
|PA2|摇杆|ADC_IN2|
|PA3|摇杆|ADC_IN3|
|PA4|SI24R1-SPI片选|SPI1_CS|
|PA5|SI24R1-SPI时钟|SPI1_CLK|
|PA6|SI24R1-SPI数据输入|SPI1_MISO|
|PA7|SI24R1-SPI数据输出|SPI1_MOSI|
|PB0|使能SI24R1|SI_CE|
|PB1|SI24R1中断请求|SI_IRQ|
|PB10|OLED复位|OLED-RES|
|PB11|OLED数据/命令选择|OLED-D/C|
|PB12|OLED-SPI片选|OLED_NSS|
|PB13|OLED-SPI时钟|OLED_SCK|
|PB15|OLED-SPI数据输出|OLED_MOSI|
|PA9|接口插座串口输出|UART1_TX|
|PA10|接口插座串口输入|UART1_RX|
|PA13|SWDIO(调试接口)|接ST-Link的SWDIO|
|PA14|SWCLK(调试接口)|接ST-Link的SWCLK|
|PA15|电源按键|POWER_KEY|
|PB4|按键|按键上|
|PB5|按键|按键下|
|PB6|按键|按键左|
|PB7|按键|按键右|
|PB8|按键|按键左上|
|PB9|按键|按键右上|
|VSS|数字地|接GND|
|VDD|数字电源|接3V3|
|BOOT0|启动模式选择|接10kΩ下拉电阻至GND（默认低电平，从 Flash 启动）；通过 NC电阻预留上拉至 VDD ，需串口下载时焊上该电阻将 BOOT0 拉高|

## 硬件设计注意事项

## 工程结构

## 任务划分

## 通信协议

## 关键算法

## 编译与烧录

## 使用说明

## 版本记录

## 参考资料
- STM32F10xxx参考手册（中文）
- Cortex-M3权威指南
- SI24R1数据手册
- MPU6050数据手册
- VL53L4CD数据手册
- IP5305T数据手册