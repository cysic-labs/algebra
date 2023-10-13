SUBDIRS := c

all: build
build:
	$(MAKE) -C $(SUBDIRS) all
	bindgen c/point_add.h -o src/bindings/point_add.rs


.PHONY: clean
clean: 
	$(MAKE) -C $(SUBDIRS) clean
	cargo clean