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
timer_init();
trisb=0;
portb=0;

if(cnt == 50){
PORTB=~PORTB;
cnt=0;
}
}
