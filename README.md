# sqlite-fill

This is a simple test of [sqlite_orm](https://github.com/fnc12/sqlite_orm) library performance filling approximately 20,000 records

## Build

1. Clone this project and then cd to the project folder;

2. Init the git submodules:
```
$ git submodule init
$ git submodule update --init --recursive
```

3. Configure the project using CMake:
```
$ cmake -B ./build -G <preferred generator> -DCMAKE_BUILD_TYPE=<Debug|Release>
```

4. Then run build command:
```
$ cmake --build ./build --config <Debug|Release>
```

5. You've done! The builded binary file available in the build directory.

## Usage

After running application will create sqlite db file and start filling it with preliminarily generated data.

## License

This project is licensed under the [MIT License](LICENSE).

## Credits

My thanks to the developers of the [sqlite_orm](https://github.com/fnc12/sqlite_orm) and [datetimepp](https://github.com/coin-au-carre/datetimepp).
