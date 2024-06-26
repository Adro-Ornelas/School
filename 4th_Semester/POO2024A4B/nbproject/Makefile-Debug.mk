#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Anfibio.o \
	${OBJECTDIR}/Angiosperma.o \
	${OBJECTDIR}/Animal.o \
	${OBJECTDIR}/Bien.o \
	${OBJECTDIR}/Briofita.o \
	${OBJECTDIR}/Cilindro.o \
	${OBJECTDIR}/CilindroHueco.o \
	${OBJECTDIR}/Circulo.o \
	${OBJECTDIR}/Credito.o \
	${OBJECTDIR}/Curso.o \
	${OBJECTDIR}/Departamento.o \
	${OBJECTDIR}/Escaleno.o \
	${OBJECTDIR}/Esfera.o \
	${OBJECTDIR}/Especie.o \
	${OBJECTDIR}/Fecha.o \
	${OBJECTDIR}/GestorContable.o \
	${OBJECTDIR}/GestorPoligonos.o \
	${OBJECTDIR}/Hexagon.o \
	${OBJECTDIR}/Muebles.o \
	${OBJECTDIR}/Musgos.o \
	${OBJECTDIR}/Ortoedro.o \
	${OBJECTDIR}/Persona.o \
	${OBJECTDIR}/Pez.o \
	${OBJECTDIR}/Pila.o \
	${OBJECTDIR}/PilaDoble.o \
	${OBJECTDIR}/Planta.o \
	${OBJECTDIR}/Poligono.o \
	${OBJECTDIR}/PoligonoIrregular.o \
	${OBJECTDIR}/PoligonoRegular.o \
	${OBJECTDIR}/Profesor.o \
	${OBJECTDIR}/Punto.o \
	${OBJECTDIR}/Queue.o \
	${OBJECTDIR}/QueueCircular.o \
	${OBJECTDIR}/Rana.o \
	${OBJECTDIR}/Rectangle.o \
	${OBJECTDIR}/Rectangulo.o \
	${OBJECTDIR}/Reptil.o \
	${OBJECTDIR}/Rodado.o \
	${OBJECTDIR}/Rombo.o \
	${OBJECTDIR}/Rosales.o \
	${OBJECTDIR}/Serpiente.o \
	${OBJECTDIR}/TarjetaDeCredito.o \
	${OBJECTDIR}/Terreno.o \
	${OBJECTDIR}/Tiburon.o \
	${OBJECTDIR}/Triangle.o \
	${OBJECTDIR}/Vector.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poo2024a4b.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poo2024a4b.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poo2024a4b ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Anfibio.o: Anfibio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Anfibio.o Anfibio.cpp

${OBJECTDIR}/Angiosperma.o: Angiosperma.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Angiosperma.o Angiosperma.cpp

${OBJECTDIR}/Animal.o: Animal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Animal.o Animal.cpp

${OBJECTDIR}/Bien.o: Bien.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bien.o Bien.cpp

${OBJECTDIR}/Briofita.o: Briofita.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Briofita.o Briofita.cpp

${OBJECTDIR}/Cilindro.o: Cilindro.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cilindro.o Cilindro.cpp

${OBJECTDIR}/CilindroHueco.o: CilindroHueco.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CilindroHueco.o CilindroHueco.cpp

${OBJECTDIR}/Circulo.o: Circulo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Circulo.o Circulo.cpp

${OBJECTDIR}/Credito.o: Credito.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Credito.o Credito.cpp

${OBJECTDIR}/Curso.o: Curso.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Curso.o Curso.cpp

${OBJECTDIR}/Departamento.o: Departamento.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Departamento.o Departamento.cpp

${OBJECTDIR}/Escaleno.o: Escaleno.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Escaleno.o Escaleno.cpp

${OBJECTDIR}/Esfera.o: Esfera.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Esfera.o Esfera.cpp

${OBJECTDIR}/Especie.o: Especie.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Especie.o Especie.cpp

${OBJECTDIR}/Fecha.o: Fecha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fecha.o Fecha.cpp

${OBJECTDIR}/GestorContable.o: GestorContable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GestorContable.o GestorContable.cpp

${OBJECTDIR}/GestorPoligonos.o: GestorPoligonos.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GestorPoligonos.o GestorPoligonos.cpp

${OBJECTDIR}/Hexagon.o: Hexagon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hexagon.o Hexagon.cpp

${OBJECTDIR}/Muebles.o: Muebles.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Muebles.o Muebles.cpp

${OBJECTDIR}/Musgos.o: Musgos.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Musgos.o Musgos.cpp

${OBJECTDIR}/Ortoedro.o: Ortoedro.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ortoedro.o Ortoedro.cpp

${OBJECTDIR}/Persona.o: Persona.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Persona.o Persona.cpp

${OBJECTDIR}/Pez.o: Pez.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pez.o Pez.cpp

${OBJECTDIR}/Pila.o: Pila.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pila.o Pila.cpp

${OBJECTDIR}/PilaDoble.o: PilaDoble.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PilaDoble.o PilaDoble.cpp

${OBJECTDIR}/Planta.o: Planta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Planta.o Planta.cpp

${OBJECTDIR}/Poligono.o: Poligono.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Poligono.o Poligono.cpp

${OBJECTDIR}/PoligonoIrregular.o: PoligonoIrregular.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PoligonoIrregular.o PoligonoIrregular.cpp

${OBJECTDIR}/PoligonoRegular.o: PoligonoRegular.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PoligonoRegular.o PoligonoRegular.cpp

${OBJECTDIR}/Profesor.o: Profesor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Profesor.o Profesor.cpp

${OBJECTDIR}/Punto.o: Punto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Punto.o Punto.cpp

${OBJECTDIR}/Queue.o: Queue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Queue.o Queue.cpp

${OBJECTDIR}/QueueCircular.o: QueueCircular.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QueueCircular.o QueueCircular.cpp

${OBJECTDIR}/Rana.o: Rana.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rana.o Rana.cpp

${OBJECTDIR}/Rectangle.o: Rectangle.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rectangle.o Rectangle.cpp

${OBJECTDIR}/Rectangulo.o: Rectangulo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rectangulo.o Rectangulo.cpp

${OBJECTDIR}/Reptil.o: Reptil.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reptil.o Reptil.cpp

${OBJECTDIR}/Rodado.o: Rodado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rodado.o Rodado.cpp

${OBJECTDIR}/Rombo.o: Rombo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rombo.o Rombo.cpp

${OBJECTDIR}/Rosales.o: Rosales.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rosales.o Rosales.cpp

${OBJECTDIR}/Serpiente.o: Serpiente.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Serpiente.o Serpiente.cpp

${OBJECTDIR}/TarjetaDeCredito.o: TarjetaDeCredito.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TarjetaDeCredito.o TarjetaDeCredito.cpp

${OBJECTDIR}/Terreno.o: Terreno.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Terreno.o Terreno.cpp

${OBJECTDIR}/Tiburon.o: Tiburon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tiburon.o Tiburon.cpp

${OBJECTDIR}/Triangle.o: Triangle.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Triangle.o Triangle.cpp

${OBJECTDIR}/Vector.o: Vector.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vector.o Vector.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
