deploy := $(shell pwd)
deploy_code := $(deploy)/src
deploy_obj := $(deploy)/obj
src_list := $(wildcard $(deploy_code)/*cc)
exclude_list := $(shell find $(deploy_code) -size 0 -exec ls {} \;)
src_list := $(filter-out $(exclude_list), $(src_list))
#obj_list = $(patsubst %.cc, $(deploy_obj)/%.o, $(notdir $(src_list)))
obj_list = $(patsubst %.cc, %.o, $(src_list))
all: $(obj_list)

$(obj_list): %.o:%.cc
	g++ -o bin/$(basename $(notdir $<)) $< src/code_utils.cpp
clean:
	@echo $(deploy_code)
	@echo $(src_list)
	@echo $(exclude_list)
	rm -rf $(obj_list)
