void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void ReturnHome(void);
void writestr(unsigned char *word);
sbit RS=P1^0;
sbit E=P1^1;
void lcdinit (void)
{
writecmd(0x38);   //function set
writecmd(0x0c);   //display on, cursor off, blink of
writecmd(0x01);   //clear display
writecmd(0x06);   //entry mode, set increment
}
void writecmd(int z)
{
RS=0;          //RS=> RS=0
P2=z;          //Data transfer
E =1;          // => E = 1
delay(150);
E =0;          // => E = 0
delay(150);
}

void writedata(char t)
{
RS = 1;  // => RS=1
P2=t;  //Data transfer
E =1;          // => E = 1
delay(150);
E =0;          // => E = 0
delay(150);
}
void writestr(unsigned char *word)
{
int i;
for (i=0;word[i]!=0;i++) //Data writing of the LCD 
{
writedata(word[i]);
}
}
void delay(int a)
{
  int i;
  for(i=0;i<a;i++)
  {
    }  
}
