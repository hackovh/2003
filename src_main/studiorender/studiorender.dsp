# Microsoft Developer Studio Project File - Name="StudioRender" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=StudioRender - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "studiorender.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "studiorender.mak" CFG="StudioRender - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "StudioRender - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "StudioRender - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Src/StudioRender", MNSDAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "StudioRender - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "STUDIORENDER_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /W4 /Zi /Ox /Ot /Og /Oi /Ob2 /I "..\public" /I "..\common" /D "NDEBUG" /D "_WIN32" /D "IMAGE_LOADER_NO_DXTC" /D "_MBCS" /D "_USRDLL" /D "STUDIORENDER_EXPORTS" /D "_WINDOWS" /D "PROTECTED_THINGS_ENABLE" /FAs /FD /c
# SUBTRACT CPP /Os /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x2C000000" /dll /map /debug /machine:I386 /libpath:"..\lib\public" /libpath:"..\lib\common"
# Begin Custom Build
TargetDir=.\Release
TargetPath=.\Release\studiorender.dll
InputPath=.\Release\studiorender.dll
SOURCE="$(InputPath)"

"..\..\bin\StudioRender.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if exist ..\..\bin\studiorender.dll attrib -r ..\..\bin\studiorender.dll 
	copy $(TargetPath) ..\..\bin\studiorender.dll 
	if exist $(TargetDir)\studiorender.map copy $(TargetDir)\studiorender.map ..\..\bin\studiorender.map 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "StudioRender - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "STUDIORENDER_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /W4 /Gm /ZI /Od /I "..\public" /I "..\common" /D "WIN32" /D fopen=dont_use_fopen /D "_DEBUG" /D "IMAGE_LOADER_NO_DXTC" /D "_MBCS" /D "_USRDLL" /D "STUDIORENDER_EXPORTS" /D "_WINDOWS" /D "PROTECTED_THINGS_ENABLE" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x2C000000" /dll /debug /machine:I386 /pdbtype:sept /libpath:"..\lib\public" /libpath:"..\lib\common"
# Begin Custom Build
TargetDir=.\Debug
TargetPath=.\Debug\studiorender.dll
InputPath=.\Debug\studiorender.dll
SOURCE="$(InputPath)"

"..\..\bin\StudioRender.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if exist ..\..\bin\studiorender.dll attrib -r ..\..\bin\studiorender.dll 
	copy $(TargetPath) ..\..\bin\studiorender.dll 
	if exist $(TargetDir)\studiorender.map copy $(TargetDir)\studiorender.map ..\..\bin\studiorender.map 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "StudioRender - Win32 Release"
# Name "StudioRender - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CStudioRender.cpp
# End Source File
# Begin Source File

SOURCE=.\FlexRenderData.cpp
# End Source File
# Begin Source File

SOURCE=..\Public\ImageLoader.cpp
# End Source File
# Begin Source File

SOURCE=..\Public\interface.cpp
# End Source File
# Begin Source File

SOURCE=..\Public\Mathlib.cpp
# End Source File
# Begin Source File

SOURCE=..\public\tier0\memoverride.cpp
# End Source File
# Begin Source File

SOURCE=.\r_studio.cpp
# End Source File
# Begin Source File

SOURCE=.\r_studiodecal.cpp
# End Source File
# Begin Source File

SOURCE=.\r_studiodraw.cpp
# End Source File
# Begin Source File

SOURCE=.\r_studioflex.cpp
# End Source File
# Begin Source File

SOURCE=.\r_studiolight.cpp
# End Source File
# Begin Source File

SOURCE=.\studiostats.cpp
# End Source File
# Begin Source File

SOURCE=..\public\utlbuffer.cpp
# End Source File
# Begin Source File

SOURCE=..\Public\vmatrix.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Public\amd3dx.h
# End Source File
# Begin Source File

SOURCE=..\Public\basetypes.h
# End Source File
# Begin Source File

SOURCE=..\Public\bspflags.h
# End Source File
# Begin Source File

SOURCE=..\Public\clientstats.h
# End Source File
# Begin Source File

SOURCE=..\Public\cmodel.h
# End Source File
# Begin Source File

SOURCE=..\Public\convar.h
# End Source File
# Begin Source File

SOURCE=.\CStudioRender.h
# End Source File
# Begin Source File

SOURCE=.\FlexRenderData.h
# End Source File
# Begin Source File

SOURCE=..\Public\ImageLoader.h
# End Source File
# Begin Source File

SOURCE=..\Public\interface.h
# End Source File
# Begin Source File

SOURCE=..\Public\IStudioRender.h
# End Source File
# Begin Source File

SOURCE=..\Public\MATHLIB.H
# End Source File
# Begin Source File

SOURCE=..\Public\measure_section.h
# End Source File
# Begin Source File

SOURCE=..\Public\model_types.h
# End Source File
# Begin Source File

SOURCE=..\common\optimize.h
# End Source File
# Begin Source File

SOURCE=..\Public\PixelWriter.h
# End Source File
# Begin Source File

SOURCE=..\Public\s3_intrf.h
# End Source File
# Begin Source File

SOURCE=..\Public\studio.h
# End Source File
# Begin Source File

SOURCE=.\StudioStats.h
# End Source File
# Begin Source File

SOURCE=..\Public\utllinkedlist.h
# End Source File
# Begin Source File

SOURCE=..\Public\UtlMemory.h
# End Source File
# Begin Source File

SOURCE=..\Public\UtlVector.h
# End Source File
# Begin Source File

SOURCE=..\Public\vcollide.h
# End Source File
# Begin Source File

SOURCE=..\Public\vector.h
# End Source File
# Begin Source File

SOURCE=..\Public\vector2d.h
# End Source File
# Begin Source File

SOURCE=..\Public\vector4d.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\lib\public\vstdlib.lib
# End Source File
# Begin Source File

SOURCE=..\lib\public\tier0.lib
# End Source File
# End Target
# End Project
