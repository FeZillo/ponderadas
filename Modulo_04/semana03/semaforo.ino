// Define as portas lógicas
short int RED_PIN = 5;
short int YELLOW_PIN = 6;
short int GREEN_PIN = 7;


class Semaforo{
  private:
    short int RED; // Pino Vermelho
    short int YELLOW; // Pino Amarelo
    short int GREEN; // Pino Verde
  public:
    // Constructor
    Semaforo(int* pinoR, int* pinoY, int* pinoG){
      this->RED = &pinoR;
      this->YELLOW = &pinoY;
      this->GREEN = &pinoG;
      init();
    }

    // Setup
    void init(){
      pinMode(this->RED, OUTPUT);
      pinMode(this->YELLOW, OUTPUT);
      pinMode(this->GREEN, OUTPUT);
    }

    // Liga o verde e desliga os outros
    void verde(){
      digitalWrite(this->RED, LOW);
      digitalWrite(this->YELLOW, LOW);
      digitalWrite(this->GREEN, HIGH);
    }

    // Liga o amarelo e desliga os outros
    void amarelo(){
      digitalWrite(this->RED, LOW);
      digitalWrite(this->YELLOW, HIGH);
      digitalWrite(this->GREEN, LOW);
    }

    // Liga o vermelho e desliga os outros
    void vermelho(){
      digitalWrite(this->RED, HIGH);
      digitalWrite(this->YELLOW, LOW);
      digitalWrite(this->GREEN, LOW);
    }

    // Começa o ciclo do semáforo
    void ligar() {
      vermelho();
      delay(6000);
      amarelo();
      delay(2000);
      verde();
      delay(2000);
      verde();
      delay(2000);
      amarelo();
      delay(2000);
    }

};

void setup() {
  
}

Semaforo semaforo(&RED_PIN, &YELLOW_PIN, &GREEN_PIN); // Instancia o objeto

void loop() {
  semaforo.ligar(); // Realiza o ciclo completo
}

