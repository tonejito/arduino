/*
	https://en.wikipedia.org/wiki/Morse_code
*/

#include <stdio.h>
#include <unistd.h>

#define offset 65

/* Use PARIS or CODEX standard (time is in ms) */
#define PARIS 60
#define CODEX 50
#define time PARIS

/* Define morse code elements */
enum morse
{
  dit, /* short mark, dot or "dit" (·) — "dot duration" is one time unit long */
  dah, /* longer mark, dash or "dah" (–) — three time units long */
  gap, /* inter-element gap between the dots and dashes within a character — one dot duration or one unit long */
  let, /* short gap (between letters) — three time units long */
  wrd, /* medium gap (between words) — seven time units long */
};

/* Define each morse code element */
/*
AA		{dit,dah,dit,dah}
AR		{dit,dah,dit,dah,dit}
AS		{dit,dah,dit,dit,dit}
BK		{dah,dit,dit,dit,dah,dit,dah}
BT		{dah,dit,dit,dit,dah}
CL		{dah,dit,dah,dit,dit,dah,dit,dit}
CT		{dah,dit,dah,dit.dah}
DO		{dah,dit,dit,dah,dah,dah}
KN		{dah,dit,dah,dah,dit}
SK		{dit,dit,dit,dah,dit,dah}
SN		{dit,dit,dit,dah,dit}
*/
/*
 !	33	{dit,dit,dit,dit,dit}
 "	34	{dit,dah,dit,dit,dah,dit}
 #	35	{}
 $	36	{dit,dit,dit,dah,dit,dit,dah}
 %	37	{}
 &	38	{dit,dah,dit,dit,dit}
 '	39	{dit,dah,dah,dah,dah,dit}
 (	40	{dah,dit,dah,dah,dit}
 )	41	{dah,dit,dah,dah,dit,dah}
 *	42	{}
 +	43	{dit,dah,dit,dah,dit}
 ,	44	{dah,dah,dit,dit,dah,dah}
 -	45	{dah,dit,dit,dit,dit,dah}
 .	46	{dit,dah,dit,dah,dit,dah}
 /	47	{dah,dit,dit,dah,dit}
*/
/*
 0	48	{dah,dah,dah,dah,dah}
 1	49	{dit,dah,dah,dah,dah}
 2	50 	{dit,dit,dah,dah,dah}
 3	51 	{dit,dit,dit,dah,dah}
 4	52 	{dit,dit,dit,dit,dah}
 5	53 	{dit,dit,dit,dit,dit}
 6	54 	{dah,dit,dit,dit,dit}
 7	55 	{dah,dah,dit,dit,dit}
 8	56 	{dah,dah,dah,dit,dit}
 9	57 	{dah,dah,dah,dah,dit}
*/
/*
 :	58	{dah,dah,dah,dit,dit,dit}
 ;	59	{dah,dit,dah,dht,dah,dit}
 <	60	{}
 =	61	{dah,dit,dit,dit,dah}
 >	62	{}
 ?	63	{dit,dit,dah,dah,dit,dit}
 @	64	{dit,dah,dah,dit,dah,dit}
*/
enum morse A[]={dit,dah};
enum morse B[]={dah,dit,dit,dit};
enum morse C[]={dah,dit,dah,dit};
enum morse D[]={dah,dit,dit};
enum morse E[]={dit};
enum morse F[]={dit,dit,dah,dit};
enum morse G[]={dah,dah,dit};
enum morse H[]={dit,dit,dit,dit};
enum morse I[]={dit,dit};
enum morse J[]={dit,dah,dah,dah};
enum morse K[]={dah,dit,dah};
enum morse L[]={dit,dah,dit,dit};
enum morse M[]={dah,dah};
enum morse N[]={dah,dit};
enum morse O[]={dah,dah,dah};
enum morse P[]={dit,dah,dah,dit};
enum morse Q[]={dah,dah,dit,dah};
enum morse R[]={dit,dah,dit};
enum morse S[]={dit,dit,dit};
enum morse T[]={dah};
enum morse U[]={dit,dit,dah};
enum morse V[]={dit,dit,dit,dah};
enum morse W[]={dit,dah,dah};
enum morse X[]={dah,dit,dit,dah};
enum morse Y[]={dah,dit,dah,dah};
enum morse Z[]={dah,dah,dit,dit};
/*
 _	95	{dit,dit,dah,dah,dit,dah}
*/

/* Define morse code as an array of element */
enum morse* code[]=
{
  A,B,C,D,E,
  F,G,H,I,J,
  K,L,M,N,O,
  P,Q,R,S,T,
  U,V,W,X,Y,Z
};

/* Define each element length */
int code_length[26]=
{
 2,4,4,3,1,
 4,4,4,2,4,
 3,4,2,2,3,
 4,4,3,3,1,
 3,4,3,4,4,4
};


void print_morse(enum morse element)
{
 switch (element)
 {
  case dit:
    printf("%c",'.');
    break;
  case dah:
    printf("%c",'-');
    break;
  case gap:
    usleep(time*1000);
    break;
  case let:
    usleep(3*time*1000);
    break;
  case wrd:
    usleep(7*time*1000);
    break;
 }
}

void alphabet()
{
  int i,j=0;
  /* Iterate on each letter */
  for (i=0 ; i<sizeof(code_length)/sizeof(int) ; i++ )
  {
    printf("%c\t",i+offset);
    /* Iterate on each letter element */
    for (j=0 ; j<code_length[i] ; j++)
    {
      print_morse(code[i][j]);
      print_morse(gap);
    }
    printf("%s","\n");
    print_morse(let);
  }
}

void print_letter(char letter)
{
  int pos = letter-offset;
  int morse_letter = code_length[pos];
  int j=0;
  /* Iterate on each letter element */
  for (j=0 ; j<morse_letter ; j++)
  {
    print_morse(code[pos][j]);
    print_morse(gap);
  }
}

int main(int argc,char* argv[])
{
 int i=0;
 char* msg=argv[1];

// alphabet();
/*
 for (i=32;i<127;i++)
   printf("%c,%d\n",i,i);
*/

 for (i=0;i<sizeof(msg)/sizeof(char);i++)
 {
   printf("%c\t",msg[i]);
   print_letter(msg[i]);
   printf("\n");
 }

 return 0;
}

