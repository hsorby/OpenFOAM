set(_FILES
  POSIX.C
  cpuInfo/cpuInfo.C
  cpuTime/cpuTimePosix.C
  memInfo/memInfo.C
  signals/sigFpe.C
  signals/sigSegv.C
  signals/sigInt.C
  signals/sigQuit.C
  signals/sigStopAtWriteNow.C
  signals/sigWriteNow.C
  signals/timer.C
  regExp/regExpPosix.C
  fileStat/fileStat.C
  fileMonitor/fileMonitor.C
  printStack/dummyPrintStack.C
  printStack/printStack.C
)
add_library(OSspecific ${_FILES})
target_compile_features(OSspecific PUBLIC cxx_std_11)
target_include_directories(OSspecific PUBLIC include PUBLIC includePrivate)
target_link_libraries(OSspecific PUBLIC OpenFOAM)
