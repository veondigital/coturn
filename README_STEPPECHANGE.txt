

install dependences

1. https://github.com/SCDependencies/datadog-cpp

mkdir build
cd build/
cmake ..
make
make package
sudo yum install ./datadogcpp-1.0.1-0.x86_64.rpm

2. https://github.com/SCDependencies/yajl

git checkout 2.1.1
see
https://github.com/SCDependencies/yajl/blob/2.1.0_feature_rpm/rpm/build.instructions.txt

3. make coturn rpm
./configure
 cat ./rpm/build.instructions.txt
