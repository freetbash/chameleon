include ../../Config

all:$(foreach n,$(wildcard *.cpp),../../temp/$(n).o)
	@echo $(C)
../../temp/%.cpp.o:%.cpp
	$(CXX) $(INCLUDE) $(FLAG) -c $^ -o $@
