all:
	verilator -Wno-fatal --cc rtl/*.sv \
		--top-module gpu \
		-Icompiler \
		-Iruntime \
		--exe sim/main.cpp \
		runtime/MiniGPURuntime.cpp \
		compiler/compiler.cpp

	make -C obj_dir -f Vgpu.mk

run:
	./obj_dir/Vgpu programs/add.txt 10

run8:
	./obj_dir/Vgpu programs/add.txt 8

run16:
	./obj_dir/Vgpu programs/add.txt 16

clean:
	rm -rf obj_dir