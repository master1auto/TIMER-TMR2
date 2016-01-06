char cnt=0;
void Interrupt(){
if (TMR2IF_bit){
cnt++;
TMR2IF_bit = 0;
}
}
void timer_init(){
T2CON = 0b01001110;
PR2 = 250;
TMR2IE_bit = 1;
INTCON = 0b11000000;
}

void main() {
ANSEL=0;
ANSELH=0;
timer_init();
TRISB=0;
PORTB=0;
while(1){
if(cnt == 50){
PORTB=~PORTB;
cnt=0;
}
}
}
