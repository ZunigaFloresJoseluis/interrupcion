char contador=0,texto[4], respaldo,respaldoC;

void main() {
       ANSELH=0x05;
       ANSELH=0x03 ;
       GIE_bit=1;
       NOT_RBPU_bit=0;

       INTEDG_bit=1;
       respaldo=TRISB;             //Guardar el estado de TRISB.
TRISB0_bit=1;               //RB0 como entrada.
TRISB1_bit=1;
INTE_bit=1;
TRISC=0;
PORTC=0;
respaldoC=PORTC;

              while (1){
 asm SLEEP                  //Entra en modo SLEEP.
 asm NOP                    //Se despierta por INT, ejecuta NOP y
                            //salta a "interrupt".




 ByteToStr(contador,texto); //Retorna de "interrupt" y continúa.

 TRISB=respaldo;            //Restaurar TRISB.

 respaldo=TRISB;            //Guardar el estado de TRISB.
 PORTB=0;
 TRISB0_bit=1;              //RB0 como entrada.



}




}


void interrupt(){
      if(PORTB.F0==1){PORTC.F0=1; }

/*
 if(PORTB.F0==0){PORTC.F0=1;}
 if(PORTB.F1==0){PORTC.F1=1;}

    // while (RB0_bit==0);

  */
 /*
 if (RB0_bit==0)PORTC=1;  //Pulsador presionado.
 else {PORTC=0;}

     PORTC=0;
 if(RB0_bit==1)PORTC=0;*/

 INTF_bit=0;

}