/*
Lights for the Cars
*/
int redCarLight = 13;
int yellowCarLight = 12;
int greenCarLight = 11;

/*
Lights for the Pedestrians
*/
int redPedestrianLight = 3;
int greenPedestrianLight = 2;

int button = 7; 
int crossTime = 3000;
unsigned long changeTime;

void setup() {
    //initialize the timer
    changeTime = millis();
    //initialize the pins
    pinMode(redCarLight, OUTPUT);
    pinMode(yellowCarLight, OUTPUT);
    pinMode(greenCarLight, OUTPUT);
    pinMode(redPedestrianLight, OUTPUT);
    pinMode(greenPedestrianLight, OUTPUT);
    pinMode(button, INPUT);
    //turning on the green light
    digitalWrite(greenCarLight, HIGH);
    digitalWrite(redPedestrianLight, HIGH);
    digitalWrite(redCarLight, LOW);
    digitalWrite(yellowCarLight, LOW);
    digitalWrite(greenPedestrianLight, LOW);
    Serial.begin(9600);
}

void loop() {
    //check the state of the button, whether pressed or not
    int state = digitalRead(button);
    Serial.println(state);
    //if the button is pressed and if 5 seconds have passed since the last button press
    if (state == HIGH && (millis() - changeTime) > 5000) {
        //call function to change the lights
        changeLights();
    }
}

void changeLights() {
    digitalWrite(greenCarLight,LOW);
    digitalWrite(yellowCarLight, HIGH);
    delay(2000);

    digitalWrite(yellowCarLight, LOW);
    digitalWrite(redCarLight, HIGH);
    
    digitalWrite(redPedestrianLight, LOW);
    digitalWrite(greenPedestrianLight, HIGH);
    delay(crossTime);

    //flashing the green pedestrian LED
    for (int i = 0; i < 10; i++) {
        digitalWrite(greenPedestrianLight, LOW);
        delay(100);
        digitalWrite(greenPedestrianLight, HIGH);
        delay(100);
    }

    digitalWrite(greenPedestrianLight, LOW);
    digitalWrite(redCarLight, LOW);
    digitalWrite(redPedestrianLight, HIGH);
    digitalWrite(greenCarLight, HIGH);

    changeTime = millis();
}