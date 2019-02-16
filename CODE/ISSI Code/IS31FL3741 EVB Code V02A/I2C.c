#include "stm32f10x.h"
/*================================= */

int Delay_Time = 3;
/*
	Delay_Time		Speed
			1					2MHz
			3					1MHz
			4					800KHz
			7					500KHz
			9					400KHz
			12				300KHz
*/

void delay_ms(uint32_t t)
{
	uint8_t tt;
	for(;t>0;t--)
	{
		for(tt=255;tt>0;tt--);
		for(tt=255;tt>0;tt--);
		for(tt=255;tt>0;tt--);
		for(tt=255;tt>0;tt--);
		for(tt=255;tt>0;tt--);
		for(tt=255;tt>0;tt--);
		for(tt=255;tt>0;tt--);
		for(tt=30;tt>0;tt--);
	}
}

void I2C_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_14;
  SDA_H;
  SCL_H; 
	LEDR_L;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;//SDB_pin
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	SDB_H;	
}

void PIN_GPIO_Config_MISO(GPIOMode_TypeDef num1)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = num1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);				// PC1,输入时不用设置速率	
	MISO_L;
}
/**/ 
void I2C_delay(int cnt)
{	
	while(cnt--)
	{
	}
}
/*********************************************************************************************************/
int I2C_Start(void)
{
	SDA_H;
	SCL_H;
	I2C_delay(Delay_Time);
	if(!SDA_read)
	{
		return FALSE1;	//SDA低时忙
	}
	SDA_L;
	I2C_delay(Delay_Time);
	if(SDA_read)
	{
	return FALSE1;	//SDA为高时出错
	}
	SCL_L;
	I2C_delay(Delay_Time);
	return TRUE1;
}
/*********************************************************************************************************/
void I2C_Stop(void)
{
	SCL_L;
	I2C_delay(Delay_Time);
	SDA_L;
	I2C_delay(Delay_Time);
	SCL_H;
	I2C_delay(Delay_Time);
	SDA_H;
	I2C_delay(Delay_Time);
}
/*********************************************************************************************************/
void I2C_Ack(void)
{	
	SCL_L;
	I2C_delay(Delay_Time);
	SDA_L;
	I2C_delay(Delay_Time);
	SCL_H;
	I2C_delay(Delay_Time);
	SCL_L;
	I2C_delay(Delay_Time);
}
/*********************************************************************************************************/
void I2C_NoAck(void)
{	
	SCL_L;
	I2C_delay(Delay_Time);
	SDA_H;
	I2C_delay(Delay_Time);
	SCL_H;
	I2C_delay(Delay_Time);
	SCL_L;
	I2C_delay(Delay_Time);
}
/*********************************************************************************************************/
int I2C_WaitAck(void) 	 //返回值=1 有ack，0没有ack
{
	SCL_L;
	I2C_delay(Delay_Time);
	SDA_H;			
	I2C_delay(Delay_Time);
	SCL_H;
	I2C_delay(Delay_Time);
	if(SDA_read)
	{	
		SCL_L;
		return FALSE1;
	}	
	return TRUE1;
}
/*********************************************************************************************************/
void I2C_SendByte(int SendByte) // 从高到低发送//
{
    int i=8;
    while(i--)
    {
        SCL_L;
        I2C_delay(Delay_Time);
      if(SendByte&0x80)
        SDA_H;  
      else 
        SDA_L;   
        SendByte<<=1;
        I2C_delay(Delay_Time);
	      SCL_H;
        I2C_delay(Delay_Time);
    }
    SCL_L;
}
/*********************************************************************************************************/
uint8_t I2C_ReceiveByte(void)  //从高到低接收//
{ 
    uint8_t i=8;
    uint8_t ReceiveByte=0;

    SDA_H;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L;
      I2C_delay(Delay_Time);
	    SCL_H;
      I2C_delay(Delay_Time);	
      if(SDA_read)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L;
    return ReceiveByte;
}

/*********************************************************************************************************/
//I2C 写一个byte，器件地址，寄存器地址，数据

uint8_t I2C_WriteByte(int DeviceAddress, int WriteAddress, int SendByte)
{		
	  //I2C_Start();
    if(!I2C_Start())return FALSE1;
    I2C_SendByte(DeviceAddress & 0xFE);//
    if(!I2C_WaitAck())
    {
			I2C_Stop(); 
			return FALSE1;
		}
    I2C_SendByte(WriteAddress);   //
    I2C_WaitAck();	
    I2C_SendByte(SendByte);
    I2C_WaitAck();   
    I2C_Stop(); 
    //Systick_Delay_1ms(10);
    return TRUE1;
}

/*********************************************************************************************************/
//I2C 写一个byte，寄存器地址，数据

uint8_t I2C_Write2Byte(int WriteAddress, int SendByte)
{		
	if(!I2C_Start())return FALSE1;
	I2C_SendByte(WriteAddress);   
	if(!I2C_WaitAck())
  {
		I2C_Stop(); 
		return FALSE1;
	}	
	I2C_SendByte(SendByte);
	I2C_WaitAck();   
	I2C_Stop(); 
	return TRUE1;
}

/*********************************************************************************************************/
//I2C 连续写
//器件地址，待写入寄存器起始地址，待写入数据数长度，数据数组地址  
uint8_t I2C_WriteBuffer(uint8_t* pBuffer, int length, int DeviceAddress, int WriteAddress )
{   
	  //I2C_Start();
    if(!I2C_Start())return FALSE1;
    I2C_SendByte(DeviceAddress & 0xFE);//???? 
    if(!I2C_WaitAck()){I2C_Stop(); return FALSE1;}
    I2C_SendByte(WriteAddress);   //??????????      
	  I2C_WaitAck();	  
		while(length--)
		{
		  I2C_SendByte(*pBuffer);
		  I2C_WaitAck();
          pBuffer++;
		}
	  I2C_Stop();
	  //Systick_Delay_1ms(10);
	  return TRUE1;
}
/*********************************************************************************************************/

// I2C 读一个byte
uint8_t I2C_ReadByte(int DeviceAddress,int ReadAddress)
{		
    uint8_t rec;
		//I2C_Start();
    if(!I2C_Start())return FALSE1;
    I2C_SendByte(DeviceAddress & 0xFE);// 
    if(!I2C_WaitAck()){I2C_Stop(); return FALSE1;}
    I2C_SendByte(ReadAddress);        //     
    I2C_WaitAck();
    I2C_Stop();                       //selectable
    I2C_Start();                      
    I2C_SendByte(DeviceAddress | 0x01);
    I2C_WaitAck();
    rec=I2C_ReceiveByte();
    I2C_WaitAck();
    I2C_Stop();
    return rec;
}


/*********************************************************************************************************/

// I2C 连续读一串数据
uint8_t I2C_ReadBuffer(uint8_t* pBuffer,   int length,     int ReadAddress,  int DeviceAddress)
{		
    if(length == 0)
    return FALSE1;
	//	I2C_Start();
    if(!I2C_Start())return FALSE1;
    I2C_SendByte(DeviceAddress & 0xFE);//???? 
    if(!I2C_WaitAck()){I2C_Stop(); return FALSE1;}
    I2C_SendByte(ReadAddress);        //??????????      
    I2C_WaitAck();
    I2C_Stop();                       //selectable
    I2C_Start();                      
    I2C_SendByte(DeviceAddress | 0x01);
    I2C_WaitAck();
    while(length)
    {
      *pBuffer = I2C_ReceiveByte();
      if(length == 1)I2C_NoAck();
      else I2C_Ack(); 
      pBuffer++;
      length--;
    }
    I2C_Stop();
    return TRUE1;
}
