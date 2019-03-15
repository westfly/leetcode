deploy := $(shell pwd)
deploy_code := $(deploy)/src
deploy_obj := $(deploy)/obj
src_list := $(wildcard $(deploy_code)/*cc)
exclude_list := $(shell find $(deploy_code) -size 0 -exec ls {} \;)
src_list := $(filter-out $(exclude_list), $(src_list))
#编译太慢，修改为只编译最新的文件
src_list :=$(shell ls -rt $(deploy_code)/*cc | tail -n1)
#obj_list = $(patsubst %.cc, $(deploy_obj)/%.o, $(notdir $(src_list)))
obj_list = $(patsubst %.cc, %.o, $(src_list))
all: $(obj_list)
#cc=clang++
cc=g++
flag=--std=c++11
$(obj_list): %.o:%.cc
	file_name=bin/$(basename $(notdir $<))
	$(cc) -o bin/$(basename $(notdir $<)) $(flag) $< src/code_utils.cpp
	#g++ -o $(file_name) --std=c++11 $< src/code_utils.cpp
	# excute command 
	./bin/$(basename $(notdir $<))
clean:
	@echo $(deploy_code)
	@echo $(src_list)
	@echo $(exclude_list)
	rm -rf $(obj_list)
