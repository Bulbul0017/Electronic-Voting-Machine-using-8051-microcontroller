#include<reg51.h>
#include<blcd.h>

sbit s0=P3^0;
sbit s1=P3^1;
sbit s2=P3^2;
sbit s3=P3^3;
sbit s4=P3^4;
sbit s5=P3^5;
sbit lr=P1^2;
sbit lg=P1^3;
sbit buz =P1^4;

void cnt();
void disp();
void winner();
conv(char x);
void del1(int d);
int c1,c2,c3,c4=0;
void main(void)
{
	P3=0x00;
	lcdinit();
	writecmd(0x84);
	writestr("WELCOME");
	del1(1);
	while(1)
	{
		if(s4==1)
		{
			cnt();
		}
		if(s5==1)
		{
			disp();
			winner();
		}
	}
}

void cnt()
{
	lg =0;
	lcdinit();
	writecmd(0x83);
	writestr("WELCOME");
	writecmd(0xc0);
	writestr("'Press a Button'");
	while(1)
	{
		if(s0==1)
		{
			c1++;break;
		}
		if(s1==1)
		{
			c2++;break;
		}
		if(s2==1)
		{
			c3++;break;
		}
		if(s3==1)
		{
			c4++;break;
		}
	}
lr=0;
	buz = 0;
lcdinit();
	writecmd(0x80);
	writestr("Voting Completed");
del1(8);
	lcdinit();
	lr=1;
	lg=1;
	buz = 1;
		writecmd(0x84);
		writestr("Thanks");
	del1(1);
}

void disp()
{
int f=123;
char count;
lcdinit();
writecmd(0x84);
writestr ("Result");
del1(8);

/*candidate l*/

lcdinit();
writecmd(0x80);
writestr("Candidate1");
writecmd(0xc0);
count=conv(c1);
del1(18);

/*candidate2*/
lcdinit();
writecmd(0x80);
writestr("Candidate2");
writecmd(0xc0);
count=conv(c2);
del1(18);

/*candidate3*/

lcdinit();
writecmd(0x80);
writestr("Candidate3");
writecmd(0xc0);
count=conv(c3);
del1(18);

/*candidate4*/

lcdinit();
writecmd(0x80);
writestr("Candidate4");
writecmd(0xc0);
count=conv(c4);
del1(18);
}

void del1(int d)
{
int k,j;
for(k=0; k<d; k++)
{
for(j=0;j<20000;j++);
}
}
conv(char x)
{
int i;
char a[10];
char t;
char temp;

temp=x;
a[0]=temp/100;
temp=temp%100;
a[1]=temp/10;
a[2]=temp%10;

for(i=0;i<3;i++)
{
t=(0x30 + a[i]);
writedata(t);
}
return 0;
}

void winner()
{
if(c1>c2 && c1>c3 && c1>c4)
{
lcdinit();
writecmd(0x83);
writestr("WINNER");
writecmd(0xc0);
writestr("Candidate 1");
}
else if(c2>c1 && c2>c3 && c2>c4)
{
lcdinit();
writecmd(0x83);
writestr("WINNER");
writecmd(0xc0);
writestr("Candidate 2");
}
else if(c3>c1 && c3>c2 && c3>c4)
{
lcdinit();
writecmd(0x83);
writestr("WINNER");
writecmd(0xc0);
writestr("Candidate 3");
}
else if(c1>c2 && c1>c3 && c1>c4)
{
lcdinit();
writecmd(0x83);
writestr("WINNER");
writecmd(0xc0);
writestr("Candidate 4");
}
else
{
lcdinit();
writecmd(0x85);
writestr("DRAW");
}
}


