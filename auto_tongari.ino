#include <Servo.h>

#define F_PIN 7 // 前に動くサーボのピン
#define U_PIN 8 // 上に動くサーボのピン
#define A_PIN 0 // センサのアナログピン

Servo s_f, s_u;
int f_val = 90;
int u_val = 90;

int a_val = 0;
int a_val_pre = 0;

void setup() {
  // デバッグ用
  Serial.begin(9600);
  Serial.setTimeout(10); // SerialでのString受信のタイムアウト設定（ms）
  

  // サーボピン初期化
  s_f.attach(F_PIN);
  s_u.attach(U_PIN);

  moveDown();
  moveBackward();
}

void loop() {
  // デバッグ用
  /*
  if (Serial.available() > 0) {
    String key = Serial.readStringUntil(';');
    key.trim();
    Serial.println(key);

    if (key == "f") {
      moveForward();
    } else if (key == "b") {
      moveBackward();
    } else if (key == "u") {
      moveUp();
    } else if (key == "d") {
      moveDown();
    }

    if (key == "s") {
      moveCorn();
    }

  }
  */

  a_val = analogRead(0);
  Serial.println(a_val);
  if (a_val < 100 && a_val_pre > 200) {
    Serial.println("Move.");
    delay(500);
    moveCorn();
  }

  delay(100);

  a_val_pre = a_val;
}

void moveCorn()
{
  moveUp();
  delay(500);
  moveForward();
  delay(3000);
  moveBackward();
  delay(500);
  moveDown();
}

void moveUp()
{
  u_val = 70;
  s_u.write(u_val);
}

void moveDown()
{
  u_val = 120;
  s_u.write(u_val);
}

void moveForward()
{
  f_val = 7
  0;
  s_f.write(f_val);
}

void moveBackward()
{
  f_val = 140;
  s_f.write(f_val);
}
