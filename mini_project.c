void Interrupt(){
  if (TMR2IF_bit){
    TMR2IF_bit = 0;
      portb++;
  }
}

void main() {
  T2CON	         = 0b01001110;
  PR2		 = 250;
  TMR2IE_bit	 = 1;
  INTCON	 = 0b11000000;
  trisb=0;
  portb=0;
  if (portb==255) portb=0;
  


}
