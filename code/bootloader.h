 M5.Lcd.setRotation(1);
  led.show();
  led.setBrightness(255);
  led.fill(led.Color(0, 0, 255));
  led.show();
    esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
  vTaskDelay(random(1, 3000 + 1000) / portTICK_PERIOD_MS);
    esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
  led.fill(led.Color(0, 0, 0));
  led.show();
  int x = (M5.Lcd.width() - 50) / 2;
  int y = (M5.Lcd.height() - 50) / 3;
  M5.Lcd.drawBitmap(x, y, 50, 50, epd_bitmap_favicon);
    esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
  vTaskDelay(random(1, 3000 + 1000) / portTICK_PERIOD_MS);
    esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
  M5Cardputer.Speaker.setVolume(128);
  M5.Lcd.setBrightness(lux);
  for (int a = 0; a < random(1, 12 + 2); a++) {
      esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
   for (int i = 0; i < 17; i++) {
      M5.Lcd.drawBitmap(105, 90, 30, 30, frames[i]);//epd_bitmap_aallArray
    vTaskDelay(33 / portTICK_PERIOD_MS);
    }
   }
    vTaskDelay(500 / portTICK_PERIOD_MS);
M5.Lcd.fillScreen(BLACK);
for (int val = 0; val < 170; val++) {
lux--;
M5.Lcd.setBrightness(lux);
    vTaskDelay(25 / portTICK_PERIOD_MS);
}
  esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
    vTaskDelay(random(1, 3000 + 1000 / portTICK_PERIOD_MS));
      esp_task_wdt_reset(); // Réinitialiser le watchdog
  vTaskDelay(1 / portTICK_PERIOD_MS);
  for (int a = 0; a < random(1, 8 + 3); a++) {
  int y1 = (M5.Lcd.height() - 21) / 2;
  int x1 = (M5.Lcd.width() - 28) / 2;
  M5.Lcd.fillScreen(0xe7bf);
  for (int i = 0; i < 26; i++) {
      M5.Lcd.drawBitmap(x1, y1, 28, 21, epd_bitmap_aallArray[i]);//epd_bitmap_aallArray
    vTaskDelay(33 / portTICK_PERIOD_MS);
      esp_task_wdt_reset(); // Réinitialiser le watchdog
    }
   }
     M5.Lcd.fillScreen(BLACK);
int delai = 0.05;
int imgx = -135;
float steppe = 6.75;  // Le pas nécessaire pour que imgx atteigne 0 en 20 itérations

for (int i = 0; i < 20; i++) { 
        esp_task_wdt_reset(); // Réinitialiser le watchdog
 
    imgx = imgx + steppe;  // On augmente imgx de 6.75 à chaque itération
    delai = delai + 0.1;   // On augmente le délai pour ralentir progressivement
    if(connectedtowifi == 1) {
    M5.Lcd.drawBitmap(0, imgx, 240, 135, epd_bitmap_wifi);
    }else{
    M5.Lcd.drawBitmap(0, imgx, 240, 135, epd_bitmap_nowifi);
    }
    vTaskDelay(delai / portTICK_PERIOD_MS);
}
    esp_task_wdt_reset(); // Réinitialiser le watchdog
