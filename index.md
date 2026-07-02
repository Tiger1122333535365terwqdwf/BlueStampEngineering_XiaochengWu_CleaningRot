# BlueStamp CleaningRobot
This Arduino-based project controls an autonomous floor-cleaning robot. It uses an ultrasonic sensor to navigate around obstacles by stopping and turning, while four DC motors and a motor driver handle its movement. To clean the floor, a vacuum and a brush assembly are integrated into the chassis.

You should comment out all portions of your portfolio that you have not completed yet, as well as any instructions:
```HTML
1。Assembly and circuit diagram design have been completed. But it hasn't been wired yet
2.Test to see if the car can move
3.Add the cleaning function section
```

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Xiaocheng Wu | Beijing Huijia Private School | Electrical Engineering | Year 9

<img width="890" height="562" alt="image" src="https://github.com/user-attachments/assets/be9b6f75-ba6c-4094-af43-f4170ca6fe05" />



  
# Final Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**



For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone

- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE



# Second Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/y3VAmNlER5Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For Milestone 2, the focus shifted from hardware assembly to bringing the cleaning robot to life through programming. I successfully deployed the custom Arduino UNO code, officially giving the robot its "brain." The core achievement of this phase is the autonomous cleaning logic. Instead of just driving around, the robot now executes a specific "sweeping" motion—moving forward and backing up to create floor friction, allowing the rear-mounted vacuum to clean thoroughly.
<img width="836" height="482" alt="Screenshot 2026-07-02 011753" src="https://github.com/user-attachments/assets/68ad4f82-c282-448d-9876-76037c2baa59" />
Additionally, I implemented a reliable dual-sensor obstacle avoidance system. By combining real-time data from the front ultrasonic sensor and the side infrared sensors, the robot detects obstacles within 20 centimeters. It instantly stops the sweeping motion, backs up, and changes direction to avoid collisions. A 10-minute work timer was also coded in. The practical test run was a huge success, proving the hardware and software work perfectly together as we head into Milestone 3.



# First Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/azjHpwhbsDQ?si=BmbZbCT58dMMpRmZ" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<img width="734" height="481" alt="image" src="https://github.com/user-attachments/assets/d02929e5-a531-42ed-a3c6-0b9eb5b9a802" />

<img width="539" height="454" alt="image" src="https://github.com/user-attachments/assets/9b1fd67d-a7e8-4828-8fc3-d3c7fd066cf9" />


Milestone 1 is all about bringing the physical body of the cleaning robot to life. I assembled the vehicle chassis and integrated the core hardware modules: the ultrasonic sensor for distance measurement, the infrared sensing module for obstacle detection, the infrared transmission module for communication, the mainboard, and the LED expansion board. After carefully connecting all the wiring, I powered on the system. The moment I switched on the battery, every LED lit up steadily across all modules—no flickering, no errors. That clean, stable glow confirmed the wiring is solid and fault‑free. In engineering, passing this first power‑on test is a quiet but significant victory. The hardware foundation is now real, reliable, and ready. With the physical platform proven, I’ll now shift focus entirely to the brain: mainboard development and coding, turning this assembled chassis into an autonomous cleaning robot.

# Schematics 
<img width="724" height="308" alt="image" src="https://github.com/user-attachments/assets/bcce2ea2-b93e-4ac7-8bd7-4b78a7a8f289" />
<img width="752" height="180" alt="image" src="https://github.com/user-attachments/assets/c4623bec-e060-40f7-a4b8-e01e293da447" />
<img width="792" height="526" alt="image" src="https://github.com/user-attachments/assets/4863996f-cc06-4b3b-aee2-18defdb6332d" />





# Code


```c++
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
```

# Bill of Materials
| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Sunfounder Kit | Used for building basic frameworks and circuits| 62.99 | <a href="https://www.amazon.com/SunFounder-Compatible-Tutorials-Including-Controller/dp/B0B778L1DZ/"> Link </a> |
| Double Sided Foam Tape |Used to connect components | 8.09 | <a href="https://www.amazon.com/Mounting-Waterproof-Adhesive-Posters-Sensors/dp/B0DJLR75H9/"> Link </a> |
| Mini desktop vacuum | Used as a cleaning module | 12.98 | <a href="amazon.com/ODISTAR-Endurance-Cordless-Rotatable-Keyboard/dp/B07Q128V6W/"> Link </a> |
| 9V Batteries | Provide power for robots | 8.88 | <a href="https://www.amazon.com/Amazon-Basics-Performance-All-Purpose-Batteries/dp/B00MH4QM1S/"> Link </a> |
| DMM| Used for circuit testing and circuit assistance | 9.99 | <a href="https://www.amazon.com/dp/B0CXM242J1"> Link </a> |
| AA Batteries| Provide power for robots| 9.99 | <a href="https://www.amazon.com/Amazon-Basics-Batteries-Leak-Free-Household/dp/B00NTCH52W/"> Link </a> |


# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.
