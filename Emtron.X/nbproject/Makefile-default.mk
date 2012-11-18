#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o ${OBJECTDIR}/_ext/1015565369/kernel.o ${OBJECTDIR}/_ext/1015565369/timer.o ${OBJECTDIR}/_ext/1015565369/uart.o ${OBJECTDIR}/_ext/1015565369/task_switch.o ${OBJECTDIR}/_ext/1015565369/PIC24.o ${OBJECTDIR}/_ext/761631083/rtos.o ${OBJECTDIR}/_ext/761631083/task.o ${OBJECTDIR}/_ext/761631083/taskQueue.o ${OBJECTDIR}/_ext/1472/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d ${OBJECTDIR}/_ext/1015565369/kernel.o.d ${OBJECTDIR}/_ext/1015565369/timer.o.d ${OBJECTDIR}/_ext/1015565369/uart.o.d ${OBJECTDIR}/_ext/1015565369/task_switch.o.d ${OBJECTDIR}/_ext/1015565369/PIC24.o.d ${OBJECTDIR}/_ext/761631083/rtos.o.d ${OBJECTDIR}/_ext/761631083/task.o.d ${OBJECTDIR}/_ext/761631083/taskQueue.o.d ${OBJECTDIR}/_ext/1472/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o ${OBJECTDIR}/_ext/1015565369/kernel.o ${OBJECTDIR}/_ext/1015565369/timer.o ${OBJECTDIR}/_ext/1015565369/uart.o ${OBJECTDIR}/_ext/1015565369/task_switch.o ${OBJECTDIR}/_ext/1015565369/PIC24.o ${OBJECTDIR}/_ext/761631083/rtos.o ${OBJECTDIR}/_ext/761631083/task.o ${OBJECTDIR}/_ext/761631083/taskQueue.o ${OBJECTDIR}/_ext/1472/main.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o: ../Devices/GraphicDisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/GraphicDisplay.c  -o ${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/kernel.o: ../Portable/PIC24/kernel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/kernel.c  -o ${OBJECTDIR}/_ext/1015565369/kernel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/kernel.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/kernel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/timer.o: ../Portable/PIC24/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/timer.c  -o ${OBJECTDIR}/_ext/1015565369/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/timer.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/uart.o: ../Portable/PIC24/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/uart.c  -o ${OBJECTDIR}/_ext/1015565369/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/uart.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/PIC24.o: ../Portable/PIC24/PIC24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/PIC24.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/PIC24.c  -o ${OBJECTDIR}/_ext/1015565369/PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/PIC24.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/PIC24.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/rtos.o: ../RTOS/rtos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/rtos.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/rtos.c  -o ${OBJECTDIR}/_ext/761631083/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/rtos.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/rtos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/task.o: ../RTOS/task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/task.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/task.c  -o ${OBJECTDIR}/_ext/761631083/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/task.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/taskQueue.o: ../RTOS/taskQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/taskQueue.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/taskQueue.c  -o ${OBJECTDIR}/_ext/761631083/taskQueue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/taskQueue.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/taskQueue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"        -g -D__DEBUG   -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o: ../Devices/GraphicDisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1543948142 
	@${RM} ${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Devices/GraphicDisplay.c  -o ${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543948142/GraphicDisplay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/kernel.o: ../Portable/PIC24/kernel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/kernel.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/kernel.c  -o ${OBJECTDIR}/_ext/1015565369/kernel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/kernel.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/kernel.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/timer.o: ../Portable/PIC24/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/timer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/timer.c  -o ${OBJECTDIR}/_ext/1015565369/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/timer.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/uart.o: ../Portable/PIC24/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/uart.c  -o ${OBJECTDIR}/_ext/1015565369/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/uart.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1015565369/PIC24.o: ../Portable/PIC24/PIC24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/PIC24.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Portable/PIC24/PIC24.c  -o ${OBJECTDIR}/_ext/1015565369/PIC24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1015565369/PIC24.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/PIC24.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/rtos.o: ../RTOS/rtos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/rtos.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/rtos.c  -o ${OBJECTDIR}/_ext/761631083/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/rtos.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/rtos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/task.o: ../RTOS/task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/task.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/task.c  -o ${OBJECTDIR}/_ext/761631083/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/task.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761631083/taskQueue.o: ../RTOS/taskQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/761631083 
	@${RM} ${OBJECTDIR}/_ext/761631083/taskQueue.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RTOS/taskQueue.c  -o ${OBJECTDIR}/_ext/761631083/taskQueue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761631083/taskQueue.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/761631083/taskQueue.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"        -omf=elf -O1 -I"C:/Users/Hans/Documents/GitHub/Emtron" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1015565369/task_switch.o: ../Portable/PIC24/task_switch.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.d 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../Portable/PIC24/task_switch.s  -o ${OBJECTDIR}/_ext/1015565369/task_switch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -Wa,-MD,"${OBJECTDIR}/_ext/1015565369/task_switch.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/task_switch.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1015565369/task_switch.o: ../Portable/PIC24/task_switch.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1015565369 
	@${RM} ${OBJECTDIR}/_ext/1015565369/task_switch.o.d 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../Portable/PIC24/task_switch.s  -o ${OBJECTDIR}/_ext/1015565369/task_switch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -Wa,-MD,"${OBJECTDIR}/_ext/1015565369/task_switch.o.d",--defsym=__MPLAB_BUILD=1,--relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1015565369/task_switch.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG   -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,-s,--no-force-link,--smart-io,-Map="C:/Users/Hans/Documents/GitHub/Emtron/Emtron.X/usage.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,-s,--no-force-link,--smart-io,-Map="C:/Users/Hans/Documents/GitHub/Emtron/Emtron.X/usage.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Emtron.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
