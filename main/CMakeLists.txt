idf_component_register(
                      SRCS  "main.cpp"
                            "program.cpp" 
                            "display.cpp"
                            "event/event.cpp"
                            "event/key_event.cpp"
                      REQUIRES "esp_driver_gpio" "arduino" "Adafruit-GFX-Library" "SSD1322_for_Adafruit_GFX"
                      INCLUDE_DIRS ".")
