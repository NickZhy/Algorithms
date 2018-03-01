src_dir := ./
obj_dir := ./exe
src_files := $(wildcard $(src_dir)/*.cpp)
obj_files := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(src_files))

CC := g++
CPPFLAGS := -Wall
CXXFLAGS := -std=c++11

all: floder objs

clean: 
	rm -rf $(obj_dir)

floder: $(obj_dir)

$(obj_dir):
	mkdir -p $(obj_dir)

objs: $(obj_files)

$(obj_dir)/%.o: $(src_dir)/%.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

