echo "开始构建"

scriptDir=$(cd `dirname $0`; pwd)
macDir="${scriptDir}/build_mac"

echo "构建路径:${macDir}"

rm -rf ${macDir}

mkdir ${macDir};

cd ${macDir}


cmake -G Xcode \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DCMAKE_C_COMPILER=/usr/bin/clang \
  -DCMAKE_CXX_COMPILER=/usr/bin/clang++ \
  ../


