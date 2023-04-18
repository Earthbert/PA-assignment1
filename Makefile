# Exemplu de Makefile pentru temă. "Rezolvați" comentariul de mai jos.

# Parametri pentru compilare.
CCFLAGS := -std=c++17 -Wall -Wextra -O0 -lm

# Directorul care conține sursele voastre, și cel unde punem binarele.
SRC_DIR := ./src
OUT_DIR := ./build

# Compilăm *toate* sursele găsite în $(SRC_DIR).
# Modificați doar dacă vreți să compilați alte surse.
CC_SRC := $(wildcard $(SRC_DIR)/*.cpp)

CC_EXECS := $(CC_SRC:$(SRC_DIR)/%.cpp=$(OUT_DIR)/%)
TARGETS := $(CC_EXECS)


.PHONY: build clean

build: $(TARGETS)

clean:
	rm -f $(TARGETS)

run-p1:
	$(OUT_DIR)/feribot
run-p2:
	$(OUT_DIR)/nostory
run-p3:
	$(OUT_DIR)/sushi
run-p4:
	$(OUT_DIR)/semnale
run-p5:
	$(OUT_DIR)/badgpt

$(CC_EXECS): $(OUT_DIR)/%: $(SRC_DIR)/%.cpp
	g++ -o $@ $^ $(CCFLAGS)
