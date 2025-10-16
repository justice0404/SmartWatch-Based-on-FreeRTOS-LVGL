#include "MyI2c.h"
#include "delay.h"


//----------------------------------------------------------------�ָ���----------------------------------------------------------------
//----------------------------------------------------------------�ָ���----------------------------------------------------------------
//----------------------------------------------------------------�ָ���----------------------------------------------------------------

//�˿�����

/**
  * @brief SDA������ģʽ����
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
  * @brief SDA�����ģʽ����
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
  * @brief SDA�����һ��λ
  * @param val ���������
  * @retval None
  */
void SDA_Output(iic_bus_t *bus,uint16_t value)
{
	if(value) //�����Ĵ���ʵ���øߵ�ƽ
	{
		bus->IIC_SDA_PORT->BSRR |= bus->IIC_SDA_PIN;
	}
	else
    {
        bus->IIC_SDA_PORT->BSRR = (uint32_t)bus->IIC_SDA_PIN << 16U;
    }
}

/**
  * @brief SCL�����һ��λ
  * @param val ���������
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
  * @brief SDA����һλ
  * @param None
  * @retval GPIO����һλ
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
  * @brief ��ʼ��IIC�˿�
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

//----------------------------------------------------------------�ָ���----------------------------------------------------------------
//----------------------------------------------------------------�ָ���----------------------------------------------------------------
//----------------------------------------------------------------�ָ���----------------------------------------------------------------

//ͨ��Э��
/*
	������SDA,SCL����Ĭ�ϸߵ�ƽ����©���ģʽ
	����SDA����״̬Ϊ�ߵ�ƽ��SCL����״̬Ϊ�͵�ƽ

	��ʼ�źţ���SCLΪ��ʱ����SDA
	��ֹ�źţ���SCLΪ��ʱ����SDA
	�ź�֡��ɣ���ʼ + ��7λ��ַ+1λ��д�� + 1λӦ�� + 8λ����֡ + 1λӦ�� ... ��ֹ

	�����ٲû��ƣ������������ԣ�
				 ֻҪ��һ��Ϊ�ͣ�SDA��SCL��Ϊ��
				 ֻ��ȫ��Ϊ�ߣ�SDA��SCL��Ϊ��
*/
 

/**
  * @brief IIC��ʼ�ź�
  * @param None
  * @retval None
  */
void IICStart(iic_bus_t *bus)
{
	SDA_Output(bus,1);
	delay_us(2); //�ȱ�֤SDA��Ϊ��
	SCL_Output(bus,1);
	delay_us(0); //��ȷ������SCL
	
	SDA_Output(bus,0);  //��SCLΪ��ʱ����SDA
	delay_us(1);
	SCL_Output(bus,0);  //�ͷ�SCL
	delay_us(1);
}

/**
  * @brief IIC�����ź�
  * @param None
  * @retval None
  */
void IICStop(iic_bus_t *bus)
{
	//����SCL�͵�ƽʱ����SDA
	SCL_Output(bus,0);
	delay_us(2);
	SDA_Output(bus,0);
	delay_us(1);
	
	//��SCLΪ�ߵ�ƽʱ����SDA����ֹ�ź�
	SCL_Output(bus,1);
	delay_us(1);
	SDA_Output(bus,1);
	delay_us(1);
}

/**
  * @brief IIC�ȴ�ȷ���ź�
  * @param None
  * @retval ERROR -- Ӧ��ʱ; SUCCESS --Ӧ��ɹ�
  */
unsigned char IICWaitAck(iic_bus_t *bus)
{
	unsigned short cErrTime = 5;
	SDA_Input_Mode(bus);  //����Ϊ����ģʽ���ȴ��ӻ�����SDA��SDAĬ��Ϊ��
	SCL_Output(bus,1);
	
	while(SDA_Input(bus))  //�ȴ�����SDA
	{
		cErrTime--;
		delay_us(1);
		
		if(0 == cErrTime) //�ȴ�ʱ�䳬��5us�����ͣ���Ӧ��ʱ
		{
			SDA_Output_Mode(bus);
			IICStop(bus);
			return ERROR;
		}
		
	}
	
	SDA_Output_Mode(bus); //5us�����ͣ�Ӧ��ɹ�
	SCL_Output(bus,0);  //����SCL
	delay_us(2);
	
	return SUCCESS;
}

/**
  * @brief IIC����ȷ���ź�
  * @param None
  * @retval None
  */
void IICSendAck(iic_bus_t *bus)
{
	SDA_Output(bus,0); //��ת������,����Ӧ��
	delay_us(1);
	SCL_Output(bus,1); //������SCL����������
	delay_us(0);
	SCL_Output(bus,0); //�ָ�����״̬
	delay_us(1);
}

/**
  * @brief IIC���ͷ�ȷ���ź�
  * @param None
  * @retval None
  */
void IICSendNotAck(iic_bus_t *bus)
{
	SDA_Output(bus,1); //��ת�����ݣ����߲�Ӧ��
	delay_us(1);
	SCL_Output(bus,1); //������SCL����������
	delay_us(0);
	SCL_Output(bus,0); //�ָ�����״̬
	delay_us(1);
}

/**
  * @brief IIC����һ���ֽ�
  * @param cSendByte ��Ҫ���͵��ֽ�
  * @retval None
  */
void IICSendByte(iic_bus_t *bus,unsigned char cSendByte)
{
	unsigned char i = 8;
	while(i--)
	{
		SCL_Output(bus,0); //ȷ��SCL����
		delay_us(2);
		SDA_Output(bus,cSendByte &0x80); //cSendByte & 1000 0000ȡ���λ
		delay_us(1);
		
		cSendByte <<= 1; //��cSendByte����һλ����λ����
		delay_us(1);
		SCL_Output(bus,1); //ת����״̬����
		delay_us(1);
	}
	
	SCL_Output(bus,0);  //�ָ�����
	delay_us(2);
}

/**
  * @brief IIC����һ���ֽ�
  * @param None
  * @retval ���յ����ֽ�
  */
unsigned char IICReceiveByte(iic_bus_t *bus)
{
	unsigned char i = 8;
	unsigned char cR_Byte = 0;
	SDA_Input_Mode(bus);
	
	while(i--)  //��ȡ��λ
	{
		cR_Byte <<= 1; //����һλ���ý��յ����ݴ��������ۻ�
		SCL_Output(bus,0);  //ȷ������
		delay_us(2);
		
		SCL_Output(bus,1); //�ӻ����ڴ�ʱд��SDA
		delay_us(1);
		
		if(SDA_Input(bus))  //�жϴӻ�д������
		{
			cR_Byte |= 0x01;  //���Ϊ1�������ұߵ�Ϊд1
		}
	}
	
	SCL_Output(bus,0); //��ȡ��ɣ��ָ�����
	SDA_Output_Mode(bus);  //�ָ����
	
	return cR_Byte;
}


//----------------------------------------------------------------�ָ���----------------------------------------------------------------
//----------------------------------------------------------------�ָ���----------------------------------------------------------------
//----------------------------------------------------------------�ָ���----------------------------------------------------------------

//ͨ��ʱ��
/*
	������
		��дĳ���ӻ���ĳ���Ĵ����ĵ����ֽ�����
		��дĳ���ӻ���ĳ���Ĵ����Ķ���ֽ�����
*/

/**
  * @brief IICʱ����ӻ�ĳ���Ĵ���д��һ���ֽ�
  * @param address -> 7Ϊ�ӻ���ַ
		   reg   -> ��д��ļĴ���
		   data  -> ��д�������
  * @retval 0 -> ���ͳɹ�
			1 -> ����ʧ��
  */
uint8_t IIC_Write_One_Byte(iic_bus_t *bus, uint8_t address,uint8_t reg,uint8_t data)
{
	//�Ҵӻ�
	IICStart(bus);  
	IICSendByte(bus,address<<1);	 //7λ�ӻ���ַ + 0��д������   
	if(IICWaitAck(bus))	//�ȴ��ӻ�Ӧ��
	{
		IICStop(bus);		 
		return 1;		
	}
	
	//�ͼĴ�����ַ
	IICSendByte(bus,reg);
	IICWaitAck(bus);
	
	//������
	IICSendByte(bus,data);     						   
	IICWaitAck(bus);  		    	   
	IICStop(bus);
	delay_us(1);
	return 0;
}

/**
  * @brief IICʱ����ӻ�ĳ���Ĵ���д�����ֽ�
  * @param address -> 7Ϊ�ӻ���ַ
		   reg   -> ��д��ļĴ���
		   length -> ���������ݳ���,��λByte
		   buf[]  -> ���������ݻ�����
  * @retval 0 -> ���ͳɹ�
			1 -> ����ʧ��
  */
uint8_t IIC_Write_Multi_Byte(iic_bus_t *bus, uint8_t address,uint8_t reg,uint8_t length,uint8_t buff[])
{			
	unsigned char i; 	
	
	//�Ҵӻ�
	IICStart(bus);  
	IICSendByte(bus,address<<1);	    
	if(IICWaitAck(bus))
	{
		IICStop(bus);
		return 1;
	}
	
	//�ͼĴ�����ַ
	IICSendByte(bus,reg);
	IICWaitAck(bus);

	//���������
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
  * @brief IICʱ��Ӵӻ�ĳ���Ĵ�������һ���ֽ�
  * @param address -> 7Ϊ�ӻ���ַ
		   reg   -> ��д��ļĴ���
  * @retval data  -> ��ȡ��������
  */
unsigned char IIC_Read_One_Byte(iic_bus_t *bus, uint8_t address,uint8_t reg)
{
	unsigned char data;
	//�Ҵӻ�
	IICStart(bus);
	IICSendByte(bus,address<<1);
	IICWaitAck(bus);
	//�ҼĴ���
	IICSendByte(bus,reg);
	IICWaitAck(bus);
	
	//�ҵ�֮�������Ĵ�����ʼ��
	IICStart(bus);
	IICSendByte(bus,(address<<1)+1); //������
	IICWaitAck(bus);
	
	data = IICReceiveByte(bus); //����data��
	IICSendNotAck(bus);  //����֮��ظ���Ӧ��
	IICStop(bus);
	return data;
}

/**
  * @brief IICʱ����ӻ�ĳ���Ĵ�����������ֽ�
  * @param address -> 7Ϊ�ӻ���ַ
		   reg   -> ��д��ļĴ���
		   length -> ����ȡ�����ݳ���,��λByte
  * @retval buf[]  -> ��ȡ�������ݻ�����
  */
uint8_t IIC_Read_Multi_Byte(iic_bus_t *bus, uint8_t address, uint8_t reg, uint8_t length, uint8_t buff[])
{
	unsigned char i;
	//�Ҵӻ���ĳ���Ĵ���
	IICStart(bus);
	IICSendByte(bus,address<<1);
	if(IICWaitAck(bus))
	{
		IICStop(bus);		 
		return 1;		
	}
	IICSendByte(bus,reg);
	IICWaitAck(bus);
	
	//�ҵ��Ĵ�����ʼ��
	IICStart(bus);
	IICSendByte(bus,(address<<1)+1);
	IICWaitAck(bus);
	for(i=0;i<length;i++)
	{
		buff[i] = IICReceiveByte(bus); //����length - 1�ֽڵ�����ʱ�����ظ�Ӧ��
		if(i<length-1)
		{IICSendAck(bus);}
	}
	IICSendNotAck(bus); //�����һ���ֽڵ����ݣ����ظ�
	IICStop(bus);
	return 0;
}
