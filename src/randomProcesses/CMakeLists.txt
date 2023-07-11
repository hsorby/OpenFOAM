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
target_include_directories(randomProcesses PUBLIC include PRIVATE includePrivate)
