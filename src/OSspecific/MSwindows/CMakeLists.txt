set(_FILES
  MSwindows.C
  cpuInfo/cpuInfo.C
  memInfo/memInfo.C
  signals/sigFpe.C
  signals/sigInt.C
  signals/sigQuit.C
  signals/sigSegv.C
  signals/sigStopAtWriteNow.C
  signals/sigWriteNow.C
  signals/timer.C
  fileStat/fileStat.C
  fileMonitor/fileMonitor.C
  printStack/dummyPrintStack.C
)
add_library(OSspecific ${_FILES})
target_compile_features(OSspecific PUBLIC cxx_std_11)
target_include_directories(OSspecific PUBLIC include PRIVATE includePrivate)
