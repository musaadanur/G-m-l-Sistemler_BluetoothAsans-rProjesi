int a=3;
int b=2;
int c=8;
int d=7;
int e=6;
int f=4;
int g=5;
 
const int in1 = 13;
const int in2 = 12;

char gelen; 

int gidilecekKat=0;
int bulunduguKat=0;

void n0 ()
{
digitalWrite(a,LOW); 
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH); 

}
void n1 ()
{
digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH); 

}
void n2 ()
{
digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);

}

void ekranayaz(int yaz){
  if(yaz==0){
    n0();
    
  }else if (yaz==1){
    n1();
  }else{
    n2();
  }
}
void Up(int y){
  
  for(int i=0; i<y; i++){
    
    digitalWrite(in2, HIGH);
    delay(2900);
    digitalWrite(in2,  LOW);
     bulunduguKat+=1;
    ekranayaz(bulunduguKat) ; 
     
   
                    }
}



void Down(int y){
 
  for( int i=0; i<y; i++){           
      digitalWrite(in1, HIGH);
      delay(2700);
      digitalWrite(in1,  LOW); 
      bulunduguKat-=1;
      ekranayaz(bulunduguKat); 
         
      
      
                         }
}


void Go(int x){
  
 if((x-bulunduguKat)<0){
      Down((x-bulunduguKat)*(-1));
 }else if((x-bulunduguKat)>0){
      Up(x-bulunduguKat);
 }else{
      int gidilecekKat=0;
      int bulunduguKat=0;
      }
}
void setup()
{ 
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);

}

  

void loop()
{
   if(Serial.available() > 0){
          gelen = Serial.read();
 
                             }
  switch (gelen)
  {
    case '0': 
      gidilecekKat=0;
      break;

    case '1':
      gidilecekKat=1;
      break;

    case '2':
      gidilecekKat=2;
      break;       
   
  }
  ekranayaz(bulunduguKat);
  Go(gidilecekKat); 
}

