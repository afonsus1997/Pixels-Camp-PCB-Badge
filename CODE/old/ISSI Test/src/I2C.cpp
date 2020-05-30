/*================================= */
#include "../include/I2C.h"
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
int I2C_WriteByte(int DeviceAddress, int WriteAddress, int SendByte)
{		
	/*  //I2C_Start();
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
    return TRUE1;*/

	Wire.beginTransmission(DeviceAddress/2); // transmit to device IS31FL373x
 	Wire.write(WriteAddress); // sends regaddress
 	Wire.write(SendByte); // sends regaddress
 	Wire.endTransmission(); // stop transmitting

}
/*
//I2C дһ��byte���Ĵ�����ַ������

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

//I2C ����д
//������ַ����д��Ĵ�����ʼ��ַ����д�����������ȣ����������ַ  
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

// I2C ��һ��byte
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



// I2C ������һ������
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
*/