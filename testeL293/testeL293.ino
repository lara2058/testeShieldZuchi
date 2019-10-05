/*
  Teste l293d
    - Manda alguns valores pwm para o l293;
    - Checar se a tensão de saída corresponde com o valor pwm 
*/

#define ctrl 3        //pino pwm de controle de velocidade
#define dir_1 2       //pino1 que define o sentido
#define dir_2 6       //pino2 que define o sentido

//NUNCA DEIXAR DIR_1 E DIR_2 EM HIGH AO MESMO TEMPO !!!!!

int values[] = {0, 64, 128, 192, 255};    //checa para 0*vcc, 0.25*vcc, 0.5*vcc, 0.75*vcc e vcc.

void setup() {
  pinMode(ctrl, OUTPUT);    //todos os pinos são outputs
  pinMode(dir_1, OUTPUT);
  pinMode(dir_2, OUTPUT);
}

void loop() {
  //comentar o comando não desejado e descomentar o desejado
  char cmd = 'E';     //motor sentido esquerda
  //char cmd = 'D';     //motor sentido direita
  for(int i = 0; i <= 4; i++){  
    if(cmd == 'E'){                 //sentido 1
      digitalWrite(dir_1, HIGH);
      digitalWrite(dir_2, LOW);
      analogWrite(ctrl, values[i]); //define o pwm pelo valor em questão 
    }else if(cmd == 'D'){           //sentido 2
      digitalWrite(dir_1, LOW);
      digitalWrite(dir_2, HIGH);
      analogWrite(ctrl, values[i]); //define o pwm pelo valor em questão 
    }
    delay(5000);      //delay para dar tempo de medir a tensão de saída corretamente
  }
  analogWrite(ctrl, 0);   //finaliza o loop desligando a saida
}
