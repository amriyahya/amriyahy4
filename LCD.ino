void inputFlags() {
  //Menu Button
  if (keyPressed == '*') {
    inputFlag = true;
    currentScreen = 1;
  }
  //Exit/Delete Button
  else if (keyPressed == '#') {
    if (parameterFlag) {
      number = "";
      parameters[currentScreen] = 0;
    } else {
      inputFlag = false;
      currentScreen = 0;
      number = "";
    }
  }
}

void resolveInput() {
  if (inputFlag) {
    currentScreen == 1;
    inputAction(keyPressed);
    keyPressed = NULL;
  }
  printScreen();
}

void inputAction(char input) {
  //Up Button
  if (input == 'A') {
    if (parameterFlag) {
      if (parameters[currentScreen] != 100) {
        parameters[currentScreen]++;
      }
    } else if (currentScreen == 1) {
      currentScreen = numOfScreens - 1;
    } else {
      currentScreen--;
    }
    //Down Button
  } else if (input == 'B') {
    if (parameterFlag) {
      if (parameters[currentScreen] != 0) {
        parameters[currentScreen]--;
      }
    } else if (currentScreen == numOfScreens - 1) {
      currentScreen = 1;
    } else {
      currentScreen++;
    }
    //Select Button
  } else if (input == 'C') {
    if (currentScreen != numOfScreens - 1) {
      parameterFlag = true;
    } else if (currentScreen == numOfScreens - 1) {
      //Power Off
      lcd.setBacklight(LOW);
    }
    //Back Button
  } else if (input == 'D') {
    parameterFlag = false;
    number = "";
    //Number Button
  } else if (input == '1' || input == '2' || input == '3' || input == '4' || input == '5' ||
             input == '6' || input == '7' || input == '8' || input == '9' || input == '0') {
    if (parameterFlag) {
      number += input;
      parameters[currentScreen] = constrain(number.toInt(), 0, 100);
    }
  }
}

void printScreen() {
  //  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(screen[currentScreen]);
  lcd.setCursor(0, 1);
  if (currentScreen == numOfScreens - 1) {
    lcd.print("                ");
  } else {
    if (parameterFlag) {
      lcd.print("-> ");
    }
    lcd.print(parameters[currentScreen]);
    lcd.print(" ");
    lcd.print(Percentage);
  }
}
