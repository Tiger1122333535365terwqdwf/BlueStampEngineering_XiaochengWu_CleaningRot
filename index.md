### Project Introduction
This Arduino-based project controls an autonomous floor-cleaning robot. It uses an ultrasonic sensor to navigate around obstacles by stopping and turning, while four DC motors and a motor driver handle its movement. To clean the floor, a vacuum and a brush assembly are integrated into the chassis.

Building upon this foundation, my specific modification to the project is the integration of a wireless IoT control and real-time timer system. To overcome the hardware limitations of the original Arduino and introduce remote capabilities, I developed a master-slave dual-board architecture. I introduced an ESP8266 WiFi module to act as a "Command Center," which hosts a local web server and drives a physical 4-digit segment display. Through a custom-built mobile web interface, users can input a specific cleaning duration and wirelessly transmit the command to the robot. The ESP8266 tracks the countdown in real-time on the physical display and uses a dedicated hardware signal wire to the primary Arduino to instantly engage or cut the robot's motor power the exact second the timer reaches zero. This modification transforms the original robot into a remotely controllable, time-precise smart cleaning system.

Besides, I built a small remote controller with an OLED screen, a buzzer, an ESP‑12F, and an Arduino Uno. Its visual interface shows the current time, battery level at the top right, and today’s date on the left — the date can be freely changed, for example I set it to 2024. The menu includes a clock and a game; the game is the Chrome dinosaur game. The clock module lets you adjust the current time and set the robot’s cleaning duration, and it beeps when cleaning ends.Then, if left idle for 15 seconds, it enters sleep mode and shows some cute face animations on the screen and switch once in 5 seconds.


| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Xiaocheng Wu | Beijing Huijia Private School | Electrical Engineering | Year 9

<img width="890" height="562" alt="image" src="https://github.com/user-attachments/assets/be9b6f75-ba6c-4094-af43-f4170ca6fe05" />

<img width="602" height="358" alt="image" src="https://github.com/user-attachments/assets/7fd0abaf-870a-40e5-bee6-eb21da0b197b" />

<img width="949" height="628" alt="image" src="https://github.com/user-attachments/assets/0bfc4b36-6b7b-4dc6-a0bb-5647689fdda8" />



# Extensions
Besides, I built a small remote controller with an OLED screen, a buzzer, an ESP‑12F, and an Arduino Uno. Its visual interface shows the current time, battery level at the top right, and today’s date on the left — the date can be freely changed, for example I set it to 2024. The menu includes a clock and a game; the game is the Chrome dinosaur game. The clock module lets you adjust the current time and set the robot’s cleaning duration, and it beeps when cleaning ends.Then, if left idle for 15 seconds, it enters sleep mode and shows some cute face animations on the screen and switch once in 5 seconds.
<img width="1007" height="677" alt="image" src="https://github.com/user-attachments/assets/41455c79-688a-44f2-a826-f97f272171f7" />
<img width="1010" height="670" alt="image" src="https://github.com/user-attachments/assets/eae68004-f10f-4db8-930f-fc4d36281ff2" />
<img width="947" height="650" alt="image" src="https://github.com/user-attachments/assets/af8aea7d-6f13-450c-b56c-12065f031a99" />
<img width="903" height="641" alt="image" src="https://github.com/user-attachments/assets/dd174877-6be9-4109-855a-7eadc75229e2" />
<img width="946" height="665" alt="image" src="https://github.com/user-attachments/assets/56a96e32-3f7b-4e35-86e4-652930c1a5e8" />
<img width="976" height="663" alt="image" src="https://github.com/user-attachments/assets/52811e9c-a2ba-443e-a8bf-203a27c68f43" />



  
# Final Milestone

<iframe width="560" height="315" src="https://www.youtube.com/embed/X6mOFYc2DLk?si=CoWOAkggOB5sXpxC" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


### Modified Pin Connections: ESP8266 Command Center



| Module / Component | Component Pin | ESP8266 Pin (Master) | Target Pin (Slave) | Function & Notes |
| --- | --- | --- | --- | --- |
| **TM1637 Display** | CLK | D1 | N/A | Clock signal for the countdown timer. |
| **TM1637 Display** | DIO | D2 | N/A | Data input/output for the countdown timer. |
| **TM1637 Display** | VCC | 3V3 (or VIN) | N/A | Power supply for the display module. |
| **TM1637 Display** | GND | GND | N/A | Ground connection for the display. |
| **Arduino UNO (Car)** | Signal Wire | D7 | A4 (UNO) | Transmits the execution signal (HIGH = Run, LOW = Stop). |
| **Arduino UNO (Car)** | Ground Wire | GND | GND (UNO) | **Critical:** Establishes a common ground reference between both boards to prevent floating signal errors. |



### Final Milestone Discription
For my final milestone at BSE, I successfully scaled the autonomous cleaning robot into a dual-board IoT system. Since the previous milestone, I introduced a secondary Arduino board to drive a 4-digit display and an ESP8266 WiFi module, effectively solving the primary board's severe pin shortage. I also built a custom English web interface featuring an uploading progress bar that automatically scales and confirms data receipt with a "Robot Accepted" status.

My biggest engineering challenge was troubleshooting a signal conflict where the communication wire was accidentally misrouted to an occupied A2 pin under a floating ground state, which initially caused the motors to run infinitely. Fixing this required rewiring the signal to a vacant A4 pin and establishing a common ground between the microcontrollers. My ultimate triumph was executing a flawless integration test where a mobile web command instantly triggered the real-time countdown and precise physical braking mechanisms.

Through this project, I mastered master-slave architectures, local HTTP servers, and non-blocking control logic. Moving forward, I want to transition to higher-performance chips like the ESP32 and explore computer vision programming. Specifically, I hope to implement lightweight YOLO object recognition models to allow the robot to intelligently identify debris and map rooms rather than relying on reactive sensors.


# Second Milestone

<iframe width="560" height="315" src="https://www.youtube.com/embed/70A_4osS0bQ?si=ZjsBnkr_pQ4pZom-" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

For Milestone 2, the focus shifted from hardware assembly to bringing the cleaning robot to life through programming. I successfully deployed the custom Arduino UNO code, officially giving the robot its "brain." The core achievement of this phase is the autonomous cleaning logic. Instead of just driving around, the robot now executes a specific "sweeping" motion—moving forward and backing up to create floor friction, allowing the rear-mounted vacuum to clean thoroughly.
<img width="836" height="482" alt="Screenshot 2026-07-02 011753" src="https://github.com/user-attachments/assets/68ad4f82-c282-448d-9876-76037c2baa59" />
Additionally, I implemented a reliable dual-sensor obstacle avoidance system. By combining real-time data from the front ultrasonic sensor and the side infrared sensors, the robot detects obstacles within 20 centimeters. It instantly stops the sweeping motion, backs up, and changes direction to avoid collisions. A 10-minute work timer was also coded in. The practical test run was a huge success, proving the hardware and software work perfectly together as we head into Milestone 3.



# First Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/azjHpwhbsDQ?si=BmbZbCT58dMMpRmZ" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<img width="734" height="481" alt="image" src="https://github.com/user-attachments/assets/d02929e5-a531-42ed-a3c6-0b9eb5b9a802" />

<img width="539" height="454" alt="image" src="https://github.com/user-attachments/assets/9b1fd67d-a7e8-4828-8fc3-d3c7fd066cf9" />


Milestone 1 is all about bringing the physical body of the cleaning robot to life. I assembled the vehicle chassis and integrated the core hardware modules: the ultrasonic sensor for distance measurement, the infrared sensing module for obstacle detection, the infrared transmission module for communication, the mainboard, and the LED expansion board. After carefully connecting all the wiring, I powered on the system. The moment I switched on the battery, every LED lit up steadily across all modules—no flickering, no errors. That clean, stable glow confirmed the wiring is solid and fault‑free. In engineering, passing this first power‑on test is a quiet but significant victory. The hardware foundation is now real, reliable, and ready. With the physical platform proven, I’ll now shift focus entirely to the brain: mainboard development and coding, turning this assembled chassis into an autonomous cleaning robot.

# Schematics 
<img width="752" height="180" alt="image" src="https://github.com/user-attachments/assets/c4623bec-e060-40f7-a4b8-e01e293da447" />

(over all graph)


<img width="1276" height="586" alt="image" src="https://github.com/user-attachments/assets/2208ecd2-39c3-4232-8e42-4a9c6b8f7bc2" />

(Motor Wiring Diagram)


<img width="839" height="638" alt="image" src="https://github.com/user-attachments/assets/74492eab-bcd1-485c-96ac-06f75129aafe" />

(Infrared obstacle avoidance wiring diagram)


# Code


```c++    
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <TM1637Display.h>

// ---------------- WiFi Settings ----------------
const char* ssid = "YOUR_WIFI_NAME";      // Replace with your actual WiFi network name
const char* password = "YOUR_WIFI_PASSWORD";  // Replace with your actual WiFi password

ESP8266WebServer server(80);

// ---------------- Hardware Pin Definitions ----------------
#define CLK D1        // TM1637 Display Clock Pin
#define DIO D2        // TM1637 Display Data Pin
#define SIGNAL_OUT D7 // Signal wire going to the UNO board's A4 pin

TM1637Display display(CLK, DIO);

// ---------------- Global Variables ----------------
long timeRemaining = 0;       // Remaining time in seconds
unsigned long lastTick = 0;   // Used for non-blocking timer
bool isRunning = false;       // System state flag

// ---------------- Embedded HTML Code ----------------
const char HTML_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><title>Robot Control Center</title><style>body { font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, sans-serif; background: #f4f6f9; color: #333; display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; } .container { background: white; padding: 30px; border-radius: 16px; box-shadow: 0 4px 20px rgba(0,0,0,0.06); width: 90%; max-width: 380px; text-align: center; } h1 { font-size: 22px; margin-bottom: 8px; color: #111; } p.subtitle { font-size: 14px; color: #007aff; font-weight: 600; margin-top: 0; margin-bottom: 20px; } .status-box { background: #eef2f7; padding: 12px; border-radius: 8px; margin-bottom: 25px; font-weight: 500; font-size: 14px; color: #555; } .status-box span { color: #2ecc71; font-weight: bold; } .input-group { text-align: left; margin-bottom: 20px; } label { display: block; margin-bottom: 8px; font-size: 14px; color: #555; font-weight: 500; } input[type="number"] { width: 100%; padding: 12px; border: 1px solid #ddd; border-radius: 8px; font-size: 16px; box-sizing: border-box; text-align: center; } button { width: 100%; padding: 14px; border: none; border-radius: 8px; font-size: 16px; font-weight: 600; cursor: pointer; transition: background 0.2s; margin-bottom: 12px; } .btn-start { background: #007aff; color: white; } .btn-start:hover { background: #0062cc; } .btn-stop { background: #ff3b30; color: white; } .btn-stop:hover { background: #d32f2f; } .progress-container { width: 100%; background-color: #eef2f7; border-radius: 10px; margin: 20px 0 5px 0; display: none; overflow: hidden; } .progress-bar { width: 1%; height: 12px; background-color: #007aff; border-radius: 10px; transition: width 0.05s linear; } .progress-text { font-size: 13px; font-weight: 600; color: #555; margin-bottom: 15px; display: none; }</style></head><body><div class="container"><h1>Robot Control Center</h1><p class="subtitle">Blue Stamp Engineering Project</p><div class="status-box">Status: <span id="status">Connected</span></div><div class="input-group"><label for="duration">Set Timer (Seconds):</label><input type="number" id="duration" min="1" max="3600" value="15"></div><button class="btn-start" onclick="sendTimer()">Start Cleaning</button><div class="progress-container" id="pContainer"><div class="progress-bar" id="pBar"></div></div><div class="progress-text" id="pText">Uploading: 1%</div><button class="btn-stop" onclick="stopRobot()">Emergency Stop</button></div><script>function sendTimer() { var timeVal = document.getElementById('duration').value; if(!timeVal || timeVal <= 0) { alert('Please enter a valid time duration.'); return; } var statusEl = document.getElementById('status'); var pContainer = document.getElementById('pContainer'); var pBar = document.getElementById('pBar'); var pText = document.getElementById('pText'); statusEl.innerText = 'Transmitting...'; statusEl.style.color = '#f39c12'; pContainer.style.display = 'block'; pText.style.display = 'block'; pText.style.color = '#555'; pBar.style.width = '1%'; var currentPercent = 1; var animationInterval = setInterval(function() { if (currentPercent >= 100) { clearInterval(animationInterval); pBar.style.width = '100%'; pText.innerText = 'Robot Accepted'; pText.style.color = '#2ecc71'; statusEl.innerText = 'Cleaning active (' + timeVal + 's)'; statusEl.style.color = '#2ecc71'; fetch('/set?time=' + timeVal).catch(err => {}); } else { currentPercent++; pBar.style.width = currentPercent + '%'; pText.innerText = 'Uploading Command: ' + currentPercent + '%'; } }, 12); } function stopRobot() { var statusEl = document.getElementById('status'); document.getElementById('pContainer').style.display = 'none'; document.getElementById('pText').style.display = 'none'; statusEl.innerText = 'Standby / Stopped'; statusEl.style.color = '#ff3b30'; fetch('/stop').catch(err => {}); }</script></body></html>
)=====";

// ---------------- Server Route Handlers ----------------

// Serve the main HTML page
void handleRoot() {
  server.send(200, "text/html", HTML_PAGE);
}

// Handle timer setup from web client (e.g., /set?time=15)
void handleSetTime() {
  if (server.hasArg("time")) {
    timeRemaining = server.arg("time").toInt();
    isRunning = true;
    lastTick = millis();
    digitalWrite(SIGNAL_OUT, HIGH); // Send command to start the robot
    server.send(200, "text/plain", "OK");
  }
}

// Handle emergency stop request from web client
void handleStop() {
  timeRemaining = 0;
  isRunning = false;
  digitalWrite(SIGNAL_OUT, LOW);  // Send command to stop the robot
  display.showNumberDec(0, true); 
  server.send(200, "text/plain", "STOPPED");
}

// ---------------- Main Setup ----------------
void setup() {
  Serial.begin(115200);
  
  // Initialize communication pin to the robot board
  pinMode(SIGNAL_OUT, OUTPUT);
  digitalWrite(SIGNAL_OUT, LOW); // Default state is off

  // Initialize display
  display.setBrightness(0x0f); // Maximum brightness
  display.showNumberDec(0, true);

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Web UI IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup server routing
  server.on("/", handleRoot);
  server.on("/set", handleSetTime);
  server.on("/stop", handleStop);
  server.begin();
}

// ---------------- Main Loop ----------------
void loop() {
  server.handleClient(); // Listen for incoming web requests

  // Non-blocking timer logic for the physical display
  if (isRunning && timeRemaining > 0) {
    digitalWrite(SIGNAL_OUT, HIGH); // Continuously send HIGH signal while active
    
    // Check if exactly 1000 milliseconds (1 second) has passed
    if (millis() - lastTick >= 1000) {
      lastTick = millis();
      timeRemaining--;
      display.showNumberDec(timeRemaining, true); // Refresh physical display
      
      // Stop condition when timer hits zero
      if (timeRemaining <= 0) {
        isRunning = false;
        digitalWrite(SIGNAL_OUT, LOW); // Cut signal to stop the robot
      }
    }
  }
}
```


```c++
// ---------------- Pin Definitions ----------------

// L298N Motor Driver Control Pins (Based on official wiring document)
const int ENA = 3;   // Left motor enable (PWM speed control)
const int IN1 = 5;   // Left motor logic 1
const int IN2 = 6;   // Left motor logic 2
const int IN3 = 9;   // Right motor logic 1
const int IN4 = 10;  // Right motor logic 2
const int ENB = 11;  // Right motor enable (PWM speed control)

// Ultrasonic Sensor Pins
const int TRIG = 12; // Transmitter pin
const int ECHO = 4;  // Receiver pin

// Infrared (IR) Obstacle Avoidance Pins
const int IR_LEFT = 8;  // Left IR sensor
const int IR_RIGHT = 2; // Right IR sensor

// Signal Receiver Pin (Connected to ESP8266 D7)
const int SIGNAL_INPUT_PIN = A4; 

// ---------------- Global Variables ----------------
int motorSpeed = 150; // Speed range: 0-255 (Adjusted lower for thorough cleaning)

// ---------------- Main Setup ----------------
void setup() {
  // Initialize motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Initialize ultrasonic pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  // Initialize IR pins
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  
  // Initialize the signal pin to listen to the ESP8266 command board
  pinMode(SIGNAL_INPUT_PIN, INPUT);
  
  // Ensure the robot starts in a stationary state
  stopMotors(); 
}

// ---------------- Main Loop ----------------
void loop() {
  // 1. Read the real-time command signal from the ESP8266 timer board
  int commandSignal = digitalRead(SIGNAL_INPUT_PIN);

  // 2. Check if authorization is granted (HIGH = Run, LOW = Stop)
  if (commandSignal == HIGH) {
    
    // Check for obstacles continuously while authorized to move
    if (detectObstacle()) {
      // Obstacle detected: execute evasion maneuver
      moveBackward();
      delay(600);      // Back up for 0.6 seconds
      turnRight();     // Turn to change direction
      delay(500);      // Turn for 0.5 seconds
      stopMotors();
      delay(200);
    } else {
      // Path is clear: execute friction-based cleaning protocol
      sweepArea();
      
      // Double check path before moving to the next cleaning zone
      if (!detectObstacle()) {
        moveForward();
        delay(800);    // Proceed forward for 0.8 seconds to reach new area
        stopMotors();
        delay(200);
      }
    }
    
  } else {
    // 3. Signal is LOW (Timer reached zero or emergency stop triggered)
    // Instantly cut all motor power and remain on standby
    stopMotors(); 
  }
}

// ---------------- Core Function: Sweeping Logic ----------------

// Executes a back-and-forth friction motion to simulate vacuuming/mopping
void sweepArea() {
  // Loop 3 times for a thorough clean in the current spot
  for (int i = 0; i < 3; i++) {
    
    // Safety check before initiating forward friction
    if (detectObstacle()) return; 
    
    moveForward();
    delay(300); // Forward friction for 0.3 seconds
    
    // Safety check before initiating backward friction
    if (detectObstacle()) return;
    
    moveBackward();
    delay(300); // Backward friction for 0.3 seconds
  }
}

// ---------------- Core Function: Obstacle Detection ----------------

// Combines data from both Ultrasonic and IR sensors for dual reliability
bool detectObstacle() {
  // 1. Ultrasonic distance measurement
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // 30ms timeout setting to prevent the code from hanging
  long duration = pulseIn(ECHO, HIGH, 30000); 
  int distance = duration * 0.034 / 2;
  
  // 2. Read IR sensor states (Normally outputs LOW when detecting an object)
  int leftState = digitalRead(IR_LEFT);
  int rightState = digitalRead(IR_RIGHT);

  // Return TRUE (Obstacle present) if object is within 20cm OR IR sensors trigger
  if ((distance > 0 && distance < 20) || leftState == LOW || rightState == LOW) {
    return true;
  }
  
  return false; // Path is clear
}

// ---------------- Basic Motor Control Functions ----------------

// Drives both motors forward
void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Drives both motors in reverse
void moveBackward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  
  // Left motor reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Right motor reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Executes a zero-radius right turn (tank turn)
void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right motor reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Cuts logic signals to both motors, halting the chassis entirely
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
| Sunfounder Kit | Used for building basic frameworks and circuits| 62.99$ | <a href="https://www.amazon.com/SunFounder-Compatible-Tutorials-Including-Controller/dp/B0B778L1DZ/"> Link </a> |
| Double Sided Foam Tape |Used to connect components | 8.09$ | <a href="https://www.amazon.com/Mounting-Waterproof-Adhesive-Posters-Sensors/dp/B0DJLR75H9/"> Link </a> |
| Mini desktop vacuum | Used as a cleaning module | 12.98$ | <a href="amazon.com/ODISTAR-Endurance-Cordless-Rotatable-Keyboard/dp/B07Q128V6W/"> Link </a> |
| 9V Batteries | Provide power for robots | 8.88$ | <a href="https://www.amazon.com/Amazon-Basics-Performance-All-Purpose-Batteries/dp/B00MH4QM1S/"> Link </a> |
| DMM| Used for circuit testing and circuit assistance | 9.99$ | <a href="https://www.amazon.com/dp/B0CXM242J1"> Link </a> |
| AA Batteries| Provide power for robots| 9.99$ | <a href="https://www.amazon.com/Amazon-Basics-Batteries-Leak-Free-Household/dp/B00NTCH52W/"> Link </a> |


# Sources
| <a href="https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/car_project/car_assemble.html"> Link </a> |

| <a href="https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/car_project/car_auto.html"> Link </a> |

| <a href="https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/car_project/car_auto.html"> Link </a> |

| <a href="https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/car_project/car_auto.html"> Link </a> |

| <a href="https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/car_project/car_auto.html"> Link </a> |


