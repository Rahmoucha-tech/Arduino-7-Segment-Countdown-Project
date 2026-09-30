int seg[7] = {2, 3, 4, 5, 6, 7, 8};
int bouton = 9;


// Table des chiffres 9 -> 0
// Ordre : A B C D E F G
byte chiffres[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};


// Fonction pour éteindre tous les segments
void eteindre()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg[i], HIGH);
  }
}


// Fonction pour afficher un chiffre
void afficherChiffre(int n)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg[i], chiffres[n][i]);
  }
}


// Fonction pour afficher A
void afficherA()
{
  // A B C D E F G
  byte A[7] = {0,0,0,1,0,0,0};

  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg[i], A[i]);
  }
}


// Fonction pour afficher C
void afficherC()
{
  // A B C D E F G
  byte C[7] = {0,1,1,0,0,0,1};

  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg[i], C[i]);
  }
}


// Fonction pour afficher E
void afficherE()
{
  // A B C D E F G
  byte E[7] = {0,1,1,0,0,0,0};

  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg[i], E[i]);
  }
}



void setup()
{
  // Segments en sortie
  for (int i = 0; i < 7; i++)
  {
    pinMode(seg[i], OUTPUT);
  }

  // Bouton avec résistance de tirage vers le haut
  pinMode(bouton, INPUT_PULLUP);

  // Éteindre au démarrage
  eteindre();
}



void loop()
{
  if (digitalRead(bouton) == LOW)
  {
    // Afficher 9 jusqu'à 0
    for (int n = 9; n >= 0; n--)
    {
      afficherChiffre(n);
      delay(500);
    }
  }

  else
  {
    // Si bouton non appuyé :
    // A -> C -> E

    afficherA();
    delay(500);

    afficherC();
    delay(500);

    afficherE();
    delay(500);
  }
}