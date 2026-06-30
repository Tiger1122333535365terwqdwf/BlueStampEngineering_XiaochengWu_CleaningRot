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
| Xiaocheng Wu | Beijing Huijia Private School | Electrical Engineering | Incoming Senior

**Replace the BlueStamp logo below with an image of yourself and your completed project. Follow the guide [here](https://tomcam.github.io/least-github-pages/adding-images-github-pages-site.html) if you need help.**

<img width="3072" height="4096" alt="微信图片_20260630232521_1374_24" src="https://github.com/user-attachments/assets/e7cb4512-b337-44e1-ac51-316355c24934" />
<img width="4096" height="3072" alt="微信图片_20260630232521_1375_24" src="https://github.com/user-attachments/assets/3e18f5f9-c1a5-442b-acfd-9f180c4e9b9f" />

  
# Final Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/F7M7imOVGug" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone<img width="3072" height="4096" alt="微信图片_20260630232520_1373_24" src="https://github.com/user-attachments/assets/f0ae6429-387e-494f-831d-65a9cb307208" />

- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE



# Second Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/y3VAmNlER5Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your second milestone, explain what you've worked on since your previous milestone. You can highlight:
- Technical details of what you've accomplished and how they contribute to the final goal
- What has been surprising about the project so far
- Previous challenges you faced that you overcame
- What needs to be completed before your final milestone 

# First Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/CaCazFBhYKs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your first milestone, describe what your project is and how you plan to build it. You can include:
- An explanation about the different components of your project and how they will all integrate together
- Technical progress you've made so far
- Challenges you're facing and solving in your future milestones
- What your plan is to complete your project

# Schematics 
<img width="724" height="308" alt="image" src="https://github.com/user-attachments/assets/bcce2ea2-b93e-4ac7-8bd7-4b78a7a8f289" />
<img width="752" height="180" alt="image" src="https://github.com/user-attachments/assets/c4623bec-e060-40f7-a4b8-e01e293da447" />



# Code
Here's where you'll put your code. The syntax below places it into a block of code. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize it to your project needs. 

```c++
#Ultrasonic Sensor Code#
const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance:");
  Serial.println(distance);
}


#Motor Driver Code#
int in1 = 2;
int in2 = 4;
int enA = 3;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  delay(1500);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(500);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  delay(1500);
}
```

# Bill of Materials
Here's where you'll list the parts in your project. To add more rows, just copy and paste the example rows below.
Don't forget to place the link of where to buy each component inside the quotation marks in the corresponding row after href =. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize this to your project needs. 

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
