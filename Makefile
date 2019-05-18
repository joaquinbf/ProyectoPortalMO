# Makefile solo para evitar tener que escribir ciertos commands que no se 
# se puedan agregar a CMake

# Corre el entorno de pruebas de Box2D
testbed:
	cd libs/Box2D-master/ && ../premake5 gmake && make -C Build/ && cd Testbed && ../Build/bin/x86_64/Debug/Testbed

.PHONY: testbed
