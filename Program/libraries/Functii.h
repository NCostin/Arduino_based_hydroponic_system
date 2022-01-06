#ifndef functii_h    // Put these two lines at the top of your file.
#define functii_h

int pin_senzorDHT= 51;
int pin_senzor_temperatura_apa=43;
int pin_senzor_nivel_apa=A14;
int pin_senzor_EC;

//Pentru senzorul de pH
int pin_senzor_pH = A15;
int samples = 10;
float adc_resolution = 1024.0;
float ph;
//

OneWire oneWire(pin_senzor_temperatura_apa);
DallasTemperature sensors(&oneWire);
DHT dht(pin_senzorDHT,DHT22);

float temp;
float humid;
float wtemp;
int nivel_apa;
int EC=analogRead(pin_senzor_EC);

void wlevel()
{
  
nivel_apa=analogRead(pin_senzor_nivel_apa);

};


void tempval()
{
  
temp=dht.readTemperature();

};

void humidity()
{
  
  humid=dht.readHumidity();

};

void watertemp()
{
  
sensors.requestTemperatures();
wtemp=sensors.getTempCByIndex(0);

};

void Val_pH(){
  
       int nr_masuratori=0;

    for (int i = 0; i < 10; i++)
    {
        nr_masuratori += analogRead(pin_senzor_pH);
        delay(10);

    }
    float voltage = 5 / adc_resolution * nr_masuratori/samples;
   ph = 7 + ((2.5 - voltage) / 0.18);

    };
#endif
