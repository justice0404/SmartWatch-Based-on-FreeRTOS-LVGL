#include "MyI2c.h"
#include "delay.h"


//----------------------------------------------------------------分割线----------------------------------------------------------------
//----------------------------------------------------------------分割线----------------------------------------------------------------
//----------------------------------------------------------------分割线----------------------------------------------------------------

//端口设置

/**
  * @brief SDA线输入模式配置
  * @param None
  * @retval None
  */
void SDA_Input_Mode(iic_bus_t *bus)
{
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	
	GPIO_InitStructure.Pin = bus->IIC_SDA_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	
	HAL_GPIO_Init(bus->IIC_SDA_PORT,&GPIO_InitStructure);
}

/**
  * @brief SDA线输出模式配置
  * @param None
  * @retval None
  */
void SDA_Output_Mode(iic_bus_t *bus)
{
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	
	GPIO_InitStructure.Pin = bus->IIC_SDA_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	
	HAL_GPIO_Init(bus->IIC_SDA_PORT,&GPIO_InitStructure);
}

/**
  * @brief SDA线输出一个位
  * @param val 输出的数据
  * @retval None
  */
void SDA_Output(iic_bus_t *bus,uint16_t value)
{
	if(value) //操作寄存器实现置高电平
	{
		bus->IIC_SDA_PORT->BSRR |= bus->IIC_SDA_PIN;
	}
	else
    {
        bus->IIC_SDA_PORT->BSRR = (uint32_t)bus->IIC_SDA_PIN << 16U;
    }
}

/**
  * @brief SCL线输出一个位
  * @param val 输出的数据
  * @retval None
  */
void SCL_Output(iic_bus_t *bus, uint16_t value)
{
    if ( value )
    {
        bus->IIC_SCL_PORT->BSRR |= bus->IIC_SCL_PIN;
    }
    else
    {
         bus->IIC_SCL_PORT->BSRR = (uint32_t)bus->IIC_SCL_PIN << 16U;
    }
}

/**
  * @brief SDA输入一位
  * @param None
  * @retval GPIO读入一位
  */
uint8_t SDA_Input(iic_bus_t *bus)
{
	if(HAL_GPIO_ReadPin(bus->IIC_SDA_PORT, bus->IIC_SDA_PIN) == GPIO_PIN_SET){
		return 1;
	}else{
		return 0;
	}
}

/**
  * @brief 初始化IIC端口
  * @param None
  * @retval None
  */
void IICInit(iic_bus_t *bus)
{
	GPIO_InitTypeDef GPIO_InitStructure  = {0};
	
	GPIO_InitStructure.Pin = bus->IIC_SDA_PIN ;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(bus->IIC_SDA_PORT, &GPIO_InitStructure);
		
	GPIO_InitStructure.Pin = bus->IIC_SCL_PIN ;
    HAL_GPIO_Init(bus->IIC_SCL_PORT, &GPIO_InitStructure);
}

//----------------------------------------------------------------分割线----------------------------------------------------------------
//----------------------------------------------------------------分割线----------------------------------------------------------------
//----------------------------------------------------------------分割线----------------------------------------------------------------

//通信协议
/*
	两条线SDA,SCL上拉默认高电平，开漏输出模式
	但是SDA空闲状态为高电平，SCL空闲状态为低电平

	起始信号：在SCL为高时拉低SDA
	终止信号：在SCL为高时拉高SDA
	信号帧组成：起始 + （7位地址+1位读写） + 1位应答 + 8位数据帧 + 1位应答 ... 终止

	总线仲裁机制：由于线与特性，
				 只要有一个为低，SDA或SCL都为低
				 只有全部为高，SDA或SCL才为高
*/
 

/**
  * @brief IIC起始信号
  * @param None
  * @retval None
  */
void IICStart(iic_bus_t *bus)
{
	SDA_Output(bus,1);
	delay_us(2); //先保证SDA先为高
	SCL_Output(bus,1);
	delay_us(0); //再确保拉高SCL
	
	SDA_Output(bus,0);  //在SCL为高时拉高SDA
	delay_us(1);
	SCL_Output(bus,0);  //释放SCL
	delay_us(1);
}

/**
  * @brief IIC结束信号
  * @param None
  * @retval None
  */
void IICStop(iic_bus_t *bus)
{
	//先在SCL低电平时拉低SDA
	SCL_Output(bus,0);
	delay_us(2);
	SDA_Output(bus,0);
	delay_us(1);
	
	//在SCL为高电平时拉高SDA，终止信号
	SCL_Output(bus,1);
	delay_us(1);
	SDA_Output(bus,1);
	delay_us(1);
}

/**
  * @brief IIC等待确认信号
  * @param None
  * @retval ERROR -- 应答超时; SUCCESS --应答成功
  */
unsigned char IICWaitAck(iic_bus_t *bus)
{
	unsigned short cErrTime = 5;
	SDA_Input_Mode(bus);  //配置为输入模式，等待从机拉低SDA，SDA默认为高
	SCL_Output(bus,1);
	
	while(SDA_Input(bus))  //等待拉低SDA
	{
		cErrTime--;
		delay_us(1);
		
		if(0 == cErrTime) //等待时间超过5us不拉低，则应答超时
		{
			SDA_Output_Mode(bus);
			IICStop(bus);
			return ERROR;
		}
		
	}
	
	SDA_Output_Mode(bus); //5us内拉低，应答成功
	SCL_Output(bus,0);  //拉低SCL
	delay_us(2);
	
	return SUCCESS;
}

/**
  * @brief IIC发送确认信号
  * @param None
  * @retval None
  */
void IICSendAck(iic_bus_t *bus)
{
	SDA_Output(bus,0); //先转换数据,拉低应答
	delay_us(1);
	SCL_Output(bus,1); //再拉高SCL，发送数据
	delay_us(0);
	SCL_Output(bus,0); //恢复空闲状态
	delay_us(1);
}

/**
  * @brief IIC发送非确认信号
  * @param None
  * @retval None
  */
void IICSendNotAck(iic_bus_t *bus)
{
	SDA_Output(bus,1); //先转换数据，拉高不应答
	delay_us(1);
	SCL_Output(bus,1); //再拉高SCL，发送数据
	delay_us(0);
	SCL_Output(bus,0); //恢复空闲状态
	delay_us(1);
}

/**
  * @brief IIC发送一个字节
  * @param cSendByte 需要发送的字节
  * @retval None
  */
void IICSendByte(iic_bus_t *bus,unsigned char cSendByte)
{
	unsigned char i = 8;
	while(i--)
	{
		SCL_Output(bus,0); //确保SCL空闲
		delay_us(2);
		SDA_Output(bus,cSendByte &0x80); //cSendByte & 1000 0000取最高位
		delay_us(1);
		
		cSendByte <<= 1; //将cSendByte左移一位，高位先行
		delay_us(1);
		SCL_Output(bus,1); //转换完状态后发送
		delay_us(1);
	}
	
	SCL_Output(bus,0);  //恢复空闲
	delay_us(2);
}

/**
  * @brief IIC接收一个字节
  * @param None
  * @retval 接收到的字节
  */
unsigned char IICReceiveByte(iic_bus_t *bus)
{
	unsigned char i = 8;
	unsigned char cR_Byte = 0;
	SDA_Input_Mode(bus);
	
	while(i--)  //读取八位
	{
		cR_Byte <<= 1; //左移一位，让接收的数据从右往左累积
		SCL_Output(bus,0);  //确保空闲
		delay_us(2);
		
		SCL_Output(bus,1); //从机将在此时写入SDA
		delay_us(1);
		
		if(SDA_Input(bus))  //判断从机写入数据
		{
			cR_Byte |= 0x01;  //如果为1，则最右边的为写1
		}
	}
	
	SCL_Output(bus,0); //读取完成，恢复空闲
	SDA_Output_Mode(bus);  //恢复输出
	
	return cR_Byte;
}


//----------------------------------------------------------------分割线----------------------------------------------------------------
//----------------------------------------------------------------分割线----------------------------------------------------------------
//----------------------------------------------------------------分割线----------------------------------------------------------------

//通信时序
/*
	包括：
		读写某个从机的某个寄存器的单个字节数据
		读写某个从机的某个寄存器的多个字节数据
*/

/**
  * @brief IIC时序向从机某个寄存器写入一个字节
  * @param address -> 7为从机地址
		   reg   -> 待写入的寄存器
		   data  -> 待写入的数据
  * @retval 0 -> 发送成功
			1 -> 发送失败
  */
uint8_t IIC_Write_One_Byte(iic_bus_t *bus, uint8_t address,uint8_t reg,uint8_t data)
{
	//找从机
	IICStart(bus);  
	IICSendByte(bus,address<<1);	 //7位从机地址 + 0（写操作）   
	if(IICWaitAck(bus))	//等待从机应答
	{
		IICStop(bus);		 
		return 1;		
	}
	
	//送寄存器地址
	IICSendByte(bus,reg);
	IICWaitAck(bus);
	
	//发数据
	IICSendByte(bus,data);     						   
	IICWaitAck(bus);  		    	   
	IICStop(bus);
	delay_us(1);
	return 0;
}

/**
  * @brief IIC时序向从机某个寄存器写入多个字节
  * @param address -> 7为从机地址
		   reg   -> 待写入的寄存器
		   length -> 待发送数据长度,单位Byte
		   buf[]  -> 待发送数据缓冲区
  * @retval 0 -> 发送成功
			1 -> 发送失败
  */
uint8_t IIC_Write_Multi_Byte(iic_bus_t *bus, uint8_t address,uint8_t reg,uint8_t length,uint8_t buff[])
{			
	unsigned char i; 	
	
	//找从机
	IICStart(bus);  
	IICSendByte(bus,address<<1);	    
	if(IICWaitAck(bus))
	{
		IICStop(bus);
		return 1;
	}
	
	//送寄存器地址
	IICSendByte(bus,reg);
	IICWaitAck(bus);

	//发多个数据
	for(i=0;i<length;i++)
	{
		IICSendByte(bus,buff[i]);     						   
		IICWaitAck(bus); 
	}		    	   
	IICStop(bus);
	delay_us(1);
	return 0;
}

/**
  * @brief IIC时序从从机某个寄存器读入一个字节
  * @param address -> 7为从机地址
		   reg   -> 待写入的寄存器
  * @retval data  -> 读取出的数据
  */
unsigned char IIC_Read_One_Byte(iic_bus_t *bus, uint8_t address,uint8_t reg)
{
	unsigned char data;
	//找从机
	IICStart(bus);
	IICSendByte(bus,address<<1);
	IICWaitAck(bus);
	//找寄存器
	IICSendByte(bus,reg);
	IICWaitAck(bus);
	
	//找到之后从这个寄存器开始读
	IICStart(bus);
	IICSendByte(bus,(address<<1)+1); //读操作
	IICWaitAck(bus);
	
	data = IICReceiveByte(bus); //读到data中
	IICSendNotAck(bus);  //读完之后回复不应答
	IICStop(bus);
	return data;
}

/**
  * @brief IIC时序向从机某个寄存器读出多个字节
  * @param address -> 7为从机地址
		   reg   -> 待写入的寄存器
		   length -> 待读取的数据长度,单位Byte
  * @retval buf[]  -> 读取到的数据缓冲区
  */
uint8_t IIC_Read_Multi_Byte(iic_bus_t *bus, uint8_t address, uint8_t reg, uint8_t length, uint8_t buff[])
{
	unsigned char i;
	//找从机的某个寄存器
	IICStart(bus);
	IICSendByte(bus,address<<1);
	if(IICWaitAck(bus))
	{
		IICStop(bus);		 
		return 1;		
	}
	IICSendByte(bus,reg);
	IICWaitAck(bus);
	
	//找到寄存器后开始读
	IICStart(bus);
	IICSendByte(bus,(address<<1)+1);
	IICWaitAck(bus);
	for(i=0;i<length;i++)
	{
		buff[i] = IICReceiveByte(bus); //读到length - 1字节的数据时，都回复应答
		if(i<length-1)
		{IICSendAck(bus);}
	}
	IICSendNotAck(bus); //读最后一个字节的数据，不回复
	IICStop(bus);
	return 0;
}
