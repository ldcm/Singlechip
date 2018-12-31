 #include <reg51.h>

 unsigned char s[] = "齐鲁工业大学";


// 延时函数
void Delay10ms(unsigned int c)
{
   unsigned char a, b;

    //--c已经在传递过来的时候已经赋值了，所以在for语句第一句就不用赋值了--//
    for (;c>0;c--)
    {
        for (b=38;b>0;b--)
        {
            for (a=130;a>0;a--);
        }          
    }       
}


// 初始化串口中断
void UsartInit()
{
    EA=0; //总中断关闭
    SCON = 0x50; // 控制寄存器
    PCON = 0x80;  // 记住就行，0x80
    TMOD = 0x20; // TMOD设置定时计数器的工作方式和功能 ，采用定时器1，工作方式2
    TH1 = 0xF3;     // 设置高八位
    TL1 = 0xF3;     // 设置低八位
    TR1=1;    // 使定时器1开始工作
    ES=1;  // 开启串口中断
    EA=1;  // 开启总中断权限
}

// 主函数
void main()
{
    // 初始化
    UsartInit();
    while(1)
    {      unsigned int i;
        // 发送数组数据
        for(i=0;i<12;i++)
        {
            // 将SBUF中的数据发送出去
            SBUF = s[i];
            // 如果发送完成，TI自动置1
            while(!TI);
            // 发送完成，软件置0
            TI=0;
        }
        //延时
        Delay10ms(10);
    }
}