#include <Arduino.h>
#include <Servo.h>

int myFunction(int, int);

int trigPin = D1;
int echoPin = D0;
int led = D3;
Servo myservo;
long duration ; 
int distance ;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(D4);

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration =  pulseIn(echoPin,HIGH);
  distance = 0.034 * duration / 2;
  
  if(distance <= 50 ){
    myservo.write(90);
  }  else{
      myservo.write(0);
    }
  

  delay (1000);
}


// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

/*
Penjelasan 

Setup : 
pinMode(led, OUTPUT);: Mengatur pin led (D3).
pinMode(trigPin, OUTPUT);: Mengatur pin trigPin (D1).
pinMode(echoPin, INPUT);: Mengatur pin echoPin (D0).
myservo.attach(D4);: Mengatur servo ke pin D4.

Loop : 
DigitalWrite(trigPin, LOW);: Mengatur trigPin ke LOW untuk memastikan tidak ada sinyal yang dikirim.
DelayMicroseconds(5);: Menunggu 5 mikrodetik.
DigitalWrite(trigPin, HIGH);: Mengirimkan sinyal trigger dengan mengatur trigPin ke HIGH.
DelayMicroseconds(10);: Menunggu 10 mikrodetik.
DigitalWrite(trigPin, LOW);: Mengakhiri sinyal trigger.
Duration = pulseIn(echoPin, HIGH);: Mengukur durasi sinyal echo yang diterima oleh echoPin.
Distance = 0.034 * duration / 2;: Menghitung jarak berdasarkan durasi sinyal echo. Konstanta 0.034 digunakan untuk mengkonversi waktu perjalanan bolak-balik menjadi jarak.
if (distance <= 50) { 
    myservo.write(90); 
    } else { myservo.write(0); 
    }: Mengatur posisi servo berdasarkan jarak yang diukur. Jika jarak kurang dari atau sama dengan 50 cm, servo diatur ke posisi 90 derajat. Jika tidak, servo diatur ke posisi 0 derajat.
delay(1000);: Menunggu 1 detik sebelum mengulangi loop.

*/