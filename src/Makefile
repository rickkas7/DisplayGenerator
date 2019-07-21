
OBJS = main.bc Adafruit_GFX.bc helpers.bc spark_wiring_print.bc spark_wiring_string.bc

all: $(OBJS)
	emcc --bind -o ../public/main.js $(OBJS)

%.bc: %.cpp
	emcc --bind -std=c++11 -o $@ $<

clean :
	rm -f *.bc ../public/main.js ../public/main.wasm
	
