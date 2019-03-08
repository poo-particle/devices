int swtch = D0;
int val;
int lastValue;
String deviceName = 'device';
unsigned int nextTime = 0;

void setup() {
    Serial.println("Setting up...");
    pinMode(swtch, INPUT);

    Particle.variable("deviceName", deviceName, String);
}

void loop() {
    if(nextTime <= millis()) {
        val = digitalRead(swtch);

        if (val != lastValue) {
            String open = val == 1 ? "true" : "false";

            Particle.publish("poopi_door_" + deviceName, "{\"open\":"+ open +"}", 60, PRIVATE);

            lastValue = val;
        }

        nextTime = millis() + 1000;
    }
}
