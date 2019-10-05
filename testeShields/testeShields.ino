/*
  Teste shields de motor VSSS

  Verifica se um shield apresenta o funcionamento correto:
    - Através de dois vetores obtem-se o sentido e o valor pwm para as rodas
      -> Sentido D (direita) ou E (esquerda)
      -> Valor de 0 a 255 (verificar com o voltímetro se a tensão nos terminais equivale ao pwm)
    - Verificar qual o sentido em relação a qual pino fica em HIGH (Xle e Xri)
*/


#define pwm_left 9          //definindo pinos para ajustar a velocidade do motor
#define pwm_right 6         

#define dir_left 8          //pino que define o sentido do motor esquerdo
#define dir_right 11        //pino que define o sentido do motor direito

/*
dir_left  ->  Frente = HIGH   Trás = LOW
dir_right ->  Frente = LOW    Trás = HIGH
*/

int values[] = {0, 64, 128, 192, 255};

void setup() {
  Serial.begin(4800);
  pinMode(dir_right, OUTPUT);       //configurando o pino 'dir_right' como  saida
  pinMode(pwm_right, OUTPUT);       //configurando o pino 'pwm_right' como saída
  pinMode(dir_left, OUTPUT);        //configurando o pino 'dir_left' como saída
  pinMode(pwm_left, OUTPUT);        //configurando o pino 'pwm_left' como saída
  digitalWrite(dir_right, LOW);     //Inicializa o pino 'dir_right' como low
  digitalWrite(dir_left, HIGH);     //Inicializa o pino 'dir_left' como high
}

void loop() {
  //char cmd = 'D';
  char cmd = 'E';
  for(int j=0; j<=4; j++){
      int value = values[j];
      switch (cmd)
      {
        /*case 'T': // Comando para andar para tras
          {
            digitalWrite(dir_right, LOW);
            digitalWrite(dir_left, HIGH);
            analogWrite(pwm_right, value);
            analogWrite(pwm_left, value);
            delay(100);
            break;
          }
        case 'F': // Comando para andar para frente
          {
            digitalWrite(dir_right, HIGH);
            digitalWrite(dir_left, LOW);
            analogWrite(pwm_right, value);
            analogWrite(pwm_left, value);
            delay(100);
            break;
          }*/
        case 'E': // Comando para andar para esquerda
          {
            digitalWrite(dir_right, HIGH);
            digitalWrite(dir_left, HIGH);
            analogWrite(pwm_right, value);
            analogWrite(pwm_left, 0);
            delay(5000);
            break;
          }
  
        case 'D': // Comando para andar para direita
          {
            digitalWrite(dir_right, LOW);
            digitalWrite(dir_left, LOW);
            analogWrite(pwm_right, 0);
            analogWrite(pwm_left, value);
            delay(5000);
            break;
          }
      }
    }
    analogWrite(pwm_right, 0);        //fazendo o pino pwm_right ficar com o valor 0
    analogWrite(pwm_left, 0);
}
