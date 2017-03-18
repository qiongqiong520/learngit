
INC_DIR:=./
SRC_DIR:=./
SRCS:=$(wildcard *.cc)
LIBS :=-lpthread
CXX:= g++
CXXFLAGS:=-Wall -g -std=c++11 $(addprefix -I,$(INC_DIR)) $(LIBS)

EXE:=./server

$(EXE):$(SRCS)
	$(CXX) -o $@ $(SRCS) $(CSSFLAGS)

clean:
	rm -rf $(EXE)
