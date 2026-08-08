# STM32F103C8T6 四轴无人机

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
|PA1|电机驱动(前右)输出PWM波形|TIM2_CH2|
|PA2|接口插座串口输出|UART2_TX|              
|PA3|接口插座串口输入|UART2_RX|
|PA4|SI24R1-SPI片选|SPI1_NSS|
|PA5|SI24R1-SPI时钟|SPI1_SCK|
|PA6|SI24R1-SPI数据输入|SPI1_MISO|
|PA7|SI24R1-SPI数据输出|SPI1_MOSI|
|PB1|ADC电池电压检测|BAT_DET|
|PB2|电源按键|POWER_KEY|
|PB10|VL53L4-IIC时钟线|IIC2_SCL|
|PB11|VL53L4-IIC数据线|IIC2_SDA|
|PB12|VL53L4关断|VL_XSHUT|
|PB13|VL53L4中断请求|VL_GPIO1|
|PB14|LED|LED4|
|PB15|LED|LED3|
|PA8|使能SI24R1|SI_CE|
|PA9|SI24R1中断请求|SI_IRQ|
|PA10|电机驱动(后右)输出PWM波形|TIM1_CH3|
|PA11|LED|LED2|
|PA12|LED|LED1|
|PA13|SWDIO(调试接口)|接ST-Link的SWDIO|
|PA14|SWCLK(调试接口)|接ST-Link的SWCLK|
|PB3|MPU6050中断请求|MPU_INT|
|PB4|电机驱动(前左)输出PWM波形|TIM3_CH1|
|PB5|电池电压检测使能|BAT_DET_EN|
|PB6|MPU6050-IIC时钟线|IIC1_SCL|
|PB7|MPU6050-IIC数据线|IIC1_SDA|
|PB9|电机驱动(后左)输出PWM波形|TIM4_CH4|
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
|PA1|摇杆|ADC_IN1|
|PA2|摇杆|ADC_IN2|              
|PA3|摇杆|ADC_IN3|
|PA4|OLED-SPI片选|OLED_NSS|
|PA5|OLED-SPI时钟|OLED_SCK|
|PA6|摇杆|ADC_IN6|
|PA7|OLED-SPI数据输出|OLED_MOSI|
|PB0|OLED复位|OLED_RES|
|PB1|OLED数据/命令选择|OLED_D/C|
|PB2|按键左上|KEY_LEFT_X|
|PB10|按键右上|KEY_RIGHT_X|
|PB11|按键上|KEY_UP|
|PB12|按键右|KEY_RIGHT|
|PB13|按键左|KEY_LEFT|
|PB14|按键下|KEY_DOWN|
|PB15|电源按键|POWER_KEY|
|PA9|接口插座串口输出|UART1_TX|
|PA10|接口插座串口输入|UART1_RX|
|PA13|SWDIO(调试接口)|接ST-Link的SWDIO|
|PA14|SWCLK(调试接口)|接ST-Link的SWCLK|
|PA15|SI24R1-SPI片选|SPI1_NSS|
|PB3|SI24R1-SPI时钟|SPI1_SCK|
|PB4|SI24R1-SPI数据输入|SPI1_MISO|
|PB5|SI24R1-SPI数据输出|SPI1_MOSI|
|PB6|SI24R1中断请求|SI_IRQ|
|PB7|使能SI24R1|SI_CE|
|VSS|数字地|接GND|
|VDD|数字电源|接3V3|
|BOOT0|启动模式选择|接10kΩ下拉电阻至GND（默认低电平，从 Flash 启动）；通过 NC电阻预留上拉至 VDD ，需串口下载时焊上该电阻将 BOOT0 拉高|

## 硬件设计注意事项
- 四个电机驱动引脚尽可能分散在不同方位，便于PCB设计接线，避免走线拥挤
- 复位电路：NRST引脚内部虽有约40kΩ弱上拉，但在电机和无线模块的强干扰下不足以稳定维持高电平，因此要外部并联10kΩ上拉电阻增强抗干扰能力，同时并接0.1μF电容滤除高频噪声；复位按键按下时NRST接地，触发硬件复位
- SWD 调试接口及串口插座引出 +5V 作为对外电源，而非 +3.3V，以确保外部设备供电稳定且隔离风险
- 电池电压范围在3.2V到4.1V，会超过ADC量程上限3.3V，所以要连分压电路，来实现电池电压监测
- 电源滤波：各 IC 的 VCC 引脚旁均放置 0.1μF 去耦电容，靠近引脚摆放，为芯片提供瞬时电流并滤除高频噪声
- SI24R1工作在2.4G频段，内部PLL以16MHz晶振为参考时钟
- MCU的GPIO输出PWM信号无法直接驱动电机，故采用N-MOS管做低边驱动；N-MOS管导通时提供电机负极到地的低阻抗回路，实现电机通断与PWM调速

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
