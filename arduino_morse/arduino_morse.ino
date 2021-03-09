char letter;
int pause = 200; // Temps de pause en ms
byte pin = 3; // Pin de la led du morse
byte Pstop = 4; // Pin de la led de la pause

void setup() {
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
  pinMode(Pstop, OUTPUT);
}

void loop() {
  if(Serial.available()){ // Si il y a du texte
    letter = Serial.read();

    //Transforme toute lettre majuscule en minuscule
    if(isAlpha(letter) && isUpperCase(letter)){
      letter = letter + 32;
    }
    // Test toutes les lettres
    switch (letter) {
      case 'a':
        Serial.print(letter);
        point(); trait();
        break;
      case 'b':
        Serial.print(letter);
        trait(); point(); point();
        break;
      case 'c':
        Serial.print(letter);
        trait(); point(); trait(); point();
        break;
      case 'd':
        Serial.print(letter);
        trait(); point(); point();
        break;
      case 'e':
        Serial.print(letter);
        point();
        break;
      case 'f':
        Serial.print(letter);
        point(); point(); trait(); point();
        break;
      case 'g':
        Serial.print(letter);
        trait(); trait(); point();
        break;
      case 'h':
        Serial.print(letter);
        point(); point(); point(); point();
        break;
      case 'i':
        Serial.print(letter);
        point(); point();
        break;
      case 'j':
        Serial.print(letter);
        point(); trait(); trait(); trait();
        break;
      case 'k':
        Serial.print(letter);
        trait(); point(); trait();
        break;
      case 'l':
        Serial.print(letter);
        point(); trait(); point(); point();
        break;
      case 'm':
        Serial.print(letter);
        trait(); trait();
        break;
      case 'n':
        Serial.print(letter);
        trait(); point();
        break;
      case 'o':
        Serial.print(letter);
        trait(); trait(); trait();
        break;
      case 'p':
        Serial.print(letter);
        point(); trait(); trait(); point();
        break;
      case 'q':
        Serial.print(letter);
        trait(); trait(); point(); trait();
        break;
      case 'r':
        Serial.print(letter);
        point(); trait(); point();
        break;
      case 's':
        Serial.print(letter);
        point(); point(); point();
        break;
      case 't':
        Serial.print(letter);
        trait();
        break;
      case 'u':
        Serial.print(letter);
        point(); point(); trait();
        break;
      case 'v':
        Serial.print(letter);
        point(); point(); point(); trait();
        break;
      case 'w':
        Serial.print(letter);
        point(); trait(); trait();
        break;
      case 'x':
        Serial.print(letter);
        trait(); point(); point(); trait();
        break;
      case 'y':
        Serial.print(letter);
        trait(); point(); trait(); trait();
        break;
      case 'z':
        Serial.print(letter);
        trait(); trait(); point(); point();
        break;
        
      case '0':
        Serial.print(letter);
        trait(); trait(); trait(); trait(); trait();
        break;
      case '1':
        Serial.print(letter);
        point(); trait(); trait(); trait(); trait();
        break;
      case '2':
        Serial.print(letter);
        point(); point(); trait(); trait(); trait();
        break;
      case '3':
        Serial.print(letter);
        point(); point(); point(); trait(); trait();
        break;
      case '4':
        Serial.print(letter);
        point(); point(); point(); point(); trait();
        break;
      case '5':
        Serial.print(letter);
        point(); point(); point(); point(); point();
        break;
      case '6':
        Serial.print(letter);
        trait(); point(); point(); point(); point();
        break;
      case '7':
        Serial.print(letter);
        trait(); trait(); point(); point(); point();
        break;
      case '8':
        Serial.print(letter);
        trait(); trait(); trait(); point(); point();
        break;
      case '9':
        Serial.print(letter);
        trait(); trait(); trait(); trait(); point();
        break;
      
      case ' ':
        Serial.println();
        digitalWrite(Pstop, HIGH);
        delay(pause * 2);
        break;
      case '\n':
        Serial.println();
        digitalWrite(Pstop, HIGH);
        delay(pause * 4); 
        break;
    }
    digitalWrite(Pstop, HIGH);
    delay(pause / 2);
    digitalWrite(Pstop, LOW);
  }

}

// Fonction du trait et du point
void trait(){
  digitalWrite(pin, HIGH);
  // Un trait est trois fois plus long qu'un point
  delay(pause * 3);
  digitalWrite(pin, LOW);
  delay(pause);
}
void point(){
  digitalWrite(pin, HIGH);
  delay(pause);
  digitalWrite(pin, LOW);
  delay(pause);
}
