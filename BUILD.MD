# For Windows
git clone https://github.com/ironx1/C-Collection.git <br />
cd C-Collection <br />
cmake -B build -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DBUILD_SHARED_LIBS=TRUE <br />
cmake --build build --config Release <br />
Note:use "cmake --build build --config Debug" if you are going to use the library in your debug project<br />

# For Linux and MacOS
git clone https://github.com/ironx1/C_Vector.git <br />
cd C-Collection <br />
cmake -B build <br />
cmake --build build
