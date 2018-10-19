PROJECT = orbital
CXX=g++
CXXFLAGS += -Wc++11-extensions -std=c++11

OUTPUTDIR = ./build/
MKDIR = mkdir -p $(OUTPUTDIR)

CXXSOURCES += $(wildcard src/*.cpp src/*/*.cpp)

all: $(PROJECT)

$(PROJECT):
	$(MKDIR)
	$(CXX) -o $(OUTPUTDIR)/$(PROJECT) $(CXXFLAGS) $(CXXSOURCES)

.PHONY : clean
clean:
	rm -rf $(OUTPUTDIR) 
