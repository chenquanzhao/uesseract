# Build Configuration
CXX ?= c++
CXXFLAGS = -llept -ltesseract -O2 -std=c++17

.PHONY: uesseract
uesseract:
	$(CXX) -o uesseract src/uesseract.cc $(CXXFLAGS)

.PHONY: clean
clean:
	rm -rf uesseract