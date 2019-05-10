double leftValue;
double rightValue;
double capValue;

/***
 * Start ESP Measure time declarations
 */
uint16_t sleep_cycle = 4095; //4096, 12 bit max
uint16_t meas_cycle = 65535; //65535, 16 bit max

uint16_t pin12Read = 0;
uint16_t pin13Read = 0;
 
bool state = 0;
int leftAna = A11;//Pin 12
int rightAna = A12;//Pin 13

void setup() {
  touch_pad_init(); //initialize capacitive touch sensors
  touch_pad_set_voltage(TOUCH_HVOLT_2V7, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_1V); //configure capacitive sensititivty
  esp_err_t touch_pad_set_meas_time(uint16_t sleep_cycle, uint16_t meas_cycle); //set read time of 10ms 
  touch_pad_set_cnt_mode(TOUCH_PAD_NUM6, TOUCH_PAD_SLOPE_7, TOUCH_PAD_TIE_OPT_LOW); 
  touch_pad_config(TOUCH_PAD_NUM5,0); //set the touch pad pin and the interrupt threshold GPIO 12
  //touch_pad_config(TOUCH_PAD_NUM4,0); //set the touch pad pin and the interrupt threshold GPIO 13
  Serial.begin(115200);//enable serial line writing
  touch_pad_filter_start(20); //filter period
  delay(100); //init delay
}

void loop() {
//  leftValue = analogRead(leftAna);
//  Serial.println(String("Read value for pin 12 is: ") + String(leftValue));
//  rightValue = analogRead(rightAna);
//  Serial.println(String("Read value for pin 13 is: ") + String(rightValue));
  touch_pad_read_filtered(TOUCH_PAD_NUM5, &pin12Read); //read pin 12 16 bit
  //touch_pad_read_filtered(TOUCH_PAD_NUM4, &pin13Read); //read pin 13 16 bit
  Serial.println(String("Pin 12 reading: ") + pin12Read);
  //Serial.println(String("Pin 13 reading: ") + pin13Read);
  delay(100); //slow read rate for testing
}
