// ---------------- 针脚定义 (根据接线文档提取) ----------------
// L298N 电机驱动控制引脚
const int ENA = 3;   // 左电机使能 (PWM调速)
const int IN1 = 5;   // 左电机逻辑1
const int IN2 = 6;   // 左电机逻辑2
const int IN3 = 9;   // 右电机逻辑1
const int IN4 = 10;  // 右电机逻辑2
const int ENB = 11;  // 右电机使能 (PWM调速)

// 超声波模块引脚
const int TRIG = 12; // 发射端
const int ECHO = 4;  // 接收端

// 红外避障模块引脚
const int IR_LEFT = 8;  // 左边红外避障
const int IR_RIGHT = 2; // 右边红外避障

// ---------------- 全局变量 ----------------
const unsigned long WORK_TIME_LIMIT = 600000; // 总工作时间：10分钟 = 600,000毫秒
unsigned long startTime = 0;
int motorSpeed = 150; // 小车速度 (范围: 0-255，建议稍微调低点以便仔细清洁)

void setup() {
  Serial.begin(9600);
  
  // 初始化电机引脚
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // 初始化超声波引脚
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  // 初始化红外避障引脚
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  
  // 记录开机时间
  startTime = millis();
  
  // 启动前停顿3秒，方便你放下小车
  delay(3000); 
}

void loop() {
  // 1. 检查是否达到10分钟工作时间
  if (millis() - startTime >= WORK_TIME_LIMIT) {
    stopMotors(); // 停止所有动作
    while(true);  // 进入死循环，等待手动重启
  }

  // 2. 检查前方是否有障碍物
  if (detectObstacle()) {
    // 遇到障碍物：后退并改变方向
    moveBackward();
    delay(600);      // 后退0.6秒
    turnRight();     // 向右转改变方向
    delay(500);      // 转向0.5秒
    stopMotors();
    delay(200);
  } else {
    // 3. 没有障碍物，执行“摩擦清洁”动作
    sweepArea();
    
    // 4. 当前区域清洁完毕，前进到下一个区域
    // 再次检测一下，防止在刚刚前进时撞墙
    if (!detectObstacle()) {
      moveForward();
      delay(800); // 前进0.8秒去新区域
      stopMotors();
      delay(200);
    }
  }
}

// ---------------- 核心功能函数 ----------------

// 区域往复摩擦清洁动作
void sweepArea() {
  // 循环3次：前进一点，后退一点，模拟拖地/吸尘摩擦
  for (int i = 0; i < 3; i++) {
    // 每次动作前检查障碍，防止在“摩擦”时撞车
    if (detectObstacle()) return; 
    
    moveForward();
    delay(300); // 前进摩擦0.3秒
    
    if (detectObstacle()) return;
    
    moveBackward();
    delay(300); // 后退摩擦0.3秒
  }
}

// 障碍检测函数 (综合超声波和红外)
bool detectObstacle() {
  // 1. 超声波测距
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH, 30000); // 30ms超时设置
  int distance = duration * 0.034 / 2;
  
  // 2. 读取红外避障状态 (通常遇到障碍物输出LOW)
  int leftState = digitalRead(IR_LEFT);
  int rightState = digitalRead(IR_RIGHT);

  // 如果超声波距离小于20cm，或者左右红外检测到障碍，则判定为有障碍
  if ((distance > 0 && distance < 20) || leftState == LOW || rightState == LOW) {
    return true;
  }
  return false;
}

// ---------------- 基础运动控制函数 ----------------

void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // 左电机正转
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // 右电机正转
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // 左电机反转
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // 右电机反转
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // 左电机正转
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // 右电机反转 (产生原地右转效果)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}