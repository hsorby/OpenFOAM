set(_FILES
  Kmesh/Kmesh.C
  fft/fft.C
  fft/calcEk.C
  fft/kShellIntegration.C
  processes/UOprocess/UOprocess.C
  turbulence/turbGen.C
  noise/noiseFFT/noiseFFT.C
  noise/noiseModels/noiseModel/noiseModel.C
  noise/noiseModels/noiseModel/noiseModelNew.C
  noise/noiseModels/pointNoise/pointNoise.C
  noise/noiseModels/surfaceNoise/surfaceNoise.C
  windowModels/windowModel/windowModel.C
  windowModels/windowModel/windowModelNew.C
  windowModels/Hanning/Hanning.C
  windowModels/uniform/uniform.C
)
add_library(randomProcesses ${_FILES})
target_compile_features(randomProcesses PUBLIC cxx_std_11)
target_include_directories(randomProcesses PUBLIC include includePrivate windowModels/windowModel)
target_link_libraries(randomProcesses PUBLIC sampling finiteVolume FFTW::DoubleThreads)
#message(STATUS "FFTW_FOUND: ${FFTW_FOUND}")
#message(STATUS "FFTW_FLOAT_LIB: ${FFTW_FLOAT_LIB}")
#message(STATUS "FFTW_DOUBLE_LIB: ${FFTW_DOUBLE_LIB}")
#message(STATUS "FFTW_LONGDOUBLE_LIB: ${FFTW_LONGDOUBLE_LIB}")
#message(STATUS "FFTW_FLOAT_THREADS_LIB: ${FFTW_FLOAT_THREADS_LIB}")
#message(STATUS "FFTW_DOUBLE_THREADS_LIB: ${FFTW_DOUBLE_THREADS_LIB}")
#message(STATUS "FFTW_LONGDOUBLE_THREADS_LIB: ${FFTW_LONGDOUBLE_THREADS_LIB}")
#message(STATUS "FFTW_FLOAT_OPENMP_LIB: ${FFTW_FLOAT_OPENMP_LIB}")
#message(STATUS "FFTW_DOUBLE_OPENMP_LIB: ${FFTW_DOUBLE_OPENMP_LIB}")
#message(STATUS "FFTW_LONGDOUBLE_OPENMP_LIB: ${FFTW_LONGDOUBLE_OPENMP_LIB}")
