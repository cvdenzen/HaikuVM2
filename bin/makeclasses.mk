all:
	"$(JAVAC)" -bootclasspath "" -extdirs "" -classpath '$(NXJ_HOME)\haikuRT\src\main\java;$(NXJ_HOME)\lib\nxt\classes.jar;$(NXJ_HOME)\bootstrap\src\main\java;$(NXJ_HOME)\examples\src\main\java;$(NXJ_HOME)\haikuBench\src\main\java;$(NXJ_HOME)\gallerie\src\main\java;$(NXJ_HOME)\incubator\src\main\java;$(CLASSESDIR)' -d '$(CLASSESDIR)' '$(ARG)' $(HAIKU_KERNELS)
	
unix:
	"$(JAVAC)" -bootclasspath "" -extdirs "" -classpath '$(NXJ_HOME)/haikuRT/src/main/java:$(NXJ_HOME)/lib/nxt/classes.jar:$(NXJ_HOME)/bootstrap/src/main/java:$(NXJ_HOME)/examples/src/main/java:$(NXJ_HOME)/haikuBench/src/main/java:$(NXJ_HOME)/gallerie/src/main/java:$(NXJ_HOME)/incubator/src/main/java:$(CLASSESDIR)' -d '$(CLASSESDIR)' '$(ARG)' $(HAIKU_KERNELS)
	
	