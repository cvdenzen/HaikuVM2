rem @echo off

rem Carl cd to arduino ide directory
D:
cd D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\libraries
echo %0 %*

if "%OS%" == "Windows_NT" goto :winnt

:win98
	echo Windows 9x/ME is no longer supported.
	echo Please upgrade to Windows 2000 or later.
	goto :eof

:append_jar
	set "TMP_CP=%TMP_CP%;%TMP_JAR%"
	goto :eof

:build_classpath
	if not exist "%~2" (
		echo Internal error. The following directory does not exist:
		echo   "%~2"
		exit /B 1
	)

	set "TMP_CP="
	for /R "%~2" %%i in (*.jar) do (
		set "TMP_JAR=%%i"
		call :append_jar
	)
	set "%~1=%TMP_CP:~1%"
	goto :eof

:search_path
	set "%~1=%~f$PATH:2"
	goto :eof

:find_make
	call :search_path MAKE make.exe
	if "%MAKE%" == "" (
		echo make.exe was not found in the default search path.
		echo Install a WINAVR.
		exit /B 1
	)
	goto :eof

:find_java_and_javac
	call :search_path JAVA java.exe
	call :search_path JAVAC javac.exe
	if "%JAVA%" == "" (
		echo java.exe was not found in the default search path.
		echo Install a JDK and set the variable LEJOS_NXT_JAVA_HOME
		echo to the root directory of the JDK.
		exit /B 1
	) else if "%JAVAC%" == "" (
		echo javac.exe was not found in the default search path.
		echo Consider setting the variable LEJOS_NXT_JAVA_HOME to
		echo the root directory of a JDK. Otherwise,
		echo some tools might not work.
	)
	goto :eof

:set_java_and_javac
	set "JAVA=%~2\bin\java.exe"
	set "JAVAC=%~2\bin\javac.exe"
	if not exist "%JAVA%" (
		echo The variable %~1 does not point to the root directory of
		echo a JRE or JDK. The following executable does not exist:
		echo   "%JAVA%"
		exit /B 1
	) else if not exist "%JAVAC%" (
		echo The variable %~1 seems to point to the root directory of
		echo a JRE. It should point to the root directory of a JDK.
		echo Otherwise, some tools might not work.
	)
	goto :eof

:winnt
	setlocal
	set "NXJ_COMMAND=%~n0"
	set "NXJ_HOME=%~dp0\.."

	call :build_classpath NXJ_CP_PC "%%NXJ_HOME%%\lib\pc"
	call :build_classpath NXJ_CP_NXT "%%NXJ_HOME%%\lib\nxt"

	if not "%LEJOS_NXT_JAVA_HOME%" == "" (
		call :set_java_and_javac LEJOS_NXT_JAVA_HOME "%%LEJOS_NXT_JAVA_HOME%%"
	) else if not "%JAVA_HOME%" == "" (
		call :set_java_and_javac JAVA_HOME "%%JAVA_HOME%%"
	) else (
		call :find_java_and_javac
	)
rem Carl
rem You cannot change name of batch file, as it is used as the COMMAND_NAME
SET NXJ_COMMAND=haiku
"%JAVA%" "-Dhaikuvm.home=%NXJ_HOME%" "-DCOMMAND_NAME=%NXJ_COMMAND%" -classpath "%NXJ_CP_PC%" haikuvm.pc.tools.HaikuVM %*

rem carl
set NXJ_COMMAND="haiku"

REM Carl edit

rem goto :eof
rem 32 bit java
set JAVA=C:\Program Files (x86)\Java\jre7\bin\java
echo %JAVA%
"%JAVA%" -version
rem this is working (20131127), but upload for leonardo is not as stable as when arduino ide is started manually.
rem Needs some investigation.
rem cd /D D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4
pushd D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4
rem set java.library.path to . for rxtxSerial.dll and to %TEMP% for jna
set JAVALIBRARYPATH=.;%TEMP%
set JAVACLASSPATH=D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\pde.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\jmdns-3.4.1.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\commons-logging-1.0.4.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\jna.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\commons-codec-1.7.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\commons-exec-1.1.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\commons-httpclient-3.1.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\core.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\ecg.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\jsch-0.1.50.jar;D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\lib\RXTXcomm.jar
"%JAVA%" -version
rem "%JAVA%" -d32 -Djava.library.path=%JAVALIBRARYPATH% -classpath %JAVACLASSPATH% processing.app.Base --Config leonardo --upload -v -v -v D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\libraries\HaikuVM\examples\HaikuVM\HaikuVM.ino
arduino --Config leonardo -v -v -v D:\downloads\arduino-1.5.4-r2-windows\arduino-1.5.4\libraries\HaikuVM\examples\HaikuVM\HaikuVM.ino
popd

:eof

exit /B %errorlevel%
