/***********************************************************************************************************************
  Sketch amalgamated by: Rich Blair
  Date: 19/07/19
  Version: 2.3
  Useage: Year Zero Project Two to control the robotic arm autonomously 
          Once you calculated all of the movements via the manual sketch 
          you can use this one to automate the process.
          Consider one movement to all six servos in one go, so: 
                            //(SD,  BA,    SH,   EL,   WV,   WR,  GR);
          RoboticArmMovement(20,  180,   30,   10,   60,   90,  73);
  License: GNU Lesser General Public License
  Documentation: https://github.com/CompEng0001/YearZeroRoboticArm
  License: GNU Lesser General Public License
  Acknowledgements: TinkerKit Braccio base libraries -> https://github.com/arduino-org/arduino-library-braccio
***********************************************************************************************************************/

/***************************************************************************************************************************
  DO NOT CHANGE ANYTHING IN THIS REGION (LINE 18 TO 67) OR THE CODE WILL NOT WORK AND WILL CAUSE YOU HOURS/DAYS OF DEBUGGING
 ***************************************************************************************************************************/

// Required library for Servo control
#include <Servo.h>

//The software PWM is connected to PIN 12. You cannot use the pin 12 if you are using
//a Braccio shield V4 or newer
#define SOFT_START_CONTROL_PIN  12

//Low and High Limit Timeout for the Software PWM
#define LOW_LIMIT_TIMEOUT 2000
#define HIGH_LIMIT_TIMEOUT 6000

// setup of Servo objects *note* names to represent position of servo on robotic arm
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

// set up angles for each servo object
int step_base, step_shoulder, step_elbow, step_wrist_ver, step_wrist_rot, step_gripper;

void setup()
{
  // Open serial for communication
  Serial.begin(115200);

  // LED for visual indicator of readiness
  digitalWrite(LED_BUILTIN, OUTPUT);

  // Initialization of RoboticArm safely
  RoboticArmBegin();

    // Some instructions to screen
  Serial.println("######################## OPERATING INFORMATION #######################");
  Serial.println("");
  Serial.println("The robotic arm will follow the sequence of instrunctions listed in loop().");
  Serial.println("This will begin when the led turns on");
  Serial.println("REMEMBER: WHEN THE ROBOT IS IN MOTION DO NOT ENTER THE OPERATING ZONE");
  Serial.println("If in doubt refer to documentations or ask for help!");
  Serial.println("");
  Serial.println("##################### END OF OPERATING INFORMATION ####################");
  delay(1000);
}

/*****************************************************************************************************************
  END OF REGION
 *****************************************************************************************************************/

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH); // Ready for first command.
  /*****************************************************************************************************************
    SD = a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
    BA = base degrees. Allowed values from 0 to 180 degrees
    SH = shoulder degrees. Allowed values from 15 to 165 degrees
    EL = elbow degrees. Allowed values from 0 to 180 degrees
    WV = wrist vertical degrees. Allowed values from 0 to 180 degrees
    WR = wrist rotation degrees. Allowed values from 0 to 180 degrees
    GR = gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  ******************************************************************************************************************/
  Serial.println("1");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  120,  82,   82,   82,  90,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
  Moves base to position 1 and stands up straight
 ****************************************************************************************************************************/
 
 Serial.println("2");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  120,  82,   82,   82,  82,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);
  
  /*****************************************************************************************************************************
  Opens the claw
 ****************************************************************************************************************************/
 
  Serial.println("3");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  120, 110,  162,  133, 90,  30);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);
  
   /*****************************************************************************************************************************
  Goes down to G1
 ****************************************************************************************************************************/
  
   Serial.println("4");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  120, 110,  162,  133, 90,  57);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);
  
   /*****************************************************************************************************************************
  Closes the claw
 ****************************************************************************************************************************/
 
    Serial.println("5");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  120,   82,   82,   82,  90,  57);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
 Picks up the ball and stands up straight
 ****************************************************************************************************************************/
 
 Serial.println("6");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  172,  82,   82,   82,  90,  57);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);
  
    /*****************************************************************************************************************************
 Moves base to R1
 ****************************************************************************************************************************/

  Serial.println("7");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  172, 140,  150,  82,  90,  57);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);
  
    /*****************************************************************************************************************************
 Places the ball into R1
 ****************************************************************************************************************************/
 
   Serial.println("8");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  172,  140,  150,  85,  90,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
  Lets go of ball
 ****************************************************************************************************************************/

  
 Serial.println("9");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  172,  82,   82,   82,  90,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);
  
    /*****************************************************************************************************************************
 Stands up straight
 ****************************************************************************************************************************/

  Serial.println("10");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  130, 82,   82,   82,  90,  30);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);
  
    /*****************************************************************************************************************************
 Moves to G2
 ****************************************************************************************************************************/

  Serial.println("11");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  130, 133,  130,  138,  90, 30);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);

 /*****************************************************************************************************************************
 Goes down to G2
 ****************************************************************************************************************************/
  
  Serial.println("12");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  130,  133,  130,  138, 90,  57);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000); 
  
  /*****************************************************************************************************************************
 Closes claw
 ****************************************************************************************************************************/

  Serial.println("13");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  130,  82,   82,   82,  90,  57);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

 /*****************************************************************************************************************************
 Stands up straight
 ****************************************************************************************************************************/
  
  
  Serial.println("14");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  151,   82,   82,   82,  90,  57);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
 Moves base to R2
 ****************************************************************************************************************************/

  Serial.println("15");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  151,  123,  135,  152, 90,  57);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

 /*****************************************************************************************************************************
 Moves to R2
 ****************************************************************************************************************************/
   Serial.println("16");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  151,  123,   135,  152, 90,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
  Lets go of ball
 ****************************************************************************************************************************/
 
 Serial.println("17");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  151,  82,   82,   82,  82,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);
  
  /*****************************************************************************************************************************
  Stands up straight 
 ****************************************************************************************************************************/
 
  Serial.println("18");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  180, 82,   82,   82,  90,  30);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);
  
   /*****************************************************************************************************************************
  Moves base to G3
 ****************************************************************************************************************************/
 
    Serial.println("19");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  180,  104,  155,  161, 90,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
 MOves down to G3 
 ****************************************************************************************************************************/

    Serial.println("20");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  180,  104,  155,  161, 90,  50);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

   /*****************************************************************************************************************************
 Closes Claw
 ****************************************************************************************************************************/
 
 Serial.println("21");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  180,  85,   150,  93,  90,  50);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);
  
    /*****************************************************************************************************************************
 Stands up straight
 ****************************************************************************************************************************/

  Serial.println("22");
                  //(SD,  BA,  SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  100, 85,   150,  93,  90,  50);
  // Wait 1 second recommended for power to discharge from the servos
  delay(1000);
  
    /*****************************************************************************************************************************
 Moves base to R3
 ****************************************************************************************************************************/
 
   Serial.println("23");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  100,  85,   170,  93,  90,  50);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);

  /*****************************************************************************************************************************
  moves down to R3
 ****************************************************************************************************************************/

  
 Serial.println("24");
                  //(SD,  BA,   SH,   EL,   WV,  WR,  GR);
  RoboticArmMovement(20,  100,  85,   170,  93,  90,  30);
  //Wait 1 second recommended for power to discharge from the servos 
  delay(1000);
  
    /*****************************************************************************************************************************
 Lets go of ball
 ****************************************************************************************************************************/
 
}
/*****************************************************************************************************************************
  DO NOT CHANGE ANYTHING IN THIS REGION OR RISK DAMAGING THE ROBOTIC ARM
 ****************************************************************************************************************************/

/**
  This functions allows you to control all the servo motors
  
  Robotic Arm moves in this order base -> shoulder -> elbow -> wrist vertical -> wrist rotation -> gripper  

  @param stepDelay The delay between each servo movement
  @param vBase next base servo motor degree
  @param vShoulder next shoulder servo motor degree
  @param vElbow next elbow servo motor degree
  @param vWrist_ver next wrist rotation servo motor degree
  @param vWrist_rot next wrist vertical servo motor degree
  @param vgripper next gripper servo motor degree
*/
void RoboticArmMovement(int stepDelay, int vBase, int vShoulder, int vElbow, int vWrist_ver, int vWrist_rot, int vgripper)
{
  digitalWrite(LED_BUILTIN, LOW);
  // DO NOT CHANGE VALUES, this avoids dangerous positions for the Braccio
  if (stepDelay > 30) stepDelay = 30;
  if (stepDelay < 10) stepDelay = 10;
  if (vBase < 0) vBase = 0;
  if (vBase > 180) vBase = 180;
  if (vShoulder < 15) vShoulder = 15;
  if (vShoulder > 165) vShoulder = 165;
  if (vElbow < 0) vElbow = 0;
  if (vElbow > 180) vElbow = 180;
  if (vWrist_ver < 0) vWrist_ver = 0;
  if (vWrist_ver > 180) vWrist_ver = 180;
  if (vWrist_rot > 180) vWrist_rot = 180;
  if (vWrist_rot < 0) vWrist_rot = 0;
  if (vgripper < 10) vgripper = 10;
  if (vgripper > 73) vgripper = 73;

  int exit = 1;

  // Until the all motors are in the desired position
  while (exit)
  {
    // For each servo motor if next degree is not the same of the previuos than do the movement
    if (vBase != step_base)
    {
      base.write(step_base);
      // One step ahead
      if (vBase > step_base) {
        step_base++;
      }
      // One step beyond
      if (vBase < step_base) {
        step_base--;
      }
    }

    if (vShoulder != step_shoulder)
    {
      shoulder.write(step_shoulder);
      // One step ahead
      if (vShoulder > step_shoulder) {
        step_shoulder++;
      }
      // One step beyond
      if (vShoulder < step_shoulder) {
        step_shoulder--;
      }

    }

    if (vElbow != step_elbow)
    {
      elbow.write(step_elbow);
      // One step ahead
      if (vElbow > step_elbow) {
        step_elbow++;
      }
      // One step beyond
      if (vElbow < step_elbow) {
        step_elbow--;
      }
    }

    if (vWrist_ver != step_wrist_ver)
    {
      wrist_ver.write(step_wrist_ver);
      // One step ahead
      if (vWrist_ver > step_wrist_ver) {
        step_wrist_ver++;
      }
      // One step beyond
      if (vWrist_ver < step_wrist_ver) {
        step_wrist_ver--;
      }
    }

    if (vWrist_rot != step_wrist_rot)
    {
      wrist_rot.write(step_wrist_rot);
      // One step ahead
      if (vWrist_rot > step_wrist_rot) {
        step_wrist_rot++;
      }
      // One step beyond
      if (vWrist_rot < step_wrist_rot) {
        step_wrist_rot--;
      }
    }

    if (vgripper != step_gripper)
    {
      gripper.write(step_gripper);
      if (vgripper > step_gripper) {
        step_gripper++;
      }
      // One step beyond
      if (vgripper < step_gripper) {
        step_gripper--;
      }
    }

    //delay between each movement
    delay(stepDelay);

    //It checks if all the servo motors are in the desired position
    if ((vBase == step_base) && (vShoulder == step_shoulder)
        && (vElbow == step_elbow) && (vWrist_ver == step_wrist_ver)
        && (vWrist_rot == step_wrist_rot) && (vgripper == step_gripper))
    {
      step_base = vBase;
      step_shoulder = vShoulder;
      step_elbow = vElbow;
      step_wrist_rot = vWrist_rot;
      step_wrist_ver = vWrist_ver;
      step_gripper = vgripper;

      //Debugging
      Serial.print("Base is: ");
      Serial.println(step_base);
      Serial.print("Shoulder is: ");
      Serial.println(step_shoulder);
      Serial.print("Elbow is: ");
      Serial.println(step_elbow);
      Serial.print("Wrist Verticle is: ");
      Serial.println(step_wrist_ver);
      Serial.print("Wrist Rotation is: ");
      Serial.println(step_wrist_rot);
      Serial.print("Gripper is: ");
      Serial.println(step_gripper);

      exit = 0;
    }
    else
    {
      exit = 1;
    }
  }
  digitalWrite(LED_BUILTIN, HIGH); 
}

/**
  Braccio initialization and set intial position
  Modifing this function you can set up the initial position of all the
  servo motors of Braccio
  @param soft_start_level: default value is 0 (SOFT_START_DEFAULT)
  You should set begin(SOFT_START_DISABLED) if you are using the Arm Robot shield V1.6
  SOFT_START_DISABLED disable the Braccio movements
*/
void RoboticArmBegin()
{
  //Calling Braccio.begin(SOFT_START_DISABLED) the Softstart is disabled and you can use the pin 12
  pinMode(SOFT_START_CONTROL_PIN, OUTPUT);
  digitalWrite(SOFT_START_CONTROL_PIN, LOW);

  // initialization pin Servo motors
  base.attach(11);
  shoulder.attach(10);
  elbow.attach(9);
  wrist_ver.attach(6);
  wrist_rot.attach(5);
  gripper.attach(3);

  //For each step motor this set up the initial degree
  base.write(0);
  shoulder.write(40);
  elbow.write(180);
  wrist_ver.write(170);
  wrist_rot.write(0);
  gripper.write(73);

  //Previous step motor position
  step_base = 0;
  step_shoulder = 100;
  step_elbow = 180;
  step_wrist_ver = 170;
  step_wrist_rot = 0;
  step_gripper = 10;

  softStart(-35); // delayMicroseconds
}

/*
  This function, used only with the Braccio Shield V4 and greater,
  turn ON the Braccio softly and save Braccio from brokes.
  The SOFT_START_CONTROL_PIN is used as a software PWM
  @param soft_start_level: the minimum value is -70, , default value is 0 (SOFT_START_DEFAULT)
*/
void softStart(int soft_start_level)
{
  long int tmp = millis();
  while (millis() - tmp < LOW_LIMIT_TIMEOUT)
    softwarePWM(80 + soft_start_level, 450 - soft_start_level); //the sum should be 530usec

  while (millis() - tmp < HIGH_LIMIT_TIMEOUT)
    softwarePWM(75 + soft_start_level, 430 - soft_start_level); //the sum should be 505usec

  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);
}

/*
  Software implementation of the PWM for the SOFT_START_CONTROL_PIN,HIGH
  @param high_time: the time in the logic level high
  @param low_time: the time in the logic level low
*/
void softwarePWM(int high_time, int low_time)
{
  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);
  delayMicroseconds(high_time);
  digitalWrite(SOFT_START_CONTROL_PIN, LOW);
  delayMicroseconds(low_time);
}

/*****************************************************************************************************************************
  END OF REGION
 ****************************************************************************************************************************/
