@echo off

IF "%1" == "SHARED" (
    cmake -B "${{github.workspace}}/build"                                      ^
          -DBUILD_SHARED_LIBRARIES=ON                                           ^
          -DCMAKE_PREFIX_PATH="${{github.workspace}}/SFML/install/lib/cmake"
) ELSE (
    cmake -B "${{github.workspace}}/build"                                      ^
          -DBUILD_SHARED_LIBRARIES=OFF                                          ^
          -DCMAKE_PREFIX_PATH="${{github.workspace}}/SFML/install/lib/cmake"
)

cmake ${{github.workspace}}/build                                               ^
      --config ${{env.BUILD_TYPE}}                
