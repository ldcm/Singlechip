 #include <reg51.h>

 unsigned char s[] = "��³��ҵ��ѧ";


// ��ʱ����
void Delay10ms(unsigned int c)
{
   unsigned char a, b;

    //--c�Ѿ��ڴ��ݹ�����ʱ���Ѿ���ֵ�ˣ�������for����һ��Ͳ��ø�ֵ��--//
    for (;c>0;c--)
    {
        for (b=38;b>0;b--)
        {
            for (a=130;a>0;a--);
        }          
    }       
}


// ��ʼ�������ж�
void UsartInit()
{
    EA=0; //���жϹر�
    SCON = 0x50; // ���ƼĴ���
    PCON = 0x80;  // ��ס���У�0x80
    TMOD = 0x20; // TMOD���ö�ʱ�������Ĺ�����ʽ�͹��� �����ö�ʱ��1��������ʽ2
    TH1 = 0xF3;     // ���ø߰�λ
    TL1 = 0xF3;     // ���õͰ�λ
    TR1=1;    // ʹ��ʱ��1��ʼ����
    ES=1;  // ���������ж�
    EA=1;  // �������ж�Ȩ��
}

// ������
void main()
{
    // ��ʼ��
    UsartInit();
    while(1)
    {      unsigned int i;
        // ������������
        for(i=0;i<12;i++)
        {
            // ��SBUF�е����ݷ��ͳ�ȥ
            SBUF = s[i];
            // ���������ɣ�TI�Զ���1
            while(!TI);
            // ������ɣ������0
            TI=0;
        }
        //��ʱ
        Delay10ms(10);
    }
}