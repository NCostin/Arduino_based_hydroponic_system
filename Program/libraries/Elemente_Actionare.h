#ifndef Elemente_h    // Put these two lines at the top of your file.
#define Elemente_h

int pin_pompa_recirculare=6;
int pin_pompa_aerare=9;
int pin_pompa_nutrienti=2;
int pin_pompa_acid=3;
int pin_pompa_baza=4;
int pin_lumina= 7;

void lumina_ON()
{
digitalWrite(pin_lumina,HIGH);
}

void lumina_OFF()
{
  digitalWrite(pin_lumina,LOW);
  }


void P_Recirculare_ON()
{
analogWrite(pin_pompa_recirculare,255);
};

void P_Recirculare_OFF()
{
analogWrite(pin_pompa_recirculare,0);
};

void P_Nutrienti_ON()
{

  analogWrite(pin_pompa_nutrienti,90);

};

void P_Nutrienti_OFF()
{

analogWrite(pin_pompa_nutrienti,0);

};

void P_Acid_ON()
{

  analogWrite(pin_pompa_acid,90);

};

void P_Acid_OFF()
{
  analogWrite(pin_pompa_acid,0);
};

void P_Baza_ON()
{
analogWrite(pin_pompa_baza,90);
}
  
void P_Baza_OFF()
{

  analogWrite(pin_pompa_baza,0);
};

void P_aerare_ON()
{
  
analogWrite(pin_pompa_aerare,136);

};

void P_aerare_OFF()
{
digitalWrite(pin_pompa_aerare,LOW);
};


#endif
