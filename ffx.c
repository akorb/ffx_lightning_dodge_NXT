#define THRESHOLD 43

task main()
{
  SetSensorLight(IN_1);
  SetSensorType(IN_1, IN_TYPE_LIGHT_INACTIVE);
  SetSensorMode(IN_1, IN_MODE_PCTFULLSCALE);
  ResetSensor(IN_1);
  
  int count = 200;
  
  ClearScreen();
  
  NumOut(0, LCD_LINE1, count);
  
  while (count >= 0)
  {
    if (SENSOR_1 > THRESHOLD)
    {
      //Wait(80);
      ClearLine(LCD_LINE1);
      count--;
      NumOut(0, LCD_LINE1, count);
      RotateMotor(OUT_A, 65, -360);
    }
  }
  
  PlayTone(294, 1000);
  Wait(1000);
}
