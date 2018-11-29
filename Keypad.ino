void keypadListening() {
  char temp;
  temp = key.getKey();
  if (temp) {
    keyPressed = temp;
    flag = 1;
    lcd.setBacklight(HIGH);
  }
}
