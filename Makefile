CXX = g++
CXXFLAGS = -std=c++20 -Wall -O2

# Target to compile and run a specific file
run:
	@if [ -z "$(FILE)" ]; then \
		echo "Usage: make run FILE=path/to/your/file.cpp"; \
	else \
		echo "Compiling $(FILE)..."; \
		$(CXX) $(CXXFLAGS) $(FILE) -o runfile && echo "Running $(FILE)..." && ./runfile; \
	fi

# Clean the generated binary
clean:
	rm -f runfile