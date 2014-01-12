#define HAIKU_APP_BASE (D:\Users\cdn\workspace\myCProject\.)
#define HAIKU_APP_NAME (LiquidCrystalHelloWorld)
#define HAIKU_CC (avr-gcc)
#define HAIKU_CC_OPT ($(HAIKU_CFLAGS) -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -mmcu=$(HAIKU_TARGET) -DF_CPU=$(HAIKU_CLOCK)UL -I"$(HAIKU_APP_BASE)" -I"$(HAIKU_VM_BASE)" -c -o"$@" "$<")
#define HAIKU_CFLAGS (-I"${HAIKU_HOME}/lib/includes/arduino/cores/arduino" -I"${HAIKU_HOME}/lib/includes/arduino/variants/leonardo")
#define HAIKU_CLIBS (-L"${HAIKU_HOME}/lib/clibs" -lleonardo -lc)
#define HAIKU_CXX (avr-g++)
#define HAIKU_CXX_OPT ($(HAIKU_CFLAGS) -Wall -Os -fpack-struct -fshort-enums            -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -mmcu=$(HAIKU_TARGET) -DF_CPU=$(HAIKU_CLOCK)UL -I"$(HAIKU_APP_BASE)" -I"$(HAIKU_VM_BASE)" -c -o"$@" "$<")
// Mapped '8' to 'HAIKU_CHAR_8'
#define HAIKU_Char (HAIKU_CHAR_8)
#define HAIKU_Clock (16000000)
#define HAIKU_Config (mytarget)
#define HAIKU_Extends (leonardo.UsingCLIB)
#define HAIKU_Extension (.hex)
#define HAIKU_GC (HAIKU_StopTheWorldGC)
#define HAIKU_HAIKUVM4C (./haikuVM)
#define HAIKU_HOME (D:\Users\cdn\workspace)
#define HAIKU_IncrementalGCSlice (10)
#define HAIKU_InitialMainThreadStackSize (142)
#define HAIKU_InitialOtherThreadStackSize (45)
#define HAIKU_InternalExceptionEnable (NullPointerException | NoSuchMethodError | OutOfMemoryError | ClassCastException | VirtualMachineError | ArithmeticException)
#define HAIKU_InternalExceptionThrow (0)
#define HAIKU_LDFLAGS (-Wl,-Map,$(HAIKU_APP_NAME).map -Wl,--gc-sections -mmcu=$(HAIKU_TARGET) -o"$(HAIKU_APP_NAME).elf" -lc -lm $(OBJS) $(USER_OBJS) $(HAIKU_CLIBS) $(LIBS))
#define HAIKU_LINKER (avr-g++)
#define HAIKU_MemorySize ((RAMEND-0x100) - 300)
#define HAIKU_MicroKernel (haiku.avr.lib.arduino.HaikuMicroKernelProcessing)
#define HAIKU_MillisDividend (128)
#define HAIKU_MillisDivisor (125)
#define HAIKU_MillisPrescale (64)
// Mapped '16/32' to 'HAIKU_16_32'
#define HAIKU_Mode (HAIKU_16_32)
#define HAIKU_Output ($(HAIKU_APP_NAME)$(HAIKU_EXTENSION))
#define HAIKU_Port (com5)
#define HAIKU_Target (atmega32u4)
#define HAIKU_Threads (0)
#define HAIKU_Upload (avrdude -p $(HAIKU_TARGET) -c avr109 -patmega32u4 -P $(HAIKU_PORT) -b57600 -U flash:w:$(HAIKU_OUTPUT))
#define HAIKU_VM_BASE (../../HaikuVM)