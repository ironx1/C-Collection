# For Windows
git clone https://github.com/ironx1/C_Vector.git <br />
cd C_Vector\Vector <br />
cmake -B build -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS -DBUILD_SHARED_LIBS <br />
cmake --build build --config Release <br /><br />

# For Linux and MacOS
git clone https://github.com/ironx1/C_Vector.git <br />
cd C_Vector/Vector <br />
cmake -B build <br />
cmake --build build --config Release
