/*
  Morse
  Turn the led on and buzz in morse code.
  Andres Hernandez - tonejito - tonejito@comunidad.unam.mx
 
  This code is released under the GPLv3 license.
 */

/* Pin 13 has an LED connected on most Arduino boards. */
int led    = 13;
int buzzer = 12;
 
/* letter A is ASCII 65 */
#define offset 65

/* Use PARIS or CODEX standard (time is in ms) */
#define PARIS 60
#define CODEX 50
#define time CODEX

/* Define morse code elements */
#define dit  1*time
#define dah  3*time
#define gap -1*time
#define let -3*time
#define wrd -7*time

/* Define each morse code element according to the ITU standard morse code */
int A[]={dit,dah};
int B[]={dah,dit,dit,dit};
int C[]={dah,dit,dah,dit};
int D[]={dah,dit,dit};
int E[]={dit};
int F[]={dit,dit,dah,dit};
int G[]={dah,dah,dit};
int H[]={dit,dit,dit,dit};
int I[]={dit,dit};
int J[]={dit,dah,dah,dah};
int K[]={dah,dit,dah};
int L[]={dit,dah,dit,dit};
int M[]={dah,dah};
int N[]={dah,dit};
int O[]={dah,dah,dah};
int P[]={dit,dah,dah,dit};
int Q[]={dah,dah,dit,dah};
int R[]={dit,dah,dit};
int S[]={dit,dit,dit};
int T[]={dah};
int U[]={dit,dit,dah};
int V[]={dit,dit,dit,dah};
int W[]={dit,dah,dah};
int X[]={dah,dit,dit,dah};
int Y[]={dah,dit,dah,dah};
int Z[]={dah,dah,dit,dit};

/* Define morse code as an array of l */
int* code[]=
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

void print_output(int value)
{
  /* Light speed is way faster than sound speed */
  digitalWrite( buzzer , value);
  digitalWrite( led , value);  
}

void print_morse(int element)
{
 switch (element)
 {
  case dit:
    print_output(HIGH);
    delay(dit);
    print_output(LOW);
    delay(dit);
    break;
  case dah:
    print_output(HIGH);
    delay(dah);
    print_output(LOW);
    delay(dit);
    break;
  case gap:
    delay((-gap));
    break;
  case let:
    delay((-let));
    break;
  case wrd:
    delay((-wrd));
    break;
 }
}

void alphabet()
{
  int i,j=0;
  /* Iterate on each letter */
  for (i=0 ; i<sizeof(code_length)/sizeof(int) ; i++ )
  {
    /* Iterate on each letter element */
    for (j=0 ; j<code_length[i] ; j++)
    {
      print_morse(code[i][j]);
    }
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

// the setup routine runs once when you press reset:
void setup()
{                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{ 
  /*
  print_letter('S');
  print_morse(gap);
  print_letter('O');
  print_morse(gap);
  print_letter('S');
  print_morse(wrd);
*/
  alphabet();
  
}

